# Clock programming for Cortina Systems CS6001 EVBs

use strict;
use warnings FATAL => qw(all); # Promote hidden apish eval warnings to errors

package config_clocks;

use clocks;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);
$VERSION = '1.0';
require Exporter;
@ISA = qw(Exporter);
@EXPORT = qw(
    tb_init tb_reset tb_ical tb_ical_40g tb_program_clock tb_set_sys_clock  tb_set_mbclksel tb_get_mbclksel
    set_mainboard_clock download_clock $FPGA_SYS_ID
    get_clocking_profile %line_cupllProfileCB %client_cupllProfileCB
    $MAXLOWRANGEREF %sysclocks sysclocksStr
);

our $FPGA_SYS_ID = 432;
# Valid T41 reference clock frequencies
# Low Range (hi x 4) 77.76-106.25MHZ
# High Range        311.04-425.00MHZ

# system clock defs
our $MAXLOWRANGEREF = eval(435_000_000 / 4); # 108 and change MHz
# This table expands rate names into Hz
our %sysclocks = (
    '77.76'      =>  77_760_000,  # 77.76 MHz
    '88.86'      =>  88_868_500,  # 88.8685715 MHz TriRate CFP
    '90.4'       =>  90_400_000,  # 90.4 MHz
    '90.59'      =>  90_590_400,  # 90.5904 MHz
    '100'        => 100_000_000,  # 100 MHz
    '106.25'     => 106_250_000,  # 106.25 MHz
    '311.04'     => 311_040_000,  # 311.04 MHz
    '325'        => 325_000_000,  # 325 MHz
    '344.66'     => 334_660_000,  # 334.66 MHz
    '350'        => 350_000_000,  # 350 MHz
    '355.47'     => 355_474_000,  # 355.474286 MHz
    '360'        => 360_000_000,  # 360 MHz
    '375'        => 375_000_000,  # 375 MHz
    '384.00'     => 384_000_000,  # 384 MHz
    '384'        => 384_092_000,  # 384.092 MHz
    '384.09'     => 384_092_000,  # 384.092 MHz
    '388.8'      => 388_800_000,  # 388.8 MHZ
    '400'        => 400_000_000,  # 400 MHz
    '410'        => 410_000_000,  # 410 MHz
    '425'        => 425_000_000,  # 425 MHz
    '435'        => 435_000_000,  # 435 MHz (over clocked)
);
# Returns a string of valid arguments, e.g., "< 88.86 | 100 |....| 425 >"
# To look good in help text, wraps every approx 59 chars, adds a 30-space indent
sub sysclocksStr($)
{
    my %temp_;  # string sort of keys puts 88 after 100, so append a zero to each key as needed.
    foreach my $key (keys %sysclocks) {
      $key =~ s/^([0-9]{2}(\.[0-9]{1,4})?)$/0$1/;    # left-pad 2-digit mhzs with a zero
      $temp_{$key} = '';
    }

    my $for_ = shift;                                # 'help' or 'error'
    my $validArgsStr = "";
    if ($for_ eq 'help') {                          # wrap and indent
      $validArgsStr .= "Use  88.86 for 88.8685715 MHz\n" . " "x 30 if exists($sysclocks{ 88.86});
      $validArgsStr .= "Use 355.47 for 355.474286 MHz\n" . " "x 30 if exists($sysclocks{355.47});
      $validArgsStr .= "Use 384.00 for 384.000000 MHz\n" . " "x 30 if exists($sysclocks{384.00});
      $validArgsStr .= "Use 384.09 or 384 for 384.092000 MHz\n"
                                                         . " "x 30 if exists($sysclocks{384.09}) and exists($sysclocks{384});
    }
    $validArgsStr .= "<";
    # Wrap for help display. This hash specifies multi-line string length ranges where newlines should
    # be inserted. There is no look-ahead to see if the next 'word' will fit.
    my %wrapat = (int( (52 + 0*(52+30))/9 ) => '',  # Wrap on or after column 82, designed for
                  int( (52 + 1*(52+30))/9 ) => '',  #    9 char 'words', e.g. " 123.45 |".
                  int( (52 + 2*(52+30))/9 ) => '',
                  int( (52 + 3*(52+30))/9 ) => '',
                  int( (52 + 4*(52+30))/9 ) => '',
                 );
    foreach my $key (sort keys %temp_) {
      $key =~ s/^0//;                               # strip off leading zero after sort.
      $validArgsStr .= " $key |";
      if ($for_ eq 'help') {                        # wrap and indent
        $validArgsStr .= "\n" . " "x 31 if exists( $wrapat{ int(length($validArgsStr)/9) } );
      }
    }
    $validArgsStr =~ s/\|$/>/;
    return $validArgsStr;
}


# This routine allows you to program the clock based on calculated divider values
# Assumes we are programming a single output clock, and assuming local timing for now
sub tb_program_clock {
    my ($module, $clk, $clk_src, $interface_type, $n1_hs, $n1_ls, $n2_hs, $n2_ls, $n3, $bwsel) = @_;
    my %addr_map = (
      0 => 0x14,
      1 => 0xe4,
      4 => 0x12, # manual clock selection
      5 => 0xed,
      6 => 0x2d,
      7 => 0x2a,
      8 => 0x00,
      9 => 0xc0,
     10 => 0x00,
     11 => 0x40,
     16 => 0x00,
     17 => 0x80,
     18 => 0x00,
     19 => 0x2c,
     20 => 0x3e,
     21 => 0xfe, # CKSEL_PIN=0 (CS_CA ignored)
     22 => 0xdf,
     23 => 0x1f,
     24 => 0x3f,
     55 => 0x00,
    131 => 0x1f,
    132 => 0x02,
    138 => 0x0f,
    139 => 0xff,
    142 => 0x00,
    143 => 0x00,
    );
	
    if (main::ten_dev_is_ws_in_progress ( 0 )) {
	  printf("warm start in progress.\n");
	  return;
    }
	
	if ((main::t40fpga_clock_module_get ( 432, $module, $clk)) ==0x0182) {
      # it is si5324, change the bwsel
      print "detect si5324\n";
      if ($bwsel>5) {
        $bwsel=$bwsel-5;
      } else {
        $bwsel=1;
      }
      #$addr_map{137}=0x1;
    }

    print "bwsel=$bwsel\n";
    $addr_map{2}  = ($bwsel<<4) + 2;
    print "aftershift: $addr_map{2}\n";
    my $clk_type = ($clk_src == 2) ? 'fixed' : 'rdiv';
    if ($clk_src == 1) {
      $addr_map{3} = 0x05;
    } elsif ($clk_src == 2) {
      $addr_map{3} = 0x45;
    } else {
      die("Invalid clock source specified: $clk_src <1,2>");
    }

    $addr_map{25} = ($n1_hs-4)<<5;

    $addr_map{31} = (($n1_ls-1)>>16) & 0x0f;
    $addr_map{32} = (($n1_ls-1)>>8)  & 0xff;
    $addr_map{33} =  ($n1_ls-1)      & 0xff;

    $addr_map{34} = (($n1_ls-1)>>16) & 0x0f;
    $addr_map{35} = (($n1_ls-1)>>8)  & 0xff;
    $addr_map{36} =  ($n1_ls-1)      & 0xff;
    if (($interface_type eq 'sfi4_1') && ($module == main::TEN_MODULE_B) and ($clk == 1)){
        # Configure clock fo SFI4.1 optical interface (devide clock 2 output by 4) SFI4.1 can only be on first slice of either module
        printf ("tb_program_clock()  Setup Module %d clock #%d for SFI4.1\n", $module, $clk);
        printf ("tb_program_clock()  addr_map{36} was 0x%02X%02X%02X\n", $addr_map{34}, $addr_map{35}, $addr_map{36});
        $addr_map{36} = ($addr_map{36} << 2) | 3  & 0xff;
        printf "tb_program_clock()  addr_map{36} is now 0x%02X%02X%02X\n", $addr_map{34}, $addr_map{35}, $addr_map{36};
    }

    $addr_map{40} = (($n2_hs-4)<<5) + ((($n2_ls-1)>>16) & 0x0f);
    $addr_map{41} = (($n2_ls-1)>>8)  & 0xff;
    $addr_map{42} =  ($n2_ls-1)      & 0xff;

    $addr_map{43} = (($n3-1)>>16) & 0x07;
    $addr_map{44} = (($n3-1)>>8)  & 0xff;
    $addr_map{45} =  ($n3-1)      & 0xff;

    $addr_map{46} = (($n3-1)>>16) & 0x07;
    $addr_map{47} = (($n3-1)>>8)  & 0xff;
    $addr_map{48} =  ($n3-1)      & 0xff;

    main::t40fpga_clock_module_enable($FPGA_SYS_ID, $module, $clk, 1);

    my $addr;

    print "tb_program_clock: Directly programming silabs: module=$module, clk=$clk, clk_type=$clk_type, $n1_hs, $n1_ls, $n2_hs, $n2_ls, $n3, $bwsel\n";
    main::ten_print("********************************************");
    main::ten_print("Directly Programming SiLabs");
    main::ten_print("Module: $module  Clock: $clk  Type: $clk_type");
    main::ten_print("");
    main::ten_print("  N1_HS: $n1_hs  N1_LS: $n1_ls");
    main::ten_print("  N2_HS: $n2_hs  N2_LS: $n2_ls");
    main::ten_print("  N3   : $n3  BWSEL: $bwsel");
    main::ten_print("********************************************");

    foreach $addr (sort { $a <=> $b } keys %addr_map) {
      my $hexval = sprintf("%x",$addr_map{$addr});
      if (main::t40fpga_clock_module_download($FPGA_SYS_ID, $module, $clk, $addr, $addr_map{$addr}) != main::CS_OK) {
        die("t40fpga_clock_module_download failed");
      }
    }

    # force init after configuration change
    if (main::t40fpga_clock_module_download($FPGA_SYS_ID, $module, $clk, 136, 0x40) != main::CS_OK) {
        die("t40fpga_clock_module_download failed");
    }

}

# Returns '1' on success
sub download_clock {
    my ($module, $clk, $clockfile) = @_;
    $clockfile =~ s/sfi42_40g/sfi42/;
    $clockfile =~ s/sfi42_10g/sfi42/;
    my $line;
    # This is for RTP
    unless (-e $clockfile) {
        $clockfile =~ s|^clocks|/proj/software/t41/clocks|;
    }
    # This is for Ottawa
    unless (-e $clockfile) {
        $clockfile =~ s|^clocks|/home/rsinglet/t41/clocks|;
    }
    if (open(FH, $clockfile)) {
        print "download_clock: $module, $clk, $clockfile\n";
        while (<FH>) {
            tr/\r\n//d;
            if (/\#/) {
                # print "$_\n";
            } else {
                my ($addr, $data);
                s/ //g;
                if (/0x/) {
                    ($addr, $data) = split ',';
                    $addr = hex($addr);
                    $data = hex($data);
                }
                else {
                    s/h//g;
                    ($addr, $data) = split ',';
                    $data = hex("0x" . $data);
                }
                if (main::t40fpga_clock_module_download($FPGA_SYS_ID, $module, $clk, $addr, $data) != main::CS_OK) {
                    die("t40fpga_clock_module_download failed");
                }
            }
        }
        close(FH);
        return 1;
    }
    print "Could not open $clockfile: '$!'\n";
    return 0;
}

##############################################################################
#
# Function:      tb_ical
#
# toggle ical bit in Silab
#
# Parameters:
#
# -silab  <onboard|module_a|module_b>
#
# -ch     <aux0:0 aux1:1 sys:2|0-3>
##############################################################################
## sub tb_ical {
##     my ($module, $ch)=@_;
##     my $cmdreg = $module ? 0x3000 : 0x2000;
##     my $ctlreg = $module ? 0x3001 : 0x2001;
##
##                                     printf("tb_ical()  module = $module, ch = $ch\n");
##                                     printf("FPGA_SYS_ID = $FPGA_SYS_ID\n");
##                                     printf("cmdreg = $cmdreg\n");
##                                     printf("ctlreg = $ctlreg\n");
##                                     wait_enter_key();
##
##     #main::dev_reg_write($FPGA_SYS_ID, 0, $cmdreg, 0x80d0 + $ch * 0x4);
##     main::dev_reg_write($FPGA_SYS_ID, 0, $cmdreg, 0x80d0 + $ch * 0x2);
##     main::dev_reg_write($FPGA_SYS_ID, 0, $cmdreg, 0x0088);
##     main::dev_reg_write($FPGA_SYS_ID, 0, $cmdreg, 0x4140);
##     main::dev_reg_write($FPGA_SYS_ID, 0, $ctlreg, 0x0001);
## }


sub tb_ical {
  my ($module, $ch) = @_;

#   return;

#   my $port_sel     = ($module == 0) ? 0x0001 : 0x0003;
#   my $chipsel_addr = ($module == 0) ? 0x1000 : 0x1800;
#   my $base_addr = 0x2000;

  my $dev_addr;
  if    ($ch == 0) { $dev_addr = 0x68; }
  elsif ($ch == 1) { $dev_addr = 0x6c; }  # Channels 1 and 2 are swapped
  elsif ($ch == 2) { $dev_addr = 0x6a; }
  elsif ($ch == 3) { $dev_addr = 0x6e; }

  my $base_addr;
  my $port_sel;
  my $chipsel_addr;
  
  $base_addr = 0x2000;
  $port_sel = 1;
  $chipsel_addr = 0x1000;
  
  $module &= 0xFF;
  
  if ($module == 0) {
      $base_addr = 0x2000;
      $port_sel = 1;
      $chipsel_addr = 0x1000;
  }
  elsif ($module == 1) {
      $base_addr = 0x2000;
      $port_sel = 3;
      $chipsel_addr = 0x1800;
  }
  elsif ($module == 3) {
      $base_addr = 0x5400;
      $port_sel = 0;
      $chipsel_addr = 0x6400;
  }
  elsif ($module == 4) {
      $base_addr = 0x4c00;
      $port_sel = $ch + 1;
      $dev_addr = 0x68;
      $chipsel_addr = 0x4800;   # Is different from the others
  }
  else {
      printf("module not 0-4.\n");
  }

  printf("tb_ical: module %d channel %d port_sel %d base_addr 0x%04X dev_addr 0x%02X\n",
    $module, $ch, $port_sel, $base_addr, $dev_addr);
  # Steer I2C to correct Silabs chip
#   main::dev_reg_write ($FPGA_SYS_ID, 0, 0x2004, $port_sel);
  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr + 4, $port_sel);

  # select proper device on port
#   main::dev_reg_write ($FPGA_SYS_ID, 0, $chipsel_addr, $ch);
  main::dev_reg_write ($FPGA_SYS_ID, 0, $chipsel_addr, $ch) if $module < 4;

  # write_i2c_register() functionality
  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr, ( 0x8000 | ($dev_addr << 1)));
  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr, 136);
  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr, (0x4100 | 0x40));
  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr + 1, 0x0001);

}


###sub tb_ical {
###  my ($module, $ch) = @_;
###
###  my $port_sel     = ($module == 0) ? 0x0001 : 0x0003;
###  my $chipsel_addr = ($module == 0) ? 0x1000 : 0x1800;
###  my $base_addr = 0x2000;
###
###  my $dev_addr;
###  if    ($ch == 0) { $dev_addr = 0x68; }
###  elsif ($ch == 1) { $dev_addr = 0x6c; }  # Channels 1 and 2 are swapped
###  elsif ($ch == 2) { $dev_addr = 0x6a; }
###  elsif ($ch == 3) { $dev_addr = 0x6e; }
###
###  printf("tb_ical, mod=%d, ch=%d\n", $module, $ch);
###  
###  # Steer I2C to correct Silabs chip
###  main::dev_reg_write ($FPGA_SYS_ID, 0, 0x2004, $port_sel);
###
###  # select proper device on port
###  main::dev_reg_write ($FPGA_SYS_ID, 0, $chipsel_addr, $ch);
###
###  # write_i2c_register() functionality
###  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr, ( 0x8000 | ($dev_addr << 1)));
###  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr, 136);
###  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr, (0x4100 | 0x40));
###  main::dev_reg_write ($FPGA_SYS_ID, 0, $base_addr+1, 0x0001);
###
###}
###
sub tb_ical_40g {
    my $module = shift;
    for (my $clock=0; $clock<=3; $clock++) {
        tb_ical($module, $clock);
    }
}

#### not used
####sub tb_ical_all {
####    for (my $module=0; $module<=1; $module++) {
####        tb_ical_40g($module);
####    }
####}

sub tb_init {
    my $sysclk_freq = shift;

	if (!main::ten_dev_is_ws_in_progress(0)) {

		# Reset the FPGA
		main::cb_ibb_reset($FPGA_SYS_ID, 1);
		sleep 1;
		main::cb_ibb_reset($FPGA_SYS_ID, 0);
		sleep 2;
   }

    printf("Set board system clock reference to $sysclk_freq\n");
    my $mbclksel;
    ($sysclk_freq, $mbclksel) = tb_set_sys_clock($sysclk_freq); # if freq was given in low range, now its x4

	if (main::ten_dev_is_ws_in_progress(0)) {
	  return ($sysclk_freq, $mbclksel);
    }
	
    printf("Populate board inventory\n");
    if (main::t40fpga_inventory() != main::CS_OK) { die "t40fpga_inventory failed\n"; }

    # Disable all silabs clocks
    for (my $i=0; $i<2; $i++) {
        for (my $j=0; $j<4; $j++) {
            main::t40fpga_clock_module_enable($FPGA_SYS_ID, $i, 1<<$j, 0);
        }
    }
    my $ceb = main::t40fpga_get_board_type($FPGA_SYS_ID) == 8;
    if ($ceb) {
        for (my $j=0; $j<4; $j++) {
            main::t40fpga_clock_module_enable($FPGA_SYS_ID, 3, 1<<$j, 0);
        }
    }

    # reset the clock board for both A and B
    main::dev_reg_write($FPGA_SYS_ID, 0, 0x1001, 0x0ff);
    main::dev_reg_write($FPGA_SYS_ID, 0, 0x1801, 0x0ff);
    main::dev_reg_write($FPGA_SYS_ID, 0, 0x6401, 0x0ff) if $ceb;
    sleep 2;
    main::dev_reg_write($FPGA_SYS_ID, 0, 0x1001, 0xf00);
    main::dev_reg_write($FPGA_SYS_ID, 0, 0x1801, 0xf00);
    main::dev_reg_write($FPGA_SYS_ID, 0, 0x6401, 0xf00) if $ceb;

    # my $devid = main::ten_mpif_get_chip_jtag_id(0);
    # print "devid: $devid\n";
    # if ($devid == 0x100843e5) {
        # $is6004=1;
    # }
    return ($sysclk_freq, $mbclksel);
}

# Set the system reference clock
sub tb_set_sys_clock {
    my $freq = shift;
    my $module = 2;
    my $clk = 4;

	if (!main::ten_dev_is_ws_in_progress(0)) {
		printf("Assert T40 reset\n");
		if (main::t40fpga_t40_reset($FPGA_SYS_ID, 1) != main::CS_OK) { die "t40fpga_t40_reset (assert) failed\n";}
    }
	
    my $sys_clock_freq = ($freq > $MAXLOWRANGEREF) ? $freq : $freq * 4 ;
    main::ten_print("Set internal system clock frequency to $sys_clock_freq");

	if (!main::ten_dev_is_ws_in_progress(0)) {
      set_mainboard_clock($clk, $freq);
    }
    my $mbclksel = tb_set_mbclksel($freq);

	if (!main::ten_dev_is_ws_in_progress(0)) {
		printf("De-assert T40 reset\n");
		# This function overwrites mbclksel
		if (main::t40fpga_t40_reset($FPGA_SYS_ID, 0) != main::CS_OK) { die "t40fpga_t40_reset (de-assert) failed\n"; }
	#     main::dev_reg_write($FPGA_SYS_ID, 0, 0x3f802, 4 + $mbclksel);
	#     main::dev_reg_write($FPGA_SYS_ID, 0, 0x3f800, 1);
		sleep 2;
	}
    return ($sys_clock_freq, $mbclksel);
}

# Set one of the clocks on the main board (as opposed to one of the clock boards)
sub set_mainboard_clock {
    my ($clk, $freq)=@_;
    my $module = 2;

    printf("Program mainboard CLK: module: $module, clk: $clk, freq: $freq Hz\n");
    my $clockfile = "sysclk_" . "$freq" . ".txt";
#    my $tmp = SV_MODULES;
#    $clockfile =$tmp . "/clocks/$clockfile";
    $clockfile = "clocks/$clockfile";
    download_clock($module, $clk, $clockfile);
}

# This is duplicated w/ config_mbclksel
sub tb_set_mbclksel {
    my $sys_ref_freq = shift;
    my $mbclksel;
    my $fpga_wr_data;

    # MBCLKSEL, FPGA address 3f802 bit 0, 1=400MHz, 0=100MHz
    my $fpga_rd_data = main::dev_reg_read (432, 0, 0x3f802);
    if ($sys_ref_freq > $MAXLOWRANGEREF) {
        $fpga_wr_data = ($fpga_rd_data & 0xffff) | 0x0001 ;
        $mbclksel = 1;
    } else {
        $fpga_wr_data = ($fpga_rd_data & 0xfffe) ;
        $mbclksel = 0;
    }

    if (!main::ten_dev_is_ws_in_progress(0)) {
      main::dev_reg_write (432, 0, 0x3f802, $fpga_wr_data);
	}
    return $mbclksel;
}

sub tb_get_mbclksel {
    my $sys_ref_freq = shift;
    my $mbclksel;
    my $fpga_wr_data;

    # MBCLKSEL, FPGA address 3f802 bit 0, 1=400MHz, 0=100MHz
    my $fpga_rd_data = main::dev_reg_read (432, 0, 0x3f802);
    if ($sys_ref_freq > $MAXLOWRANGEREF) {
        $fpga_wr_data = ($fpga_rd_data & 0xffff) | 0x0001 ;
        $mbclksel = 1;
    } else {
        $fpga_wr_data = ($fpga_rd_data & 0xfffe) ;
        $mbclksel = 0;
    }
    return $mbclksel;
}

sub tb_reset {
    my $sys_ref_freq = shift;

    if (main::t40fpga_t40_reset($FPGA_SYS_ID,1) != main::CS_OK) { die "t40fpga_t40_reset (assert) failed\n"; }
    sleep 2;
    if (main::t40fpga_t40_reset($FPGA_SYS_ID,0) != main::CS_OK) { die "t40fpga_t40_reset (de-assert) failed\n";}
    tb_set_mbclksel($sys_ref_freq);
}




# --------------------------------------------------------------------------------------------------
# global variables for clocking configurations (specifically for cleanup PLL)
# --------------------------------------------------------------------------------------------------
our $line_cupllProfileStr = "";
our %line_cupllProfileCB;
our $client_cupllProfileStr = "";
our %client_cupllProfileCB;

# --------------------------------------------------------------------------------------------------
# subroutine get_clocking_profile()
# --------------------------------------------------------------------------------------------------
sub get_clocking_profile {
    my @profArgNames;
    my @profArgVals;
    my $argsFound  = 0;
    my $argvFound  = 0;
    my $NONE_STR  = "\@\@\@ none \@\@\@";
    my $_cupllProfileStr ="";
    # Optional arguments
    my %optional = (
        'profileId' => 1,
        'profileName' => 1,
        'cupllSysClkSrc' => 1,
        'txClkDist'=> 1,
    );
    my %txClkSource_enum = (
        'fixed'   => main::TX_CLOCK_SOURCE_FIXED   ,  #  /* Tx FracDiv off system GPLL, through clock protection mux.  */
        'rxdiv'   => main::TX_CLOCK_SOURCE_RXDIV   ,  #  /* Recovered/synthesized clock                                */
        'ext_clk' => main::TX_CLOCK_SOURCE_EXT_CLK ,  #  /* Source is external via XFI_TX_CLKREF pin.                  */
        'ext_aux' => main::TX_CLOCK_SOURCE_EXT_AUX ,  #  /* Source is external via XFI_AUX_LPTIME_CLKREF pin.          */
        'pilot'   => main::TX_CLOCK_SOURCE_PILOT   ,  #  /* Fixed source via RX internal pilot, no divider.            */
        'pilotdiv'=> main::TX_CLOCK_SOURCE_PILOTDIV,  #  /* Fixed source via RX internal pilot, divider and protection.*/
        'rxline'  => main::TX_CLOCK_SOURCE_RXLINE  ,  #  /* Fixed source via RX line (MPIF_RXDIV_CFG0:mode=3).         */
    );
    # my $CS2_STRING_OLD = "Id\\s+Name\\s+Type\\s+Val\\s+Source\\s+Source\\s+Freq\\s+Sch";
    my $CS2_STRING_OLD = "Id\\s+Name\\s+Val\\s+Source\\s+Source\\s+Freq\\s+Sch";
    # my $CS2_STRING_NEW = "profileId profileName trafficType kval txClkSource cupllSysClkSrc cupllSysClkFreq txClkDist ";
    my $CS2_STRING_NEW = "profileId profileName kval txClkSource cupllSysClkSrc cupllSysClkFreq txClkDist ";

    # get args
    my $profName   = shift;
    my $profId     = shift;
    # my $trafficType = shift;
    my $kval        = shift;
    my $inFile     = shift;
    my $cupllArgvRef = shift;   # reference to hash to be built, argvs keyed by arg names

    open FIN, $inFile or die "Can't open $inFile for reading";
    while (<FIN>) {
        tr/\r\n//d;
        if (/^\<cn2\>.*/) {          # get parm names

            # Collapse some argument names into single-work mnemonics
            # s/\<cn2\>\s+Id\s+Name\s+Source\s+Source\s+Freq\s+/profileId profileName txClkSource cupllSysClkSrc cupllSysClkFreq /;
            s/\<cn2\>\s+$CS2_STRING_OLD\s+/$CS2_STRING_NEW/;
            s/\s+/ /g;

            # parse argument names out of string, store in order in array @profArgVals
            my $_argnames = $_;
            while ($_argnames =~ /^\s*(\w+)\s+(\w.*)/) {         # store parm names in an array to preserve order
                $_argnames = $2;
                push(@profArgNames, $1);
                $argsFound++;
            }
            if ($_argnames =~ /\s*(\w+)\W*/ ) { push(@profArgNames, $1); $argsFound++;}   # get last argname.
        }

        # Use regexp to match all keys, since won't have access to them by name again until loop has expired.
        # Looking for " <id> ; <name> ; <traffic type> ; <kvalue> ; <don't care>"
        # elsif ( (/^\s+([0-9]{1,3})\s*\;\s+(\w{3,})\s*\;\s+(\w{2,})\s*\;\s+([0-9]{1,3})\s*\;.*$/) and
        elsif ( (/^\s+([0-9]{1,2})\s*\;\s+(\w{2,})\s*\;\s+([0-9]{1,2})\s*\;.*$/) and
                ( ($1 eq $profId) or ($2 eq $profName) )     and
                # (  $3 eq $trafficType )  and ($4 eq $kval ) )  {
                (  $3 eq $kval )  )  {
            last unless $argsFound;

            # parse arg values out of string, store in order in array @profArgVals
            my $_argvals = $_;
            while ($_argvals =~ /\s*(\w*);(\s+.*)$/) {  # looking for " myargval; rest..." or " myargval;"
                $_argvals = $2;
                push(@profArgVals, ( ($1) ? $1 : $NONE_STR) );
                $argvFound++;
            }
            if ($_argvals =~ /\s*(\w+);/ )    { push(@profArgVals, $1);  $argvFound++;}   # get last argv.
            last;
        }
    }   # end while

    close FIN;

    # Check to see if we found argument names and values
    # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  EXIT ON ERROR >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    return "ERROR, get_clocking_profile(): Invalid input file $inFile. Didn't find argument names;" unless $argsFound;
    return "ERROR, get_clocking_profile(): No match found for profile id '$profId', name '$profName'," .
           # " traffic type '$trafficType', kval '$kval' in $inFile;" unless $argvFound;
           " kval '$kval' in $inFile;" unless $argvFound;

    # Validate that we have the right number of argument values.
    if ($argsFound != $argvFound) {
      s/\s+/ /g;
      # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  EXIT ON ERROR >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      return "ERROR, get_clocking_profile(): Number of args \($argsFound\) must match number of values \($argvFound\). \n" .
                   "Input file '$inFile', sought profile '$profId', name '$profName'\n" .
                   "Profile: $_\n";
    }

    # Check for missing register values. They can be missing for some optional arguments.
    my $ii=0;

    # Validation: Missing argv's must be optional.
    foreach (@profArgNames) {
        if ($profArgVals[$ii] eq $NONE_STR) {
            # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  EXIT ON ERROR >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            return "ERROR, get_clocking_profile(): Parameter '$profArgNames[$ii]' has no value. Input file '$inFile', profile '$profId', name '$profName'\n"
                unless exists $optional{$profArgNames[$ii]};
            $profArgVals[$ii] = "";
        }
        if ($profArgNames[$ii] eq 'txClkSource') {
            # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  EXIT ON ERROR >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            return "ERROR, get_clocking_profile(): Unknown txClkSource: '$'. Input file '$inFile', profile '$profId', name '$profName'\n"
                unless exists $txClkSource_enum{$profArgVals[$ii]};
        }
        $ii++;
    }

    # Processing: Replace missing argv flag with empty string, and
    #             Map txClkSource value to an API enumeration
    # Generate two output types: 1) arg list "...;parm;val;..." and 2) hash for API call
    # Print formatted args to screen
    $ii=0;
    my $_clksrcstr = "";
    foreach (@profArgNames) {
        if (${profArgVals[$ii]} eq $NONE_STR) {
            $profArgVals[$ii] = "";
        }
        $_clksrcstr = "";
        if ($profArgNames[$ii] eq 'txClkSource') {
            # convert Tx clock source into an enum
            $_clksrcstr       = $profArgVals[$ii];
            $profArgVals[$ii] = $txClkSource_enum{$profArgVals[$ii]};
            $_clksrcstr      .= "($profArgVals[$ii])";
        }
        $_cupllProfileStr .= "${profArgNames[$ii]}=>" . ( ($_clksrcstr ne "") ? $_clksrcstr : $profArgVals[$ii] ) . ";";
        $cupllArgvRef->{$profArgNames[$ii]} = $profArgVals[$ii];

        #Print in format "    nnnnnnnnnnnnnn : vvvvvvvvvvv"
        # print sprintf("    %-15s : ", ${profArgNames}[$ii]) . ( ($_clksrcstr ne "") ? $_clksrcstr : $profArgVals[$ii] ) . "\n";
        $ii++;
    }
    return ($_cupllProfileStr);
}   # end sub

1;
