##############################################################################
# Pre-calculated syncdsync parameters
##############################################################################

use strict;
use warnings FATAL => qw(all); # Promote hidden apish eval warnings to errors

package syncdsync;

use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);
$VERSION = '1.0';
require Exporter;
@ISA = qw(Exporter);
@EXPORT = qw( get_syncdsync_oxu2 get_syncdsync_oxu3 get_syncdsync_cust_oxu3 );

#   client_line => [ pjo, fs, c15 ]
my %syncdsync_amp_oxu2 = (
    oc192_otu2                   => [ 1, 64, 0 ],
    oc192_otu2e                  => [ 1, 592, 0 ],
    oc192_otu1e                  => [ 1, 531, 0 ],
    oc192_oc192                  => [ 1, 0, 0 ],
    otu2_otu2                    => [ 1, 0, 0 ],
    otu2e_otu2e                  => [ 1, 0, 0 ],
    otu1e_otu1e                  => [ 1, 0, 0 ],
    otu1f_otu1f                  => [ 1, 0, 0 ],
    '8gfc_enh_otu2'              => [ 3, 2278, 0 ],
    '4gfc_enh_otu2'              => [ 2, 8755, 0 ],
    '2gfc_enh_otu2'              => [ 1, 11994, 0 ],
    '1gfc_enh_otu2'              => [ 1, 13613, 0 ],
    # Bugzilla 26608 Start
    '8gfc_enh_otu2e'              => [ 3, 2729, 0 ],
    '4gfc_enh_otu2e'              => [ 2, 8981, 0 ],
    '2gfc_enh_otu2e'              => [ 1, 12106, 0 ],
    '1gfc_enh_otu2e'              => [ 1, 13669, 0 ],
    # Bugzilla 26608 End
    '10gfc_tc_otu2e'             => [ 1, 64, 0 ],
    '10gfc_tc_ra_otu2e'          => [ 1, 64, 0 ],
    '10gfc_tc_g709_otu2e'        => [ 1, 64, 0 ], # Bug 31054
    '10gfc_otu1f'                => [ 1, 0, 0 ],
    '10gewan_otu2'               => [ 1, 64, 0 ],
    '10ge6_1_otu2'               => [ 1, 0, 0 ],
    '10ge6_2_otu2'               => [ 1, 0, 0 ],
    '10ge7_3_otu2'               => [ 1, 0, 0 ],
    '10ge7_1_otu2e'              => [ 1, 64, 0 ],
    '10ge7_2_otu1e'              => [ 1, 0, 0 ],
    '10ge_gfpf_oc192_odu2_otu2'  => [ 1, 64, 0 ],
    '10ge_10ge'                  => [ 1, 0, 0 ],
    'fdr10_iba_fdr10_iba'        => [ 1, 0, 0 ], # Bug 39242
    '10g_iba_10g_iba'            => [ 1, 0, 0 ], # Bug 38565
    '5g_iba_5g_iba'              => [ 1, 0, 0 ], # Bug 38565
    '2_5g_iba_2_5g_iba'          => [ 1, 0, 0 ], # Bug 38565
    '10ge_otu2e'                 => [ 1, 0, 0 ],
    '10ge_ra_otu2'               => [ 1, 0, 0 ],
    '10ge_ra_otu2e'              => [ 1, 64, 0 ],
    '10ge_ra_10ge_ra'            => [ 1, 0, 0 ], # Bugzilla 37022
    '10ge_10gelanxaui'           => [ 1, 0, 0 ],
    '10gelanxaui_10ge'           => [ 1, 0, 0 ],
    '10ge_tc_28blk_5sblk_otu2e'  => [ 4, 463, 0],
    '10ge_tc_28blk_11sblk_otu2e' => [ 3, 478, 0],
    '10ge_tc_32blk_4sblk_otu2e'  => [ 3, 465, 0],
    '10ge_tc_32blk_8sblk_otu2e'  => [ 4, 479, 0],
    '10gfc_10gfc'                => [ 1, 0, 0 ],
    '8gfc_8gfc'                  => [ 1, 0, 0 ],
    '10ge_gfpf_oc192'            => [ 1, 0, 0 ],   # Bugzilla 29991
    'cbr_1118099736_cbr_1118099736' => [1, 0, 0 ],
    'cbr_1052329163_cbr_1052329163' => [1, 0, 0 ],
    '10ge6_1_oc192'                 => [ 1, 0, 0 ],
    '8gfc_otu2'                     => [ 1, 0, 0 ], # Dummy for bmp 8gfc oduflex
    '10g_iba_otu2e'              => [ 4, 522, 0 ], # Bug 39393
    '2gfc_2gfc'                  => [ 1, 0, 0 ], # Bug 39690
    '4gfc_4gfc'                  => [ 1, 0, 0 ], # Bug 39690
    'cpri_4_cpri_4'              => [ 1, 0, 0 ], # Bug 39690
    '1ge_1ge'                    => [ 1, 0, 0 ]  # Bug 39690
);

my %syncdsync_gmp_lo_oxu2 = (
    oc192_otu2               => [ 1, 0, 0 ],
    '8gfc_otu2'              => [ 2, 0, 0 ],
    '4gfc_otu2'              => [ 2, 0, 0 ],
    '2gfc_otu2'              => [ 2, 0, 0 ],
    '2gisc_otu2'             => [ 2, 0, 0 ],
    '1gfc_otu2'              => [ 1, 0, 0 ], # Bug 38871
    '1ge_otu2'               => [ 1, 0, 0 ], # Bug 38871
    # Note - there is really no 2_5g_iba and 5g_iba
    #  Datapath is always run at 10g internally and
    #  we oversample internally for the slower rates
    '2_5g_iba_otu2e'         => [ 3, 0, 0 ],
    '5g_iba_otu2e'           => [ 3, 0, 0 ],
    '10g_iba_otu2e'          => [ 3, 0, 0 ],
    'fdr10_iba_otu2e'        => [ 3, 0, 0 ], # Bug 39242
    '10ge_otu2e'             => [ 3, 0, 0 ], # Bug 39242
    'cpri_4_otu2'              => [ 2, 0, 0 ], # Bugzilla 39690
);

my %syncdsync_gmp_ho_oxu2 = (
);

#   client_line => [ pjo, fs, c15 ]
my %syncdsync_oxu3_amp = (
    odu2_odu3                    => [ 2, 0, 0 ],
    odu2e_otu3                   => [ 2, 0, 0 ],
    odu2_otu3                    => [ 2, 0, 0 ],
    'odu2_otu3+'                 => [ 3, 2121, 0 ],
#    'odu2_otu3+'                => [ 2, 0, 0 ],
    odu2_otu3p2                  => [ 1, 3083, 0 ],
    odu2_otu3e                   => [ 2, 2122, 0 ],
    odu2_otu3e4                  => [ 1, 2326, 0 ],  # Bugzilla 28237
    odu2_otu3e2                  => [ 1, 1875, 0 ], # old rate
    'odu2e_otu3+'                => [ 3, 0, -4 ],
    odu2e_otu3p2                 => [ 3, 992, 0 ],
    odu1e_otu3p2                 => [ 3, 1244, 0 ],
    odu1e_otu3e4                 => [ 3, 462, 0 ],   # Bugzilla 28237
    odu2e_otu3e                  => [ 3, 0, -2 ], # Bugzilla 31347
    # odu2e_otu3e                => [ 2, 0, 0 ],  # Testing GMP !!!!!!!!!!!!!!!
    odu2e_otu3e2                 => [ 3, 15, 0 ],
    odu2e_otu3e4                 => [ 3, 207, 0 ],   # Bugzilla 28237
    otu2ex4_40gep                => [ 1, 0, 0 ],
    oc768_otu3                   => [ 1, 128, 0 ],
    'oc768_otu3+'                => [ 1, 654, 0 ],
    oc768_otu3e                  => [ 1, 654, 0 ],  # otu3e should be treated as otu3e1, invalid as per G.709
    oc768_otu3e2                 => [ 1, 658, 0 ],
    oc768_oc768                  => [ 1, 0, 0 ],

    '40gep_40gep'                => [ 1, 0, 0 ],
    '40ge_tc_otu3'               => [ 4, 11, 0 ],
#    '40gelan_otu3e'              => [ 3, 128, -1 ],
    '40gep_otu3'                 => [ 4, 11, 0 ],
    '40gep_otu3e'                => [ 4, 127, 0 ],      # otu3e should be treated as otu3e1, invalid as per G.709
    '40gep_otu3+'                => [ 4, 126, 0 ],     
    '40gex_otu3+'                => [ 4, 541, 0 ],     # Transcoded  28006
    '40gep_otu3e2'               => [ 4, 175, 0 ],
    '40gep_otu3e4'               => [ 4, 178, 0 ],
    '40gep_otu2ex4'              => [ 1, 0, 0 ],
#    '40gesbi_otu3'               => [ 1, 128, 0 ],     # Will not fit
#    '40gesbi_otu3e'              => [ 1, 128, 0 ],     # otu3e should be treated as otu3e1, invalid as per G.709
    '40gesbi_otu3e2'             => [ 4, 175, 0 ],
#    '40ges6466_otu3'             => [ 1, 128, 0 ],     # Will not fit
#    '40ges6466_otu3e'            => [ 1, 128, 0 ],     # otu3e should be treated as otu3e1, invalid as per G.709
    '40ges6466_otu3+'            => [ 4, 126, 0 ],     
    '40ges6466_otu3e2'           => [ 4, 175, 0 ],
    '40gex_otu3e'                => [ 4, 11, 0 ],       # What is x? For transcode use _tc to be consistent
    '40gex_ra_otu3e'             => [ 4, 11, 0 ],       # otu3e should be treated as otu3e1, invalid as per G.709
    '40gex_otu3'                 => [ 4, 11, 0 ],
    '40gesbi_otu3e1'             => [ 1, 128, 0 ],
    '40ges6466_otu3e1'           => [ 1, 128, 0 ],

    'cbr40g50188149150_otu3e3'   => [ 4, 0, 0 ],
    odu3_otu3                    => [ 1, 128, 0 ],
    'odu3_otu3+'                 => [ 2, 468, 0 ],
    'odu3_otu3e2'                 => [ 2, 468, 0 ],  # dummy  will not work
    otu3_otu3                    => [ 2, 128, 0 ],
    otu3e4_otu3e4                => [ 2, 128, 0 ],
    otu3e_otu3e                  => [ 3, 0, -2 ],
    otu3e3_otu3e3                => [ 4, 0, 0 ],
    otu3p2_otu3p2                => [ 3, 0, 0 ],
    'otu3+_otu3+'                => [ 3, 0, 0 ],

    odu2_otu3p2dj                => [ 1, 3082, 0 ],
    odu2_otu3dj                  => [ 1, 0, 0 ],
    odu2_otu3edj                 => [ 1, 2122, 0 ],
    'otu3_otu3+'                 => [ 2, 468, 0 ],
    otu3e2_otu3e2                => [ 4, 0, 0 ],     # Bugzilla 28979
    'odu2_odu3+'                 => [ 3, 2087, 0 ]
);

my %syncdsync_gmp_lo_oxu3 = (
    oc768_otu3e                  => [ 3, 0, 0 ],  # otu3e should be treated as otu3e1, invalid as per G.709
    oc768_otu3e2                 => [ 3, 0, 0 ],
    oc768_otu3                   => [ 3, 0, 0 ],  # Bugzilla 31435
    odu3_otu3                    => [ 1, 0, 0 ],
    odu3_otu3e                   => [ 1, 0, 0 ],
    odu3_otu3e2                  => [ 3, 0, 0 ],
    '40ge_tc_otu3'               => [ 3, 0, 0 ],
    '40gep_otu3+'                => [ 3, 0, 0 ],
    '40gex_otu3'                 => [ 3, 0, 0 ],  # Bugzilla 28254
    '40gex_otu3+'                => [ 3, 0, 0 ],  # Bugzilla 28254
    '40gex_otu3e'                => [ 3, 0, 0 ],  # Bugzilla 28254
    '40gex_otu3e2'               => [ 3, 0, 0 ],  # Bugzilla 28254
    '40gep_otu3e'                => [ 2, 0, 0 ],
    '40gep_otu3e2'               => [ 3, 0, 0 ],
    '40gesbi_otu3e2'             => [ 3, 0, 0 ],
    '40ges6466_otu3e2'           => [ 3, 0, 0 ],
    '40ges6466_otu3e'            => [ 3, 0, 0 ],
    '40ges6466_otu3'             => [ 3, 0, 0 ],
    '40ges6466_otu3+'            => [ 3, 0, 0 ],
);

my %syncdsync_gmp_ho_oxu3 = (
    odu2_otu3                    => [ 1, 0, 0 ],
    odu2_otu3e                   => [ 1, 0, 0 ],
    odu2_otu3e2                  => [ 1, 0, 0 ],
    odu2_otu3e4                  => [ 1, 0, 0 ],
    odu1e_otu3e                  => [ 1, 0, 0 ],
    odu1e_otu3e2                 => [ 1, 0, 0 ],
    odu1e_otu3e4                 => [ 1, 0, 0 ],    
    odu2e_otu3e                  => [ 1, 0, 0 ],
   'odu2e_otu3+'                 => [ 1, 0, 0 ],
    odu2e_otu3e2                 => [ 2, 0, 0 ],  # Bugzilla 29100
    odu2e_otu3e4                 => [ 2, 0, 0 ],  # Bugzilla 28237
    odu3_otu3                    => [ 1, 0, 0 ],
    'odu3_otu3+'                 => [ 3, 0, 0 ],
    odu3_otu3e                   => [ 3, 0, 0 ],
    odu3_otu3e2                  => [ 3, 0, 0 ],  # Bugzilla 29481
);


sub get_syncdsync_oxu2 {
    my ($client, $line, $map_method) = @_;
    print "get_syncdsync_oxu2: $client, $line, map_method=$map_method\n";
    my $lookup = join '_', $client, $line;
    if($map_method == main::TEN_MAP_GMP_LO) {
        die "get_syncdsync_oxu2: Can't find '$lookup' for TEN_MAP_GMP_LO in the hash" unless exists $syncdsync_gmp_lo_oxu2{$lookup};
        return (@{$syncdsync_gmp_lo_oxu2{$lookup}});
    }
    elsif($map_method == main::TEN_MAP_GMP_HO) {
        die "get_syncdsync_oxu2: Can't find '$lookup' for TEN_MAP_GMP_HO in the hash" unless exists $syncdsync_gmp_ho_oxu2{$lookup};
        return (@{$syncdsync_gmp_ho_oxu2{$lookup}});
    }
    else {
        die "get_syncdsync_oxu2: Can't find '$lookup' in the hash" unless exists $syncdsync_amp_oxu2{$lookup};
        return (@{$syncdsync_amp_oxu2{$lookup}});
    }
}

sub get_syncdsync_oxu3 {
    my ($client, $line, $map_method) = @_;
    print "get_syncdsync_oxu3: $client, $line, map_method=$map_method\n";
    my $lookup = join '_', $client, $line;
    if($map_method == main::TEN_MAP_GMP_LO) {
        die "get_syncdsync_oxu3() Can't find '$lookup' for TEN_MAP_GMP_LO in the hash" unless exists $syncdsync_gmp_lo_oxu3{$lookup};
        return (@{$syncdsync_gmp_lo_oxu3{$lookup}});
    }
    elsif(($map_method == main::TEN_MAP_GMP_HO) || ($map_method == main::TEN_MAP_GMP_HO_DT)) {
        die "get_syncdsync_oxu3() Can't find '$lookup' for TEN_MAP_GMP_HO in the hash" unless exists $syncdsync_gmp_ho_oxu3{$lookup};
        return (@{$syncdsync_gmp_ho_oxu3{$lookup}});
    }
    else {
        die "get_syncdsync_oxu3() Can't find '$lookup' in the hash" unless exists $syncdsync_oxu3_amp{$lookup};
        return (@{$syncdsync_oxu3_amp{$lookup}});
    }
}


1;
