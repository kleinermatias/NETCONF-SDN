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
# Makefile for building general directory
#
# $Id: Makefile,v 1.3 2011/03/04 19:39:11 rsinglet Exp $
#

##############################################################
# The following 3 lines must be defined for each bar Makefile
##############################################################
CHIP            =    TENABO
CHIPROOT        =    $(shell cd ../..; pwd)
include $(CHIPROOT)/Makefile.common

##############################################################
# Local makefile options
##############################################################

CFLAGS += 

# put the SRCS searching path here like PATH1:PATH1
VPATH           = $(TENGENERALDIR):$(CSPLATFORMDIR)

# put the dependant header files here
##Moved to makefile.common
##HDRS            =    cs_types.h \
##                     cs_rtos.h \
##		     $(wildcard *.h)

INC            +=    -I.

# put all the source files here (without dir part)
SRCS            =    $(wildcard *.c)
OBJS            =    $(SRCS:%.c=$(BUILDDIR)/%.o)


###########################################
# building target
###########################################
target: platform $(OBJS)

platform:
	$(CSPLATFORMDIR)/makebuilddir $(BUILDDIR)

$(BUILDDIR)/%.o : %.c $(HDRS)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

