#/***********************************************************************/
#/* This file contains information proprietary to Cortina Systems, Inc. */
#/* (Cortina). Any use or disclosure, in whole or in part, of this      */
#/* information to any unauthorized party, for any purposes other than  */
#/* that for which it is provided is expressly prohibited except as     */
#/* authorized by Cortina in writing. Cortina reserves its rights to    */
#/* pursue both civil and criminal penalties for copying or disclosure  */
#/* of this material without authorization. Cortina Systems (R),        */
#/* Cortina (TM) and the Cortina Systems Earth Logo are the trademarks  */
#/* or registered trademarks of Cortina Systems, Inc. and its           */
#/* subsidiaries in the U.S. and other countries. Any other product     */
#/* and company names are the trademarks of their respective owners.    */
#/* Copyright (C) 2006-2011 Cortina Systems, Inc. All rights reserved.  */
#/***********************************************************************/
#
# Makefile common sections for building target of TENABO
#
# $Id: Makefile,v 1.5 2012/02/15 22:42:45 jccarlis Exp $
#

export CHIP     =    TENABO
CHIPROOT        =    $(shell pwd)
include Makefile.common

##############################################################
# Local makefile options
##############################################################

TARGET          =    $(BUILDDIR)/tenabo.a
OBJS            =    $(BUILDDIR)/ten_*.o

###########################################
# building target
###########################################
default: all


#all: chk_reg_chg

t41_registers.h:

# add stuff here
all: t41_registers.h $(CSPLATFORMDIR)/makebuilddir
	$(CSPLATFORMDIR)/makebuilddir $(BUILDDIR)
	$(MAKE) -e -C $(TENMODULEDIR)/debug
	$(MAKE) -e -C $(TENMODULEDIR)/dm
	$(MAKE) -e -C $(TENMODULEDIR)/fec
	$(MAKE) -e -C $(TENMODULEDIR)/fracdiv
	$(MAKE) -e -C $(TENMODULEDIR)/general
	$(MAKE) -e -C $(TENMODULEDIR)/glb
	$(MAKE) -e -C $(TENMODULEDIR)/gpllx1
	$(MAKE) -e -C $(TENMODULEDIR)/highlevel
	$(MAKE) -e -C $(TENMODULEDIR)/hl_config
	$(MAKE) -e -C $(TENMODULEDIR)/hsif
	$(MAKE) -e -C $(TENMODULEDIR)/irq
	$(MAKE) -e -C $(TENMODULEDIR)/mpif
	$(MAKE) -e -C $(TENMODULEDIR)/n10g
	$(MAKE) -e -C $(TENMODULEDIR)/n40g
	$(MAKE) -e -C $(TENMODULEDIR)/ohpp
	$(MAKE) -e -C $(TENMODULEDIR)/pp10g
	$(MAKE) -e -C $(TENMODULEDIR)/pp40g
	$(MAKE) -e -C $(TENMODULEDIR)/stats
	$(MAKE) -e -C $(TENMODULEDIR)/syncdsync
	$(MAKE) -e -C $(TENMODULEDIR)/xcon
	$(AR) -r $(TARGET) $(OBJS)
	ls -l $(TARGET)

dynamic: t41_registers.h $(CSPLATFORMDIR)/makebuilddir
	$(CSPLATFORMDIR)/makebuilddir $(BUILDDIR)
	$(MAKE) -e -C $(TENMODULEDIR)/debug
	$(MAKE) -e -C $(TENMODULEDIR)/dm
	$(MAKE) -e -C $(TENMODULEDIR)/fec
	$(MAKE) -e -C $(TENMODULEDIR)/fracdiv
	$(MAKE) -e -C $(TENMODULEDIR)/general
	$(MAKE) -e -C $(TENMODULEDIR)/glb
	$(MAKE) -e -C $(TENMODULEDIR)/gpllx1
	$(MAKE) -e -C $(TENMODULEDIR)/highlevel
	$(MAKE) -e -C $(TENMODULEDIR)/hl_config
	$(MAKE) -e -C $(TENMODULEDIR)/hsif
	$(MAKE) -e -C $(TENMODULEDIR)/irq
	$(MAKE) -e -C $(TENMODULEDIR)/mpif
	$(MAKE) -e -C $(TENMODULEDIR)/n10g
	$(MAKE) -e -C $(TENMODULEDIR)/n40g
	$(MAKE) -e -C $(TENMODULEDIR)/ohpp
	$(MAKE) -e -C $(TENMODULEDIR)/pp10g
	$(MAKE) -e -C $(TENMODULEDIR)/pp40g
	$(MAKE) -e -C $(TENMODULEDIR)/stats
	$(MAKE) -e -C $(TENMODULEDIR)/syncdsync
	$(MAKE) -e -C $(TENMODULEDIR)/xcon
	$(LD) -o $(BUILDDIR)/libtenabo.so $(OBJS) -shared
	ls -l $(BUILDDIR)/libtenabo.so


clean: cleanall
# currently we're getting this file from the nightly cron job 
# instead of regenerating on the fly, so don't remove it.
#	$(RM) ten_registers.h
#	$(RM) diff.sav
#	rm -Rf html

cleanall:
	$(MAKE) -e -C $(TENMODULEDIR)/fracdiv clean
	$(MAKE) -e -C $(TENMODULEDIR)/debug clean
	$(MAKE) -e -C $(TENMODULEDIR)/dm clean
	$(MAKE) -e -C $(TENMODULEDIR)/general clean
	$(MAKE) -e -C $(TENMODULEDIR)/glb clean
	$(MAKE) -e -C $(TENMODULEDIR)/hsif clean
	$(MAKE) -e -C $(TENMODULEDIR)/gpllx1 clean
	$(MAKE) -e -C $(TENMODULEDIR)/highlevel clean
	$(MAKE) -e -C $(TENMODULEDIR)/hl_config clean
	$(MAKE) -e -C $(TENMODULEDIR)/irq clean
	$(MAKE) -e -C $(TENMODULEDIR)/mpif clean
	$(MAKE) -e -C $(TENMODULEDIR)/n10g clean
	$(MAKE) -e -C $(TENMODULEDIR)/n40g clean
	$(MAKE) -e -C $(TENMODULEDIR)/ohpp clean
	$(MAKE) -e -C $(TENMODULEDIR)/pp10g clean
	$(MAKE) -e -C $(TENMODULEDIR)/pp40g clean
	$(MAKE) -e -C $(TENMODULEDIR)/stats clean
	$(MAKE) -e -C $(TENMODULEDIR)/syncdsync clean
	$(MAKE) -e -C $(TENMODULEDIR)/xcon clean
	$(RM) $(OBJS)
	$(RM) $(TARGET)


