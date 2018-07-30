/***********************************************************************/
/* This file contains information proprietary to Cortina Systems, Inc. */
/* (Cortina). Any use or disclosure, in whole or in part, of this      */
/* information to any unauthorized party, for any purposes other than  */
/* that for which it is provided is expressly prohibited except as     */
/* authorized by Cortina in writing. Cortina reserves its rights to    */
/* pursue both civil and criminal penalties for copying or disclosure  */
/* of this material without authorization. Cortina Systems (R),        */
/* Cortina (TM) and the Cortina Systems Earth Logo are the trademarks  */
/* or registered trademarks of Cortina Systems, Inc. and its           */
/* subsidiaries in the U.S. and other countries. Any other product     */
/* and company names are the trademarks of their respective owners.    */
/* Copyright (C) 2006-2013 Cortina Systems, Inc. All rights reserved.  */
/***********************************************************************/
/*
 * ten_main.c 
 *
 * $Id: ten_main.c,v 1.4 2013/02/22 20:48:25 jccarlis Exp $
 *
 * Memory Model Main Test Bench for T40 Driver.  
 * This file is for demonstration and preliminary testing purposes only.
 *
 */

#include "tenabo40.h"

#ifdef MAKE_STANDALONE_TESTBENCH

/* Declare 2 instances of T40 chips in memory,              */
/* but using only Chip 1, not Chip 0 in this example for    */
/* better testing of offset/indexing conditions.            */

T41_t Chips[2];
void print_status(cs_status status);

int t40_testbench_main(void)
{
  cs_uint16 dev_id1;
  cs_uint16 module_id_b;
  cs_uint16 module_id_a; 
  
  printf("\nT40 TestBench\n\n");
  
  module_id_a = TEN_INVALID_MODULE_ID;
  module_id_b = TEN_INVALID_MODULE_ID;
  Chips[1].mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
  Chips[1].mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;

  /* First, the driver must be loaded.  */
  print_status(ten_drvr_load());

  /* Now the driver is ready to receive some driver-level APIs.  */
  /* Show the statistics in hex format */
  ten_drvr_ctl_stats_hex_format(1);
  ten_drvr_print_summary();

  /* Register a chip (device 1) with its base address.  */
  dev_id1 = 1;
  print_status(ten_dev_register(dev_id1, (cs_uint32)&Chips[1]));
  
  /* Initialize the device. */
  print_status(ten_dev_main_init(dev_id1));

  /* Now the driver is ready to receive some device-level APIs.  */
  printf("Device Chip Id = %08X\n", ten_mpif_get_chip_jtag_id(dev_id1));
  
  print_status(ten_mpif_scratch_pad2(dev_id1, 0xAA55));
  printf("Read scratchpad = %04X\n", ten_mpif_read_scratch_pad2(dev_id1));

  /* Initialize one side of the chip, Module A.          */
  /* Need to save the "id" or "handle" that is returned  */
  /* in order to call subsequent module-level APIs.      */
  module_id_a = ten_mod_main_init(dev_id1, TEN_MODULE_A);
  if (module_id_a == TEN_INVALID_MODULE_ID)
  {
    printf("Error opening module.\n");
    return (-1);
  }

  /* Initialize the other side of the chip, Module B. */
  module_id_b = ten_mod_main_init(dev_id1, TEN_MODULE_B);
  if (module_id_b == TEN_INVALID_MODULE_ID)
  {
    printf("Error opening module.\n");
    return (-1);
  }
  
  /* Now the driver is ready to receive some module-level APIs */
  /* Must use the previously-saved module "id" or "handle"     */
  /* The handle contains information about device and module.  */
  
  ten_drvr_print_summary();
  
  ten_dev_dump_cb(dev_id1);
  ten_mod_dump_cb(module_id_a);
  ten_mod_dump_cb(module_id_b);
  
  print_status(ten_dev_print_cfg(dev_id1));
  print_status(ten_dev_print_status(dev_id1));
  print_status(ten_mod_print_cfg(module_id_a));
  print_status(ten_mod_print_status(module_id_a));
  print_status(ten_mod_print_cfg(module_id_b));
  print_status(ten_mod_print_status(module_id_b));
  
  /* Now ready to receive APISH/Perl Configuration Scripts... */

  /* print out the full device statistics */
  printf("Full Chip Statistics Dump\n");
  /* print_status(ten_dev_print_stats(dev_id1));
  ten_mod_print_stats(module_id_a);
  ten_mod_print_stats(module_id_b); */
  
  /* To unload driver and release memory:  */                                         
  /* Clean up, first unload Module A and B */
  print_status(ten_mod_close(module_id_a));
  print_status(ten_mod_close(module_id_b));
  
  /* Unregister the device */
  print_status(ten_dev_unregister(dev_id1));
  
  /* Finally, unload the driver, all memory malloc'd by the driver is released */
  print_status(ten_drvr_unload());

  return (0);
}

void print_status(cs_status status)
{
  if (status == CS_OK)
  {
    printf("CS_OK\n");
  }
  else
  {
    printf(">>>> CS_ERROR\n");
  }
}
#endif

