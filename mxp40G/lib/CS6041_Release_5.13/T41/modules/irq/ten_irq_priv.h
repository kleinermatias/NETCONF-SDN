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
 * ten_irq_priv.h
 *
 * $Id: ten_irq_priv.h,v 1.5 2013/02/22 20:44:29 jccarlis Exp $
 *
 * THIS FILE CONTAINS IRQ API FOR PRIVATE USE.
 *
 */
#ifndef __TEN_IRQ_PRIV_H__
#define __TEN_IRQ_PRIV_H__

/* Including the code that prints out interrupt register and bit-field names is optional due to
 * the amount of memory all of the strings will take. The following define will enable or disable
 * the inclusion of the printing code and data structures.
 * Set to '1' to include the code and structures
 * Set to '0' to NOT include them
 */
#define TEN_IRQ_PRINT_INTERRUPTS 1

#define TEN_IRQ_RET_IF_ERROR(f, c) { if ((f) != CS_OK) return (c); }

/******************************************************************************
 * Interrupt Tree Data Structures
 * These structs define the interrupt tree so that interrupts can be
 * enabled/disabled from any node up and/or down the tree. It implements a
 * double-linked-list of interrupt nodes.
 * Every node in the interrupt hierarchy needs the following information:
 *   - The address of the interrupt register (ireg)
 *   - The address of the interrupt enable register (ereg)
 *   - The number of slices of this register (slices)
 *   - The stride between slices (stride)
 *   - The bits of the enable register that is used to enable interrupts (mask)
 *   - Each bit in a node can point to another child node, so for each bit
 *     the child node needs to be identified, for walking down the tree (children)
 *   - To walk up the tree, each slice of a node can point to either
 *     - Different bits in the same parent register
 *     - The same bit in different slices of the same parent register
 *     - Different bits in different parent registers
 *     'parents' holds a pointer to the parent nodes
 *   - To enable/disable interrupt up the tree the enable bits in the
 *     parent register must be known. This can be different for each slice.
 ******************************************************************************/
/* A pointer to an interrupt node */
typedef struct ten_irq_node_s *ten_irq_node_ptr;

/* An interrupt node has children (up to 16)
   Register bit 0 is array element 0 */
typedef struct ten_irq_node_children_s {
    ten_irq_node_ptr child;
    cs_uint8         slice;
} ten_irq_node_child_t;

/* An interrupt node can have multiple children (1 for each slice) */
typedef ten_irq_node_child_t ten_irq_node_children_t[];

/* An interrupt's parent is a node associated with a mask */
typedef struct ten_irq_node_parent_s {
    ten_irq_node_ptr parent;
    cs_uint16        mask;
} ten_irq_node_parent_t;

/* An interrupt node can have multiple parents (1 for each slice) */
typedef ten_irq_node_parent_t ten_irq_node_parents_t[];

/* This is the structure that gets passed to an interrupt handler */
typedef struct ten_irq_handler_data_s {
    cs_uint16                dev_id;
    ten_irq_node_ptr         node;
    cs_uint16                ireg_data;
    cs_uint16                ereg_data;
    cs_uint16                sreg_data;     /* Will be 0 when there is no status register for a node */
    cs_uint8                 slice;
} ten_irq_handler_data_t;

/* This is a registerable interrupt handler */
typedef void (*ten_irq_handler_t)(ten_irq_handler_data_t);

/* An interrupt node */
/* This struct can't be a const because the 'handler' field will be modified whan an interrupt handler is registered */
typedef struct ten_irq_node_s {
    cs_uint32                ireg;
    cs_uint32                ereg;
    cs_uint32                sreg;
    cs_uint16                slices;
    cs_uint16                stride;
    cs_uint8                 num_children;
    cs_uint16                mask;
    ten_irq_node_children_t *children;
    ten_irq_node_parents_t  *parents;
    ten_irq_handler_t        handler;
#if TEN_IRQ_PRINT_INTERRUPTS
    char                    *name;
    cs_uint8                 last_child;        /* Defines the size of the variable-length array below */
/* To save a little bit of memory, this statement can be changed to the following
 * in a newer compiler (gcc 3+)
    char                    *child_name[];
 */
    char                    *child_name[16];
#endif
} ten_irq_node_t;

#endif /* __TEN_IRQ_PRIV_H__ */

