#!/usr/bin/perl

##############################################################################
# Main script to provision T40/T41 Configurations
# Tested against SW Version <5.1>
##############################################################################

# Map HSIF type strings to enums
my %hsif_enum = (
    'disabled' => TEN_HSIF_PROTOCOL_DISABLED,
    'sfi5_1'   => TEN_HSIF_PROTOCOL_SFI51,
    'sfi4_1'   => TEN_HSIF_PROTOCOL_SFI41,
    'xfi'      => TEN_HSIF_PROTOCOL_XFI,
    'sfi4_2'   => TEN_HSIF_PROTOCOL_SFI42_10G,
    'xaui'     => TEN_HSIF_PROTOCOL_XAUI,
    'cfp_mr'   => TEN_HSIF_PROTOCOL_CFP
);

if (defined $batch_args) {
#     print "full.pl: batch_args exists\n";
    @ARGV = split ';', $batch_args;
}

use strict;
use warnings FATAL => qw(all); # Promote hidden apish eval warnings to errors
use Data::Dumper;

use configs;            # High-level functions that could be ported to C
use client_40g;
use config_clocks;      # Board-specific FPGA and clocking functions
use check;              # Traffic test functions for automated test scripts
use syncdsync;
use clocks;

##############################################################################
# Global variables
##############################################################################
my $disable_server_logging = 0; # Set this to '1' to disable server logging

my $sysclk_freq;
my $sysclk_Mhz_int = 0;
my $dev_id = 0; # First device in the system

my $mod_a;
my $mod_b;
my $mod_line       ='invalid';
my $mod_num_line   ='invalid';   # Bugzilla 30856
my $slice_line     ='invalid';
my $mod_client     ='invalid';
my $mod_num_client ='invalid'; # Bugzilla 30856
my $slice_client   ='invalid';
my $mbclksel;

my $line_interface='invalid';
my $client_interface='invalid';
my $client_sub_type;

my $lb_kpga_interface;
my $module_lb_kpga;

my $provision_line   = 0;
my $provision_client = 0;

my $a_mod_mode  = TEN_GLOBAL_MODE_QUAD_10G;  # = 1
my $b_mod_mode  = TEN_GLOBAL_MODE_QUAD_10G;
my $line_mode   = TEN_GLOBAL_MODE_QUAD_10G;
my $client_mode = TEN_GLOBAL_MODE_QUAD_10G;
my $quad_mode;
my $gpllx1_inst_line;
my $gpllx1_inst_client;
my $gpllx1_inst_lb_kpga;

my $config_is_fc_ra_fc;
my $line_rate=0;
my $client_rate=0;
my $xcon_client_rate=0; # Bugzilla 2006
my $mux_odu2v_rate=0;
my $use_xaui_protection_switch_mode = 0;

my $sfi41_ufec_alloc =0;
my $mod_line_int = 0;      # A2
my $slice_line_int = 2;
my $mod_client_int = 0;    # A1
my $slice_client_int = 1;
            
my $enable_intr_flag = 0;  # Added for autogen - interrupt handlers are enabled by a compile time switch in the driver. Since this 
                           # switch is off by default, we do not enable the INTR handlers.

##############################################################################
# Process logging option
##############################################################################
# Disable logging in the server
if ($disable_server_logging) {
    ten_drvr_ctl_logging(CS_DISABLE);
    api_dump_off();
}
else {
    ten_drvr_ctl_logging(CS_ENABLE);
    api_dump_on();
}

# Tell apish to stop printing out all the stuff to the client screen
client_dump_off();

my $collect_driver_log = 0;
if ($collect_driver_log) {
  # automatically collect a driver log
  client_dump_on();
  api_dump_on();
  ten_drvr_ctl_logging(CS_ENABLE);
  ten_drvr_start_output_to_file("/proj/software/t41/t41_driver_log.txt");
}

# put useable command line in driver's log file
my $full_cmd_line = "batch full.pl,'";
foreach my $cmd_line_arg (@ARGV) {
  $full_cmd_line = $full_cmd_line . $cmd_line_arg . ";"
}
$full_cmd_line = $full_cmd_line . "'";
ten_print($full_cmd_line);

##############################################################################
# Process the command line options
##############################################################################
my %args = check_args();

if ($args{help}) {
    # help was displayed, so stop running
    return 0;
}

# This prints the arguments out for easy readability
print Dumper \%args;

$dev_id = $args{dev_id}; # Bugzilla 30856 Start

##############################################################################
# Bug 24820: fc_ra_fc should provision line as otu2
##############################################################################
$config_is_fc_ra_fc = ( (($args{line} eq '8gfc_ra') and ($args{client} eq '8gfc_ra')) or
                        (($args{line} eq '4gfc_ra') and ($args{client} eq '4gfc_ra')) or
                        (($args{line} eq '2gfc_ra') and ($args{client} eq '2gfc_ra')) or
                        (($args{line} eq '1gfc_ra') and ($args{client} eq '1gfc_ra')) );

if ($config_is_fc_ra_fc) {
  $args{line} = 'otu2';
  #$args{line_fec} = 'deallocate';
  $args{line_fec} = 'nofec';
  $args{line_traffic_type_enum} = 5;
}

$sysclk_freq = $sysclocks{$args{sysclk}};
$sysclk_Mhz_int = int( $args{sysclk} ); # truncate for integer API parms
print "-sysclk $args{sysclk} expanded to $sysclk_freq\n";
if ($args{reset_t40}) {
    # Reset the T40 chip and exit
    tb_reset($sysclk_freq);
    return 0;
}

# The ID number is generated by tc.pl
# Printing it out into the log file will make finding a specific run easier
if (exists $args{id}) {
    ten_print("Regression ID: $args{id}");
}

# Determine whether this is a monolithic or aggregation config
my $aggregation = $args{mode} eq 'mux' ? 1 : 0;
my $k = $args{k_value};

# Attempt to map hsif_A and hsif_B to hsif_line and hsif_client if hsif_line and hsif_client have not been specified
if ($args{hsif_A} ne 'disabled') {
    # HSIF A was specified
    if ($args{line_port} < 4) {
        # Line is on Side A
        if ($args{hsif_line} eq 'disabled') {
            # hsif_line has not been specified on command line
            $args{hsif_line} = $args{hsif_A};
        }
    }
    elsif ($args{client_port} < 4) {
        # Client is on Side A
        if ($args{hsif_client} eq 'disabled') {
            # hsif_client has not been specified on command line
            $args{hsif_client} = $args{hsif_A};
        }
    }
}
if ($args{hsif_B} ne 'disabled') {
    # HSIF A was specified
    if ($args{line_port} > 3) {
        # Line is on Side B
        if ($args{hsif_line} eq 'disabled') {
            # hsif_line has not been specified on command line
            $args{hsif_line} = $args{hsif_B};
        }
    }
    elsif ($args{client_port} > 3) {
        # Client is on Side B
        if ($args{hsif_client} eq 'disabled') {
            # hsif_client has not been specified on command line
            $args{hsif_client} = $args{hsif_B};
        }
    }
}

my $return_value;
($return_value, $args{mld_line_enabled}, $args{mld_client_enabled}) = validate_hsif_traffic_type (%args);
if ($return_value) {
    failure("Host interface for the traffic type is invalid");
    return 1;
}

my ($ret_value, $sync, $map_oxuv, $map_odtu) = validate_sync_vs_async(%args);
if ($ret_value) {
    failure("Sync vs async selection for the configuration is invalid!");
    return 1;
} else {
    $args{sync} = $sync;
    $args{map_oxuv_enum} = $map_oxuv;
    $args{map_odtu_enum} = $map_odtu;
}
print "\n\nsync:".$args{sync}.", map_oxuv:". $args{map_oxuv_enum}.", map_odtu:". $args{map_odtu_enum}."\n\n";


##############################################################################
# Check supported FEC modes and traffic combinations
##############################################################################
# 1. FEC related
if ((($args{line} eq 'otu3e') or($args{line} eq 'otu3e1')) and (($args{line_fec} eq 'ufec25p') or ($args{line_fec} eq 'ufec26p'))) {
  if($sysclk_freq < 425000000) {
    failure("OTU3e with 25% UFEC or 26% UFEC needs to be run with option -sysclk=425");
    return 1;
  }
}

if ((($args{line} eq 'otu3e') or ($args{line} eq 'otu3e1') or ($args{line} eq 'otu3e2')) and 
    ($args{line_fec} eq 'ufec25p_295')) {
  if($sysclk_freq < 425000000) {
    failure("OTU3E/OTU3E1/OTU3E2 with 25_295% UFEC needs to be run with option -sysclk=425");
    return 1;
  }
}

# Check for line and client compatibility
if (validate_line_client(%args)) {
    failure("Line and client not compatible");
    return 1;
}

($ret_value, $args{timeslots}) = validate_timeslots (%args);
if ($ret_value) {
    failure("Mapper type and number of time slices not compatible");
    return 1;
}
printf ("args{timeslots} = $args{timeslots}\n");


if ($args{line} ne 'invalid') {
    if ($args{line} =~ /otu/) {
        if ($args{line_fec} eq 'deallocate') {
            failure("line = $args{line} and line fec not specified");
            return 1;
        }
    }
}
if ($args{client} ne 'invalid') {
    if ($args{client} =~ /otu/) {
        if ($args{client_fec} eq 'deallocate') {
            failure("client = $args{client} and client fec not specified");
            return 1;
        }
    }
}

if ((($args{line_fec} ne 'gfec') and ($args{line_fec} ne '0fec') and ($args{line_fec} ne 'nofec') and ($args{line_fec} ne 'ufec7p')) and
     ($args{line} eq 'otu3+')) {
    failure("line_fec '0fec|gfec|ufec7p/nofec' are the only supported FECs for $args{line}");
    return 1;
}
if ((($args{line_fec} ne 'gfec') and ($args{line_fec} ne '0fec') and ($args{line_fec} ne 'ufec7p') and ($args{line_fec} ne 'nofec')) and
    ($args{line} eq 'otu3p2')) {
    failure("line_fec '0fec|gfec|ufec7p' are the only supported FECs for $args{line}");
    return 1;
}

 if (($args{line_fec} eq 'ufec7p_sdha') and ($args{client} ne 'oc192')) {
    failure("line_fec 'ufec7p_sdha' is only supported for client 'oc192'");
    return 1;
}

if (($args{line} ne 'invalid') && ($args{client} ne 'invalid')) {
    # check for XAUI protection switching mode
    if (($mod_line eq $mod_client) and ($args{client_port} eq $args{line_port})) {
      if (($args{hsif_client} eq 'xaui') and ($args{hsif_line} eq 'xfi')) {
        print "Use protection switching on XAUI client port.\n";
        $args{client_port} = $args{client_port} - 4;
        $use_xaui_protection_switch_mode = 1;

      }
      elsif (($args{hsif_client} eq 'xfi') and ($args{hsif_line} eq 'xaui')) {
        print "Use protection switching on XAUI line port.\n";
        $args{line_port} = $args{line_port} - 4;
        $use_xaui_protection_switch_mode = 1;
      }
      else {
        failure("Line and Client are on the same port.\n");
        return 1;
      }
    }
}

# Bugzilla #30058 - Add full.pl check for CFP STL-256.4 -term;trans not valid 
if (($args{client} =~ /oc768/) and ($args{oc_term_enum} eq TEN_OC192_TERM_TRANSPARENT_CBR10)) {
  if (($args{hsif_client} eq 'xfi') or ($args{hsif_client} eq 'cfp_mr')) {
    failure("Invalid -term;trans with CFP STL-256.4; use <transregen|rsregen|msregen> instead.");
    return 1;
  }
}

# Bugzilla #38953 - wire configuration for OTU3 XFI to OTU3 SFI-5.1 not supported
if (($args{mode} eq 'wire40') and (($args{hsif_client} eq 'xfi') or ($args{hsif_line} eq 'xfi'))) {
  failure("Invalid HSIF XFI for 40G wire mode, use -trans instead.");
  return 1;
}
if (($args{mode} eq 'wire40') and (($args{hsif_client} eq 'cfp_mr') or ($args{hsif_line} eq 'cfp_mr'))) {
  failure("Invalid HSIF CFP MR for 40G wire mode, use -trans instead.");
  return 1;
}

###############################################################################
# Change the variables to match the configuration and system
###############################################################################
# Initialize the FPGA and sys_refclk
# Configure the MBCLKSEL pin to T40 based on sys_refclk
# This also hard-resets the FPGA and T40
print "\nBeginning provisioning\n\n";

# The line-side should be provisioned if this is not dynamic reprovisioning or
# the line-side port was specified (i.e. 10G provisioning)
if (($args{mode} eq 'mux') || ($args{mode} eq 'trans10') || ($args{mode} eq 'trans40') ||
    ($args{mode} eq 'wire10') || ($args{mode} eq 'wire40')) {
    if ($args{dyn_repro} == TEN_INITIAL_CONFIG) {
        # Both line and client will need to be provisioned
        $provision_line   = 1;
        if (($args{mode} eq 'mux') and (($args{client} eq 'null') or ($args{client} eq 'invalid'))) {
            $provision_client = 0;
        } else {
            $provision_client = 1;
        }
    }
    elsif ($args{dyn_repro} == TEN_REPRO_LINE_AND_CLIENT) {
        #if (($args{line} eq 'null') or ($args{line} eq 'invalid')) {
        #    $provision_line = 0;
        #} else {
        #    # Do not change the clients hsif or syncdsync
        #    $provision_line = 1;
        #}
        if (($args{client} ne 'null') and ($args{client} ne 'invalid')) {
            $provision_client = 1;
            $provision_line = 1;
        } else {
            # Do not change the clients hsif or syncdsync
            $provision_client = 0;
            $provision_line = 0;
        }
    } else { #($args{dyn_repro} == TEN_REPRO_CLIENT)
        # Only Client side will be reprovisioned
        $provision_line   = 0;
        if (($args{client} ne 'null') and ($args{client} ne 'invalid')) {
            $provision_client = 1;
        } else {
            # Do not change the clients hsif or syncdsync
            $provision_client = 0;
        }
    }
} else {
    # Must be installing a Cross connect looback or KPGA or PBERT
    if (($args{line} ne 'invalid')) {
        # Line is being provsioned with loop or test pattern
        $provision_line   = 1;
        $provision_client = 0;
    } else {  # $args{client} ne 'invalid')
        # Client is being provsioned with loop or test pattern
        $provision_line   = 0;
        $provision_client = 1;
    }
}

my $cfp_mr_10g_line_traffic = TEN_TRAFFIC_TYPE_NONE;
my $cfp_mr_10g_client_traffic = TEN_TRAFFIC_TYPE_NONE;

if ( ($args{hsif_line} eq 'cfp_mr') and ($args{linerate} == 10) ) {
  if ( ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_6_2) ||
       ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_7_3) ||
       ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE) ||
       ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_6_1) ||
       ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) ||
       ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_RA) ||
       ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_TC) ||
       ($args{line_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_GFPF)) {
         $cfp_mr_10g_line_traffic = TEN_TRAFFIC_TYPE_10GE;
  }
  else {
    $cfp_mr_10g_line_traffic = $args{line_traffic_type_enum};
  }
}

if ( ($args{hsif_client} eq 'cfp_mr') and ($args{clientrate} == 10) ) {
  if ( ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_6_2) ||
       ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_7_3) ||
       ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE) ||
       ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_6_1) ||
       ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2) ||
       ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_RA) ||
       ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_TC) ||
       ($args{client_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE_GFPF)) {
         $cfp_mr_10g_client_traffic = TEN_TRAFFIC_TYPE_10GE;
  }
  else {
    $cfp_mr_10g_client_traffic = $args{client_traffic_type_enum};
  }
}

print ("provision_line = $provision_line, provision_client = $provision_client\n");

if ($args{dyn_repro} == TEN_INITIAL_CONFIG) {
    # Initialize the device driver because this is the initial provisioning
    my $_orgiginal_sysclk_freq = $sysclk_freq;          # tb_reset MUST get the rate in its original range (i.e. not x4).
    ($sysclk_freq, $mbclksel) = tb_init($sysclk_freq);  # If given in low range, now sysclk_freq is x4.

    ten_dev_main_init( $dev_id );
    $mod_a = ten_mod_main_init( $dev_id, TEN_MODULE_A );
    $mod_b = ten_mod_main_init( $dev_id, TEN_MODULE_B );
    config_init_cupll_silabs_initialized();
    if (!ten_dev_is_ws_in_progress($dev_id)) {
      tb_reset($_orgiginal_sysclk_freq);
    }
} else {
    # Dynamic reprovisioning.  Device driver has already been initialized
    $mbclksel = tb_get_mbclksel($sysclk_freq);
    $sysclk_freq = ($sysclk_freq > $MAXLOWRANGEREF) ? $sysclk_freq : $sysclk_freq * 4 ;
    $mod_a = $dev_id << 8;
    $mod_b = $mod_a + 1;
}


# override chip type if desired, or end an override by using default. This must be called after
# ten_dev_init (or ten_dev_main_init).
if    ($args{chip} eq 't41')     { $return_value = ten_dev_override_chiptype( $dev_id, TEN_CHIP_OVERRIDE_T41 );}
elsif ($args{chip} eq 't40')     { $return_value = ten_dev_override_chiptype( $dev_id, TEN_CHIP_OVERRIDE_T40 );}
elsif ($args{chip} eq 'default') { $return_value = ten_dev_override_chiptype( $dev_id, TEN_CHIP_OVERRIDE_DEF );}
else  {
    failure("Bad chip type override. use 't40', 't41', or 'default'");
    return 1;
}
if ($return_value) {
    failure("ERROR: API function ten_dev_override_chiptype()");
    return 1;
}


# Set bus error checking
ten_dev_set_bus_error_check($dev_id, $args{bus_error_check});

###############################################################################
# Check interface compatibility
###############################################################################
#####   Set up all of the Line side variables  #####

if ($args{line} ne 'invalid') {
    # A valid line traffic type has been specified
    if ($args{line_port} < 4) {
        # Line is on Side A
        if ($args{hsif_line} ne 'disabled') {
            # hsif_line has been specified on command line
            $args{hsif_A} = $args{hsif_line};
        }
        elsif ($args{hsif_A} ne 'disabled') {
            # hsif_A has been specified on command line
            $args{hsif_line} = $args{hsif_A};
        } else {
            failure("Neither -hsif_line nor -hsif_A were specified");
            return 1;
        }
    } else {
        # Line is on Side B
        if ($args{hsif_line} ne 'disabled') {
            # hsif_line has been entered
            $args{hsif_B} = $args{hsif_line};
        }
        elsif ($args{hsif_B} ne 'disabled') {
            # hsif_B has been entered
            $args{hsif_line} = $args{hsif_B};
        } else {
            failure("Neither -hsif_line nor -hsif_B were specified");
            return 1;
        }
    }
    $args{hsif_line_enum} = $hsif_enum{$args{hsif_line}};

    if ($args{linerate} == 40) {
        # Line Side is 40G
        $line_mode = TEN_GLOBAL_MODE_S_40G; # = 0
        $slice_line = 0;

        if ($args{line_port} < 4) {
            # Line is on Side A
            $a_mod_mode = TEN_GLOBAL_MODE_S_40G;  # = 0
            $mod_line = $mod_a;
            $mod_num_line = TEN_MODULE_A;  # Bugzilla 30856
            $gpllx1_inst_line = 1;  # GPLL 1

        } else {
            # Line is on Side B
            $b_mod_mode = TEN_GLOBAL_MODE_S_40G;
            $mod_line = $mod_b;
            $mod_num_line = TEN_MODULE_B;  # Bugzilla 30856
            $gpllx1_inst_line = 9;  # GPLL 9
        }

        if ($args{hsif_line_enum} == TEN_HSIF_PROTOCOL_SFI42_10G) {
            #/* This is a 40g configuration */
            $args{hsif_line_enum} = TEN_HSIF_PROTOCOL_SFI42_40G;
        }
    } else {
        # Line Side is 10G
        $slice_line = $args{line_port} & 3;

        if ($args{line_port} < 4) {
            # Line is on Side A
            $mod_line = $mod_a;
            $mod_num_line = TEN_MODULE_A;  # Bugzilla 30856
            $gpllx1_inst_line = 1;  # GPLL 1
        } else {
            # Line is on Side B
            $mod_line = $mod_b;
            $mod_num_line = TEN_MODULE_B;  # Bugzilla 30856
            $gpllx1_inst_line = 9;  # GPLL 9
        }
        $args{hsif_line_enum} = $hsif_enum{$args{hsif_line}};
    }

    $line_interface = $args{hsif_line};
    if ($line_interface eq 'sfi4_2') {
        $line_interface = $args{linerate} == 40 ? 'sfi4_2_40g' : 'sfi4_2_10g';
    }
    print ("mod_line = $mod_line, args{line_port} = $args{line_port}, slice_line = $slice_line\n");
    print ("args{hsif_line} = $args{hsif_line}, line_mode = $line_mode, args{linerate} = $args{linerate} \n");
}

######   Set up all of the Client side variables   #####
if ($args{client} ne 'invalid') {
    # A valid client traffic type has been specified
    if ($args{client_port} < 4) {
        # Client is on Side A
        if ($args{hsif_client} ne 'disabled') {
            # hsif_client has been specified on command line
            $args{hsif_A} = $args{hsif_client};
        }
        elsif ($args{hsif_A} ne 'disabled') {
            # hsif_A has been specified on command line
            $args{hsif_client} = $args{hsif_A};
        } else {
            failure("Neither -hsif_client nor -hsif_A were specified");
            return 1;
        }
    } else {
        # Line is on Side B
        if ($args{hsif_client} ne 'disabled') {
            # hsif_client has been entered
            $args{hsif_B} = $args{hsif_client};
        }
        elsif ($args{hsif_B} ne 'disabled') {
            # hsif_B has been entered
            $args{hsif_client} = $args{hsif_B};
        } else {
            failure("Neither -hsif_client nor -hsif_B were specified");
            return 1;
        }
    }
    $args{hsif_client_enum} = $hsif_enum{$args{hsif_client}};

    if ($args{clientrate} == 40) {
        # Client Side is 40G
        $client_mode = TEN_GLOBAL_MODE_S_40G;
        $slice_client = 0;

        if ($args{client_port} < 4) {
            # Client is on Side A
            $a_mod_mode = TEN_GLOBAL_MODE_S_40G; # = $client_mode
            $mod_client = $mod_a;
            $mod_num_client = TEN_MODULE_A;  # Bugzilla 30856
            $gpllx1_inst_client = 1;  # GPLL 1
        } else {
            # Client is on Side B
            $b_mod_mode = TEN_GLOBAL_MODE_S_40G; # = $client_mode
            $mod_client = $mod_b;
            $mod_num_client = TEN_MODULE_B;  # Bugzilla 30856
            $gpllx1_inst_client = 9;  # GPLL 9
        }

        if ($args{hsif_client_enum} == TEN_HSIF_PROTOCOL_SFI42_10G) {
            #/* This is a 40g configuration */
            $args{hsif_client_enum} = TEN_HSIF_PROTOCOL_SFI42_40G;
        }
    } else {
        # Client Side is 10G
        $slice_client = $args{client_port} & 3;

        if ($args{client_port} < 4) {
            # Client is on Side A
            $mod_client = $mod_a;
            $mod_num_client = TEN_MODULE_A;  # Bugzilla 30856
            $gpllx1_inst_client = 1;  # GPLL 1
        } else {
            # Client is on Side B
            $mod_client = $mod_b;
            $mod_num_client = TEN_MODULE_B;  # Bugzilla 30856
            $gpllx1_inst_client = 9;  # GPLL 9
        }
    }

    $client_interface = $args{hsif_client};
    if ($client_interface eq 'sfi4_2') {
        $client_interface = $args{clientrate} == 40 ? 'sfi4_2_40g' : 'sfi4_2_10g';
    }
    print ("mod_client = $mod_client, args{client_port} = $args{client_port}, slice_client = $slice_client\n");
    print ("args{hsif_client} = $args{hsif_client}, client_mode = $client_mode, args{clientrate} = $args{clientrate} \n");
}

###############################################################################
# Set up variables for loopback and KPGA modes
###############################################################################
if (($args{mode} eq 'lb10') || ($args{mode} eq 'lb40') ||
    ($args{mode} eq 'kpga10') || ($args{mode} eq 'kpga40') ||
    ($args{mode} eq 'hsif_kpga10') || ($args{mode} eq 'hsif_kpga40') ||
    ($args{mode} eq 'cbr_kpga10') || ($args{mode} eq 'cbr_kpga40')) {
    # Only one side is going to be provisioned
    if ($args{line} ne 'invalid') {
        # Line side is the one that has been specified
        $args{hsif_lb_kpga}              = $args{hsif_line};
        $args{hsif_lb_kpga_enum}         = $args{hsif_line_enum};
        $args{lb_kpga}                   = $args{line};
        $args{lb_kpga_traffic_type_enum} = $args{line_traffic_type_enum};
        $args{lb_kpga_port}              = $args{line_port};
        $args{lb_kpga_fec}               = $args{line_fec};
        $args{lb_kpga_fec_enum}          = $args{line_fec_enum};
        $args{lb_kpga_tcm}               = $args{line_tcm};
        $args{lb_kpga_tcm_bits}          = $args{line_tcm_bits};
        $args{module_id_lb_kpga}         = $mod_line;
        $args{slice_lb_kpga}             = $slice_line;
        $args{lb_kpga_mode}              = $line_mode;
        $lb_kpga_interface               = $line_interface;
        $gpllx1_inst_lb_kpga             = $gpllx1_inst_line;
        $quad_mode                       = $line_mode;
        $args{mld_lb_kpga_enabled}       = $args{mld_line_enabled};

    } else {
        # Client side is the one that has been specified
        $args{hsif_lb_kpga}              = $args{hsif_client};
        $args{hsif_lb_kpga_enum}         = $args{hsif_client_enum};
        $args{lb_kpga}                   = $args{client};
        $args{lb_kpga_traffic_type_enum} = $args{client_traffic_type_enum};
        $args{lb_kpga_port}              = $args{client_port};
        $args{lb_kpga_fec}               = $args{client_fec};
        $args{lb_kpga_fec_enum}          = $args{client_fec_enum};
        $args{lb_kpga_tcm}               = $args{client_tcm};
        $args{lb_kpga_tcm_bits}          = $args{client_tcm_bits};
        $args{module_id_lb_kpga}         = $mod_client;
        $args{slice_lb_kpga}             = $slice_client;
        $args{lb_kpga_mode}              = $client_mode;
        $lb_kpga_interface               = $client_interface;
        $gpllx1_inst_lb_kpga             = $gpllx1_inst_client;
        $quad_mode                       = $client_mode;
        $args{mld_lb_kpga_enabled}       = $args{mld_client_enabled};
    }
  $module_lb_kpga = (($args{module_id_lb_kpga} & 1) == 0) ? TEN_MODULE_A : TEN_MODULE_B;
}


###############################################################################
# Check client and assign module id for line and client
###############################################################################
if ($args{mode} eq 'mux') {
    if ($args{client} eq 'invalid') {
        # Client was not specified, so set it on opposite side as Line
        if ($mod_line == $mod_a) {
            $mod_client = $mod_b;
            $mod_num_client = TEN_MODULE_B;  # Bugzilla 30856
        } else {
            $mod_client = $mod_a;
            $mod_num_client = TEN_MODULE_A;  # Bugzilla 30856
        }
    }
}
print ("args{hsif_A} = $args{hsif_A}, args{hsif_B} = $args{hsif_B}\n");

my $mr_mode_a = $args{hsif_A} eq 'sfi4_1' ? 0 : 1;
my $mr_mode_b = $args{hsif_B} eq 'sfi4_1' ? 0 : 1;

if(my $rev_id = main::ten_mpif_get_chip_rev_id($dev_id) == 1) {
    if (($args{hsif_line} eq 'sfi4_1') and ($slice_line != 0)) {
        failure("Line slice must be 0 for sfi4.1.  Line slice = $slice_line");
        return 1;
    }
    if (($args{hsif_client} eq 'sfi4_1') and ($slice_client != 0)) {
        failure("Client slice must be 0 for sfi4.1.  Client slice = $slice_client");
        return 1;
    }
}
else {
    if ($args{hsif_line} eq 'sfi4_1') {
        if (($mod_line == $mod_a) and ($slice_line != 1) and ($args{line_fec} =~ /ufec/)) {
            failure("Line slice must be 1 for sfi4.1 side A.  Line slice = $slice_line");
            return 1;
        }
        elsif (($mod_line == $mod_b) and ($slice_line != 0) and ($args{line_fec} =~ /ufec/)) {
            failure("Line slice must be 4 for sfi4.1 side B.  Line slice = $slice_line");
            return 1;
        }
    }
    if ($args{hsif_client} eq 'sfi4_1') {
        if (($mod_client != $mod_a) and ($slice_client != 1) and ($args{client_fec} =~ /ufec/)) {
            failure("Client slice must be 1 for sfi4.1 side A.  Client slice = $slice_client");
            return 1;
        }
        elsif (($mod_client != $mod_b) and ($slice_client != 0) and ($args{client_fec} =~ /ufec/)) {
            failure("Client slice must be 4 for sfi4.1 side B.  Client slice = $slice_client");
            return 1;
        }        
    }
}

print ("args{mode} = $args{mode}\n");

#print ("args{a_mod_rate} = $args{a_mod_rate}, args{hsif_A} = $args{hsif_A}, a_mod_mode = $a_mod_mode\n");
#print ("args{b_mod_rate} = $args{b_mod_rate}, args{hsif_B} = $args{hsif_B}, b_mod_mode = $b_mod_mode\n");
print ("\n\n");


###############################################################################
#   Provision Main Board Clk and GPLL internal reference Clock (TX from RX)
###############################################################################
if ($args{dyn_repro} == TEN_INITIAL_CONFIG) {
    ###############################################################################
    # Global Initialization
    ###############################################################################
    print("dev_id = $dev_id, a_mod_mode = $a_mod_mode, b_mod_mode = $b_mod_mode, mbclksel = $mbclksel, mr_mode_a = $mr_mode_a, mr_mode_b = $mr_mode_b\n");
    ten_hl_config_global( $dev_id, $a_mod_mode, $b_mod_mode, $mbclksel, $mr_mode_a, $mr_mode_b );
    ten_hl_ohpp_and_shadow_ram_init($dev_id);
    
    # Bugzilla #28476 - Need to power down unused HSIF SERDES lanes/slices 
    ten_hl_hsif_power_down_serdes($mod_a);
    ten_hl_hsif_power_down_serdes($mod_b);
} else {
    if ($provision_client) {
        if ($args{hsif_client} ne 'sfi4_1') {
            # Bugzilla 29609 Start
            if ($args{clientrate} == 10) {
                ten_mpif_clock_select_gpll_in($dev_id, $mod_num_client, $slice_client, CS_TX, 1);  # Bugzilla 30856
            } else {
                ten_mpif_clock_select_gpll_in($dev_id, $mod_num_client, TEN_SLICE_ALL, CS_TX, 1);  # Bugzilla 30856
            }
            # Bugzilla 29609 End
        }
    }
    if ($provision_line) {
        if ($args{hsif_line} ne 'sfi4_1') {
            # Bugzilla 29609 Start
            if ($args{linerate} == 10) {
                ten_mpif_clock_select_gpll_in($dev_id, $mod_num_line, $slice_line, CS_TX, 1);     # Bugzilla 30856
            } else {
                ten_mpif_clock_select_gpll_in($dev_id, $mod_num_line, TEN_SLICE_ALL, CS_TX, 1);   # Bugzilla 30856
            }
            # Bugzilla 29609 End
        }
    }
}


###############################################################################
#   Check for UFEC allocation with SFI4.1
###############################################################################
if ($args{dyn_repro} == TEN_REPRO_LINE_AND_CLIENT) {
    $sfi41_ufec_alloc = config_get_port0_sfi4_1_ufec_alloc_status(!$mod_line, $slice_line, 
                                                                  $args{linerate}, $args{hsif_line_enum}, 
                                                                  $args{line_fec_enum});
    print("FEC allocation = $sfi41_ufec_alloc\n");
}

###############################################################################
#   Provision FRACTIONAL DIVIDER
###############################################################################
# Modify the signal type to include the FEC percentage, if any
my $line_signal_type   = combine_signal_type_and_fec($args{line},    $args{line_fec});
my $client_signal_type = combine_signal_type_and_fec($args{client}, $args{client_fec});
my $slice = $aggregation ? $slice_client : $slice_line;

# Push the line rate and client rate to the control block with helper function ten_cb_rates then
# calculate and store hysteresis in ten_calc_hyst, called from ten_hl_syncdsync_datapath_config
if ($args{line} ne 'invalid') {
    if ($line_signal_type eq 'null') {
        $line_rate = clocks_get_bps('odu2');
    } else {
        $line_rate = clocks_get_bps($line_signal_type);
    }
    print ("args{line}       = $args{line}\n");
    print ("args{line_fec}   = $args{line_fec}\n");
    print ("line_signal_type = $line_signal_type\n");
    print ("line_rate        = $line_rate\n");
}
if ($args{client} ne 'invalid') {
    if ($client_signal_type eq 'null') {
        $client_rate = clocks_get_bps('odu2');
    } else {
        $client_rate = clocks_get_bps($client_signal_type);
    }
    print ("args{client}       = $args{client}\n");
    print ("args{client_fec}   = $args{client_fec}\n");
    print ("client_signal_type = $client_signal_type\n");
    print ("client_rate        = $client_rate\n");
}

ten_print("### ten_cb_rates($dev_id, $line_rate, $client_rate)");
ten_cb_rates($dev_id, $line_rate, $client_rate);


#odu2   odu2      (10037273920 bps) oc192
#odu1e  odu1e10ge (10355829830 bps) 10ge7_2
#odu2e  odu2e10ge (10399525320 bps) 10ge 10gfc_tc
#odu1f  odu1e10fc (10562946430 bps) 10gfc
#   odu2e10fc (10607515820 bps)

# otu3e2 44583355580
# odu3   40319218980

# Bugzilla 28237 Start
if (($args{mode} eq 'mux') || ($args{mode} eq 'trans10')) {
    if ($args{xcon_client_type} eq 'invalid') {
       if($args{oduflex_enbl} == 1) {
           if ($args{client} eq '8gfc') {
               $args{xcon_client_type} = '8gfc';
               $xcon_client_rate = 8500000000*(239/238);  # 8GFC
               $mux_odu2v_rate = 8500000000*(239/238);   # 8GFC
           }
           if ($args{client} eq 'cbr_10362079327') {
               $args{xcon_client_type} = 'cbr_10362079327';
               $xcon_client_rate = 10312500000*(836/832)*(239/238);
               $mux_odu2v_rate = 10312500000*(836/832)*(239/238);
           }           
       }
       else {
            # xcon client not specified
            if ($args{client} eq 'otu2') {
                $args{xcon_client_type} = 'odu2';   # OC192
                $xcon_client_rate = 10037273920;    # ODU2
                $mux_odu2v_rate = 10037273920;      # ODU2
            }
            elsif ($args{client} eq 'oc192') {
                $args{xcon_client_type} = 'oc192';
                $xcon_client_rate = 9953280000;     # OC192
                $mux_odu2v_rate = 10037273920;      # ODU2
            }
            elsif ($args{client} eq '10ge6_1') {
                $args{xcon_client_type} = '10ge6_1';
                $xcon_client_rate = 10312500000;    # 10GE LAN
                $mux_odu2v_rate = 10037273920;      # ODU2
            }
            elsif ($args{client} eq '10ge6_2') {
                $args{xcon_client_type} = '10ge6_2';
                $xcon_client_rate = 10312500000;    # 10GE LAN
                $mux_odu2v_rate = 10037273920;      # ODU2
            }
            elsif ($args{client} eq '10ge7_2') {
                $args{xcon_client_type} = '10ge7_2';
                $xcon_client_rate = 10312500000;    # 10GE LAN
                $mux_odu2v_rate = 10355829830;      # ODU1e
            }
            elsif ($args{client} eq '10ge7_3') {
                $args{xcon_client_type} = '10ge7_3';
                $xcon_client_rate = 10312500000;    # 10GE LAN
                $mux_odu2v_rate = 10037273920;      # ODU2
            }
            elsif ($args{client} eq 'otu2e') {
                $args{xcon_client_type} = 'odu2e';
                $xcon_client_rate = 10399525320;    # ODU2e
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            elsif ($args{client} eq 'otu1e') {
                $args{xcon_client_type} = 'odu1e';
                $xcon_client_rate = 10355829830;    # ODU1e
                $mux_odu2v_rate = 10355829830;      # ODU1e
            }
            elsif ($args{client} eq '10ge7_1') {
                $args{xcon_client_type} = '10ge7_1';
                $xcon_client_rate = 10312500000;    # 10GE LAN
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            elsif ($args{client} eq '10ge_ra') {
                $args{xcon_client_type} = '10ge_ra';
                $xcon_client_rate = 10312500000;    # 10GE LAN
                if ($args{ra_10ge_odu2e_mode} eq '1') {
                    $mux_odu2v_rate = 10399525320;      # ODU2e
                }
                else {
                    $mux_odu2v_rate = 10037273920;      # ODU2
                }
            }
            elsif ($args{client} eq '10gfc') {
                $args{xcon_client_type} = '10gfc';
                $xcon_client_rate = 10518750000;    # 10GFC
                $mux_odu2v_rate = 10562946430;      # ODU1f
            }
            elsif ($args{client} eq '10gfc_tc_ra') {
                $args{xcon_client_type} = '10gfc_tc';
                $xcon_client_rate = 10518750000;    # 10GFC
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            elsif ($args{client} =~ /10gfc_tc/) { # Bug 31054
                $args{xcon_client_type} = '10gfc_tc';
                $xcon_client_rate = 10518750000;    # 10GFC   # Bugzilla 28237
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            # Bugzilla 39242 Start
            elsif ($args{client} eq 'fdr10_iba') { 
                $args{xcon_client_type} = 'fdr10_iba';
                $xcon_client_rate = 10312500000;    # FDR10_IB
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            # Bugzilla 39242 End
            elsif ($args{client} eq '10ge') { 
                $args{xcon_client_type} = '10ge';
                $xcon_client_rate = 10312500000;    # 10GE
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            elsif ($args{client} eq 'cbr_10362079327') { 
                $args{xcon_client_type} = '10ge_s';
                $xcon_client_rate = 10362079327;    # 10GE
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            # Bugzilla 38565 Start
            elsif ($args{client} =~ /_iba/) { 
                $args{xcon_client_type} = '10g_iba';
                $xcon_client_rate = 10000000000;    # 10G_IB
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            # Bugzilla 38565 End
            # Bugzilla 29042/29100 Start
            elsif ($args{client} eq 'otu3') {
                $args{xcon_client_type} = 'odu2';   # OC192
                $xcon_client_rate = 10037273920;    # ODU2
                $mux_odu2v_rate = 10037273920;      # ODU2
            }
            elsif (($args{client} eq 'otu3e') || ($args{client} eq 'otu3e1')) {
                $args{xcon_client_type} = 'odu2e';
                $xcon_client_rate = 10399525320;    # ODU2e
                $mux_odu2v_rate = 10399525320;      # ODU2e
            }
            elsif ($args{client} eq 'otu3e2') {
                $args{xcon_client_type} = 'odu2e';
                $xcon_client_rate = 10399525320;    # ODU2e
                $mux_odu2v_rate = 10399525320;      # ODU2e
            # Bugzilla 29042/29100 End
            } else {
                # Default to ODU2
                $args{xcon_client_type} = 'odu2';
                $xcon_client_rate = 10037273920;    # ODU2
                $mux_odu2v_rate = 10037273920;      # ODU2
            }
        }
    }
    # Bugzilla 29100 Start
    else {
        if ($args{xcon_client_type} eq 'oc192') {
            $xcon_client_rate = 9953280000;     # OC192
            $mux_odu2v_rate = 10037273920;      # ODU2
        }
        elsif ($args{xcon_client_type} eq 'odu2') {
            $xcon_client_rate = 10037273920;    # ODU2
            $mux_odu2v_rate = 10037273920;      # ODU2
        }
        elsif ($args{xcon_client_type} eq 'odu2e') {
            $xcon_client_rate = 10399525320;    # ODU2e
            $mux_odu2v_rate = 10399525320;      # ODU2e
        }
        elsif ($args{xcon_client_type} eq 'otu1e') {
            $xcon_client_rate = 10355829830;    # ODU1e
            $mux_odu2v_rate = 10355829830;      # ODU1e
        }
    }
    # Bugzilla 29100 End


    unless (exists $ten_xcon_client_enum{$args{xcon_client_type}}) {
        die "Invalid -xcon_client_type $args{xcon_client_type}\n";
    }
    $args{xcon_client_enum} = $ten_xcon_client_enum{$args{xcon_client_type}};


    #print("xcon_signal_type = $xcon_signal_type\n");
    print("args{xcon_client_type} = $args{xcon_client_type}\n");
    #print("mux_odu2v_type = $mux_odu2v_type\n");
    print("xcon_client_rate = $xcon_client_rate\n");
    print("mux_odu2v_rate = $mux_odu2v_rate\n");

}

# Bugzilla 28237 End
elsif ($args{mode} eq 'trans40') {
    if ($args{xcon_client_type} eq 'invalid') {
        # xcon_client_type has not been specified
        if ($args{client} =~ /otu3/) {
            # Bugzilla 28176 Start
            if(($args{client} eq 'otu3e') || ($args{client} eq 'otu3e1'))  {
                $args{xcon_client_type} = 'odu3e1';
                $xcon_client_rate = 41774364410; # Bugzilla 28979
            }
            elsif($args{client} eq 'otu3e2')  {
                $args{xcon_client_type} = 'odu3e2';
            }
            elsif($args{client} eq 'otu3e4')  {
                $args{xcon_client_type} = 'odu3e4';
            }
            elsif($args{client} eq 'otu3')  {
                $args{xcon_client_type} = 'odu3';
            }
            # Bugzilla 28176 End
        }
        elsif ($args{client} =~ /40ge/){
            # 40ge serial 64b/66b will be going accross the XCON unless it is CBR
            $args{xcon_client_type} = '40ges6466';  #  TEN_TRAFFIC_TYPE_S64_66_40GE
        }
        elsif ($args{client} eq 'otu2ex4'){
            $args{xcon_client_type} = 'odu2e';
            $xcon_client_rate = 10399525320;
        }
        # Bugzilla 29609 Start
        elsif ($args{client} eq 'null'){
                $args{xcon_client_type} = 'odu3';  # Dummy
        # Bugzilla 29609 End
        } else {
            # Non-OTN, so client is going accross the XCON
            $args{xcon_client_type} = $args{client};
        }
    }

    unless (exists $ten_xcon_client_enum{$args{xcon_client_type}}) {
        die "Invalid -xcon_client_type $args{xcon_client_type}\n";
    }
    $args{xcon_client_enum} = $ten_xcon_client_enum{$args{xcon_client_type}};

    # Bugzilla 28006 Start
    if ($args{client} =~ /40ge/) {
        # 40GE Client is being received
        unless (exists $ten_40ge_rx_pre_enum{$args{client}}) {
            die "Invalid 40ge -client $args{client}\n";
        }
        if ($args{pre_line} eq 'none') {
          # pre_line not specified
          $args{pre_line_rx_enum}   = $ten_40ge_rx_pre_enum{$args{client}};
          $args{pre_line_tx_enum}   = $ten_40ge_tx_pre_enum{$args{client}};
          $args{pre_line} = $args{client};
        }
        if ($args{pre_client} eq 'none') {
          # pre_client not specified
          $args{pre_client_rx_enum} = $ten_40ge_rx_pre_enum{$args{client}};
          $args{pre_client_tx_enum} = $ten_40ge_tx_pre_enum{$args{client}};
          $args{pre_client} = $args{client};
        }
        $args{deskew_ctrl} = TEN_PP40G_DESKEW; # Use deskew inside of PP40G block
    }
    elsif ($args{xcon_client_type} =~ /40ge/) {
        # OTU3v to OTU3v with 40ge Client is being sent accross the XCON
        unless (exists $ten_40ge_rx_pre_enum{$args{xcon_client_type}}) {
            die "Invalid 40ge -xcon_client_type $args{xcon_client_type}\n";
        }

        if ($args{pre_line} eq 'none') {
          # pre_line not specified
          $args{pre_line_rx_enum}   = $ten_40ge_rx_pre_enum{$args{xcon_client_type}};
          $args{pre_line_tx_enum}   = $ten_40ge_tx_pre_enum{$args{xcon_client_type}};
          $args{pre_line} = $args{xcon_client_type};
        }
        if ($args{pre_client} eq 'none') {
          # pre_client not specified
          $args{pre_client_rx_enum} = $ten_40ge_rx_pre_enum{$args{xcon_client_type}};
          $args{pre_client_tx_enum} = $ten_40ge_tx_pre_enum{$args{xcon_client_type}};
          $args{pre_client} = $args{xcon_client_type};
        }
        $args{deskew_ctrl} = TEN_PP40G_DESKEW; # Use deskew inside of PP40G block
    }
    # Bugzilla 28006 End

    if ($args{xcon_client_type} =~ /40ge/) {
        if ($args{xcon_client_type} eq '40gex') {
            $xcon_client_rate = 40117187500;  # 41,250,000,000 * 64/66(pcs) * 1027/1024(tc)
        } else {
            $xcon_client_rate = 41250000000;
        }
    } elsif ($xcon_client_rate == 0) {     # Bugzilla 28979
        $xcon_client_rate = clocks_get_bps($args{xcon_client_type});
    }

}
#elsif ($args{mode} eq 'trans10') {
#    if ($args{xcon_client_type} eq 'invalid') {
#        if (($args{client} =~ /otu2/) || ($args{client} =~ /otu1/)) {
#            #$args{xcon_client_type} = 'odu2e';
#            $args{xcon_client_type} = $args{client};
#            $args{xcon_client_type} =~ s/otu/odu/;
#            $xcon_signal_type = $args{client};
#
#        } else {
#            $xcon_signal_type = $args{client};
#            $args{xcon_client_type} = $args{client};
#        }
#    }
#}
#print ("args{xcon_client_type} = $args{xcon_client_type}\n");

# Bugzilla 28006 Start
#if ($args{xcon_client_type} =~ /40ge/) {
#    if ($args{xcon_client_type} eq '40gex') {
#        $xcon_client_rate = 40117187500;
#    } else {
#        $xcon_client_rate = 41250000000;
#    }
#} else {
#    if (($args{mode} eq 'mux') && ($args{clientrate} == 10)) {
#        $xcon_client_rate = clocks_get_bps($xcon_signal_type);
#    } else {
#        $xcon_client_rate = clocks_get_bps($args{xcon_client_type});
#    }
#}
## Bugzilla 28006 End
#print ("xcon_client_rate = $xcon_client_rate\n");

my $method = get_syncdsync_muxponder_method($args{line}, $args{client}, $args{mode}, $args{map_oxuv_enum}, $args{map_odtu_enum}); # Bugzilla 27167
#print ("method = $method\n");

# Bugzilla 30823 Start
my $prot_signal_type = 'odu2';
my $is_dual_mux = 0;
if (($args{mode} eq 'mux') && ($args{clientrate} == 40)) {
    $is_dual_mux = 1;
}

if ($provision_line) {
    # Provision the line-side fractional divider
    # Bugzilla 23887 - split RX and TX and corrected for signal type in each case
    # Line RX Pilot Clock
    ten_print("autoconfig_fracdiv #1\n");
    
    if (($line_interface eq 'cfp_mr') and ($args{linerate} == 10)) {
      # 10G CFP_MR fracdiv provisioning
      if (ten_hl_hsif_cfp_get_current_traffic($mod_line, $slice_line) != $cfp_mr_10g_line_traffic) {
        if (($slice_line == 0) or ($slice_line == 1)) {
          # configure 0/1 pair
          autoconfig_fracdiv($mod_line, 1, 0, $line_mode, $line_signal_type, $line_interface, $k,
                             $sysclk_freq, 0, $args{mld_line_enabled}, $is_dual_mux);
        }
        else {  
          # configure 2/3 pair
          autoconfig_fracdiv($mod_line, 3, 0, $line_mode, $line_signal_type, $line_interface, $k,
                             $sysclk_freq, 0, $args{mld_line_enabled}, $is_dual_mux);
        }
      }
    }
    else {
      # normal fracdiv provisioning (not 10G CPF_MR case)
      autoconfig_fracdiv($mod_line, $slice_line, 0, $line_mode, $line_signal_type, $line_interface, $k,
                         $sysclk_freq, 0, $args{mld_line_enabled}, $is_dual_mux);
    }
}

if (($args{mode} =~ /lb/)) {
    # Loopback so there is only one traffic type
    if ($provision_line) {
        # Line TX  Protection Clock
        ten_print("autoconfig_fracdiv #2\n");
        autoconfig_fracdiv($mod_line, $slice_line, 1, $line_mode, $line_signal_type, $line_interface, $k,
                           $sysclk_freq, $args{mode}, $args{mld_line_enabled}, $is_dual_mux);
    }
}
elsif($args{mode} eq 'mux') {
    if ($provision_client) {
        if ($args{clientrate} == 40) {
            # Dual muxponder
            $prot_signal_type = $args{xcon_client_type};
        }
        else {
            if($client_signal_type =~ /otu/) {
                $prot_signal_type = combine_signal_type_and_fec($args{client},'nofec');
            }
            else { # Non OTN client
                $prot_signal_type = $client_signal_type;
            }
        }
        # Line TX Protection Clock for Client
        ten_print("autoconfig_fracdiv #3\n");
        autoconfig_fracdiv($mod_line, $slice_client, 1, $line_mode, $prot_signal_type, $client_interface, $k,
                           $sysclk_freq, $args{mode}, $args{mld_client_enabled}, $is_dual_mux);
    }
}
elsif(!($args{mode} =~ /kpga/)) {
    # Not KPGA so a protection clock may be needed
    my $protect_client = 0;
    if(($args{mode} eq 'trans10') || ($args{mode} eq 'trans40')) {
        if($client_signal_type =~ /otu/) {
            # OTN Client
            if($args{map_oxuv_enum} == TEN_MAP_BMP) {
                $prot_signal_type = $line_signal_type;
                $protect_client = 0;
            }
            else {
                $protect_client = 1;
                if($args{mode} eq 'trans10') {
                    $prot_signal_type = combine_signal_type_and_fec($args{client},'nofec');
                }
                else { # trans40
                    if($args{xcon_client_type} eq 'invalid') {
                        $prot_signal_type = combine_signal_type_and_fec($args{client},'nofec');
                    }
                    else {
                        $prot_signal_type = $args{xcon_client_type};
                    }
                }
            }
        }
        else {
            # Non OTN client
            if($args{map_oxuv_enum} == TEN_MAP_BMP) {
                $prot_signal_type = $line_signal_type;
                $protect_client = 0;
            }
            else {
                $prot_signal_type = $client_signal_type;
                $protect_client = 1;
            }
        }
    }
    elsif(($args{mode} eq 'wire10') || ($args{mode} eq 'wire40')) {
#    elsif($args{mode} =~ /wire/) {
       $prot_signal_type = $client_signal_type;
       $protect_client = 0;
    }
    
    if (($provision_line && ($protect_client == 0)) ||     # Line has changed and Line TX Protection is line rate
        ($provision_client && ($protect_client == 1))) {   # Client has changed and Line TX Protection is client rate
        # Line TX Protection Clock
        ten_print("autoconfig_fracdiv #4\n");
        autoconfig_fracdiv($mod_line, $slice_line, 1, $line_mode, $prot_signal_type, $client_interface, $k,
                           $sysclk_freq, $args{mode}, $args{mld_line_enabled}, $is_dual_mux);

        # Bugzilla 29621 Start
        # Configure TX Protection clock for SyncDsync
        if(($args{mode} eq 'trans40') && ($args{map_odtu_enum} != TEN_MAP_BMP)) {
            # Line TX Protection Clock
            ten_print("autoconfig_fracdiv #5\n");
            autoconfig_fracdiv($mod_line, 3, 1, $line_mode, $prot_signal_type, $client_interface, $k,
                               $sysclk_freq, $args{mode}, $args{mld_line_enabled}, $is_dual_mux);
        }
        # Bugzilla 29621 End
    }
}

if ($provision_client) {
    # Provision the client-side fractional divider
    # Client RX Pilot Clock
    ten_print("autoconfig_fracdiv #6\n");
    if (($client_interface eq 'cfp_mr') and ($args{clientrate} == 10)) {
      # 10G CFP_MR fracdiv provisioning
      if (ten_hl_hsif_cfp_get_current_traffic($mod_client, $slice_client) != $cfp_mr_10g_client_traffic) {
        if (($slice_client == 0) or ($slice_client == 1)) {
          # configure 0/1 pair
      
                             
          autoconfig_fracdiv($mod_client, 1, 0, $client_mode, $client_signal_type, $client_interface, $k,
                             $sysclk_freq, 0, $args{mld_client_enabled}, $is_dual_mux);
        }
        else {  # configure 2/3 pair
      
                             
          autoconfig_fracdiv($mod_client, 3, 0, $client_mode, $client_signal_type, $client_interface, $k,
                             $sysclk_freq, 0, $args{mld_client_enabled}, $is_dual_mux);
        }
      }
    }
    else {
      # normal fracdiv provisioning (not 10G CPF_MR case)
      autoconfig_fracdiv($mod_client, $slice_client, 0, $client_mode, $client_signal_type, $client_interface, $k,
                         $sysclk_freq, 0, $args{mld_client_enabled}, $is_dual_mux);
    }
    # Client TX Protection Clock
    if(!($args{mode} =~ /kpga/)) {
        if(($args{mode} eq 'trans10') || ($args{mode} eq 'trans40')) {
            if($client_signal_type =~ /otu/) {
                if($args{map_oxuv_enum} == TEN_MAP_BMP) {
                    $prot_signal_type = $client_signal_type;
                }
                else {
                    if($args{mode} eq 'trans10') {
                        $prot_signal_type = combine_signal_type_and_fec($args{client},'nofec');
                    }
                    else { # trans40
                        if($args{xcon_client_type} eq 'invalid') {
                            $prot_signal_type = combine_signal_type_and_fec($args{client},'nofec');
                        }
                        else {
                            $prot_signal_type = $args{xcon_client_type};
                        }
                    }
                }
            }
            else {
                $prot_signal_type = $client_signal_type;
            }
        }
        elsif($args{mode} eq 'mux') {
            if ($args{clientrate} == 40) {
                $prot_signal_type = $args{xcon_client_type};
            }
            else {
                $prot_signal_type = $client_signal_type;
            }
        }
        elsif($args{mode} =~ /wire/) {
           $prot_signal_type = $client_signal_type;
        }
        elsif($args{mode} =~ /lb/) {
           $prot_signal_type = $client_signal_type;
        }

        # Client TX Protection Clock
        ten_print("autoconfig_fracdiv #7\n");
        autoconfig_fracdiv($mod_client, $slice_client, 1, $client_mode, $prot_signal_type, $client_interface, $k,
                           $sysclk_freq, $args{mode}, $args{mld_client_enabled}, $is_dual_mux);

        # Bugzilla 29621 Start
        # Configure TX Protection clock for SyncDsync
        if(($args{mode} eq 'trans40') && ($args{map_oxuv_enum} != TEN_MAP_BMP) && ($args{client} =~ /otu3/)) {
          ten_print("autoconfig_fracdiv #8\n");
          autoconfig_fracdiv($mod_client, 3, 1, $client_mode, $prot_signal_type, $client_interface, $k,
                               $sysclk_freq, 0, $args{mld_client_enabled}, $is_dual_mux);
        }
        # Bugzilla 29621 End
    }
}

# Bugzilla 30823 End
###############################################################################
#   Provision Silab and cleanup PLLs
###############################################################################
# Sequence:
# 1. Divide line rates by 4 if 40G
# 2. If any CUPLL specified then check CUPLL Profile - Silabs will need a refclk f from there
# 3. Configure Silabs
# 4. If line CUPLL specified then populate control block and call hl
# 5. If this is intial config and CUPLL Calibration specified then provision Calibration block (once!)
# 6. If line CUPLL specified and Calibration specified then turn on Calibration for slice_line
# 7. If client CUPLL specified then populate control block and call hl
# 8. If client CUPLL specified and Calibration specified then turn on Calibration for slice_client

my $line_cupll   = ($args{line_cupll_profile} ne 'none');
my $client_cupll = ($args{client_cupll_profile} ne 'none');
my $line_cupllProfileStr;
my $client_cupllProfileStr;
my $use_cupll_calibration = 1;
my $cupll_line_rate;
my $cupll_client_rate;
my $slice_line_cupll   = $args{line_cupll}   & 3; # line_cupll, client_cupll don't
my $slice_client_cupll = $args{client_cupll} & 3; #  have to match slice numbers

if ( ($line_cupll) or ($client_cupll) ) {
  my $_rc; my $_rs;
  ($_rc, $_rs) = validate_cleanup_pll_args (%args);
  die $_rs unless $_rc;
}

# Bugzilla #36263 - mpif reset for all hsif interface, XFI toggle needs to be performed only once *before*
# CUPLL and XFI.  This helps with dynamic reprovisioning because XFI/MR registers are set back to default 
# before programming.
if ($args{dyn_repro} != TEN_REPRO_CLIENT) {
  if ($args{hsif_line} eq 'xfi') {
    ten_mpif_global_reset_sds_xfi_mpif($dev_id, $slice_line, CS_RESET_TOGGLE);
  }
}

if ($args{hsif_client} eq 'xfi') {
  ten_mpif_global_reset_sds_xfi_mpif($dev_id, $slice_client, CS_RESET_TOGGLE);
}

if ($line_cupll) {
  $cupll_line_rate = ($args{linerate} == 40) ? $line_rate/4 : $line_rate;
  $line_cupllProfileStr = get_clocking_profile($args{line_cupll_profile}, $args{line_cupll_profile}, $k,
                                               "./cupll_profiles_calc.txt", \%line_cupllProfileCB);
  die $line_cupllProfileStr if ($line_cupllProfileStr =~ /^ERROR, get_clocking_profile/);
  # print ("*"x45 . "\n");
}
if ($client_cupll) {
  $cupll_client_rate = ($args{clientrate} == 40) ? $client_rate/4 : $client_rate;
  $client_cupllProfileStr = get_clocking_profile($args{client_cupll_profile}, $args{client_cupll_profile}, $k,
                                                 "./cupll_profiles_calc.txt", \%client_cupllProfileCB);
  die $client_cupllProfileStr if ($client_cupllProfileStr =~ /^ERROR, get_clocking_profile/);
  # print ("*"x45 . "\n");
}

#   Provision Silab. Call get_clocking_profile() first, in case cleanup PLLs are being config'd.
#    If so, Silabs needs CUPLL System Clock freq.
if ($args{client} ne 'null') {

    ### if (0) { # for testing purposes, for protection switching for SFI 5.1 and 4.2
    ###   if (config_silab($dev_id, 1, $slice_line, $tmp_mod_client, $slice_client, $args{line}, $args{client},
    ###               $line_interface, $client_interface, $k, $line_mode, $client_mode, $args{sync},
    ###               $args{dyn_repro}, $args{mode}, $args{line_fec}, $args{client_fec}, $line_cupll, $client_cupll,
    ###               $args{map_oxuv_enum}, $args{map_odtu_enum}) == -1) {  # Bugzilla 2006
    ###     return 1;
    ###  }
    ###}

    # Support CFP MRA with MRB protection switching
    my $tmp_mod_client = $mod_num_client;  # Bugzilla 30856
    my $tmp_mod_line = $mod_num_line;      # Bugzilla 30856

    if (($args{hsif_client} eq 'cfp_mr') and ($args{client_port} < 4)) {
      $tmp_mod_client = TEN_MODULE_B;
    }
    if (($args{hsif_line} eq 'cfp_mr') and ($args{line_port} < 4)) {
      $tmp_mod_line = TEN_MODULE_B;
    }

    # do not configure silabs in warm start mode (to avoid traffic hits)
    if (!ten_dev_is_ws_in_progress($dev_id)) {
    
       # special case handling for CFP_MR 10G modes 
       if ( (($args{hsif_client} eq 'cfp_mr') and ($args{clientrate} == 10)) or 
            (($args{hsif_line} eq 'cfp_mr') and ($args{linerate} == 10)) ) {
          my $tmp_slice_line_silabs = $slice_line;
          my $tmp_slice_client_silabs = $slice_client;
          my $tmp_cfp_mr_10g_trans_line_type = $args{line};
          my $tmp_cfp_mr_10g_trans_client_type = $args{client};
          
          if ($args{hsif_line} eq 'cfp_mr') {
            if (($slice_line == 0) or ($slice_line == 1)) {
              $tmp_slice_line_silabs = 2; #1
            }
            else {
              $tmp_slice_line_silabs = 2; #3
            }
          }
            
          if ($args{hsif_client} eq 'cfp_mr') {
            if (($slice_client == 0) or ($slice_client == 1)) {
              $tmp_slice_client_silabs = 2; #1;
            }
            else {
              $tmp_slice_client_silabs = 2; #3;
            }
          }

          if ($args{hsif_line} eq 'cfp_mr') {
            if (ten_hl_hsif_cfp_get_current_traffic($mod_line, $slice_line) == $cfp_mr_10g_line_traffic) {
              $tmp_cfp_mr_10g_trans_line_type = 'invalid';
            }
            
            # CEB (Customer Evaluation Board) can only have 1 traffic type across all 4 ports
            # so if any pair (0-1 or 2-3) is already up, then don't initialize silabs again.
            # This is mainly to demonstrate hitless dynamic reconfig on all 4 ports on the CEB Board
            if (t40fpga_get_board_type($FPGA_SYS_ID) == 8) {
              if (($slice_line == 0) or ($slice_line == 1)) {
                if (ten_hl_hsif_cfp_get_current_traffic($mod_line, 2) == $cfp_mr_10g_line_traffic) {
                  $tmp_cfp_mr_10g_trans_line_type = 'invalid';
                }
              }
              if (($slice_line == 2) or ($slice_line == 3)) {
                if (ten_hl_hsif_cfp_get_current_traffic($mod_line, 0) == $cfp_mr_10g_line_traffic) {
                  $tmp_cfp_mr_10g_trans_line_type = 'invalid';
                }
              }
            }
          }
          
          if ($args{hsif_client} eq 'cfp_mr') {
            if (ten_hl_hsif_cfp_get_current_traffic($mod_client, $slice_client) == $cfp_mr_10g_client_traffic) {
              $tmp_cfp_mr_10g_trans_client_type = 'invalid';
            }
            
            # CEB (Customer Evaluation Board) can only have 1 traffic type across all 4 ports
            # so if any pair (0-1 or 2-3) is already up, then don't initialize silabs again.
            # This is mainly to demonstrate hitless dynamic reconfig on all 4 ports on the CEB Board
            if (t40fpga_get_board_type($FPGA_SYS_ID) == 8) {
              if (($slice_client == 0) or ($slice_client == 1)) {
                if (ten_hl_hsif_cfp_get_current_traffic($mod_client, 2) == $cfp_mr_10g_client_traffic) {
                  $tmp_cfp_mr_10g_trans_client_type = 'invalid';
                }
              }
              if (($slice_client == 2) or ($slice_client == 3)) {
                if (ten_hl_hsif_cfp_get_current_traffic($mod_client, 0) == $cfp_mr_10g_client_traffic) {
                  $tmp_cfp_mr_10g_trans_client_type = 'invalid';
                }
              }
            }
          }
          
          if (config_silab($dev_id, $tmp_mod_line, $tmp_slice_line_silabs, $tmp_mod_client, 
                           $tmp_slice_client_silabs, $tmp_cfp_mr_10g_trans_line_type, $tmp_cfp_mr_10g_trans_client_type,
                           $line_interface, $client_interface, $k, $line_mode, $client_mode, $args{sync},
                           $args{dyn_repro}, $args{mode}, $args{line_fec}, $args{client_fec}, $line_cupll, 
                           $client_cupll, $args{map_oxuv_enum}, $args{map_odtu_enum}) == -1) {  # Bugzilla 2006
             return 1;
          }
        }
        else {
          # normal for config_silabs (ie, not 10G CFP_MR transponder modes) 
            if (config_silab($dev_id, $tmp_mod_line, $slice_line, $tmp_mod_client, $slice_client, 
                             $args{line}, $args{client}, $line_interface, $client_interface, $k, 
                             $line_mode, $client_mode, $args{sync}, $args{dyn_repro}, $args{mode}, 
                             $args{line_fec}, $args{client_fec}, $line_cupll, $client_cupll,
                             $args{map_oxuv_enum}, $args{map_odtu_enum}) == -1) {  # Bugzilla 2006
               return 1;
          }
        }
      }
}

### rob removed for t41ceb mux
# Bugzilla 31661 Start
# if ($args{t100} == 1) {
#     # Configure REFCLK so that clock comming in from T100 board is routed to the T41 TX
#     if (t40fpga_crosspoint (432, 0, 1, 3) == CS_ERROR) {
#         print("Call to t40fpga_crosspoint() FAILED!!!!\n");
#         return 1;
#     }
#
#     ## Set REFCLK B Lane 0 Sel in MSA_REFCLK_CTLR
#     #my $msa_refclk_ctrl = t40fpga_read_reg (432, 0x4400);
#     #$msa_refclk_ctrl |= 0x100;
#     #t40fpga_write_reg (432, 0x4400, $msa_refclk_ctrl);
# }
# Bugzilla 31661 End

#  Provision Cleanup PLLs. Call config_silab first to establish stable CUPLL System Clock.
if ($line_cupll) {
  my $p = \%line_cupllProfileCB;     # shorthand alias
  # Bugzilla 35199 Start 
  if (($args{line} eq '4gfc') || ($args{line} eq '2gfc') || ($args{line} eq '2gisc') ||
      # Bugzilla 26608 Start
      ($args{line} eq '4gfc_enh') || ($args{line} eq '2gfc_enh') ||
      ($args{line} eq '4gfc_ra') || ($args{line} eq '2gfc_ra') ||
      ($args{line} eq '1gfc') || ($args{line} eq '1ge') || # Bug 38871
      # Bugzilla 26608 End
      ($args{line} eq 'cpri_4')) { # Bug 39690
    my $subrate_div;
    # Bugzilla 26608 Start
    if (($args{line} eq '4gfc') || ($args{line} eq '4gfc_enh') || ($args{line} eq '4gfc_ra')) {
    # Bugzilla 26608 End
      # Half rate refclk divider
      $subrate_div = 1;
    # Bugzilla 26608 Start
    } elsif (($args{line} eq '2gfc') || ($args{line} eq '2gisc') || ($args{line} eq '2gfc_enh') || ($args{line} eq '2gfc_ra') ||
    # Bugzilla 26608 End
             ($args{line} eq 'cpri_4')) { # Bug 39690
      # Quarter rate refclk divider
      $subrate_div = 2;
    } elsif (($args{line} eq '1gfc') || ($args{line} eq '1ge')) { # Bugzilla 38871 End
      # Eigth rate refclk divider
      $subrate_div = 3;
    }
    ten_set_cb_cupll_calc_t41_v2($dev_id, $cupll_line_rate, $p->{txClkSource}, $k,
                      ( ($p->{cupllSysClkFreq} =~ /^0x\w/) ? hex($p->{cupllSysClkFreq}) : $p->{cupllSysClkFreq} ),
                      ( ($p->{pdoffset}        =~ /^0x\w/) ? hex($p->{pdoffset})        : $p->{pdoffset} ),
                      $subrate_div  );
  } else {
    ten_set_cb_cupll_calc_t41($dev_id, $cupll_line_rate, $p->{txClkSource}, $k,
                      ( ($p->{cupllSysClkFreq} =~ /^0x\w/) ? hex($p->{cupllSysClkFreq}) : $p->{cupllSysClkFreq} ),
                      ( ($p->{pdoffset}        =~ /^0x\w/) ? hex($p->{pdoffset})        : $p->{pdoffset} ) );
  }
  # Bugzilla 35199 End 

  ten_hl_cupll_config_t41($mod_line, $slice_line_cupll);

  # CUPLL Calibrate block (PDCAL) should only be provisioned once
  # After that, any channel can use it
  if (($args{dyn_repro} == TEN_INITIAL_CONFIG) && $line_cupll) {
    ten_hl_cupll_calibrate_config_t41($dev_id, $slice_line_cupll);
  }
}

# Calibrate CUPLL if used on line side, uses line CUPLL cb
if ($line_cupll && $use_cupll_calibration) {
  # 0 = Use Calibration, 0x080 = Unused Override value
  ten_xfi_cupll_pdcal_t41($mod_line, $slice_line_cupll, 0, 0x080);
}

if ($client_cupll) {
  my $p = \%client_cupllProfileCB;   # shorthand alias
  # Bugzilla 35199 Start 
  if (($args{client} eq '4gfc') || ($args{client} eq '2gfc') || ($args{client} eq '2gisc') ||
      # Bugzilla 26608 Start
      ($args{client} eq '4gfc_enh') || ($args{client} eq '2gfc_enh') ||
      ($args{client} eq '4gfc_ra') || ($args{client} eq '2gfc_ra') ||
      ($args{client} eq '1gfc') || ($args{client} eq '1ge') || # Bug 38871
      # Bugzilla 26608 End
      ($args{client} eq 'cpri_4')) { # Bug 39690
    my $subrate_div;
    # Bugzilla 26608 Start
    if (($args{client} eq '4gfc') || ($args{client} eq '4gfc_enh') || ($args{client} eq '4gfc_ra')) {
    # Bugzilla 26608 End
      # Half rate refclk divider
      $subrate_div = 1;
    # Bugzilla 26608 Start
    } elsif (($args{client} eq '2gfc') || ($args{client} eq '2gisc') || ($args{client} eq '2gfc_enh') || ($args{client} eq '2gfc_ra') ||
    # Bugzilla 26608 End
             ($args{client} eq 'cpri_4')) { # Bug 39690
      # Quarter rate refclk divider
      $subrate_div = 2;
    } elsif (($args{client} eq '1gfc') || ($args{client} eq '1ge')) { # Bugzilla 38871 End
      # Eigth rate refclk divider
      $subrate_div = 3;
    }
    ten_set_cb_cupll_calc_t41_v2($dev_id, $cupll_client_rate, $p->{txClkSource}, $k,
                      ( ($p->{cupllSysClkFreq} =~ /^0x\w/) ? hex($p->{cupllSysClkFreq}) : $p->{cupllSysClkFreq} ),
                      ( ($p->{pdoffset}        =~ /^0x\w/) ? hex($p->{pdoffset})        : $p->{pdoffset} ),
                      $subrate_div  );
  } else {
    ten_set_cb_cupll_calc_t41($dev_id, $cupll_client_rate, $p->{txClkSource}, $k,
                      ( ($p->{cupllSysClkFreq} =~ /^0x\w/) ? hex($p->{cupllSysClkFreq}) : $p->{cupllSysClkFreq} ),
                      ( ($p->{pdoffset}        =~ /^0x\w/) ? hex($p->{pdoffset})        : $p->{pdoffset} ) );
  }
  # Bugzilla 35199 End 

  ten_hl_cupll_config_t41($mod_client, $slice_client_cupll);

  # CUPLL Calibrate block (PDCAL) should only be provisioned once
  # After that, any channel can use it
  if (($args{dyn_repro} == TEN_INITIAL_CONFIG) && !$line_cupll) {
    ten_hl_cupll_calibrate_config_t41($dev_id, $slice_client_cupll);
  }
}

# Calibrate CUPLL if used on client side, uses client CUPLL cb
if ($client_cupll && $use_cupll_calibration) {
  # 0 = Use Calibration, 0x080 = Unused Override value
  ten_xfi_cupll_pdcal_t41($mod_client, $slice_client_cupll, 0, 0x080);
}

###############################################################################
# Provision Host Interface HSIF
###############################################################################
# The 'default' state isn't good for HSIF, so override it
# Provision Datapath with all ports HSIF disabled (XFI disable and MR disabled)
# tx_xfiselect=0, rx_xfiselect=0, tx_pswtchen=0, tx_mrprotocol=0, rx_pswtchen=0, rx_mrprotocol=0
if ($args{dyn_repro} == TEN_INITIAL_CONFIG) {
    ten_hsif_provision_datapath($mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0);
    ten_hsif_provision_datapath($mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0);
}

if ($provision_line) {
    # Both line and client will change
    if ($args{linerate} == 40) {

        # Support CFP MRA with MRB protection switching
        my $tmp_mod_line = $mod_line;
        if (($args{hsif_line} eq  'cfp_mr') and ($args{line_port} < 4)) {
          $tmp_mod_line = $mod_b;     # Bugzilla 30856
        }
        # Configure the serdes clock to be used for 40G.  All ports on this module will be affected
        ten_hsif_set_clk_40g ($tmp_mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1);
        ten_hsif_set_clk_40g ($tmp_mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1);
    }
}

if ($provision_client) {
    if ($args{clientrate} == 40) {

        # Support CFP MRA with MRB protection switching
        my $tmp_mod_client = $mod_client;
        if (($args{hsif_client} eq 'cfp_mr') and ($args{client_port} < 4)) {
          $tmp_mod_client = $mod_b;     # Bugzilla 30856
        }

        # Configure the serdes clock to be used for 40G.  All ports on this module will be affected
        ten_hsif_set_clk_40g ($tmp_mod_client, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1);
        ten_hsif_set_clk_40g ($tmp_mod_client, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1);
    }
}

###################################
#####       CFP LASER         #####
###################################
if (!ten_dev_is_ws_in_progress($dev_id)) {
  if ($args{dyn_repro} == TEN_INITIAL_CONFIG) {   # Bugzilla 31024
    if (ten_dev_is_t41($dev_id)) {
      if ( (($args{clientrate} == 40) && (($args{hsif_client} eq 'xfi') || ($args{hsif_client} eq  'cfp_mr'))) ||
          (($args{linerate} == 40) && (($args{hsif_line} eq 'xfi') || ($args{hsif_line} eq  'cfp_mr'))) ) {
        # Automatically turn on laser
        # Read 0x6003 (J500/CFP1/XFI) and 0x6007 (J501/CFP2/CFP_MR).
        # Bit 5 will be low if a module is plugged
        # into its respective connector.
        # module ? CFP2_C : CFP1_C

        my $cfp1 = main::dev_reg_read(432, 0, 0x6003);
        printf("\nCFP1 (0x6003) = 0x%04X\n", $cfp1);
        # Enables the laser in the CFP optical module.
        if (($cfp1&0x0020) == 0) {
          # 0x06002
          print("CFP1:  t40fpga_cfp_power:  CFP1_C\n");
          main::t40fpga_cfp_power(432, 0);  # CFP1_C
        }
        else {
          print("CFP1:  not populated\n");
        }

        my $cfp2 = main::dev_reg_read(432, 0, 0x6007);
        printf("\nCFP2 (0x6007) = 0x%04X\n", $cfp2);
        if (($cfp2&0x0020) == 0) {
          # 0x06006
          print("CFP2:  t40fpga_cfp_power:  CFP2_C\n\n");
          main::t40fpga_cfp_power(432, 1);  # CFP2_C;
        }
        else {
          print("CFP2:  not populated\n\n");
        }
      }
    }

    if (main::t40fpga_get_board_type($FPGA_SYS_ID)==8) {
       printf("EVB detected\n\n");

      #dev_reg_write(432,0,0x6c0f,1);
      # cfp over mrb
      dev_reg_write(432,0,0x6c08,1);

      # cfp over xfi
      dev_reg_write(432,0,0x6c00,9);

      #XFP
      #dev_reg_write(432,0,0x6c04,1);

       # override xfi clock distribution to '0' for EVB
       $args{xfi_clock_distribution} = 0;
    }
  }
}

###############################
#####   Provision HSIF    #####
###############################

  my $xfi_dir = 0;
  my $xfi_invert = 0;
  my $tmp_slice_line = 0;
  my $tmp_slice_client = 0;
  my $line_perform_cfp_retune_vco = 0;
  my $client_perform_cfp_retune_vco = 0;
  
  # Set up LINE HSIF CFP_MR pairs: 0-1 or 2-3
  # CFP_MR only has 2 clocks (on port 0 and 2).  
  # Slice 1 needs the clock from slice 0 and slice 3 needs the clock from slice 2
  if ($provision_line) {
    if ( ($args{hsif_line} eq 'cfp_mr') and ($args{linerate} == 10) ) {
      if (($slice_line eq 0) || ($slice_line eq 1)) {
        $tmp_slice_line = 0;
      }
      else {
        $tmp_slice_line = 2;
      }
      
      if ($args{line} ne 'null') {
      
        $line_perform_cfp_retune_vco = (ten_hl_hsif_cfp_get_current_traffic($mod_line, $tmp_slice_line) != $cfp_mr_10g_line_traffic);

        if (provision_hsif($mod_line,
                           $args{hsif_line_enum},
                           $args{linerate},
                           $tmp_slice_line,
                           $args{line_traffic_type_enum},
                           $sysclk_freq,
                           $args{sync},
                           0,
                           $args{eds},
                           $xfi_dir,
                           $xfi_invert,
                           $args{mode_enum},
                           $args{xfi_clock_distribution},
                           $use_xaui_protection_switch_mode,
                           $args{cfp_mrb1_mrb3}, 
                           $k)) {
          failure("HSIF line provisioning failed");
          return 1;
        }
      }
    }
  }
  
  # Set up CLIENT HSIF CFP_MR pairs: 0-1 or 2-3
  # CFP_MR only has 2 clocks (on port 0 and 2).  
  # Slice 1 needs the clock from slice 0 and slice 3 needs the clock from slice 2
  if ($provision_client) {
    if ( ($args{hsif_client} eq 'cfp_mr') and ($args{clientrate} == 10) ) {
      if (($slice_client eq 0) || ($slice_client eq 1)) {
        $tmp_slice_client = 0;
      }
      else {
        $tmp_slice_client = 2;
      }
     
      if ($args{client} ne 'null') {
      
        $client_perform_cfp_retune_vco = (ten_hl_hsif_cfp_get_current_traffic($mod_client, $tmp_slice_client) != $cfp_mr_10g_client_traffic);
        
        if (provision_hsif($mod_client,
                           $args{hsif_client_enum},
                           $args{clientrate},
                           $tmp_slice_client,
                           $args{client_traffic_type_enum},
                           $sysclk_freq,
                           $args{sync},
                           0,
                           $args{eds},
                           $xfi_dir,
                           $xfi_invert,
                           $args{mode_enum},
                           $args{xfi_clock_distribution},
                           $use_xaui_protection_switch_mode,
                           $args{cfp_mrb1_mrb3},
                           $k)) {
          failure("HSIF client provisioning failed");
          return 1;
        }
      }
    }
  }

  ###################################
  #####   Provision HSIF LINE   #####
  ###################################
  if ($provision_line) {
    # Provision Side A line
    # These routines will call failure("Unspecified Reason") if the waitfor_vcotune test fails, so that the
    # test case will end gracefully and the regression run continue

    $xfi_dir = 0;
    $xfi_invert = 0;

    if ($args{hsif_line} eq 'xfi') {
      my $board_type = main::t40fpga_get_board_type($FPGA_SYS_ID);
      printf("t40fpga_get_board_type = %d\n", $board_type);
      if ($slice_line==0 || $slice_line==2) {
        if (($board_type==4) || ($board_type==6)) {
          # T40 XFP Board or T41 XFP Board for T41 driver testing
          # invert the SERDES lane for XFP
          $xfi_dir = main::CS_TX_AND_RX;
          $xfi_invert = 1;
        } else {
          # invert the SERDES lane for SFP+
          $xfi_dir = main::CS_RX;
          $xfi_invert = 1;
        }
      }
      elsif ($slice_line==1 || $slice_line==3) {
        if ($board_type==5) {
          # T40 SFP+ Board
          # invert the SERDES lane for SFP+
          $xfi_dir = main::CS_TX;
          $xfi_invert = 1;
        }
        elsif ($board_type == 9) {
          $xfi_dir = main::CS_RX;
          $xfi_invert = 1;
        }
      }
    }
    if ($args{line} ne 'null') {
    
      if ( ($args{hsif_line} eq 'cfp_mr') and ($args{linerate} == 10) ) {
        if (($slice_line eq 0) || ($slice_line eq 1)) {
          $tmp_slice_line = 1;
        }
        else {
          $tmp_slice_line = 3;
        }
      }  
      else {
        $tmp_slice_line = $slice_line;
      }
    
      if (provision_hsif($mod_line,
                         $args{hsif_line_enum},
                         $args{linerate},
                         $tmp_slice_line,
                         $args{line_traffic_type_enum},
                         $sysclk_freq,
                         $args{sync},
                         $args{auxclk},
                         $args{eds},
                         $xfi_dir,
                         $xfi_invert,
                         $args{mode_enum},
                         $args{xfi_clock_distribution},
                         $use_xaui_protection_switch_mode,
                         $args{cfp_mrb1_mrb3},
                         $k)) {
        failure("HSIF line provisioning failed");
        return 1;
      }
    }
  }

  $xfi_dir = 0;
  $xfi_invert = 0;

  #####################################
  #####   Provision HSIF CLIENT   #####
  #####################################
if ($provision_client) {
    if (($args{hsif_client} eq 'xfi') and ($args{client} ne 'null')) {
    if ($slice_client==0 || $slice_client==2) {
        if ((main::t40fpga_get_board_type($FPGA_SYS_ID)==4) || (main::t40fpga_get_board_type($FPGA_SYS_ID)==6)) {
          printf("T40 XFP Board or T41 XFP Board for T41 driver testing");
          # invert the SERDES lane for XFP
          $xfi_dir = main::CS_TX_AND_RX;
          $xfi_invert = 1;
        } else {
          # invert the SERDES lane for SFP+
          $xfi_dir = main::CS_RX;
          $xfi_invert = 1;
        }
      }
    elsif ($slice_client==1 || $slice_client==3) {
        if (main::t40fpga_get_board_type($FPGA_SYS_ID)==5) {
          printf("T40 SFP+ Board\n");
          # invert the SERDES lane for SFP+
          $xfi_dir = main::CS_TX;
          $xfi_invert = 1;
        }
      }
    }
    if ($args{client} ne 'null') {
    
      if (($args{hsif_client} eq 'cfp_mr') and ($args{clientrate} == 10)) {
        if (($slice_client eq 0) || ($slice_client eq 1)) {
          $tmp_slice_client = 1;
        }
        else {
          $tmp_slice_client = 3;
        }
      }
      else {
        $tmp_slice_client = $slice_client;
      }
    
      if (provision_hsif($mod_client,
                         $args{hsif_client_enum},
                         $args{clientrate},
                         $tmp_slice_client,
                         $args{client_traffic_type_enum},
                         $sysclk_freq,
                         $args{sync},
                         $args{auxclk},
                         $args{eds},
                         $xfi_dir,
                         $xfi_invert,
                         $args{mode_enum},
                         $args{xfi_clock_distribution},
                         $use_xaui_protection_switch_mode,
                         $args{cfp_mrb1_mrb3},
                         $k)) {
        failure("HSIF client provisioning failed");
        return 1;
      }
    }
  }
  
if ($client_perform_cfp_retune_vco) {
    ten_hl_hsif_cfp_retune_vco($mod_client, $slice_client);
}

if ($line_perform_cfp_retune_vco) {
    ten_hl_hsif_cfp_retune_vco($mod_line, $slice_line);
}

## Bugzilla 31661 Start
#if ($args{t100} == 1) {
#    if ($provision_line) {
#        # TX clock provided by T100 is 1/4 of clock comming from Silabs so divide ref clock to serdes by 1 instead of 4.
#        if (($mod_line == $mod_a) && ($args{hsif_line_enum} == TEN_HSIF_PROTOCOL_CFP)) {
#            # HSIF for side A is CFP MR on side B
#            ten_hsif_set_refclk_cfg ($mod_b, TEN_HSIF_REFCLK_CFG_CKREFDIV, 0);
#        } else {
#            ten_hsif_set_refclk_cfg ($mod_line, TEN_HSIF_REFCLK_CFG_CKREFDIV, 0);
#        }
#    }
#}
## Bugzilla 31661 End

###############################################################################
#   Provision Syncdsync
###############################################################################
my $num_just_oxu2=0; my $num_pjo_oxu2=0; my $num_just_oxu3=0; my $num_pjo_oxu3=0;
my $num_just_oxu3_client=0; my $num_pjo_oxu3_client=0;
my $PLvalue=1, my $QLvalue=1, my $PCvalue=1, my $QCvalue=1, my $line_client_rate_equal=0, my $line_client_same=0;
my $trans_num; my $trans_den;
my $num_fs1 = 0;
my $num_fs2 = 0;

if ($args{client} ne 'null') {
    if (($args{mode} eq 'mux') || ($args{mode} eq 'trans10') || ($args{mode} eq 'trans40') ||
        ($args{mode} eq 'wire10') || ($args{mode} eq 'wire40')) {
        if($args{client} eq '10ge_tc') {
            $client_sub_type = $args{client}.'_'.$args{gfp_frame_format};
            ($num_just_oxu2, $num_pjo_oxu2, $num_just_oxu3, $num_pjo_oxu3, $num_fs1, $num_fs2) =
                get_syncdsync_params($args{line}, $client_sub_type, $args{mode}, $args{sync}, $args{xcon_client_type},
                                     $args{pre_line}, $args{pre_client}, $args{map_oxuv_enum}, $args{map_odtu_enum},  $args{ra_10ge_odu2e_mode});  # Bugzilla 28006
        }
        else {
            ($num_just_oxu2, $num_pjo_oxu2, $num_just_oxu3, $num_pjo_oxu3, $num_just_oxu3_client, $num_pjo_oxu3_client, $num_fs1, $num_fs2) =
            get_syncdsync_params($args{line}, $args{client}, $args{mode}, $args{sync}, $args{xcon_client_type},
                                 $args{pre_line}, $args{pre_client}, $args{map_oxuv_enum}, $args{map_odtu_enum},  $args{ra_10ge_odu2e_mode}); # Bugzilla 28006
        }

        ($PLvalue, $QLvalue, $PCvalue, $QCvalue, $line_client_same, $line_client_rate_equal) =
            get_line_client_params($args{line}, $args{client}, $args{line_fec}, $args{client_fec}, $args{mode}, $args{sync}, $args{xcon_client_type}); # Bugzilla 27167
    }
    elsif (($args{mode} eq 'lb10') || ($args{mode} eq 'lb40')) {
        ($num_just_oxu2, $num_pjo_oxu2, $num_just_oxu3, $num_pjo_oxu3) =
        get_syncdsync_params($args{lb_kpga}, $args{lb_kpga}, $args{mode}, $args{sync}, $args{xcon_client_type},
                             $args{pre_line}, $args{pre_client}, $args{map_oxuv_enum}, $args{map_odtu_enum},  $args{ra_10ge_odu2e_mode});  # Bugzilla 28006

        ($PLvalue, $QLvalue, $PCvalue, $QCvalue, $line_client_same, $line_client_rate_equal) =
            get_line_client_params($args{lb_kpga}, $args{lb_kpga}, $args{lb_kpga_fec}, $args{lb_kpga_fec}, $args{mode}, $args{sync}, $args{xcon_client_type}); # Bugzilla 27167
    }

    print("P Client = $PCvalue\n");
    print("Q Client = $QCvalue\n");
    print("P Line   = $PLvalue\n");
    print("Q Line   = $QLvalue\n");
    print("args{sync} = $args{sync}\n");
    print("args{mode_enum} = $args{mode_enum}\n");
    print("num_just_oxu2 = $num_just_oxu2, num_pjo_oxu2 = $num_pjo_oxu2\n");
    print("num_just_oxu3 = $num_just_oxu3, num_pjo_oxu3 = $num_pjo_oxu3\n");
    print("num_just_oxu3_client = $num_just_oxu3_client, num_pjo_oxu3_client = $num_pjo_oxu3_client\n");
#    print("num_fs1 = $num_fs1, num_fs2 = $num_fs2\n");

    if ($method == TEN_1TO1_ASYNC_2LEVEL) {
        print ("method = TEN_1TO1_ASYNC_2LEVEL ($method)\n");
    }
    elsif ($method == TEN_SYNC_ASYNC_1LEVEL) {
        print ("method = TEN_SYNC_ASYNC_1LEVEL ($method)\n");
    }
    elsif ($method == TEN_1TO1_ASYNC_1LEVEL) {
        print ("method = TEN_1TO1_ASYNC_1LEVEL ($method)\n");
    }
    elsif ($method == TEN_BOTH_1TO1) {
        print ("method = TEN_BOTH_1TO1 ($method)\n");
    }
    elsif ($method == TEN_ASYNC_ASYNC_1LEVEL) {
        print ("method = TEN_ASYNC_ASYNC_1LEVEL ($method)\n");
    }
    elsif ($method == TEN_1TO1_ASYNC_1TO1_1LEVEL) {
        print ("method = TEN_1TO1_ASYNC_1TO1_1LEVEL ($method)\n");
    }
    elsif ($method == TEN_ASYNC_ASYNCX4_1LEVEL) {
        print ("method = TEN_ASYNC_ASYNCX4_1LEVEL ($method)\n");
    } else {
        print("method = $method\n");
    }

    if (($args{mode} eq 'trans40') || ($args{mode} eq 'wire40')) {
      if ($args{pre_line} eq '40gex')  {
          # 40GE Client will be transcoded
          ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 1056, 1027);
      } else {
          ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 1, 1); # num, denom
      }

      if (!ten_dev_is_t41($dev_id)) {
          #ten_syncdsync_set_cb_40g_transponder($dev_id,
          #                                     $num_just_oxu3, $num_pjo_oxu3,
          #                                     $PLvalue, $QLvalue, $PCvalue, $QCvalue,
          #                                     $line_client_same,
          #                                     $line_client_rate_equal);
          ten_syncdsync_thread_set_cb_40g_transponder($dev_id, 0,
                                               $num_just_oxu3, $num_pjo_oxu3,
                                               $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                               $line_client_same,
                                               $line_client_rate_equal);
      }
      else {
              # Bugzilla 28006 Start
              if (($args{map_oxuv_enum} != TEN_MAP_BMP) && ($args{map_odtu_enum} != TEN_MAP_DONT_CARE) && ($args{map_odtu_enum} != TEN_MAP_BMP)) {
ten_print("### ten_syncdsync_set_cb_40g_transponder_dual_async_t41($dev_id, $slice_client, $num_just_oxu3, $num_pjo_oxu3, $num_just_oxu3_client, $num_pjo_oxu3_client, $PLvalue, $QLvalue, $PCvalue, $QCvalue, $client_rate, $xcon_client_rate, $line_rate)");
                  ten_syncdsync_set_cb_40g_transponder_dual_async_t41($dev_id, $slice_client,
                                                                $num_just_oxu3, $num_pjo_oxu3,
                                                                $num_just_oxu3_client, $num_pjo_oxu3_client,
                                                                $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                                                $client_rate, $xcon_client_rate, $line_rate);


              } else {
              # Bugzilla 28006 End
ten_print("### ten_syncdsync_set_cb_40g_transponder_t41($dev_id, $slice_client, $num_just_oxu3, $num_pjo_oxu3, $PLvalue, $QLvalue, $PCvalue, $QCvalue, $client_rate, $xcon_client_rate, $line_rate, $line_client_same, $line_client_rate_equal)");
                  ten_syncdsync_set_cb_40g_transponder_t41($dev_id, $slice_client,
                                                           $num_just_oxu3, $num_pjo_oxu3,
                                                           $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                                           $client_rate, $xcon_client_rate, $line_rate,
                                                           $line_client_same,
                                                           $line_client_rate_equal);
              }
       }
    }
    elsif ($args{mode} eq 'mux') {
        if($args{client} =~ /10gfc_tc/) { # Bug 31054
            #ten_syncdsync_set_cb_transcode($dev_id, 51, 50);
            ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 51, 50); # 250/238 = 255/238 * 50/51
        }
        elsif ($args{hsif_client} eq 'xaui') {
            #ten_syncdsync_set_cb_transcode($dev_id, 64, 66);
            ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 64, 66);
        }
        else {
            #ten_syncdsync_set_cb_transcode($dev_id, 1, 1);
            ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 1, 1); # num, denom
        }

        if (!ten_dev_is_t41($dev_id)) {
            #ten_syncdsync_set_cb_40g_muxponder($dev_id,
            #                                   $num_just_oxu2, $num_pjo_oxu2,
            #                                   $num_just_oxu3, $num_pjo_oxu3,
            #                                   $PLvalue, $QLvalue, $PCvalue, $QCvalue);
            ten_syncdsync_thread_set_cb_40g_muxponder($dev_id, $slice_client,
                                                       $num_just_oxu2, $num_pjo_oxu2,
                                                       $num_just_oxu3, $num_pjo_oxu3,
                                                       $PLvalue, $QLvalue, $PCvalue, $QCvalue);
        }
        else {

# Bug 39217 8gfc/oduflex/odu2/odtu must have 2 PJO's to accomodate +-100ppm
if (($args{oduflex_enbl} == 1) && ($args{client} eq '8gfc')) {
  $num_pjo_oxu3 = 2;
}  

ten_print("$dev_id)");
ten_print("$slice_client)");
ten_print("$num_just_oxu2)");
ten_print("$num_pjo_oxu2,  ");
ten_print("$num_just_oxu3, ");
ten_print("$num_pjo_oxu3,  ");
ten_print("$PLvalue,       ");
ten_print("$QLvalue,       ");
ten_print("$PCvalue,       ");
ten_print("$QCvalue,       ");
ten_print("$client_rate,   ");
ten_print("$xcon_client_rate,");
ten_print("$line_rate)");


#ten_print("### ten_syncdsync_set_cb_40g_muxponder_t41($dev_id, $slice_client, $num_just_oxu2, $num_pjo_oxu2, $num_just_oxu3, $num_pjo_oxu3, $PLvalue, $QLvalue, $PCvalue, $QCvalue, $client_rate, $xcon_client_rate, $line_rate)");
ten_print("### ten_syncdsync_set_cb_40g_muxponder_t41($dev_id, $slice_client, $num_just_oxu2, $num_pjo_oxu2, $num_just_oxu3, $num_pjo_oxu3, $PLvalue, $QLvalue, $PCvalue, $QCvalue, $client_rate, $mux_odu2v_rate, $line_rate)");
                ten_syncdsync_set_cb_40g_muxponder_t41($dev_id, $slice_client,
                                                       $num_just_oxu2, $num_pjo_oxu2,
                                                       $num_just_oxu3, $num_pjo_oxu3,
                                                       $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                                       #$client_rate, $xcon_client_rate, $line_rate);
                                                       $client_rate, $mux_odu2v_rate, $line_rate);
        }
    }
    elsif (($args{mode} eq 'trans10') || ($args{mode} eq 'wire10')) {
        if($args{client} =~ /10gfc_tc/) { # Bug 31054
            #ten_syncdsync_set_cb_transcode($dev_id, 51, 50);
            ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 51, 50);
        }
        elsif (($args{hsif_client} eq 'xaui') && $args{sync} == 1) {
            #ten_syncdsync_set_cb_transcode($dev_id, 64, 66);
            ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 64, 66);
        }
        elsif ($args{client} eq '10ge_tc') {
            if($client_sub_type eq '10ge_tc_28blk_5sblk') {
                #ten_syncdsync_set_cb_transcode($dev_id, 2310, 2249);
                ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 2310, 2249);
            }
            elsif ($client_sub_type eq '10ge_tc_28blk_11sblk') {
                #ten_syncdsync_set_cb_transcode($dev_id, 5082, 4943);
                ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 5082, 4943);
            }
            elsif ($client_sub_type eq '10ge_tc_32blk_4sblk') {
                #ten_syncdsync_set_cb_transcode($dev_id, 264, 257);
                ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 264, 257);
            }
            elsif ($client_sub_type eq '10ge_tc_32blk_8sblk') {
                #ten_syncdsync_set_cb_transcode($dev_id, 1056, 1027);
                ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 1056, 1027);
            }
        }
        else {
            #ten_syncdsync_set_cb_transcode($dev_id, 1, 1);
            ten_syncdsync_thread_set_cb_transcode($dev_id, $slice_client, 1, 1);  # num, denom
        }

        if (!ten_dev_is_t41($dev_id)) {
            #ten_syncdsync_set_cb_10g_transponder($dev_id,
            #                                     $num_just_oxu2, $num_pjo_oxu2,
            #                                     $PLvalue, $QLvalue, $PCvalue, $QCvalue,
            #                                     $line_client_same,
            #                                     $line_client_rate_equal);
            ten_syncdsync_thread_set_cb_10g_transponder($dev_id, $slice_client,
                                                        $num_just_oxu2, $num_pjo_oxu2,
                                                        $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                                        $line_client_same,
                                                        $line_client_rate_equal);
        }
        else {
            ten_print("### ten_syncdsync_set_cb_10g_transponder_t41($dev_id, $slice_client, $num_just_oxu2, $num_pjo_oxu2, $PLvalue, $QLvalue, $PCvalue, $QCvalue, $line_client_same, $line_client_rate_equal, $args{oduflex_enbl}, $args{oduflex_line_port}, $args{oduflex_line_port}, $client_rate, $xcon_client_rate, $line_rate)");
            ten_syncdsync_set_cb_10g_transponder_t41($dev_id, $slice_client,
                                                     $num_just_oxu2, $num_pjo_oxu2,
                                                     $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                                     $line_client_same,
                                                     $line_client_rate_equal,
                                                     $args{oduflex_enbl},
                                                     $args{oduflex_line_port}, $args{oduflex_line_port},
                                                     $client_rate, $xcon_client_rate, $line_rate);
        }
    }
    elsif ($args{mode} eq 'lb10') {
        ten_syncdsync_thread_set_cb_transcode($dev_id, $args{slice_lb_kpga}, 1, 1);  # num, denom
        ten_syncdsync_thread_set_cb_10g_transponder($dev_id, $args{slice_lb_kpga},
                                                    $num_just_oxu2, $num_pjo_oxu2,
                                                    $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                                    $line_client_same,
                                                    $line_client_rate_equal);
    }
    elsif ($args{mode} eq 'lb40') {
        ten_syncdsync_thread_set_cb_transcode($dev_id, $args{slice_lb_kpga}, 1, 1);  # num, denom
        ten_syncdsync_thread_set_cb_40g_transponder($dev_id, 0,
                                                    $num_just_oxu3, $num_pjo_oxu3,
                                                    $PLvalue, $QLvalue, $PCvalue, $QCvalue,
                                                    $line_client_same,
                                                    $line_client_rate_equal);
    }

    if (($args{mode} eq 'mux') || ($args{mode} eq 'trans10') || ($args{mode} eq 'trans40') ||
        ($args{mode} eq 'wire10') || ($args{mode} eq 'wire40') ||
        ($args{mode} eq 'kpga10') || ($args{mode} eq 'kpga40') ||
        ($args{mode} eq 'cbr_kpga10') || ($args{mode} eq 'cbr_kpga40') || ($args{mode} eq 'pbert10')) {

        if(0) {
            $trans_num = 1; $trans_den = 1;
            ten_hl_config_syncdsync($mod_line, $slice, $mod_client, $slice_client,
                                    $args{line}, $args{client},
                                    $line_interface, $client_interface,
                                    $k, $args{mode}, $args{sync},
                                    $args{line_fec}, $args{client_fec}, #$aggregation,
                                    $num_just_oxu2, $num_pjo_oxu2, $num_just_oxu3, $num_pjo_oxu3,
                                    $PLvalue, $QLvalue, $PCvalue, $QCvalue, $line_client_rate_equal,
                                    $trans_num, $trans_den);
        }
        else {
            #if ((!ten_dev_is_t41($dev_id)) || ($args{mode} eq 'wire10')) {
            if (!ten_dev_is_t41($dev_id)) {
                #if (ten_hl_syncdsync_datapath_config($mod_line, $slice, $mod_client, $slice_client,
                #                                     $args{mode_enum},
                #                                     $args{sync},
                #                                     $method,
                #                                     $k,
                #                                     $args{line_fec_enum}, $args{client_fec_enum})) {
                #    failure("ten_hl_syncdsync_datapath_config() failed\n");
                #    return 1;
                #}

                if(ten_hl_syncdsync_threadsafe_datapath_config($mod_line, $slice, $mod_client, $slice_client,
                                                               $args{mode_enum},
                                                               $args{sync},
                                                               $method,
                                                               $k,
                                                               $args{line_fec_enum}, $args{client_fec_enum})) {
                    failure("ten_hl_syncdsync_threadsafe_datapath_config() failed\n");
                    return 1;
                }
            }
            else {
                if ((($args{line} ne '2gfc') and ($args{client} eq '2gfc')) || # Bug 38779
                    ($args{client} eq '2gisc') || # Bug 38779
                    # Bugzilla 26608 Start
                    (($args{line} =~ /otu2/)  and ($args{client} eq '2gfc_enh')) ||
                    (($args{line} eq 'otu2')  and ($args{client} eq '2gfc_ra')) ||
                    (($args{line} ne 'cpri_4') and ($args{client} eq 'cpri_4'))) { # Bug 39690
                    # Bugzilla 26608 End
                    # 2G data rates require k/4 on the line side to maintain an 8.3MHz TXDiv
                    my $k_client = $k;
                    my $k_line = $k/4;
                    if(ten_hl_syncdsync_datapath_config_t41_v2($mod_line, $slice, $mod_client, $slice_client,
                                                               $args{line_fec_enum}, $args{client_fec_enum},
                                                               $args{mode_enum},
                                                               $method,
                                                               $k_line, $k_client,
                                                               $args{map_odtu_enum},
                                                               $args{map_oxuv_enum},
                                                               $args{timeslots})) {
                        failure("ten_hl_syncdsync_datapath_config_t41_v2() failed\n");
                        return 1; die;
                    }
                }
                elsif ((($args{line} ne '4gfc') and ($args{client} eq '4gfc')) || # Bug 38779
                       # Bugzilla 26608 Start
                       (($args{line} =~ /otu2/)  and ($args{client} eq '4gfc_enh')) ||
                        (($args{line} eq 'otu2')  and ($args{client} eq '4gfc_ra')) ) {
                       # Bugzilla 26608 End
                    # 4G data rates require k/2 on the line side to maintain an 8.3MHz TXDiv
                    my $k_client = $k;
                    my $k_line = $k/2;
                    if(ten_hl_syncdsync_datapath_config_t41_v2($mod_line, $slice, $mod_client, $slice_client,
                                                               $args{line_fec_enum}, $args{client_fec_enum},
                                                               $args{mode_enum},
                                                               $method,
                                                               $k_line, $k_client,
                                                               $args{map_odtu_enum},
                                                               $args{map_oxuv_enum},
                                                               $args{timeslots})) {
                        failure("ten_hl_syncdsync_datapath_config_t41_v2() failed\n");
                        return 1;
                    }
                }
                elsif ((($args{line} ne '1gfc') and ($args{client} eq '1gfc')) || 
                       (($args{line} ne '1ge') and ($args{client} eq '1ge'))) { # Bug 38871
                    # 1G data rates require k/8 on the line side to maintain an 8.3MHz TXDiv
                    my $k_client = $k;
                    my $k_line = $k/8;
                    if(ten_hl_syncdsync_datapath_config_t41_v2($mod_line, $slice, $mod_client, $slice_client,
                                                               $args{line_fec_enum}, $args{client_fec_enum},
                                                               $args{mode_enum},
                                                               $method,
                                                               $k_line, $k_client,
                                                               $args{map_odtu_enum},
                                                               $args{map_oxuv_enum},
                                                               $args{timeslots})) {
                        failure("ten_hl_syncdsync_datapath_config_t41_v2() failed\n");
                        return 1;
                    }
                }
                else {
                    if(ten_hl_syncdsync_datapath_config_t41($mod_line, $slice, $mod_client, $slice_client,
                                                            $args{line_fec_enum}, $args{client_fec_enum},
                                                            $args{mode_enum},
                                                            $method,
                                                            $k,
                                                            $args{map_odtu_enum},
                                                            $args{map_oxuv_enum},
                                                            $args{timeslots})) {
                        failure("ten_hl_syncdsync_datapath_config_t41() failed\n");
                        return 1;
                    }

                    ##################################################################
                    #####   Provision additional syncdsyncs for UFEC with SFI4.1 #####
                    ##################################################################
                    if($sfi41_ufec_alloc) {
                        # A2 TX - A2 RXDIV to feed CLKSEL_INT_RXDIV FOR GPLL A2 on line_int loopback path
                        ten_syncdsync_config_1_to_1 ($mod_line_int,
                                                     $slice_line_int,            # slice
                                                     $args{client_port},         # rx_div_mux   Source is Side B Slice 3
                                                     CS_TX,                      # direction
                                                     $k);                        # k value

                        # Change A0 RX from SYNC to 1:1
                        ten_syncdsync_config_1_to_1 ($mod_line,
                                                     $slice_line,                # slice
                                                     $args{line_port},           # Don't care
                                                     CS_RX,                      # direction
                                                     $k);                        # k value

                        # A1 TX - A1 RXDIV to feed CLKSEL_INT_RXDIV FOR GPLL A1 on client_int loopback path
                        ten_syncdsync_config_1_to_1 ($mod_client_int,
                                                     $slice_client_int,          # slice
                                                     $args{line_port},           # rx_div_mux   Source is Side A Slice 0
                                                     CS_TX,                      # direction
                                                     $k);                        # k value

                        if($line_rate == $client_rate) {
                            # A0 RX 1:1
                            ten_syncdsync_config_1_to_1 ($mod_client_int,
                                                         $slice_client_int,          # slice
                                                         $args{client_port},         # Don't care
                                                         CS_RX,                      # direction
                                                         $k);                        # k value
                        }
                        else {
                            # A1 RX - sync
                            my $num    = $QLvalue*16*4;
                            my $denom  = $PLvalue*16*4*$k;
                            ten_syncdsyncrx_cfg($mod_client_int,
                                                $slice_client_int,
                                                $num>>32,
                                                $num&0xFFFF_FFFF,
                                                $denom>>32,
                                                $denom&0xFFFF_FFFF,
                                                0,0,0,0,0,0,0);
                        }

                        # Override B3 RXDIV to A1
                        ten_syncdsynctx_set_configuration_rx_div_mux($mod_client, 
                                                                     $slice_client, 
                                                                     $slice_client_int);
                    }
                }
            }
        }
    }
    elsif (($args{mode} eq 'lb10') || ($args{mode} eq 'lb40')) {
       if(ten_hl_syncdsync_threadsafe_datapath_config($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{module_id_lb_kpga}, $args{slice_lb_kpga},
                                                       $args{mode_enum},
                                                       $args{sync},
                                                       $method,
                                                       $k,
                                                       $args{lb_kpga_fec_enum}, $args{lb_kpga_fec_enum})) {
           failure("ten_hl_syncdsync_threadsafe_datapath_config() failed\n");
           return 1;
       }
    }
}

########################################################################################
# Bugzilla 35995
# SFI 4.1 on side A can only be provisioned on port A1 and requires clock to be enabled
# on port A0 and A1. The chip requires SFI4.1 block to receive clock on TX_CLKINP pin 
# which is wired to Silab 0 output on the board. Since Silab 0 input is wired to RXDIV 
# A0, Cortina uses syncdsync A0 in the TX direction due to board design restriction.
########################################################################################
if(my $rev_id = main::ten_mpif_get_chip_rev_id($dev_id) == 2) {
  if (($args{hsif_line} eq 'sfi4_1') and ($slice_line == 1)) {
    my $gpll_inst_override_tx = 0;
    
    ten_syncdsync_config_1_to_1 ($mod_line,
                                 0,                      # slice
                                 $args{client_port},     # rx_div_mux   Source is Side B Slice 3
                                 CS_TX,                  # direction
                                 $k);                    # k value

    sleep(2);

    if ($mod_line_int < 4) {
        $gpllx1_inst_line = 1;  # GPLL 1
    } else {
        $gpllx1_inst_line = 9;  # GPLL 9
    }

    $gpll_inst_override_tx = $gpllx1_inst_line+4+$slice_line;

    ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_tx,1);
    ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_tx,0);
  }
}

# Bugzilla 31850 Start
########################################################################################
#  Provision Cortina board specific rx_div_mux
########################################################################################
if ($args{linerate} == 40) {
    if ($args{hsif_line} eq 'xfi') {
        if ($args{mode} eq 'lb40') {
            if ($args{line_port} >= 4) {
                # Provision RX Div Mux for Silabs on Side B slice 2
                ten_syncdsync_config_1_to_1 ($mod_line,
                                             2,         # slice
                                             4,         # rx_div_mux   Source is Side B Slice 0
                                             CS_TX,     # direction
                                             $k);       # k value
            }
        }
        elsif(($args{mode} eq 'trans40') && ($sync==0)) {
            # Provision RX Div Mux for SyncDsync on Side B slice 2
            ten_syncdsync_config_1_to_1 ($mod_line,
                                         2,         # slice
                                         3,         # rx_div_mux   Source is Side A Slice 3
                                         CS_TX,     # direction
                                         $k);       # k value
        }
    }
    elsif (($args{hsif_line} eq 'cfp_mr') && ($args{line_port} < 4)) {
        # Side A using CFP MR HSIF on side B
        if ($sync == 1) {
            # Provision RX Div Mux for Silabs on Side B slice 0
            ten_syncdsync_config_1_to_1 ($mod_b,
                                         0,           # slice
                                         0,           # rx_div_mux  # Bugzilla #36329, was 4 
                                         CS_TX,       # direction
                                         $k);         # k value
        }
    }
}

if(($args{clientrate} == 40) && ($args{hsif_client} eq 'xfi')) {
    if ($args{mode} eq 'lb40') {
        if ($args{client_port} >= 4) {
            # Provision RX Div Mux for Silabs on Side B slice 2
            ten_syncdsync_config_1_to_1 ($mod_client,
                                         2,            # slice
                                         4,            # rx_div_mux  Source is Side B Slice 0
                                         CS_TX,        # direction
                                         $k);          # k value
        }
    }
    elsif(($args{mode} eq 'trans40') && ($sync == 1)) {
        # Provision RX Div Mux for Silabs on Side B slice 2
        ten_syncdsync_config_1_to_1 ($mod_client,
                                     2,           # slice
                                     #4,           # rx_div_mux   Source is Side A Slice 3
                                     0,           # rx_div_mux   Source is Side A Slice 0
                                     CS_TX,       # direction
                                     $k);         # k value
    }
    elsif(($args{mode} eq 'trans40') && ($sync==0) &&
          (($args{map_odtu_enum}==TEN_MAP_DONT_CARE) || ($args{map_oxuv_enum} == TEN_MAP_BMP))) { # Bugzilla 28006  28176
        # Async Line with Sync client
        # Provision RX Div Mux for SyncDsync on Side B slice 2
        ten_syncdsync_config_1_to_1 ($mod_client,
                                     2,           # slice
                                     3,           # rx_div_mux   Source is Side A Slice 3
                                     CS_TX,       # direction
                                     $k);         # k value
    }
}
# Bugzilla 31850 End

# Bugzilla #36216:  Pilot clock settings in 10G transponder configurations using MR10G (CFP) Serdes
if ( ($args{hsif_client} eq 'cfp_mr') and ($sync == 1) and ($args{clientrate} == 10) and ($args{line} ne 'invalid') ) {
    my $tmp_rx_div_mux;
    if ($mod_num_line == TEN_MODULE_B) {
      $tmp_rx_div_mux = $slice_line | 0x4;
    }
    else {
      $tmp_rx_div_mux = $slice_line;
    }
    if (t40fpga_get_board_type($FPGA_SYS_ID) == 8) {
      printf("Fix rx div mux for CEB (Customer Evaluation Board) %x\n", $tmp_rx_div_mux);
      ten_mpif_global_reset_syncdsync($dev_id, $mod_num_client, TEN_SLICE2, CS_TX, CS_RESET_DEASSERT);
      ten_syncdsynctx_set_configuration_rx_div_mux($mod_client, TEN_SLICE2, $tmp_rx_div_mux);

    }
    else {
      print("Fix rx div mux for Non-CEB\n");
      if (($slice_client == 0) or ($slice_client == 2)) {
        ten_mpif_global_reset_syncdsync($dev_id, $mod_num_client, $slice_client+1, CS_TX, CS_RESET_DEASSERT);
        ten_syncdsynctx_set_configuration_rx_div_mux($mod_client, $slice_client+1, $tmp_rx_div_mux);
      }
    }
}

if ( ($args{hsif_line} eq 'cfp_mr') and ($sync == 1) and ($args{linerate} == 10) and ($args{client} ne 'invalid') ) {
    my $tmp_rx_div_mux;
    if ($mod_num_client == TEN_MODULE_B) {
      $tmp_rx_div_mux = $slice_client | 0x4;
    }
    else {
      $tmp_rx_div_mux = $slice_client;
    }
    if (t40fpga_get_board_type($FPGA_SYS_ID) == 8) {
      printf("Fix rx div mux for CEB (Customer Evaluation Board) %x\n", $tmp_rx_div_mux);
      ten_mpif_global_reset_syncdsync($dev_id, $mod_num_line, TEN_SLICE2, CS_TX, CS_RESET_DEASSERT);
      ten_syncdsynctx_set_configuration_rx_div_mux($mod_line, TEN_SLICE2, $tmp_rx_div_mux);
    }
    else {
      print("Fix rx div mux for Non-CEB\n");
      if (($slice_line == 0) or ($slice_line == 2)) {
        ten_mpif_global_reset_syncdsync($dev_id, $mod_num_line, $slice_line+1, CS_TX, CS_RESET_DEASSERT);
        ten_syncdsynctx_set_configuration_rx_div_mux($mod_line, $slice_line+1, $tmp_rx_div_mux);
      }
    }
}

###############################################################################
#   Provision Mapper LINE
###############################################################################
if ($args{dyn_repro} == TEN_INITIAL_CONFIG) {
    # De-assert cross-connect resets and enable clocks
    ten_mpif_global_clock_disable_common( $dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON );
    ten_mpif_global_reset_common( $dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON );
    ten_mpif_global_reset_common( $dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS );
}


###############################################################################
# Configure N10G and PP10G for the type of client traffic upto ODTU23 layer
###############################################################################
if ($args{mode} eq 'mux') {
    if (($args{client} eq 'otu3') || ($args{client} eq 'otu3e2') || ($args{client} eq 'otu3+')) {  # Bugzilla 29100
        if(ten_hl_config_otu3v_odtu_otu3v_t41($mod_line,
                                              $args{line_traffic_type_enum},
                                              $args{line_fec_enum},
                                              $args{client_traffic_type_enum},
                                              $args{client_fec_enum},
                                              $args{xcon_client_enum},
                                              $args{term_otu_enum},
                                              $args{line_tcm_bits},
                                              $args{client_tcm_bits},
                                              $args{mld_line_enabled},
                                              $args{mld_client_enabled},
                                              $args{map_odtu_enum},
                                              $args{map_oxuv_enum})) {
            failure("ten_hl_config_otu3v_odtu_otu3v_t41() failed\n");
            return 1;
        }
        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame               #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        for (my $i=0; $i<TEN_MAX_SLICES ;$i++) {
            print("An interrupt hander thread must be running for Elastic Store centering to work\n");
            ten_n10g_otnr_intr_handler_enable ($mod_line, $i, TEN_N10G_OTNR_INTR_ILOF);
            ten_n10g_otnr_intr_handler_enable ($mod_client, $i, TEN_N10G_OTNR_INTR_ILOF);
        }
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, 0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # Buzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # Buzilla 30856
        # End Bugzilla 27270 Amplitude Recentering
    }

    elsif (($args{client} eq 'oc192') || ($args{client} eq 'oc192_async')) {
        if (ten_hl_config_oc192_otu3v_t41 ($mod_line,
                                           $slice,
                                           $slice_client,
                                           $args{dyn_repro},
                                           $args{line_traffic_type_enum},
                                           $args{line_fec_enum},
                                           $args{oc_term_enum},
                                           $args{line_tcm_bits},
                                           $args{mld_line_enabled},
                                           $args{map_odtu_enum},    # 40g mapping
                                           $args{map_oxuv_enum},    # 10g mapping
                                           $args{timeslots},
                                           $args{ts_mask})) {
            failure("ten_hl_config_oc192_otu3v_t41() failed\n");
            return 1;
        }
        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for Sonet Loss Of Frame             #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for Sonet Loss Ofn Frame
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n10g_sdfr_sdfist_handler_enable ($mod_line, $slice, TEN_N10G_SDFR_SDFIST_LOF);
        ten_n10g_sdfr_sdfist_handler_enable ($mod_client, $slice_client, TEN_N10G_SDFR_SDFIST_LOF);
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, $slice_client, 0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G Bugzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   0,             1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G Bugzilla 30856
        # End Bugzilla 27270 Amplitude Recentering
        
        if ($args{monitor} == 2) {
          # enable passive monitoring on OC192/10GEWAN signal
          ten_hl_pp10g_config($mod_client, $slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0); 
          ten_hl_pp10g_tx_reset($mod_client, $slice_client, CS_RESET_DEASSERT);
          ten_hl_pp10g_rx_reset($mod_client, $slice_client, CS_RESET_DEASSERT);
          ten_n10g_set_gblr_dpcfg_sbypld($mod_client, $slice_client, 0);
        }
    }

    elsif (($args{client} eq '10ge6_1') || ($args{client} eq '10ge6_2') ||
           ($args{client} eq '10ge7_1') || ($args{client} eq '10ge7_2') || ($args{client} eq '10ge7_3') ||
           ($args{client} eq '10ge_ra') || ($args{client} eq '10ge_gfpf_oc192_odu2') ||
           ($args{client} eq '1ge') || ($args{client} eq '10ge')) { # Bug 38871
        if (ten_hl_config_10ge_otu3v_t41 ($mod_line,
                                          $slice,
                                          $slice_client,
                                          $args{dyn_repro},
                                          $args{line_traffic_type_enum},
                                          $args{line_fec_enum},
                                          $args{client_traffic_type_enum},
                                          $sysclk_Mhz_int,
                                          $args{line_tcm_bits},
                                          $args{mld_line_enabled},
                                          $args{map_odtu_enum},
                                          $args{map_oxuv_enum},
                                          $args{timeslots},
                                          TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4,
                                          $args{ten_ge_flow_enum})) {
            failure("ten_hl_config_10ge_otu3v_t41() failed\n");
            return 1;
        }
        # Bugzilla 29751 Start
        if ($args{hsif_client} ne 'xaui') {
            if (($args{client} eq '10ge') or ($args{client} eq '10ge7_1') or ($args{client} eq '10ge7_2')) {
                #################################################################################################################
                # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
                # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
                #################################################################################################################
                if($enable_intr_flag) {
                    # Enable ISR for PCS in sync */
                    print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                    ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                    ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                }
            }
        }

        if ($args{client} eq '10ge_tc') {
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            if($enable_intr_flag) {
                # Enable ISR for PCS in sync */
                print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            }
        }
        # Bugzilla 29751 End
    }

    elsif ($args{client} eq 'cbr_10362079327') {
        if (ten_hl_config_10ge_otu3v_t41 ($mod_line,
                                          $slice,
                                          $slice_client,
                                          $args{dyn_repro},
                                          $args{line_traffic_type_enum},
                                          $args{line_fec_enum},
                                          TEN_TRAFFIC_TYPE_CBR_10G,
                                          $sysclk_Mhz_int,
                                          $args{line_tcm_bits},
                                          $args{mld_line_enabled},
                                          $args{map_odtu_enum},
                                          $args{map_oxuv_enum},
                                          $args{timeslots},
                                          TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4,
                                          $args{ten_ge_flow_enum})) {
            failure("ten_hl_config_10ge_otu3v_t41() failed\n");
            return 1;
        }
    }

    elsif (($args{client} =~ /otu2/) or ($args{client} =~ /otu1/)) {
        if (ten_hl_config_otu2v_otu3v_t41($mod_line,
                                      $slice,
                                      $slice_client,
                                      $args{dyn_repro},
                                      $args{line_traffic_type_enum},
                                      $args{line_fec_enum},
                                      $args{client_traffic_type_enum},
                                      $args{client_fec_enum},
                                      $args{term_otu_enum},
                                      $args{line_tcm_bits},
                                      $args{client_tcm_bits},
                                      $args{mld_line_enabled},
                                      $args{map_odtu_enum},
                                      $args{map_oxuv_enum},
                                      $args{timeslots},
                                      $args{ts_mask})) {
            failure("ten_hl_config_otu2v_otu3v_t41() failed\n");
            return 1;
        }
        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame               #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for OTN Loss Of Frame */
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n10g_otnr_intr_handler_enable ($mod_line, $slice, TEN_N10G_OTNR_INTR_ILOF);
        ten_n10g_otnr_intr_handler_enable ($mod_client, $slice_client, TEN_N10G_OTNR_INTR_ILOF);
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, $slice_client, 0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G Bugzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   0,             1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G Bugzilla 30856
        # End Bugzilla 27270 Amplitude Recentering
    }

    elsif (($args{client} =~ /10gfc_tc/) || # Bug 31054
           ($args{client} eq '8gfc_enh') ||
           ($args{client} eq '8gfc_ra') ||
           ($args{client} eq '8gfc') ||
           ($args{client} eq '4gfc') || # Bug 38779
           ($args{client} eq '2gfc') || # Bug 38779
           ($args{client} eq '2gisc') || # Bug 38779
           ($args{client} =~ /cpri/)) {   # Bug 39690
        if (ten_hl_config_fc_otu3v_t41 ($mod_line,
                                        $slice,
                                        $slice_client,
                                        $args{dyn_repro},
                                        $args{line_traffic_type_enum},
                                        $args{line_fec_enum},
                                        $args{client_traffic_type_enum},
                                        $sysclk_Mhz_int,
                                        $args{line_tcm_bits},
                                        $args{mld_line_enabled},
                                        $args{map_odtu_enum},
                                        $args{map_oxuv_enum},
                                        $args{timeslots},
                                        $args{ts_mask})) {
            failure("ten_hl_config_fc_otu3v_t41() failed\n");
            return 1;
        }
        # Bugzilla 29751 Start
        if (($args{client} eq '10gfc') or ($args{client} eq '8gfc_enh')) {
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            if($enable_intr_flag) {
                # Enable ISR for PCS in sync */
                print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            }
        }
        # Bugzilla 29751 End
    }

    elsif (($args{client} eq 'pbert_8gfc') || ($args{client} eq 'pbert_10gfc') ||
           ($args{client} eq 'pbert_10ge')) {
        ten_hl_config_pbert_odtu23($mod_line,
                                   $slice,
                                   $mod_client,
                                   $slice_client,
                                   $args{line_traffic_type_enum},
                                   $args{client_traffic_type_enum},
                                   $args{dyn_repro},
                                   $sysclk_Mhz_int);
    }

    # Bugzilla 38565 Start
    elsif (($args{client} =~ /_iba/)) {
        if (ten_hl_config_infiniband_otu3v_t41 ($mod_line,
                                        $slice,
                                        $slice_client,
                                        $args{dyn_repro},
                                        $args{line_traffic_type_enum},
                                        $args{line_fec_enum},
                                        $args{client_traffic_type_enum},
                                        $sysclk_Mhz_int,
                                        $args{line_tcm_bits},
                                        $args{mld_line_enabled},
                                        $args{map_odtu_enum},
                                        $args{map_oxuv_enum},
                                        $args{timeslots},
                                        $args{ts_mask})) {
            failure("ten_hl_config_infiniband_otu3v_t41() failed\n");
            return 1;
        }
        if ($args{client} eq '10g_iba') {
          # For 10GIB no samples are dropped
          ten_pp10g_mon10b_gb_sel_t41($mod_line,   $slice_line,   0);
          ten_pp10g_mon10b_gb_sel_t41($mod_client, $slice_client, 0);
        }
        if ($args{client} eq '5g_iba') {
          # For 5GIB clocked at 10Gbps, gb_sel=1 means:   Every 2nd received data bit is input to the 10B monitor
          # Required if clocking datapath at 10Gbps
          ten_pp10g_mon10b_gb_sel_t41($mod_line,   $slice_line,   1);
          ten_pp10g_mon10b_gb_sel_t41($mod_client, $slice_client, 1);
        }
        if ($args{client} eq '2_5g_iba') {
          # For 2.5GIB clocked at 10Gbps, gb_sel=2 means:   Every fourth received data bit is input to the 10B monitor
          # Required if clocking datapath at 10Gbps
          ten_pp10g_mon10b_gb_sel_t41($mod_line,   $slice_line,   2);
          ten_pp10g_mon10b_gb_sel_t41($mod_client, $slice_client, 2);
        }
        # Bugzilla 29751 Start
        if (($args{client} eq '10g_iba') or ($args{client} eq 'fdr10_iba')) { # Bug 39242
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            if($enable_intr_flag) {
                # Enable ISR for PCS in sync */
                print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                # causes bus errors
                ## ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                ## ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            }
        }
        # Bugzilla 29751 End
    }
    # Bugzilla 38565 End

    elsif ($args{client} eq 'null') {
        # Bugzilla 26401 Start
        ####if (ten_hl_config_fec_t41 ($mod_client, $slice_client, TEN_SLICE_10G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
        ####    failure("10G FEC Provisioning failed on module $mod_client and slice $slice_client\n");
        ####    return 1;
        ####}
        ten_hl_config_aggregation_idle($mod_line, $slice, $mod_client, $slice_client);
        # Bugzilla 26401 End
    }
    elsif ($args{client} eq 'invalid') {
    }
    else {
        failure("Muxponder -client '$args{client}' not supported");
        return 1;
    }

    if ($args{line} =~ /otu3/) {
        # The signal to the KPA is the OPU-3 payload or the unaligned line interface input (as determined by OBY)
        ten_n40g_gblr4x_set_kpasel ($mod_line, 1);
    }
    if ($args{client} =~ /otu3/) {
        # The signal to the KPA is the OPU-3 payload or the unaligned line interface input (as determined by OBY)
        ten_n40g_gblr4x_set_kpasel ($mod_client, 1);
    }

    #### this is already done in the preceeding hl_config APIs
    ####    if (($args{client} =~ /otu2/) || ($args{client} =~ /otu1/)) {
    ####        ten_print("ten_hl_config_fec_t41 #1\n");
    ####        if (ten_hl_config_fec_t41 ($mod_client, $slice_client, TEN_SLICE_10G, $args{client_fec_enum}) == CS_ERROR) {
    ####            failure("10G FEC Provisioning failed on module $mod_client and slice $slice_client\n");
    ####            return 1;
    ####        }
    ####    }
}

elsif ($args{mode} eq 'trans40') {
    # Monolithic 40G mode
    if ($args{client} =~ /otu3/) {
        if ($args{xcon_client_enum} == TEN_TRAFFIC_TYPE_OC768) {
            # Bugzilla 28977 Start
            if (ten_hl_config_otu3v_oc768_otu3v_t41_v2 ($mod_line,
                                                        $args{dyn_repro},
                                                        $args{line_traffic_type_enum},
                                                        $args{line_fec_enum},
                                                        $args{client_traffic_type_enum},
                                                        $args{client_fec_enum},
                                                        $args{xcon_client_enum},
                                                        $args{oc_term_enum},
                                                        $args{line_tcm_bits},
                                                        $args{client_tcm_bits},
                                                        $args{mld_line_enabled},
                                                        $args{mld_client_enabled},
                                                        $args{map_odtu_enum},
                                                        $args{map_oxuv_enum},
                                                        $args{deskew_ctrl}) != CS_OK) {
                failure("ten_hl_config_otu3v_oc768_otu3v_t41_v2() failed\n");
                return 1;
            }
            # Bugzilla 28977 End
            # Bugzilla 29751 Start
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for Sonet Loss Of Frame             #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            # Enable ISR for Sonet Out Of Frame
            print("An interrupt hander thread must be running for Elastic Store centering to work\n");
            ten_n40g_sdfr_sdfist_handler_enable ($mod_line, TEN_N40G_SDFR_SDFIST_OOF);
            ten_n40g_sdfr_sdfist_handler_enable ($mod_client, TEN_N40G_SDFR_SDFIST_OOF);
            # Bugzilla 29751 End

            # Bugzilla 27270 Amplitude Recentering
            setup_amp_recenter($dev_id, $mod_num_client, 0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
            setup_amp_recenter($dev_id, $mod_num_line,   0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
            # End Bugzilla 27270 Amplitude Recentering
        }
        # Bugzilla 28006 Start
        elsif ($args{xcon_client_type} =~ /40ge/) {
            if (ten_hl_config_otu3v_40ge_otu3v_t41 ($mod_line,
                                                    $args{dyn_repro},
                                                    $args{line_traffic_type_enum},
                                                    $args{line_fec_enum},
                                                    $args{client_traffic_type_enum},
                                                    $args{client_fec_enum},
                                                    $args{xcon_client_enum},   # Bugzilla 27167
                                                    $args{pre_line_rx_enum},   # Bugzilla 28006
                                                    $args{pre_line_tx_enum},   # Bugzilla 28006
                                                    $args{pre_client_rx_enum}, # Bugzilla 28006
                                                    $args{pre_client_tx_enum}, # Bugzilla 28006
                                                    $args{line_tcm_bits},
                                                    $args{client_tcm_bits},
                                                    $args{mld_line_enabled},
                                                    $args{mld_client_enabled},
                                                    $args{map_odtu_enum},
                                                    $args{map_oxuv_enum},
                                                    $args{deskew_ctrl},
                                                    $sysclk_Mhz_int) != CS_OK) {
                failure("ten_hl_config_otu3v_40ge_otu3v_t41() failed\n");
                return 1;
            }
        
            # Bugzilla 29751 Start
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            # Enable ISR for 40GE PCS in sync
            print("An interrupt hander thread must be running for Elastic Store centering to work\n");
            ten_pp40g_pcs_rx_interupt_handler_enable ($mod_line, TEN_PP40G_PCS_RX_INTERRUPT_XDCBLOCKLOCKI);
            ten_pp40g_pcs_rx_interupt_handler_enable ($mod_client, TEN_PP40G_PCS_RX_INTERRUPT_XDCBLOCKLOCKI);
            # Bugzilla 29751 End

            # Bugzilla 27270 Amplitude Recentering
            setup_amp_recenter($dev_id, $mod_num_client, 0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Buzilla 30856
            setup_amp_recenter($dev_id, $mod_num_line,   0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Buzilla 30856
            # End Bugzilla 27270 Amplitude Recentering
        # Bugzilla 28006 End
        } else {
            # Bugzilla 28977/29481 Start
            if (ten_hl_config_otu3v_otu3v_t41_v2 ($mod_line,
                                               $args{dyn_repro},
                                               $args{line_traffic_type_enum},
                                               $args{line_fec_enum},
                                               $args{client_traffic_type_enum},
                                               $args{client_fec_enum},
                                               $args{term_otu_enum},
                                               $args{line_tcm_bits},
                                               $args{client_tcm_bits},
                                               $args{mld_line_enabled},
                                               $args{mld_client_enabled},
                                               $args{map_odtu_enum},
                                               $args{map_oxuv_enum},
                                               $args{deskew_ctrl})) {
                failure("ten_hl_config_otu3v_otu3v_t41_v2() failed\n");
                return 1;
            }
            # Bugzilla 28977/29481 End
            # Bugzilla 29751 Start
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame               #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            # Enable ISR for OTN Out Of Frame
            print("An interrupt hander thread must be running for Elastic Store centering to work\n");
            ten_n40g_otnr4x_intr_handler_enable ($mod_line, TEN_N40G_OTNR4X_INTR_IIF);
            ten_n40g_otnr4x_intr_handler_enable ($mod_client, TEN_N40G_OTNR4X_INTR_IIF);
            # Bugzilla 29751 End

            # Bugzilla 27270 Amplitude Recentering
            setup_amp_recenter($dev_id, $mod_num_client, 0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
            setup_amp_recenter($dev_id, $mod_num_line,   0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
            # End Bugzilla 27270 Amplitude Recentering
        }
    }
    elsif ($args{client} =~ /40ge/) {
        if ($args{line} =~ /40ge/) {
           if (ten_hl_config_40ge_40ge_t41($mod_line,
                                           $args{dyn_repro},
                                           $args{line_traffic_type_enum},
                                           $args{client_traffic_type_enum},
                                           $args{pre_line_tx_enum},
                                           $args{pre_line_rx_enum},
                                           $args{pre_client_tx_enum},
                                           $args{pre_client_rx_enum},
                                           $args{mld_line_enabled},
                                           $args{mld_client_enabled},
                                           $args{map_oxuv_enum},
                                           $args{deskew_ctrl},
                                           $sysclk_Mhz_int) != CS_OK) {
             failure("ten_hl_config_40ge_40ge_t41 failed");
          }
        }
        elsif ($args{line} =~ /otu3/) {
          if (ten_hl_config_40ge_otu3v_t41($mod_line,
                                           $args{dyn_repro},
                                           $args{line_traffic_type_enum},
                                           $args{client_traffic_type_enum},
                                           $args{pre_line_tx_enum},
                                           $args{pre_line_rx_enum},
                                           $args{pre_client_tx_enum},
                                           $args{pre_client_rx_enum},
                                           $args{line_fec_enum},
                                           $args{line_tcm_bits},
                                           $args{mld_line_enabled},
                                           $args{mld_client_enabled},
                                           $args{map_oxuv_enum},
                                           $args{timeslots},
                                           $args{deskew_ctrl},
                                           $sysclk_Mhz_int) != CS_OK) {
             failure("ten_hl_config_40ge_otu3v_t41 failed");
          }
        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for 40GE PCS in sync
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_pp40g_pcs_rx_interupt_handler_enable ($mod_line, TEN_PP40G_PCS_RX_INTERRUPT_XDCBLOCKLOCKI);
        ten_pp40g_pcs_rx_interupt_handler_enable ($mod_client, TEN_PP40G_PCS_RX_INTERRUPT_XDCBLOCKLOCKI);
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, 0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
        # End Bugzilla 27270 Amplitude Recentering
      }
        elsif ($args{line} eq 'otu2ex4') {
            my $fec_type = ($args{line_traffic_type_enum}==TEN_FEC_MODE_DEALLOCATE) ? $args{client_fec_enum} : $args{line_fec_enum};

            if (ten_hl_config_otu2v_40gep_t41($mod_line,
                                              $args{dyn_repro},
                                              $args{line_traffic_type_enum},
                                              $args{client_traffic_type_enum},
                                              $fec_type,
                                              $args{deskew_ctrl},
                                              $sysclk_Mhz_int) != CS_OK) {
                failure("ten_hl_config_otu2v_40gep_t41 call failed");
                return 1;
            }
        }
    }
    elsif ($args{client} =~ /oc768/) {
        # Bugzilla 28977 Start
        if (ten_hl_config_oc768_otu3v_t41_v2 ($mod_line,
                                              $args{dyn_repro},
                                              $args{line_traffic_type_enum},
                                              $args{line_fec_enum},
                                              $args{oc_term_enum},
                                              $args{line_tcm_bits},
                                              $args{mld_line_enabled},
                                              $args{mld_client_enabled},
                                              $args{map_oxuv_enum},
                                              $args{timeslots},
                                              $args{deskew_ctrl}) != CS_OK) {
            failure("ten_hl_config_oc768_otu3v_t41_v2 call failed");
            return 1;
        }
        # Bugzilla 28977 End
        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for Sonet Loss Of Frame             #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for Sonet Out Of Frame
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n40g_sdfr_sdfist_handler_enable ($mod_line, TEN_N40G_SDFR_SDFIST_OOF);
        ten_n40g_sdfr_sdfist_handler_enable ($mod_client, TEN_N40G_SDFR_SDFIST_OOF);
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, 0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   0, 1, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 40G  Bugzilla 30856
        # End Bugzilla 27270 Amplitude Recentering
    }
    elsif (($args{client} =~ /cbr40g50188149150/) || ($args{client} eq '40gelan')) {
         if (ten_hl_config_40g_monolithic($mod_line, $mod_client, $args{line_traffic_type_enum}, $args{client_traffic_type_enum},
                                          $args{dyn_repro}, $args{line_fec_enum}, $args{client_fec_enum}, $args{sync}, $args{term_otu_enum},
                                          $args{line_tcm_bits}, $args{client_tcm_bits}, $args{oc_term_enum}) == 1) {
            failure("ten_hl_config_40g_monolithic call failed");
            return 1;
        }
    }

    if (($args{line} =~ /otu3/) || ($args{line} =~ /otu3+/) || ($args{line} =~ /otu3e/)) {
        if (($args{line_fec} eq 'ufec7p') and ($args{line} eq 'otu3e3')) {
            # This is a non-standard UFEC

            #  ten_hl_mpif_fec_init already done in config_fec_40g
            #main::ten_hl_mpif_fec_init($mod_line, $line_port, main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC);

            # Reset the
            #cs_status ten_mpif_global_reset_ufec(cs_uint16 dev_id, cs_uint16 select, cs_dir_t dir, cs_reset_action_t act)
            ####    main::ten_mpif_global_reset_ufec ($dev_id, main::TEN_MPIF_GLOBAL_UFEC_0, main::CS_TX_AND_RX, main::CS_RESET_TOGGLE);

            #$PLvalue = 263;
            #$QLvalue = 243;
            #$ncols_line =  $PLvalue - 1;
            #$npar_line =  $PLvalue - $QLvalue - 1 - ($stm256md * 2) - $stm64md;
            #####     my $ncols_line = 263 - 1;
            #####     my $npar_line = 263 - 243 - 1;

            # Set NCOLS and NPAR for OTU3V  ncols 262 npar 19
            ####             main::ten_n40g_otnr4x_set_ncols ($mod_line, $ncols_line);
            ####             main::ten_n40g_otnr4x_set_nparb_npar ($mod_line, 0, $npar_line);
            ####             main::ten_n40g_otnt4x_set_ncols ($mod_line, $ncols_line);
            ####             main::ten_n40g_otnt4x_set_nparb_npar ($mod_line, 0, $npar_line);

            #####            #main::ten_ufec_config_decoder($mod_line, $line_port, overhead);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGC0, 0x01a7);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGC1, 0x0073);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGB , 0x010b);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGB0, 0x07ff);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA0, 0x2f40);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA1, 0x0107);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA2, 0x4720);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA3, 0x0640);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA4, 0x29f8);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA5, 0x039c);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA7, 0x2bff);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA6, 0x0);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA6, 0x32a3);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGB1, 0x0003);
            #####            #main::ten_reg_write($dev_id, main::TEN_UFEC_URX_URXCFGA6, 0x32a3);
            #####
            #####            #main::ten_ufec_config_encoder(module_id, slice, overhead);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGC0, 0x01a7);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGC1, 0x0073);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGB0, 0x0000);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA0, 0x2f40);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA1, 0x0107);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA2, 0x4720);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA3, 0x0240);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA4, 0x6c3c);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA5, 0x0574);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA6, 0x29f8);
            #####            main::ten_reg_write($dev_id, main::TEN_UFEC_UTX_UTXCFGA7, 0x079c);
            print("config_otu3_cbr  provision ufec 8 percent\n");
            ten_ufec_custom_config($mod_line, TEN_FEC_MODE_OTUkV_263);

            #  ten_n40g_otnt4x_scrambling and ten_n40g_otnr4x_descrambling already done in config_fec_40g
            #main::ten_n40g_otnt4x_scrambling($mod_line, 0, 1);
            #main::ten_n40g_otnr4x_descrambling($mod_line, 1, 0, 1);

            #  ten_n40g_otnt4x_ocfg and ten_n40g_otnr4x_ocfg already done in config_fec_40g
            #main::ten_n40g_otnt4x_ocfg($mod_line, 1, 1);
            #main::ten_n40g_otnr4x_ocfg($mod_line, 1, 1);

            #main::ten_hl_ufec_ed_config($mod_line, $line_port, main::CS_TX_AND_RX, main::CS_ENABLE, $ncols_line);
            #####     main::ten_hl_ufec_ed_config($mod_line, 0, main::CS_TX_AND_RX, main::CS_ENABLE, $ncols_line);

            #####     main::ten_n40g_otnr4x_oacfg0_dsyhyst($mod_line, 11);
        }
    }

    if ($args{client} =~ /otu3/) {
    }
    elsif ($args{client} eq 'null') {
        ####   if (ten_hl_config_fec_t41 ($mod_client, 0, TEN_SLICE_40G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
        ####    failure("40G FEC Provisioning failed on module $mod_client\n");
        ####    return 1;
        ####}
        ##### Bugzilla 29609 Start
        ####if ($args{dyn_repro} == TEN_REPRO_LINE_AND_CLIENT) {
        ####    if (ten_hl_config_fec_t41 ($mod_line, 0, TEN_SLICE_40G, TEN_FEC_MODE_DEALLOCATE) == CS_ERROR) {
        ####        failure("10G FEC Provisioning failed on module $mod_line and slice $slice_line\n");
        ####        return 1;
        ####    }
        ####}
        ten_hl_config_40g_idle_t41 ($mod_line, $args{dyn_repro});
        # Bugzilla 29609 End
    }
}
elsif ($args{mode} eq 'wire40') {
    # 40G Wire mode.  Line and Client must be the same.  No framing is done
    #ten_hl_config_40g_wire_t41($mod_line);
    ten_hl_config_40g_wire_t41_v2($mod_line,  
                                  $args{line_traffic_type_enum},
                                  $args{line_fec_enum},
                                  $args{client_traffic_type_enum},
                                  $args{client_fec_enum});
}

elsif ($args{mode} eq 'trans10') {
    # 10G Transponder mode
    if ((($args{line} =~ /otu2/) || ($args{line} =~ /otu1/)) and ($args{client} eq 'oc192')) {
        if($sfi41_ufec_alloc) {
            if(ten_hl_config_oc192_otu2_sfi41_t41($dev_id,
                                                  $args{dyn_repro},
                                                  $args{line_traffic_type_enum},
                                                  $args{line_fec_enum},
                                                  $args{oc_term_enum},
                                                  $args{line_tcm_bits},
                                                  $args{map_oxuv_enum})) {
                failure("ten_hl_config_oc192_otu2_sfi41_t41() failed\n");
                return 1;
            }
        }
        else {
            if (ten_hl_config_oc192_otu2v_t41 ($mod_line,
                                               $slice_line,
                                               $mod_client,
                                               $slice_client,
                                               $args{dyn_repro},
                                               $args{line_traffic_type_enum},
                                               $args{line_fec_enum},
                                               $args{oc_term_enum},
                                               $args{line_tcm_bits},
                                               $args{map_oxuv_enum})) {
                failure("ten_hl_config_oc192_otu2v_t41() failed\n");
                return 1;
            }
            if ($args{monitor} == 2) {
              # enable passive monitoring on OC192/10GEWAN signal
              ten_hl_pp10g_config($mod_client, $slice_client, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0); 
              ten_hl_pp10g_tx_reset($mod_client, $slice_client, CS_RESET_DEASSERT);
              ten_hl_pp10g_rx_reset($mod_client, $slice_client, CS_RESET_DEASSERT);
              ten_n10g_set_gblr_dpcfg_sbypld($mod_client, $slice_client, 0);
            }
        }
        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for Sonet Loss Of Frame             #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for Sonet Loss Of Frame
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n10g_sdfr_sdfist_handler_enable ($mod_line, $slice_line, TEN_N10G_SDFR_SDFIST_LOF);
        ten_n10g_sdfr_sdfist_handler_enable ($mod_client, $slice_client, TEN_N10G_SDFR_SDFIST_LOF);
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, $slice_client, 0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G  Bugzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   $slice_line,   0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G  Bugzilla 30856
        # End Bugzilla 27270 Amplitude Recentering
    }
    elsif (($args{line} eq 'oc192') and ($args{client} eq 'oc192')) {
        if (ten_hl_config_oc192_oc192_t41 ($mod_line,
                                           $slice_line,
                                           $mod_client,
                                           $slice_client,
                                           $args{dyn_repro},
                                           $args{oc_term_enum})) {
            failure("ten_hl_config_oc192_oc192_t41() failed\n");
            return 1;
        }
        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for Sonet Loss Of Frame             #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for Sonet Loss Of Frame
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n10g_sdfr_sdfist_handler_enable ($mod_line, $slice_line, TEN_N10G_SDFR_SDFIST_LOF);
        ten_n10g_sdfr_sdfist_handler_enable ($mod_client, $slice_client, TEN_N10G_SDFR_SDFIST_LOF);
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, $slice_client, 0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G  Bugzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   $slice_line,   0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G  Bugzilla 30856
        # End Bugzilla 27270 Amplitude Recentering
    }
    elsif ((($args{line} =~ /otu2/) || ($args{line} =~ /otu1/)) and ($args{client} eq $args{line})) {
        if($sfi41_ufec_alloc) {
            if (ten_hl_config_otu2v_otu2v_ufec_sfi41_t41($dev_id,
                                                         $args{dyn_repro},
                                                         $args{line_traffic_type_enum},
                                                         $args{line_fec_enum},
                                                         $args{client_traffic_type_enum},
                                                         $args{client_fec_enum},
                                                         $args{term_otu_enum},
                                                         $args{line_tcm_bits},
                                                         $args{client_tcm_bits},
                                                         $args{map_oxuv_enum})) {
                failure("ten_hl_config_otu2v_otu2v_ufec_sfi41_t41() failed\n");
                return 1;
            }
        }
        else {
            if (ten_hl_config_otu2v_otu2v_t41 ($mod_line,
                                               $slice_line,
                                               $mod_client,
                                               $slice_client,
                                               $args{dyn_repro},
                                               $args{line_traffic_type_enum},
                                               $args{line_fec_enum},
                                               $args{client_traffic_type_enum},
                                               $args{client_fec_enum},
                                               $args{term_otu_enum},
                                               $args{line_tcm_bits},
                                               $args{client_tcm_bits},
                                               $args{map_oxuv_enum})) {
                failure("ten_hl_config_otu2v_otu2v_t41() failed\n");
                return 1;
            }
        }

        # Bugzilla 29751 Start
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame               #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for OTN In Frame */
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n10g_otnr_intr_handler_enable ($mod_line, $slice_line, TEN_N10G_OTNR_INTR_IIF);
        ten_n10g_otnr_intr_handler_enable ($mod_client, $slice_client, TEN_N10G_OTNR_INTR_IIF);
        # Bugzilla 29751 End

        # Bugzilla 27270 Amplitude Recentering
        setup_amp_recenter($dev_id, $mod_num_client, $slice_client, 0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G  Bugzilla 30856
        setup_amp_recenter($dev_id, $mod_num_line,   $slice_line,   0, $args{recenter_type}, $args{recenter_mrgns}, $sysclk_freq);  # 10G  Bugzilla 30856
        # End Bugzilla 27270 Amplitude Recentering

        # Bugzilla 29997 Start
        ten_n10g_oohr_otu2_aps_pcc_handler_enable($mod_line, $slice_line, TEN_APS_DETECT_VALUE_CHANGED, TEN_OOHR_ALL_LAYERS);
        #ten_n10g_oohr_otu2_aps_pcc_handler_enable($mod_line, $slice_line, TEN_APS_DETECT_VALUE_UNSTABLE, TEN_OOHR_ALL_LAYERS);
        # Bugzilla 29997 End
    }
    elsif ((($args{line} eq 'otu2') and ($args{client} eq '10ge6_1')) ||
           (($args{line} eq 'otu2') and ($args{client} eq '10ge6_2')) ||
           (($args{line} eq 'otu2') and ($args{client} eq '10ge_ra')) ||
           (($args{line} eq 'otu2e') and ($args{client} eq '10ge_ra')) ||
           (($args{line} eq 'otu2e') and ($args{client} eq '10ge')) ||
           (($args{line} eq 'otu2') and ($args{client} eq '10ge_gfpf_oc192_odu2')) ||
           (($args{line} eq 'otu2e') and ($args{client} eq '10ge_tc')) ||
           (($args{line} eq 'otu2e') and ($args{client} eq '10ge7_1')) ||
           (($args{line} eq 'otu1e') and ($args{client} eq '10ge7_2')) ||
           (($args{line} eq 'otu2') and ($args{client} eq '10ge7_3')) ||
           (($args{line} eq 'otu2') and ($args{client} eq '1ge'))) { # Bug 38871
        if($sfi41_ufec_alloc) {
            if(ten_hl_config_10ge_otu2v_ufec_sfi41_t41($dev_id,
                                                       $args{dyn_repro},
                                                       $args{line_traffic_type_enum},
                                                       $args{line_fec_enum},
                                                       $args{client_traffic_type_enum},
                                                       $sysclk_Mhz_int,
                                                       $args{line_tcm_bits},
                                                       $args{gfp_frame_format_enum},
                                                       $args{ten_ge_flow_enum})) {
                failure("ten_hl_config_10ge_otu2v_ufec_sfi41_t41() failed\n");
                return 1;
            }
        }
        else {
            if (ten_hl_config_10ge_otu2v_t41 ($mod_line,
                                              $slice_line,
                                              $mod_client,
                                              $slice_client,
                                              $args{dyn_repro},
                                              $args{line_traffic_type_enum},
                                              $args{line_fec_enum},
                                              $args{client_traffic_type_enum},
                                              $sysclk_Mhz_int,
                                              $args{line_tcm_bits},
                                              $args{gfp_frame_format_enum},
                                              $args{ten_ge_flow_enum})) {
                failure("ten_hl_config_10ge_otu2v_t41() failed\n");
                return 1;
            }
        }

        # Bugzilla 29751 Start
        if ($args{hsif_client} ne 'xaui') {
            if (($args{client} eq '10ge') or ($args{client} eq '10ge7_1') or ($args{client} eq '10ge7_2')) {
                #################################################################################################################
                # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
                # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
                #################################################################################################################
                if($enable_intr_flag) {
                    # Enable ISR for PCS in sync */
                    print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                    ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                    ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                }
            }
        }

        if ($args{client} eq '10ge_tc') {
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            if($enable_intr_flag) {
                # Enable ISR for PCS in sync */
                print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            }
        }
        # Bugzilla 29751 End
    }

    elsif (($args{line} eq '10ge_ra') and ($args{client} eq '10ge_ra')) { # Bugzilla 37022
        if (ten_hl_config_traffic_type_ra_same ($mod_line,
                                                $slice_line,
                                                $mod_client,
                                                $slice_client,
                                                $args{dyn_repro},
                                                $args{line_traffic_type_enum},
                                                $sysclk_Mhz_int,
                                                $args{gfp_frame_format_enum},
                                                $args{ten_ge_flow_enum})) {
            failure("ten_hl_config_traffic_type_ra_same() failed\n");
            return 1;
        }
    }

    elsif (($args{client} eq 'pbert_8gfc') || ($args{client} eq 'pbert_10gfc') ||
           ($args{client} eq 'pbert_2gfc') || ($args{client} eq 'pbert_4gfc') ||
           ($args{client} eq 'pbert_10ge')) {
        ten_hl_config_pbert_otu2($mod_line, $slice,
                                      $mod_client, $slice_client,
                                      $args{client_traffic_type_enum},
                                      $args{dyn_repro},
                                      $sysclk_Mhz_int);
        if (($args{line} =~ /otu2/) || ($args{line} =~ /otu1/)) {
            if (($args{dyn_repro} != TEN_REPRO_CLIENT) and ($args{client} ne 'null')) {
                ten_print("ten_hl_config_fec_t41 #2\n");
                if (ten_hl_config_fec_t41 ($mod_line, $slice_line, TEN_SLICE_10G, $args{line_fec_enum}) == CS_ERROR) {
                    failure("10G FEC Provisioning failed on module $mod_line and slice $slice_line\n");
                    return 1;
                }
            }
        } 
    }
    # Bug 24820: Feature fc_ra_fc
    elsif ( $config_is_fc_ra_fc ) {
        ten_hl_config_fc_ra_fc($mod_line, $slice,
                               $mod_client, $slice_client,
                               $args{dyn_repro},
                               $sysclk_Mhz_int,
                               $args{client_traffic_type_enum});
    }
    elsif ((($args{line} eq 'otu1f') and ($args{client} eq '10gfc')) ||
           (($args{line} eq 'otu2e') and ($args{client} =~ /10gfc_tc/)) || # Bug 31054
           (($args{line} eq 'otu2')  and ($args{client} =~ /gfc_ra/) and ($config_is_fc_ra_fc == 0)) ||
           # Bugzilla 26608 Start
           (($args{line} =~ /otu2/)  and ($args{client} eq '8gfc_enh')) ||
           # Bugzilla 26608 End
           (($args{line} eq 'otu2')  and ($args{client} eq '8gfc')) ||
           (($args{line} eq 'otu2')  and ($args{client} eq '4gfc')) ||
           (($args{line} eq 'otu2')  and ($args{client} eq '2gfc')) ||
           (($args{line} eq 'otu2')  and ($args{client} eq '2gisc')) ||
           (($args{line} eq 'otu2')  and ($args{client} eq 'cpri_4')) || # Bugzilla 39690
           # Bugzilla 26608 Start
           (($args{line} =~ /otu2/)  and ($args{client} eq '4gfc_enh')) ||
           (($args{line} =~ /otu2/)  and ($args{client} eq '2gfc_enh')) ) {
           # Bugzilla 26608 End
        if (ten_hl_config_fc_otu2v_t41 ($mod_line,
                                        $slice,
                                        $mod_client,
                                        $slice_client,
                                        $args{dyn_repro},
                                        $args{line_traffic_type_enum},
                                        $args{line_fec_enum},
                                        $args{client_traffic_type_enum},
                                        $sysclk_Mhz_int,
                                        $args{line_tcm_bits},
                                        $args{map_oxuv_enum},
                                        $args{timeslots},
                                        $args{ts_mask})) {
            failure("ten_hl_config_fc_otu2v_t41() failed\n");
            return 1;
        }
        # Bugzilla 29751 Start
        if (($args{client} eq '10gfc') or ($args{client} eq '8gfc_enh')) {
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            if($enable_intr_flag) {
                # Enable ISR for PCS in sync */
                print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            }
        }
        # Bugzilla 29751 End
    }
    elsif (($args{line} eq 'otu2e') and ($args{client} =~ /_iba/)) {
        if (ten_hl_config_infiniband_otu2v_t41 ($mod_line,
                                        $slice,
                                        $mod_client,
                                        $slice_client,
                                        $args{dyn_repro},
                                        $args{line_traffic_type_enum},
                                        $args{line_fec_enum},
                                        $args{client_traffic_type_enum},
                                        $sysclk_Mhz_int,
                                        $args{line_tcm_bits},
                                        $args{map_oxuv_enum},
                                        $args{timeslots},
                                        $args{ts_mask})) {
            failure("ten_hl_config_infiniband_otu2v_t41() failed\n");
            return 1;
        }
        if ($args{client} eq '10g_iba') {
          # For 10GIB no samples are dropped
          ten_pp10g_mon10b_gb_sel_t41($mod_line,   $slice_line,   0);
          ten_pp10g_mon10b_gb_sel_t41($mod_client, $slice_client, 0);
        }
        if ($args{client} eq '5g_iba') {
          # For 5GIB clocked at 10Gbps, gb_sel=1 means:   Every 2nd received data bit is input to the 10B monitor
          # Required if clocking datapath at 10Gbps
          ten_pp10g_mon10b_gb_sel_t41($mod_line,   $slice_line,   1);
          ten_pp10g_mon10b_gb_sel_t41($mod_client, $slice_client, 1);
        }
        if ($args{client} eq '2_5g_iba') {
          # For 2.5GIB clocked at 10Gbps, gb_sel=2 means:   Every fourth received data bit is input to the 10B monitor
          # Required if clocking datapath at 10Gbps
          ten_pp10g_mon10b_gb_sel_t41($mod_line,   $slice_line,   2);
          ten_pp10g_mon10b_gb_sel_t41($mod_client, $slice_client, 2);
        }
        # Bugzilla 29751 Start
        if (($args{client} eq '10g_iba') or ($args{client} eq 'fdr10_iba')) { # Bug 39242
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            if($enable_intr_flag) {
                # Enable ISR for PCS in sync */
                print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                # causes bus errors
                ## ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
                ## ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            }
        }
        # Bugzilla 29751 End
    }
    elsif ($args{client} eq 'null') {
        ten_hl_config_idle($mod_line, $slice, $mod_client, $slice_client, $args{dyn_repro});
    }

    elsif (($args{line} eq '10ge') and ($args{client} eq '10ge')) {
        ten_hl_config_10ge_10ge($mod_line, $slice, $mod_client, $slice_client,
                                $args{dyn_repro}, $args{sync}, $sysclk_Mhz_int);
    }
    # Bugzilla 29991 Start
    elsif (($args{line} eq 'oc192') and ($args{client} eq '10ge_gfpf')) {
        if (ten_hl_config_oc192_10ge_t41 ($mod_line,
                                      $slice,
                                      $mod_client,
                                      $slice_client,
                                      $args{dyn_repro},
                                      $args{line_traffic_type_enum},
                                      $args{client_traffic_type_enum},
                                      #args{gfp_mode},
                                      $args{gfp_frame_format_enum},
                                      $args{ten_ge_flow_enum},
                                      $sysclk_Mhz_int) != CS_OK) {
            failure("ten_hl_config_oc192_10ge_t41 call failed");
            return 1;
        }
        
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        if($enable_intr_flag) {
            # Enable ISR for PCS in sync */
            print("An interrupt hander thread must be running for Elastic Store centering to work\n");
            ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
        }
    }
    elsif (($args{line} eq 'oc192') and ($args{client} eq '8gfc_ra')) {
        if (ten_hl_config_fc_oc192_t41 ($mod_line,
                                        $slice,
                                        $mod_client,
                                        $slice_client,
                                        $args{dyn_repro},
                                        $args{line_traffic_type_enum},
                                        $args{client_traffic_type_enum},
                                        $sysclk_Mhz_int) != CS_OK) {
            failure("ten_hl_config_oc192_10ge_t41 call failed");
            return 1;
        }
        
        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        if($enable_intr_flag) {
            # Enable ISR for PCS in sync */
            print("An interrupt hander thread must be running for Elastic Store centering to work\n");
            ten_pp10g_pcs_rx_rxint_handler_enable ($mod_client, $slice_client, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            ten_pp10g_pcs_rx_rxint_handler_enable ($mod_line, $slice_line, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
        }
    }
    elsif (($args{line} eq 'oc192') and ($args{client} eq '10ge6_1')) {
        if (ten_hl_config_10ge6_1_oc192_t41($mod_line,
                                            $slice_line,
                                            $mod_client,
                                            $slice_client,
                                            $args{dyn_repro},
                                            $args{line_traffic_type_enum},
                                            $args{client_traffic_type_enum},
                                            $sysclk_Mhz_int,
                                            $args{ten_ge_flow_enum})) {
                failure("ten_hl_config_10ge6_1_oc192_t41() failed\n");
                return 1;
            }
    }
    # Bugzilla 29991 End
    else {
        failure("Transponder -line '$args{line}' and -client '$args{client}' not supported");
        return 1;
    }

    if (($args{line} =~ /otu2/) || ($args{line} =~ /otu1/)) {
        #### if (($args{dyn_repro} != TEN_REPRO_CLIENT) and ($args{client} ne 'null')) {
        ####    ten_print("ten_hl_config_fec_t41 #3\n");
        ####    if (ten_hl_config_fec_t41 ($mod_line, $slice_line, TEN_SLICE_10G, $args{line_fec_enum}) == CS_ERROR) {
        ####        failure("10G FEC Provisioning failed on module $mod_line and slice $slice_line\n");
        ####        return 1;
        ####    }
        #### }
        # Set KPASEL = 1
        # Fix bus error: if client is 'null', then
        # ten_hl_config_idle put N10G line into reset,
        # so do not attempt setting N10G line kpasel.
        if ($args{client} ne 'null') {
            main::ten_n10g_gblr_set_kpasel($mod_line, $slice_line, 1); # KPA input from OxU2 payload
        }
    }

    if (($args{client} =~ /otu2/) || ($args{client} =~ /otu1/)) {
        #### ten_print("ten_hl_config_fec_t41 #4\n");
        #### if (ten_hl_config_fec_t41 ($mod_client, $slice_client, TEN_SLICE_10G, $args{client_fec_enum}) == CS_ERROR) {
        ####     failure("10G FEC Provisioning failed on module $mod_client and slice $slice_client\n");
        ####     return 1;
        #### }
        # Bugzilla 24956 Start
        ten_hl_n10g_config_lof_from_traffic($mod_client, $slice_client, $args{client_traffic_type_enum}, $args{client_fec_enum});
        ten_hl_n10g_config_lom_from_traffic($mod_client, $slice_client, $args{client_traffic_type_enum}, $args{client_fec_enum});
        # Bugzilla 24956 End

        # Set KPASEL = 1
        main::ten_n10g_gblr_set_kpasel($mod_client, $slice_client, 1);  #  KPA input from OxU2 Payload
    }
}
elsif ($args{mode} eq 'wire10') {
        ten_hl_config_10g_wire_t41_v2($mod_line,
                                    $slice_line,
                                    $mod_client,
                                    $slice_client,
                                      $args{dyn_repro},
                                      $args{line_traffic_type_enum},
                                      $args{client_traffic_type_enum});
                                      
        if (($args{client} =~ /otu2/) || ($args{client} =~ /otu1/)) {
          ten_hl_n10g_config_lof_from_traffic ($mod_client, $slice_client, $args{client_traffic_type_enum}, $args{client_fec_enum});
          ten_hl_n10g_config_lom_from_traffic ($mod_client, $slice_client, $args{client_traffic_type_enum}, $args{client_fec_enum});
        }
        if (($args{line} =~ /otu2/) || ($args{line} =~ /otu1/)) {
          ten_hl_n10g_config_lof_from_traffic ($mod_line, $slice_line, $args{line_traffic_type_enum}, $args{line_fec_enum});
          ten_hl_n10g_config_lom_from_traffic ($mod_line, $slice_line, $args{line_traffic_type_enum}, $args{line_fec_enum});
        }                               
}
elsif ($args{mode} eq 'lb10') {
    if ($args{lb_kpga_traffic_type_enum} == TEN_TRAFFIC_TYPE_10GE) {
        ten_hl_config_10ge_xcon_loopback ($args{module_id_lb_kpga},
                                          $args{slice_lb_kpga},
                                          $args{lb_kpga_traffic_type_enum},
                                          $args{dyn_repro},
                                          $sysclk_Mhz_int);
        # Bugzilla 29751 Start
        if ($args{hsif_lb_kpga} ne 'xaui') {
            #################################################################################################################
            # The following code is used to enable the interrupt and register a handler for PCS In Sync                     #
            # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
            #################################################################################################################
            if($enable_intr_flag) {
                # Enable ISR for PCS in sync */
                print("An interrupt hander thread must be running for Elastic Store centering to work\n");
                ten_pp10g_pcs_rx_rxint_handler_enable ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, TEN_PP10G_PCS_RX_RXINT_SYNCDETI);
            }
        }
        # Bugzilla 29751 End
    }
    elsif (($args{lb_kpga} =~ /otu2/) || ($args{lb_kpga} =~ /otu1/)) {
        ten_hl_config_otu2_xcon_loopback ($args{module_id_lb_kpga},
                                          $args{slice_lb_kpga},
                                          $args{lb_kpga_traffic_type_enum},
                                          $args{dyn_repro},
                                          $args{term_otu_enum},
                                          $args{lb_kpga_tcm_bits},
                                          $sysclk_Mhz_int);
        if (ten_hl_config_fec_t41 ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, TEN_SLICE_10G, $args{lb_kpga_fec_enum}) == CS_ERROR) {
            failure("10G FEC Provisioning failed on module $args{module_id_lb_kpga} and slice $args{slice_lb_kpga}\n");
            return 1;
        }
        # Bugzilla 24956 Start
        ten_hl_n10g_config_lof_from_traffic($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{lb_kpga_traffic_type_enum}, $args{lb_kpga_fec_enum});
        ten_hl_n10g_config_lom_from_traffic($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{lb_kpga_traffic_type_enum}, $args{lb_kpga_fec_enum});
        # Bugzilla 24956 End

        # Set KPASEL = 1
        main::ten_n10g_gblr_set_kpasel ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, 1);  # KPA input from OxU2 payload

        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame               #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for OTN In Frame */
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n10g_otnr_intr_handler_enable ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, TEN_N10G_OTNR_INTR_IIF); # Bugzilla 29751
    }
    elsif ($args{lb_kpga_traffic_type_enum} == TEN_TRAFFIC_TYPE_OC192) {
        my $oc192_term = 1;

        if ($args{term} eq 'trans') {
          $oc192_term = main::TEN_OC192_TERM_TRANSPARENT_CBR10;
        }
        elsif ($args{term} eq 'transregen') {
          $oc192_term = main::TEN_OC192_TERM_TRANSPARENT_REGENERATOR;
        }
        elsif ($args{term} eq 'rsregen') {
          $oc192_term = main::TEN_OC192_TERM_RS_LAYER_REGENERATOR;
        }
        elsif ($args{term} eq 'msregen') {
          $oc192_term = main::TEN_OC192_TERM_MS_LAYER_REGENERATOR;
        }

        if (ten_hl_config_oc192_xcon_loopback ($args{module_id_lb_kpga},
                                               $args{slice_lb_kpga},
                                               $args{lb_kpga_traffic_type_enum},
                                               $args{dyn_repro},
                                               $oc192_term)){
            failure("ten_hl_config_oc192_xcon_loopback() failed!\n");
            return 1;
        }

        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for Sonet Loss Of Frame             #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for Sonet Loss Of Frame
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n10g_sdfr_sdfist_handler_enable ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, TEN_N10G_SDFR_SDFIST_LOF);  # Bugzilla 29751
   }
}
elsif ($args{mode} eq 'lb40') {
    if ($args{lb_kpga} =~ /otu3/) {
        # Bugzilla 28977 Start
        if (ten_hl_config_otu3v_xcon_loopback_t41_v2 ($args{module_id_lb_kpga},
                                                      $args{dyn_repro},
                                                      $args{lb_kpga_traffic_type_enum},
                                                      $args{lb_kpga_fec_enum},
                                                      $args{term_otu_enum},
                                                      $args{lb_kpga_tcm_bits},
                                                      $args{mld_lb_kpga_enabled},
                                                      $args{deskew_ctrl}) != CS_OK) {
            failure("ten_hl_config_otu3v_xcon_loopback_t41_v2() Failed!!!!\n");
            return 1;
        }
        # Bugzilla 28977 End

        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame               #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for OTN Out Of Frame
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n40g_otnr4x_intr_handler_enable ($args{module_id_lb_kpga}, TEN_N40G_OTNR4X_INTR_IIF); # Bugzilla 29751
    }
    elsif ($args{lb_kpga} eq 'oc768') {
        # Bugzilla 28977 Start
        if (ten_hl_config_oc768_xcon_loopback_t41_v2 ($args{module_id_lb_kpga},
                                                      $args{dyn_repro},
                                                      $args{lb_kpga_traffic_type_enum},
                                                      $args{oc_term_enum},
                                                      $args{mld_lb_kpga_enabled},
                                                      $args{deskew_ctrl}) != CS_OK) {
            failure("ten_hl_config_oc768_xcon_loopback_t41()_v2 Failed!!!!\n");
            return 1;
        }
        # Bugzilla 28977 End

        #################################################################################################################
        # The following code is used to enable the interrupt and register a handler for Sonet Loss Of Frame             #
        # This code should not be used in the Autogen scripts because customers will handle interrupts in their own way #
        #################################################################################################################
        # Enable ISR for Sonet Out Of Frame
        print("An interrupt hander thread must be running for Elastic Store centering to work\n");
        ten_n40g_sdfr_sdfist_handler_enable ($args{module_id_lb_kpga}, TEN_N40G_SDFR_SDFIST_OOF); # Bugzilla 29751
    }
}
elsif ($args{mode} eq 'kpga10') {
    if ($args{lb_kpga} eq 'oc192_otu2') {
        ten_hl_config_oc192_otu2_kpga ($args{module_id_lb_kpga},
                                       $args{slice_lb_kpga},
                                       $args{lb_kpga_traffic_type_enum},
                                       $args{dyn_repro},
                                       $args{kpga_pattern_enum});
        if (ten_hl_config_fec_t41 ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, TEN_SLICE_10G, $args{lb_kpga_fec_enum}) == CS_ERROR) {
            failure("10G FEC Provisioning failed on module $args{module_id_lb_kpga} and slice $args{slice_lb_kpga}\n");
            return 1;
        }
        # Bugzilla 24956 Start
        ten_hl_n10g_config_lof_from_traffic ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{lb_kpga_traffic_type_enum}, $args{lb_kpga_fec_enum});
        ten_hl_n10g_config_lom_from_traffic ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{lb_kpga_traffic_type_enum}, $args{lb_kpga_fec_enum});
        # Bugzilla 24956 End
    }
    elsif (($args{lb_kpga} =~ /otu2/) || ($args{lb_kpga} =~ /otu1/) || ($args{lb_kpga} eq 'cbr_1118099736') || ($args{lb_kpga} eq 'cbr_1052329163')) {
        ten_hl_config_otu2_kpga ($args{module_id_lb_kpga},
                                 $args{slice_lb_kpga},
                                 $args{lb_kpga_traffic_type_enum},
                                 $args{dyn_repro},
                                 $args{kpga_pattern_enum}, 1);
        if (ten_hl_config_fec_t41 ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, TEN_SLICE_10G, $args{lb_kpga_fec_enum}) == CS_ERROR) {
            failure("10G FEC Provisioning failed on module $args{module_id_lb_kpga} and slice $args{slice_lb_kpga}\n");
            return 1;
        }
        # Bugzilla 24956 Start
        ten_hl_n10g_config_lof_from_traffic ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{lb_kpga_traffic_type_enum}, $args{lb_kpga_fec_enum});
        ten_hl_n10g_config_lom_from_traffic ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{lb_kpga_traffic_type_enum}, $args{lb_kpga_fec_enum});
        # Bugzilla 24956 End
    }
    elsif ($args{lb_kpga} eq 'oc192') {
        ten_hl_config_oc192_kpga ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{dyn_repro}, $args{kpga_pattern_enum});
        if (ten_hl_config_fec_t41 ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, TEN_SLICE_10G, $args{lb_kpga_fec_enum}) == CS_ERROR) {
            failure("10G FEC Provisioning failed on module $args{module_id_lb_kpga} and slice $args{slice_lb_kpga}\n");
            return 1;
        }
    }
    else {
      failure("Unsupported KPGA10 mode\n");
      return 1;
    }
}
elsif ($args{mode} eq 'kpga40') {
    if ($args{lb_kpga} eq 'oc768_otu3') {
        ten_hl_config_oc768_otu3v_kpga_t41 ($args{module_id_lb_kpga},
                                            #$args{lb_kpga_traffic_type_enum},
                                            TEN_TRAFFIC_TYPE_OTU3,
                                            $args{lb_kpga_fec_enum},
                                            $args{kpga_pattern_enum},
                                            $args{mld_lb_kpga_enabled},
                                            1);
    }
    elsif ($args{lb_kpga} =~ /otu3/) {
        if (ten_hl_config_otu3v_kpga_t41 ($args{module_id_lb_kpga},
                                          $args{lb_kpga_traffic_type_enum},
                                          $args{lb_kpga_fec_enum},
                                          $args{kpga_pattern_enum},
                                          $args{mld_lb_kpga_enabled}, #MLD
                                          1) == CS_ERROR) {
            failure("ten_hl_config_otu3v_kpga_t41() Failed!!!!\n");
            return 1;
        }
    }
    elsif ($args{lb_kpga} eq 'oc768') {
        ten_hl_config_oc768_kpga_t41 ($args{module_id_lb_kpga}, $args{kpga_pattern_enum}, $args{mld_lb_kpga_enabled}, 1);

        # Set external LOS Filter input as active high
        if ($args{module_id_lb_kpga} == $mod_a) {
            ten_glb_misc_xlos_inv_mra ($dev_id, 0x0F);
        } else {
            ten_glb_misc_xlos_inv_mrb ($dev_id, 0x0F);
        }

        # Turn off the XLOS in case there is not an optical module connected
        ten_hsif_set_ok_ctrl($args{module_id_lb_kpga}, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0);
    }
}
elsif ($args{mode} eq 'hsif_kpga10') {
    if ($args{lb_kpga} ne 'invalid') {
        if ($args{hsif_lb_kpga_enum} == TEN_HSIF_PROTOCOL_SFI42_10G) {
          failure("SFI4.2 not supported with HSIF KPGA10 mode!\n");
          return 1;
        }
        ten_hl_config_10g_hsif_kpga ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{hsif_lb_kpga_enum}, 1, $args{hsif_kpga_pattern_enum});
    }

}
elsif ($args{mode} eq 'hsif_kpga40') {
    if ($args{lb_kpga} ne 'invalid') {
        if ($args{hsif_lb_kpga_enum} == TEN_HSIF_PROTOCOL_SFI42_40G) {
          failure("SFI4.2 not supported with HSIF KPGA40 mode!\n");
          return 1;
        }
        ten_hl_config_40g_hsif_kpga ($args{module_id_lb_kpga}, $args{hsif_lb_kpga_enum}, 1, $args{hsif_kpga_pattern_enum});
    }
}
elsif ($args{mode} eq 'cbr_kpga10') {
    ten_hl_config_10g_cbr_kpga_t41 ($args{module_id_lb_kpga},
                                    $args{slice_lb_kpga},
                                    $args{kpga_pattern_enum},
                                    $args{dyn_repro});

}
elsif ($args{mode} eq 'cbr_kpga40') {
    ten_hl_config_40g_cbr_kpga_t41 ($args{module_id_lb_kpga},
                                    $args{kpga_pattern_enum});
}
#elsif ($args{mode} eq 'bpert10') {
#    if ($args{line} ne 'invalid') {
#        ten_hl_config_10g_pbert ($mod_line, $slice_line, $args{line}, $args{dyn_repro}, $sysclk_Mhz_int);
#    } else {
#        ten_hl_config_10g_pbert ($mod_client, $slice_client, $args{client}, $args{dyn_repro}, $sysclk_Mhz_int);
#    }
#}

###############################################################################
# If this is aggregation then null out the other three channels
###############################################################################
if ($args{mode} eq 'mux') {
    if ($args{dyn_repro} == TEN_INITIAL_CONFIG) {
        if ($args{clientrate} != 40) {     # Bugzilla 29100
            foreach my $i (0..3) {
                if ((!defined $slice_client)  || ($i != $slice_client)) {
                    ten_hl_config_aggregation_idle($mod_line, $i, $mod_client, $i);
                }
            }
        }
    }
}

if ($provision_line) {
  if (($args{hsif_line} eq 'xaui') and ($use_xaui_protection_switch_mode == 1)) {
    ten_hsif_set_ok_ctrl($mod_line | TEN_MODULE_B, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0);
  }
  else {
    ten_hsif_set_ok_ctrl($mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0);
  }
}

if ($provision_client) {
  if (($args{hsif_client} eq 'xaui') and ($use_xaui_protection_switch_mode == 1)) {
    ten_hsif_set_ok_ctrl($mod_client | TEN_MODULE_B, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0);
  }
  else {
    ten_hsif_set_ok_ctrl($mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0);
  }
}

###############################################################################
# Configure CLOCKMUX
###############################################################################
# The parameters are dependent on the clock dividers; refer to the API documentation and data sheet
# Switch clocking mux to normal datapath

my $rx_rdiv; my $rx_ctvdiv; my $tx_rdiv; my $tx_ctvdiv; my $tx_ctrdiv; my $fortyg_cupll;

if ($provision_client) {
    if ($args{clientrate} == 40) {
    # Client 40G  
        if (ten_dev_is_t41($dev_id) and ($args{hsif_client} eq 'xfi')) {
            for (my $ch = 0; $ch < 4; $ch++) {
                # For 40G CUPLL applications, only slice 2 should be provisioned CUPLL;
                $fortyg_cupll = ($ch == 2) ? (2 * $client_cupll) : 0;
                if ($args{client_port} >= 4) {
                    # XFI 40G client
                    if ($args{mode} eq 'hsif_kpga40') {
                        # module, slice, aux_clk, k_value, stxp_pilot_sel, cupll_in_use
                        ten_hl_xfi_config_clockmux_t41($mod_client, $ch, $args{auxclk}, $k, 1, $fortyg_cupll);
                    }
                    else {
                        if ($args{xfi_clock_distribution} || ($client_cupll==1)) {
                          # module, slice, aux_clk, k_value, stxp_pilot_sel, cupll_in_use
                          ten_hl_xfi_config_clockmux_t41($mod_client, $ch, $args{auxclk}, $k, 1, $fortyg_cupll);
                        }
                        else {
                          # module, slice, aux_clk, k_value, stxp_pilot_sel, cupll_in_use
                          ten_hl_xfi_config_clockmux_t41($mod_client, $ch, $args{auxclk}, $k, 1, $fortyg_cupll);
                        }
                    }
                }
            }
        }
        elsif (ten_dev_is_t41($dev_id) and ($args{hsif_client} eq 'cfp_mr')) {
            ten_hl_cfp_config_clockmux($mod_client, TEN_SLICE_ALL, 0);
        }
        else {
            ten_hl_mr_40g_config_clockmux($mod_client);
        }
        ten_mpif_clock_select_gpll_in ($dev_id, $mod_num_client, TEN_SLICE_ALL, CS_TX, 0);   # Bugzilla 30856
        ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_client);
    }
    else {
        # 10G Client Port
            if ($args{hsif_client} eq 'xfi') {
            if ($args{client_port} >= 4) {
                # XFI 10G clients
                # module, slice, aux_clk, k_value, stxp_pilot_sel, cupll_in_use
                ten_hl_xfi_config_clockmux_t41($mod_client, $slice_client, $args{auxclk}, $k, 1, $client_cupll);
            }
        }
        elsif ($args{hsif_client} eq 'sfi4_1') {
            # Set reference to RXPLL to RXCLKIN
            if ($args{client_port} < 4) {
              # Client is on Side A
              ten_mpif_set_clock_switch_force($dev_id, TEN_MODULE_A, $args{client_port}, CS_RX, CS_DISABLE);
            }
            else {
              # Client is on Side B
              ten_mpif_set_clock_switch_force($dev_id, TEN_MODULE_B, $args{client_port}%4, CS_RX, CS_DISABLE);
            }
            for (my $ch = 1; $ch < 4; $ch++) {
                main::ten_hl_hsif_mr_switch_clock ($mod_client, $ch);
            }
        }
        elsif (ten_dev_is_t41($dev_id) and ($args{hsif_client} eq 'cfp_mr')) {
               # CFP MR 10G
               ten_hl_cfp_config_clockmux($mod_client, $slice_client, 0);
               if (!ten_dev_is_ws_in_progress($dev_id) and ($args{dyn_repro} == TEN_INITIAL_CONFIG)) {
                 tb_ical(3,2);
               }
        }
        else {
            if (($args{hsif_client} eq 'xaui') and ($use_xaui_protection_switch_mode == 1)) {
              ten_hl_mr_config_clockmux($mod_client | TEN_MODULE_B, $slice_client);
            }
            else {
              ten_hl_mr_config_clockmux($mod_client, $slice_client);
            }
        }
    }
    ten_mpif_clock_select_gpll_in ($dev_id, $mod_num_client, $slice_client, CS_TX, 0);  # Bugzilla 30856
    ten_hl_gpllx1_waitfor_gpll_lock($dev_id, $gpllx1_inst_client + $slice_client);
}

if ($provision_line) {
    # Configure CLOCKMUX for MR interfaces
    if ($args{linerate} == 40) {
        if ((ten_dev_is_t41($dev_id)) and ($args{hsif_line} eq 'xfi')) {
            for (my $ch = 0; $ch < 4; $ch++) {
                # For 40G CUPLL applications, only slice 2 should be provisioned CUPLL;
                $fortyg_cupll = ($ch == 2) ? (2 * $line_cupll) : 0;
                if ($args{line_port} >= 4) {
                    if (($args{sync} == 0) && ($args{mode} ne 'kpga40') && ($args{mode} ne 'hsif_kpga40') && ($args{mode} ne 'cbr_kpga40')) {
                        # Force $k =64 because syncdsync on tx side was forced to k_value = 64
                        # module, slice, aux_clk, k_value, stxp_pilot_sel, cupll_in_use
                        ten_hl_xfi_config_clockmux_t41($mod_b, $ch, $args{auxclk}, 64, 1, $fortyg_cupll);
                    }
                    else {
                      if ($args{xfi_clock_distribution} || ($line_cupll==1)) {
                        # module, slice, aux_clk, k_value, stxp_pilot_sel, cupll_in_use
                        ten_hl_xfi_config_clockmux_t41($mod_b, $ch, $args{auxclk}, $k, 1, $fortyg_cupll);
                        }
                      else {
                        # module, slice, aux_clk, k_value, stxp_pilot_sel, cupll_in_use
                        ten_hl_xfi_config_clockmux_t41($mod_b, $ch, $args{auxclk}, $k, 5, $fortyg_cupll);
                    }
                        }
                }
            }
        }
        elsif ((ten_dev_is_t41($dev_id)) and ($args{hsif_line} eq 'cfp_mr')) {
            ten_hl_cfp_config_clockmux($mod_line, TEN_SLICE_ALL, 0);
        }
        else {
            ten_hl_mr_40g_config_clockmux($mod_line);
        }
        ten_mpif_clock_select_gpll_in( $dev_id, $mod_num_line, TEN_SLICE_ALL, CS_TX, 0x0 );  # Bugzilla 30856
        ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_line);
    }
    else {
        # 10G traffic
        if ($args{hsif_line} eq 'xfi') {
            if ($args{line_port} >= 4) {
                if (($args{sync} == 0) && ($args{mode} ne 'kpga10') && ($args{mode} ne 'hsif_kpga10') && ($args{mode} ne 'cbr_kpga10')) {
                    # Force $k =64 because syncdsync on tx side was forced to k_value = 64
                    ten_hl_xfi_config_clockmux_t41($mod_b, $slice_line, $args{auxclk}, 64, 1, $line_cupll);
                }
                else {
                    ten_hl_xfi_config_clockmux_t41($mod_b, $slice_line, $args{auxclk}, $k, 1, $line_cupll);
                }
                    # XFI 10G line
            }
        }
        elsif ($args{hsif_line} eq 'sfi4_1') {
            #ten_hl_hsif_mr_switch_clock($mod_line, $slice_line);
            # Set reference to RXPLL to RXCLKIN
            if ($args{line_port} < 4) {
              ten_mpif_set_clock_switch_force($dev_id, TEN_MODULE_A, $args{line_port}, CS_RX, CS_DISABLE);
            }
            else {
              ten_mpif_set_clock_switch_force($dev_id, TEN_MODULE_B, $args{line_port}%4, CS_RX, CS_DISABLE);
            }
            for (my $ch = 1; $ch < 4; $ch++) {
                main::ten_hl_hsif_mr_switch_clock ($mod_line, $ch);
            }
        }
        elsif (ten_dev_is_t41($dev_id) and ($args{hsif_line} eq 'cfp_mr')) {
            ten_hl_cfp_config_clockmux($mod_line, $slice_line, 0);
            if (!ten_dev_is_ws_in_progress($dev_id) and ($args{dyn_repro} == TEN_INITIAL_CONFIG)) {
              tb_ical(3,2);
            }
        }
        else {
            if (($args{hsif_line} eq 'xaui') and ($use_xaui_protection_switch_mode == 1)) {
              ten_hl_mr_config_clockmux($mod_line | TEN_MODULE_B, $slice_line);
            }
            else {
                ten_hl_mr_config_clockmux($mod_line, $slice_line);
            }
        }
        ten_mpif_clock_select_gpll_in($dev_id, $mod_num_line, $slice_line, CS_TX, 0);  # Bugzilla 30856
        ten_hl_gpllx1_waitfor_gpll_lock($dev_id, $gpllx1_inst_line + $slice_line);
    }
}

if ($args{client} ne 'null') {
    #if ($args{line} ne 'invalid') {
    if ($provision_line and ($args{line_port} >= 4)) {
        my $gpllx1_inst = ($mod_num_line == TEN_MODULE_A) ? 1 : 9;  # Bugzilla 30856
        ten_hl_gpllx1_waitfor_gpll_lock($dev_id, $gpllx1_inst + $slice_line);
        #ten_hl_gpllx1_waitfor_gpll_lock($dev_id, $gpllx1_inst_line + $slice_line);
    }

    if ($args{client} ne 'invalid') {
        my $gpllx1_inst = ($mod_num_client == TEN_MODULE_A) ? 1 : 9;  # Bugzilla 30856
        ten_hl_gpllx1_waitfor_gpll_lock($dev_id, $gpllx1_inst + $slice_client);
        #ten_hl_gpllx1_waitfor_gpll_lock($dev_id, $gpllx1_inst_client + $slice_client);
    }
}

##############################################################################
# Bug 24820 fc_ra_fc: return line type to original argument so otn framing is ignored
##############################################################################
if ($config_is_fc_ra_fc) {
  $args{line} = $args{client};
}


# Passive monitoring
if (($args{mode} eq 'wire10') && ($args{monitor} == 1)) {
  ten_hl_config_passive_monitor($mod_line, $slice_line, $mod_client, $slice_client, $args{client_traffic_type_enum});
}


##############################################################################
# New facility for running custimizations before releaseing reset, Bug 27063
##############################################################################

if ($args{read} ne 'none') {
    open FIN, $args{read} or die "Can't open $args{read} for reading";
    print "\n"."="x80 ."\n";
    print "= Begin evaluation of custom configs in file $args{read}\n";
    print '='x80 ."\n";
    while (<FIN>) {
        eval;
    }   # end while
    close FIN;
    print '='x37 ." Done ". '='x37 ."\n\n";
}



###############################################################################
# Remove SW resets
###############################################################################
if($args{hold_in_reset} == 0) {
    if (($args{mode} eq 'trans40') || ($args{mode} eq 'wire40')) {
        config_release_reset_trans40_wire40($dev_id, $mod_line, $mod_client, $args{client},
                                            $args{client_fec}, $args{sync},
                                            $provision_line, $provision_client, $gpllx1_inst_line, $gpllx1_inst_client, $args{term},       # Bugzilla 29609
                                            $args{hsif_client}, $args{hsif_line}, $args{deskew_ctrl}, $args{xcon_client_type}); # Bugzilla 28006
    }
    elsif (($args{mode} eq 'lb40') || ($args{mode} eq 'kpga40') || ($args{mode} eq 'cbr_kpga40')) {
        config_release_reset_lb40_kpga40($dev_id, $args{module_id_lb_kpga}, $args{lb_kpga}, $args{mode},
                                         $gpllx1_inst_lb_kpga, $gpllx1_inst_lb_kpga, $args{hsif_lb_kpga}, $args{deskew_ctrl}); # Bugzilla 28977
    }
    elsif (($args{mode} eq 'lb10') || ($args{mode} eq 'kpga10') || ($args{mode} eq 'cbr_kpga10')) {
        config_release_reset_lb10_kpga10($dev_id, $args{module_id_lb_kpga}, $args{slice_lb_kpga},
                                         $args{lb_kpga_traffic_type_enum}, $args{notest}, $args{hsif_lb_kpga});
    }
    elsif ($args{mode} eq 'hsif_kpga40') {
        config_release_reset_hsif_kpga40($dev_id, $args{module_id_lb_kpga}, $gpllx1_inst_lb_kpga, $args{hsif_lb_kpga});
    }
    elsif ($args{mode} eq 'hsif_kpga10') {
        config_release_reset_hsif_kpga10($dev_id, $args{module_id_lb_kpga}, $args{slice_lb_kpga},
                                         $args{notest}, $args{hsif_lb_kpga});
    }
    elsif(($args{mode} eq 'mux') && ($args{clientrate} == 40)) {
        config_release_reset_otu3v_odtu_otu3v($dev_id, $mod_line, $mod_client, $args{client},
                                              $args{client_fec}, $args{sync},
                                              $provision_line, $gpllx1_inst_line, $gpllx1_inst_client, $args{term},
                                              $args{hsif_client});
    }
    elsif ($args{client} ne 'null') {
        config_release_reset_traffic($dev_id, $mod_line, $mod_client, $slice_line, $slice_client,
                                     $provision_line, $provision_client, $args{hsif_line}, $args{linerate},
                                     $args{clientrate}, $args{client_traffic_type_enum},
                                     $aggregation, $args{notest}, $args{mode},
                                     $line_cupll, $client_cupll, $slice_line_cupll, $slice_client_cupll);
    }
}
else {
    print("Chip is held in soft reset\n");
    print("Use config_release_reset_<trans40_wire40 |
                                     lb40_kpga40    |
                                     lb10_kpga10    |
                                     hsif_kpga10    |
                                     hsif_kpga40    |
                                     traffic>          function to remove reset\n");
    return 0;
}


    ############################################################
    #####   Provision GPLL for line_int path in loopback   #####
    ############################################################
    if($sfi41_ufec_alloc) {
        my $gpll_inst_override_rx = 0;
        my $gpll_inst_override_tx = 0;

        if($mod_line_int == 0) { 
            ten_mpif_global_clock_disable_mr_a($dev_id, $slice_line_int, CS_TX_AND_RX, 1);
        }
        else {
            ten_mpif_global_clock_disable_mr_b($dev_id, $slice_line_int, CS_TX_AND_RX, 1);
        }

        if ($mod_line_int < 4) {
            $gpllx1_inst_line = 1;  # GPLL 1
        } else {
            $gpllx1_inst_line = 9;  # GPLL 9
        }

        $gpll_inst_override_rx = $gpllx1_inst_line+$slice_line_int;
        $gpll_inst_override_tx = $gpllx1_inst_line+4+$slice_line_int;

        ten_hl_gpllx1_init($dev_id, $gpll_inst_override_rx, $args{hsif_line_enum}, 0);
        ten_hl_gpllx1_init($dev_id, $gpll_inst_override_tx, $args{hsif_line_enum}, 0);
        
        ten_hl_hsif_control_loopback ($mod_line_int, 
                                      $slice_line_int, 
                                      TEN_HSIF_LOOPBACK_FAR_END, 
                                      1); 

        # Setup GPLL line to RXDIV client, and divider to 128
        ten_mpif_clock_select_int_rxdiv($dev_id,
                                        $mod_line_int,
                                        $slice_line_int,
                                        CS_TX_AND_RX,
                                        1);

        ten_gpllx1_set_stxp0_tx_clkdiv_rdiv_ctrl($dev_id, 
                                                 $gpll_inst_override_rx, 
                                                 12);        
        ten_gpllx1_set_stxp0_tx_clkdiv_rdiv_ctrl($dev_id, 
                                                 $gpll_inst_override_tx, 
                                                 12);

        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_rx,1);
        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_rx,0);
        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_tx,1);
        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_tx,0);
    }
    
    ##############################################################
    #####   Provision GPLL for client_int path in loopback   #####
    ##############################################################
    if($sfi41_ufec_alloc) {
        my $gpll_inst_override_rx = 0;
        my $gpll_inst_override_tx = 0;

        if($mod_client_int == 0) { 
            ten_mpif_global_clock_disable_mr_a($dev_id, $slice_client_int, CS_TX_AND_RX, 1);
        }
        else {
            ten_mpif_global_clock_disable_mr_b($dev_id, $slice_client_int, CS_TX_AND_RX, 1);
        }

        if ($mod_client_int < 4) {
            $gpllx1_inst_client = 1;  # GPLL 1
        } else {
            $gpllx1_inst_client = 9;  # GPLL 9
        }

        $gpll_inst_override_rx = $gpllx1_inst_client+$slice_client_int;
        $gpll_inst_override_tx = $gpllx1_inst_client+4+$slice_client_int;

        ten_hl_gpllx1_init($dev_id, $gpll_inst_override_rx, $args{hsif_line_enum}, 0);
        ten_hl_gpllx1_init($dev_id, $gpll_inst_override_tx, $args{hsif_line_enum}, 0);

        ten_hl_hsif_control_loopback ($mod_client_int, 
                                      $slice_client_int, 
                                      TEN_HSIF_LOOPBACK_FAR_END, 
                                      1); 

        # Setup GPLL line to RXDIV client, and divider to 128
        ten_mpif_clock_select_int_rxdiv($dev_id,
                                        $mod_client_int,
                                        $slice_client_int,
                                        CS_TX_AND_RX,
                                        1);

        ten_gpllx1_set_stxp0_tx_clkdiv_rdiv_ctrl($dev_id, 
                                                 $gpll_inst_override_rx, 
                                                 12);        
        ten_gpllx1_set_stxp0_tx_clkdiv_rdiv_ctrl($dev_id, 
                                                 $gpll_inst_override_tx, 
                                                 12);

        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_rx,1);
        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_rx,0);
        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_tx,1);
        ten_gpllx1_set_txvco0_init($dev_id, $gpll_inst_override_tx,0);
    }
    
    if($sfi41_ufec_alloc) {
        main::ten_hl_config_remove_soft_resets($mod_line_int, $slice_line_int, $mod_client_int, $slice_client_int,
                                               $args{client_traffic_type_enum},,
                                               $aggregation);
    }

#print ("Start Sedeco N40G Deskew error handler polling\n");
#ten_sadeco_n40g_deskew_error_handler_enable ($mod_line);
#ten_sadeco_n40g_deskew_error_handler_enable ($mod_client);

# print ("Start HSIF error handlers polling\n");
# ten_dlos_recovery_error_handler_enable ($mod_client, $slice_client);
# ten_lof_recovery_error_handler_enable ($mod_client, $slice_client);
# ten_pcs_recovery_error_handler_enable ($mod_client, $slice_client);

#print ("\nProvisioning complete\n");

###############################################################################
# These are checking functions to validate the connections
###############################################################################

# For debugging the SFI-4.2 Standard deskew issues
# if (($args{hsif_A} eq 'sfi4_2') and $aggregation) {
#     check_hsif_skew(5, 0, $args{eds});
# }

# Apply Client Side HSIF loopbacks if enabled
if ($args{client_hsif_loopback} != TEN_HSIF_LOOPBACK_NONE ) {
  if ($args{clientrate} == 40) {
    ten_hl_hsif_control_loopback($mod_client, TEN_SLICE_ALL, $args{client_hsif_loopback}, CS_ENABLE);
  }
  else {
    ten_hl_hsif_control_loopback($mod_client, $slice_client, $args{client_hsif_loopback}, CS_ENABLE);
  }
}

# Apply Line Side HSIF loopbacks if enabled
if ($args{line_hsif_loopback} != TEN_HSIF_LOOPBACK_NONE) {
 if ($args{linerate} == 40) {
    ten_hl_hsif_control_loopback($mod_line, TEN_SLICE_ALL, $args{line_hsif_loopback}, CS_ENABLE);
  }
  else {
    ten_hl_hsif_control_loopback($mod_line, $slice_line, $args{line_hsif_loopback}, CS_ENABLE);
  }
}

# Initialize pbert_40g if requested
if (($args{pbert_40g_test} eq 'line') ||
    ($args{pbert_40g_test} eq 'loop_fe')) {
    print     "\nEnabling line-side pbert_40g\n";
    ten_print("\nEnabling line-side pbert_40g\n");
    # Initialize pbert_40g:  Random-sized packets (default),  Min length 0x0040 (default),  Max length 0x05ee (default)
    # Typelen LSB=1,  Typelen MSB=6,  IFG=5, eth_da=unicast (default)
    main::ten_hl_config_40g_pbert_t41($mod_line, main::XCON_UNIT_LEN_RANDOM, 0x0040, 0x05ee, 1, 6, 5, 0);
    main::ten_pp40g_pbert_control_generator_t41($mod_line, CS_ENABLE);
}
if (($args{pbert_40g_test} eq 'client') ||
    ($args{pbert_40g_test} eq 'loop_fe')) {
    print     "\nEnabling client-side pbert_40g\n";
    ten_print("\nEnabling client-side pbert_40g\n");
    # Initialize pbert_40g:  Random-sized packets (default),  Min length 0x0040 (default),  Max length 0x05ee (default)
    # Typelen LSB=1,  Typelen MSB=6,  IFG=5, eth_da=unicast (default)
    main::ten_hl_config_40g_pbert_t41($mod_client, main::XCON_UNIT_LEN_RANDOM, 0x0040, 0x05ee, 1, 6, 5, 0);
    main::ten_pp40g_pbert_control_generator_t41($mod_client, CS_ENABLE);
}

# Enable far-end loopbacks if requested
if ($args{pbert_40g_test} eq 'loop_fe') {
  print     "\nEnabling far end loopbacks for pbert_40g_test\n";
  ten_print("\nEnabling far end loopbacks for pbert_40g_test\n");
  ten_hl_hsif_control_loopback (TEN_MODULE_A, TEN_SLICE_ALL, TEN_HSIF_LOOPBACK_FAR_END, CS_ENABLE);
  ten_hl_hsif_control_loopback (TEN_MODULE_B, TEN_SLICE_ALL, TEN_HSIF_LOOPBACK_FAR_END, CS_ENABLE);
}

my $bus_error_cnt;

if ($args{notest} == 0) {
    if (check_all($mod_line, $slice_line, $mod_client, $slice_client, $aggregation, 
                  $mod_client_int, $slice_client_int, $sfi41_ufec_alloc, %args)) {
        failure("check_all failed");
        $bus_error_cnt = ten_dev_get_bus_error_count($dev_id);
        if ($bus_error_cnt != 0) {
          print "($bus_error_cnt bus errors)\n";
          ten_print("($bus_error_cnt bus errors)\n");
        }
        
        if ($collect_driver_log) {
          ten_drvr_stop_output_to_file( );
        }
        client_dump_on();
        return 1;
    }
}

print "\nScript PASSED";
ten_print("Script PASSED");

$bus_error_cnt = ten_dev_get_bus_error_count($dev_id);
if ($bus_error_cnt != 0) {
  print " ($bus_error_cnt bus errors)";
  ten_print(" ($bus_error_cnt bus errors)");
}
print "\n";
ten_print("\n");

if ($collect_driver_log) {
  ten_drvr_stop_output_to_file( );
}

# Now that configuration is complete, tell apish to start printing to the client screen,
# for interactive use of stats, debugging, etc.
client_dump_on();

return 0;
