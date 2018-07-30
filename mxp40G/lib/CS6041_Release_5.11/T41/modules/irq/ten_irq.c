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
 * ten_irq.c
 *
 * Interrupt related code is implemented here.
 *
 * $Id: ten_irq.c,v 1.11 2013/02/22 20:44:29 jccarlis Exp $
 *
 */

#include "ten_irq_tree.h"
#include "ten_irq.h"
#include <util.h>

/* This is the top-most interrupt in the tree */
#define TEN_IRQ_TOP TEN_IRQ_NODE_MPIF_GLOBAL_INTERRUPT

#define TEN_IRQ_NO_STATUS 0

/* This is a dummy parent node */
ten_irq_node_parent_t dummy_parent = { 0, 0 };

/* This macro determines whether the address 'x' is within the memory space of the UFEC block */
#define IS_UFEC_ADDRESS(x) ((x >= TEN_UFEC_URX_R1C00) && (x < TEN_N40G_GBL4X_SWRST))


/* exit a function upon detecting invalid device id */
cs_status TEN_INVALID_DEV_EXIT(cs_uint16 dev_id)
{
  cs_uint32 err_code = 0;

  if ( !(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return(CS_ERROR);
  }
  return (CS_OK);
}

/* '1' in enable_bits bit positions will enable the interrupt by writing '1' in those bit positions
 * '1' in disable_bits bit positions will disable the interrupts by writing '0' in those bit positions
 * CS_ERROR will be returned if there are '1' bits in both enable_bits and disable_bits
 * This routine is NOT for sliced interrupts
 */
cs_status ten_dev_irq_enable_disable(cs_uint16 dev_id, ten_irq_node_ptr node, cs_uint16 enable_bits, cs_uint16 disable_bits, ten_irq_tree_dir_t dir)
{
    cs_uint32             enable_reg_addr;
    cs_uint32             enable_reg_data;
    cs_boolean            enable;
    cs_uint16             i;
    ten_irq_node_parent_t parent;
    ten_irq_node_ptr      child;
    cs_status             status;

    TEN_INVALID_DEV_EXIT(dev_id) ;

    if (enable_bits)
        if (disable_bits) return CS_ERROR;
        else enable = TRUE;
    else if (disable_bits) enable = FALSE;
    /* If there are no bits set in either then there's nothing to do */
    else return CS_OK;

    enable_reg_addr = node->ereg;

    /* Operate on all the slices */
    for (i=0; i<node->slices; i++)
    {
        TEN_DEV_LOCK(dev_id, TEN_ID_IRQ);
        enable_reg_data = ten_reg_read(dev_id, enable_reg_addr);
        enable_reg_data |= enable_bits;             /* enable the selected bits */
        enable_reg_data &= ~disable_bits;           /* disable the selected bits */
        enable_reg_data &= node->mask;              /* don't modify unused or reserved bits */
        status = ten_reg_write(dev_id, enable_reg_addr, enable_reg_data);
        TEN_DEV_UNLOCK(dev_id, TEN_ID_IRQ);
        if (status == CS_ERROR)
            return CS_ERROR;
        enable_reg_addr += node->stride;
    }

    /* Recurse up the tree */
    if (node->parents != TEN_IRQ_NODE_NO_NODE)
    {
        /* Slice 0 is used as the parent since this routine isn't for sliced interrupts */
        parent = (*(node->parents))[0];
        if (dir == TEN_IRQ_DIR_UP || dir == TEN_IRQ_DIR_BOTH)
        {
            TEN_IRQ_RET_IF_ERROR(ten_dev_irq_enable_disable(dev_id,
                                                            parent.parent,
                                                            enable ? parent.mask : 0,
                                                            enable ? 0 : parent.mask,
                                                            dir), CS_ERROR);
        }
    }

    /* Recurse down the tree */
    if (node->children != TEN_IRQ_NODE_NO_NODE)
    {
        if (dir == TEN_IRQ_DIR_DOWN || dir == TEN_IRQ_DIR_BOTH)
        {
            for (i=0; i<=15; i++)
            {
                /* Only enable those children whose enable bits are set and disable bits are clear */
                if ((1<<i) & (enable_bits | disable_bits))
                {
                    /* children is a variable-length array; check the index against the length */
                    if (i < node->num_children)
                    {
                        child = (*node->children)[i].child;
                        if (child != TEN_IRQ_NODE_NO_NODE)
                        {
                            TEN_IRQ_RET_IF_ERROR(ten_dev_irq_enable_disable(dev_id,
                                                                            child,
                                                                            enable ? 0xffff : 0,
                                                                            enable ? 0 : 0xffff,
                                                                            dir), CS_ERROR);
                        }
                    }
                }
            }
        }
    }
    return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE DEVICE INTERRUPTS                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_irq_enable(cs_uint16          dev_id,
                             ten_irq_node_ptr   node,
                             cs_uint16          enable_bits,
                             ten_irq_tree_dir_t dir)
/* INPUTS     : o Device ID                                     */
/*              o Pointer to an interrupt node                  */
/*              o Bitmask of the register bits to enable        */
/*              o Direction to enable (up or down the tree)     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables interrupts at the device level (rather than the      */
/* module level). Can be used to enable interrupts in Module A  */
/* or Module B with care; all slices will be enabled when going */
/* down the tree.                                               */
/* The [enable_bits] parameter is specified as:                 */
/*                1 = enable the bit                            */
/*                0 = leave the bit as-is                       */
/* The [dir] parameter is specified as:                         */
/*                TEN_IRQ_DIR_ONLY = 0 enables this node only   */
/*                TEN_IRQ_DIR_UP   = 1 enables this node and up */
/*                                     the tree                 */
/*                TEN_IRQ_DIR_DOWN = 2 enables this node and    */
/*                                     down the tree            */
/*                TEN_IRQ_DIR_BOTH = 3 enables this node and up */
/*                                     and down the tree        */
/* This function is useful for enabling all interrupts in the   */
/* device:                                                      */
/*   ten_dev_irq_enable(dev_id,                                 */
/*     ptr TEN_IRQ_NODE_MPIF_GLOBAL_INTERRUPT,                  */
/*     0xffff, TEN_IRQ_DIR_DOWN)                                */
/* It can also be used to enable individual intermediate or     */
/* leaf nodes without going up or down the tree by setting dir  */
/* to TEN_IRQ_DIR_ONLY.                                         */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    return ten_dev_irq_enable_disable(dev_id, node, enable_bits, 0, dir);
}

/****************************************************************/
/* $rtn_hdr_start  DISABLE DEVICE INTERRUPTS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_irq_disable(cs_uint16          dev_id,
                              ten_irq_node_ptr   node,
                              cs_uint16          disable_bits,
                              ten_irq_tree_dir_t dir)
/* INPUTS     : o Device ID                                     */
/*              o Pointer to an interrupt node                  */
/*              o Bitmask of the register bits to disable       */
/*              o Direction to disable (up or down the tree)    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Disables interrupts at the device level (rather than the     */
/* module level). Can be used to disable interrupts in Module A */
/* or Module B with care; all slices will be disabled when      */
/* going down the tree.                                         */
/* The [disable_bits] parameter is specified as:                */
/*                1 = disable the bit                           */
/*                0 = leave the bit as-is                       */
/* The [dir] parameter is specified as:                         */
/*                TEN_IRQ_DIR_ONLY = 0 disables this node only  */
/*                TEN_IRQ_DIR_UP   = 1 disables this node and   */
/*                                     up the tree              */
/*                TEN_IRQ_DIR_DOWN = 2 disables this node and   */
/*                                     down the tree            */
/*                TEN_IRQ_DIR_BOTH = 3 disables this node and   */
/*                                     up and down the tree     */
/* This function is useful for disabling all interrupts in the  */
/* device:                                                      */
/*   ten_dev_irq_disable(dev_id,                                */
/*     ptr TEN_IRQ_NODE_MPIF_GLOBAL_INTERRUPT,                  */
/*     0xffff, TEN_IRQ_DIR_DOWN)                                */
/* It can also be used to disable individual intermediate or    */
/* leaf nodes without going up or down the tree by setting dir  */
/* to TEN_IRQ_DIR_ONLY.                                         */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    return ten_dev_irq_enable_disable(dev_id, node, 0, disable_bits, dir);
}

/* Bugzilla 18209 Start */
/* Clear interrupts down the tree, whether they're enabled or not */
cs_status ten_dev_irq_clear_node(cs_uint16 dev_id, ten_irq_node_ptr node)
{
    cs_uint16             i, data;
    ten_irq_node_ptr      child;
    cs_uint32             reg_addr;

    TEN_INVALID_DEV_EXIT(dev_id) ;

    reg_addr = node->ireg;

    /* Operate on all the slices
       This will hit each slice multiple times but it's easier to implement this way
       and consumes less space */
    for (i=0; i<node->slices; i++)
    {
        TEN_DEV_LOCK(dev_id, TEN_ID_IRQ);
        data = ten_reg_read(dev_id, reg_addr);
        ten_reg_write(dev_id, reg_addr, data);
        JUST_LOG_2(LOG_INFO, "T41","ten_dev_irq_clear: Clearing 0x%05X: %s\n", reg_addr, node->name);
        TEN_DEV_UNLOCK(dev_id, TEN_ID_IRQ);
        reg_addr += node->stride;
    }

    /* Recurse down the tree */
    if (node->children != TEN_IRQ_NODE_NO_NODE)
    {
        for (i=0; i<=15; i++)
        {
            /* children is a variable-length array; check the index against the length */
            if (i < node->num_children)
            {
                child = (*node->children)[i].child;
                if (child != TEN_IRQ_NODE_NO_NODE)
                {
                    TEN_IRQ_RET_IF_ERROR(ten_dev_irq_clear_node(dev_id, child), CS_ERROR);
                }
            }
        }
    }
    return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  DISABLE DEVICE INTERRUPTS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_irq_clear(cs_uint16 dev_id)
/* INPUTS     : o Device ID                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Clear all interrupts in the device.                          */
/* This function will walk the interrupt tree and clear all     */
/* interrupts whether they are enabled or not. It accesses alll */
/* interrupt registers whether the blocks are enabled or not,   */
/* so bus errors are to be expected.                            */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    return ten_dev_irq_clear_node(dev_id, &TEN_IRQ_NODE_MPIF_GLOBAL_INTERRUPT);
}
/* Bugzilla 18209 End */

/* Enable for module/slice registers
 * '1' in enable_bits bit positions will enable the interrupt by writing '1' in those bit positions
 */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   not currently implemented: 0xFF = TEN_SLICE_ALL            */
cs_status ten_mod_irq_enable_disable(cs_uint16 module_id, cs_uint8 slice_in, ten_irq_node_ptr node, cs_uint16 enable_bits, cs_uint16 disable_bits, ten_irq_tree_dir_t dir)
{
    cs_boolean            enable;
    cs_uint8              slice;
    cs_uint16             dev_id;
    cs_uint8              module;
    cs_uint32             enable_reg_addr;
    cs_uint16             enable_reg_data;
    ten_irq_node_parent_t parent;
    ten_irq_node_ptr      child;
    int                   i;
    cs_status             status;
    cs_uint32             err_code = 0;
   cs_char8 *func = "ten_mod_irq_enable_disable";  

    if (enable_bits)
        if (disable_bits) return CS_ERROR;
        else enable = TRUE;
    else if (disable_bits) enable = FALSE;
    /* If there are no bits set in either then there's nothing to do */
    else return CS_OK;

    if (!(TEN_IS_MOD_VALID(module_id, &err_code)))
    {
        CS_HNDL_ERROR(module_id, err_code, NULL);
        return (CS_ERROR);
    }
    dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);

    slice = slice_in;
    /* Slices 0-3 are in module 0 and slices 4-7 are in module 1 */
    module = TEN_MOD_ID_TO_MOD_NUM(module_id);
    /* Figure out the absolute slice number for this instance, this varies depending on the module.
     * Look at the number of slices and the address range (if necessary) to convert module/slice to
     * absolute slice */
    switch (node->slices)
    {
        case 1: slice = 0;
                break;
        case 2: slice = module;
                break;
        /* GFEC10g only has three slices and module_id is ignored */
        case 3: break;
        case 4: /* XFI address range */
                if (node->ireg >= TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_SRX0_RX_CONFIG && node->ireg < TEN_XCON_GLB_RESET)
                {
                    /* XFI only exists in module B */
                    if (module != TEN_MODULE_B) return CS_ERROR;
                }
                break;
        case 8: slice += module * 4;
                break;
        default: return CS_ERROR;
    }
    /* Verify that the module/slice is valid for this block */
    if (slice > (node->slices - 1))
        return CS_ERROR;

    CS_PRINT("%s() %s, %s, enable_bits=0x%04X, disable_bits=0x%04X, dir=%d\n", 
             func, ten_module_strings[module_id&1], ten_slice_strings[slice_in], enable_bits, disable_bits,dir);


    /* Calculate the enable register address based on the absolute slice and the stride */
    enable_reg_addr = node->ereg + slice * node->stride;
    TEN_DEV_LOCK(dev_id, TEN_ID_IRQ);
    enable_reg_data = ten_reg_read(dev_id, enable_reg_addr);
    enable_reg_data |= enable_bits;     /* enable the selected bits */
    enable_reg_data &= ~disable_bits;   /* disable the selected bits */
    enable_reg_data &= node->mask;      /* don't modify unused or reserved bits */
    status = ten_reg_write(dev_id, enable_reg_addr, enable_reg_data);
    TEN_DEV_UNLOCK(dev_id, TEN_ID_IRQ);
    if (status == CS_ERROR)
        return CS_ERROR;

    /* Recurse down the tree */
    if (node->children != TEN_IRQ_NODE_NO_NODE)
    {
        if (dir == TEN_IRQ_DIR_DOWN || dir == TEN_IRQ_DIR_BOTH)
        {
            for (i=0; i<=15; i++)
            {
                /* Only enable those children whose enable bits are set and disable bits are clear */
                if ((1<<i) & (enable_bits | disable_bits))
                {
                    /* children is a variable-length array; check the index against the length */
                    if (i < node->num_children)
                    {
                        child = (*node->children)[i].child;
                        if (child != TEN_IRQ_NODE_NO_NODE)
                        {
                            TEN_IRQ_RET_IF_ERROR(ten_mod_irq_enable_disable(module_id, slice_in,
                                                                            child,
                                                                            enable ? 0xffff : 0,
                                                                            enable ? 0 : 0xffff,
                                                                            dir), CS_ERROR);
                        }
                    }
                }
            }
        }
    }

    /* Recurse up the tree */
    if (node->parents != TEN_IRQ_NODE_NO_NODE)
    {
        if (dir == TEN_IRQ_DIR_UP || dir == TEN_IRQ_DIR_BOTH)
        {
            /* The parent may collect multiple slices but not be sliced itself */
            parent = (*(node->parents))[slice];
            /* Interrupts from multiple slices may converge into one register; detect this and call the non-sliced routine */
            if ((*(parent.parent)).slices == 1)
            {
                TEN_IRQ_RET_IF_ERROR(ten_dev_irq_enable_disable(dev_id, parent.parent,
                                                                enable ? parent.mask : 0,
                                                                enable ? 0 : parent.mask,
                                                                dir), CS_ERROR);
            }
            else
            {
                TEN_IRQ_RET_IF_ERROR(ten_mod_irq_enable_disable(module_id, slice_in, parent.parent,
                                                                enable ? parent.mask : 0,
                                                                enable ? 0 : parent.mask,
                                                                dir), CS_ERROR);
            }
        }
    }
    return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE MODULE/SLICE INTERRUPTS               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_mod_irq_enable(cs_uint16          module_id,
                             cs_uint8           slice,
                             ten_irq_node_ptr   node,
                             cs_uint16          enable_bits,
                             ten_irq_tree_dir_t dir)
/* INPUTS     : o Module ID                                     */
/*              o Slice                                         */
/*              o Pointer to an interrupt node                  */
/*              o Bitmask of the register bits to enable        */
/*              o Direction to enable (up or down the tree)     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables interrupts at the module/slice level (rather than    */
/* the device level).                                           */
/* The [enable_bits] parameter is specified as:                 */
/*                1 = enable the bit                            */
/*                0 = leave the bit as-is                       */
/* The [dir] parameter is specified as:                         */
/*                TEN_IRQ_DIR_ONLY = 0 enables this node only   */
/*                TEN_IRQ_DIR_UP   = 1 enables this node and up */
/*                                     the tree                 */
/*                TEN_IRQ_DIR_DOWN = 2 enables this node and    */
/*                                     down the tree            */
/*                TEN_IRQ_DIR_BOTH = 3 enables this node and up */
/*                                     and down the tree        */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    return ten_mod_irq_enable_disable(module_id, slice, node, enable_bits, 0, dir);
}

/****************************************************************/
/* $rtn_hdr_start  DISABLE MODULE/SLICE INTERRUPT               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_mod_irq_disable(cs_uint16          module_id,
                              cs_uint8           slice,
                              ten_irq_node_ptr   node,
                              cs_uint16          disable_bits,
                              ten_irq_tree_dir_t dir)
/* INPUTS     : o Module ID                                     */
/*              o Slice                                         */
/*              o Pointer to an interrupt node                  */
/*              o Bitmask of the register bits to disable       */
/*              o Direction to disable (up or down the tree)    */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Disables interrupts at the module/slice level (rather than   */
/* the device level).                                           */
/* The [disable_bits] parameter is specified as:                */
/*                1 = disable the bit                           */
/*                0 = leave the bit as-is                       */
/* The [dir] parameter is specified as:                         */
/*                TEN_IRQ_DIR_ONLY = 0 enables this node only   */
/*                TEN_IRQ_DIR_UP   = 1 enables this node and up */
/*                                     the tree                 */
/*                TEN_IRQ_DIR_DOWN = 2 enables this node and    */
/*                                     down the tree            */
/*                TEN_IRQ_DIR_BOTH = 3 enables this node and up */
/*                                     and down the tree        */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    return ten_mod_irq_enable_disable(module_id, slice, node, 0, disable_bits, dir);
}

cs_status ten_irq_walk_node(cs_uint16 dev_id, ten_irq_node_ptr node, cs_uint8 slice)
{
    cs_uint32              interrupt_reg_address, parent_interrupt_address;
    cs_uint16              interrupt_reg_data;
    cs_uint32              enable_reg_address, parent_enable_address;
    cs_uint16              enable_reg_data;
    cs_uint16              masked_interrupt_data;
    ten_irq_node_ptr       child;
    cs_uint8               child_slice;
    int                    i;
    ten_irq_handler_data_t handler_data;
    ten_irq_node_parent_t  parent;

    cs_boolean             call_handler = FALSE;
#ifdef TEN_IRQ_LOCK_INTERRUPT_WALKER
    cs_boolean             locked = FALSE;
#endif
    cs_uint16              status_reg_data = 0;
    /*cs_char8 *func = "ten_irq_walk_node";*/  

    TEN_INVALID_DEV_EXIT(dev_id) ;
    if (slice > node->slices)
        return CS_ERROR;

  /*CS_PRINT("%s() %s\n", func, ten_slice_strings[slice]);*/


    interrupt_reg_address = node->ireg + node->stride * slice;
    enable_reg_address    = node->ereg + node->stride * slice;
#ifdef TEN_IRQ_LOCK_INTERRUPT_WALKER
    TEN_DEV_LOCK(dev_id, TEN_ID_IRQ);
    locked = TRUE;
#endif
    interrupt_reg_data = ten_reg_read(dev_id, interrupt_reg_address);
    /* Don't bother reading the enable register if there's nothing to look for here */
    if (interrupt_reg_data != 0)
    {
        enable_reg_data = ten_reg_read(dev_id, enable_reg_address);
        masked_interrupt_data = interrupt_reg_data & enable_reg_data;
        for (i=0; i<16; i++)
        {
            if (masked_interrupt_data & 1)
            {
                /* Is this a leaf ot intermediate node? The entire register could be a leaf,
                 * or just the bit in question */
                if ((node->children == TEN_IRQ_NODE_NO_NODE) ||
                    /* Bug 20186 #4 start */
                    (i >= node->num_children) ||
                    /* Bug 20186 #4 end */
                    ((i < node->num_children) && (*node->children)[i].child == TEN_IRQ_NODE_NO_NODE))
                {
                    /* This is a leaf */
#if TEN_IRQ_PRINT_INTERRUPTS
                    /* child_name is a variable-length array; make sure we don't go beyond the end of it */
                    if (i <= node->last_child)
                        CS_PRINT("ISR '%s : %s' fired at address 0x%05X bit %d\n",
                            node->name, node->child_name[i],
                            interrupt_reg_address, i);
#endif
                    call_handler = TRUE;
                }
                else
                {
                    /* children is a variable-length array; check the index against the length */
                    if (i < node->num_children)
                    {
                        child = (*node->children)[i].child;
                        /* If the parent node was not slice 0 but the child node is,
                         * then the child is a slice-off-of-a-slice and the child slice
                         * should be the same as the parent slice */
                        child_slice = (*node->children)[i].slice;
                        if (slice > 0 && child_slice == 0)
                            child_slice = slice;
#ifdef TEN_IRQ_LOCK_INTERRUPT_WALKER
                        if (locked)
                        {
                            TEN_DEV_UNLOCK(dev_id, TEN_ID_IRQ);
                            locked = FALSE;
                        }
#endif
                        /* Bug 20186 start */
                        if (child != TEN_IRQ_NODE_NO_NODE)
                        /* Bug 20186 end */
                            ten_irq_walk_node(dev_id, child, child_slice);
                    }
                }
            }
            masked_interrupt_data >>= 1;
        }

        /* If this is a leaf node and an interrupt was set */
        if (call_handler)
        {
            if (node->sreg)
                status_reg_data = ten_reg_read(dev_id, node->sreg + node->stride * slice);
            /* All interrupt registers in Tenabo 2 are RW1C so write a '1' to clear the interrupt */
            /* Bug 12558: Disabled interrupts should not be automatically cleared
             *            Previously, all interrupts were cleared.
             *            Now, only enabled interrupts are cleared. */
            ten_reg_write(dev_id, interrupt_reg_address, interrupt_reg_data & enable_reg_data);
            /* Bug 15067 work-around */
            /* Bug 26181 removes the workaround for T41 */
            /* The UFEC interrupts are cleared differently than the rest of the chip.
             * They don't automatically clear all the way to the root, each intermediate node must
             * be manually cleared. The steps to do this are:
             *   1) Disable leaf which generated the interrupt
             *   2) Clear the target interrupt from the leaf to UFEC root only if there are no other
             *      interrupts pending in additional leaves that feed the node
             *   3) Re-enable leaf which generated the interrupt */
            if ((ten_dev_is_t41(dev_id) == FALSE) && IS_UFEC_ADDRESS(interrupt_reg_address)) {
              /* The interrupt enable is already saved in enable_reg_data; it will be restored later.
               * Clear the enable while walking the tree so that the intermediate nodes don't get set again */
              ten_reg_write(dev_id, enable_reg_address, 0);
              /* Walk up the tree clearing the interrupt */
              /* Get the parent node */
              parent = (*(node->parents))[slice];
              do {
                parent_interrupt_address = (*(parent.parent)).ireg + (*(parent.parent)).stride * slice;
                parent_enable_address = (*(parent.parent)).ereg + (*(parent.parent)).stride * slice;
                if (IS_UFEC_ADDRESS(parent_interrupt_address)) {
                  /* Clear the leaf interrupt at this level */
                  ten_reg_write(dev_id, parent_interrupt_address, parent.mask);
                  /* See if there are any other interrupts active at this level
                    - if there are, we're done walking up the tree so terminate the loop by setting a flag
                    - if there aren't then continue up the tree as long as we're in UFEC space */
                  if (ten_reg_read(dev_id, parent_interrupt_address))
                    parent = dummy_parent;
                  else
                    parent = (*((*(parent.parent)).parents))[slice];
                }
                /* This is the end of the UFEC interrupt tree so terminate the loop by setting a flag */
                else parent = dummy_parent;
              } while (parent.parent);
              /* Re-enable the interrupt */
              ten_reg_write(dev_id, enable_reg_address, enable_reg_data);
            }
#ifdef TEN_IRQ_LOCK_INTERRUPT_WALKER
            if (locked)
            {
                TEN_DEV_UNLOCK(dev_id, TEN_ID_IRQ);
                locked = FALSE;
            }
#endif
            /* Call any registered interrupt handlers */
            if (node->handler != TEN_IRQ_NO_HANDLER)
            {
                handler_data.dev_id    = dev_id;
                handler_data.node      = node;
                handler_data.ireg_data = interrupt_reg_data;
                handler_data.ereg_data = enable_reg_data;
                handler_data.sreg_data = status_reg_data;       /* This will be 0 if there is no status register for this node */
                handler_data.slice     = slice;
                (*(node->handler))(handler_data);
            }
        }
    }
#ifdef TEN_IRQ_LOCK_INTERRUPT_WALKER
    if (locked)
    {
        TEN_DEV_UNLOCK(dev_id, TEN_ID_IRQ);
        locked = FALSE;
    }
#endif
    return CS_OK;
}

cs_status ten_irq_walk_tree(cs_uint16 dev_id)
{
    /* Start at the global interrupt and walk the tree to all leaves */
    ten_irq_walk_node(dev_id, &TEN_IRQ_TOP, 0);
    return CS_OK;
}

/****************************************************************/
/* $rtn_hdr_start  INTERRUPT SERVICE ROUTINE                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_irq_isr(cs_uint16 dev_id)
/* INPUTS     : o Device ID                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Walk the interrupt tree and call any registered handlers for */
/* interrupt nodes that have both active and enabled            */
/* interrupts. Interrupts that are active but not enabled will  */
/* be ignored. Registered interrupt handlers will be called as  */
/* soon as their node has been polled in the tree traversal.    */
/* Active and enabled interrupts at that node will be cleared   */
/* before the handler is called. The handler will be passed all */
/* relevant information in a ten_irq_handler_data_t, including  */
/* the active and enabled interrupts.                           */
/* Interrupt handlers should not return anything.               */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    return ten_irq_walk_tree(dev_id);
}

/****************************************************************/
/* $rtn_hdr_start  REGISTER AN INTERRUPT HANDLER                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_irq_register_handler(cs_uint16         dev_id,
                                   ten_irq_node_ptr  node,
                                   ten_irq_handler_t handler)
/* INPUTS     : o Device ID                                     */
/*              o Pointer to an interrupt node                  */
/*              o Pointer to an interrupt handler, or           */
/*                TEN_IRQ_NO_HANDLER to unregister an existing  */
/*                handler                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Register a user-supplied interrupt handler against any       */
/* interrupt node (intermediate node or leaf node).             */
/* An interrupt register is a node and is in the form           */
/* TEN_IRQ_NODE_{register name}; e.g.                           */
/* TEN_IRQ_NODE_MPIF_GLOBAL_INTERRUPT                           */
/* The handler will be called if any interrupt bit at that node */
/* is both enabled and active. The handler will not be called   */
/* if an interrupt is active but not enabled.                   */
/* The handler will be passed a pointer to a                    */
/* ten_irq_handler_data_t that will be populated with all of    */
/* the interrupt information.                                   */
/* Only one handler may be registered for any node; CS_ERROR    */
/* will be returned if the node already has a registered        */
/* handler.                                                     */
/* Example:                                                     */
/*   ten_irq_register_handler(                                  */
/*     dev_id, ptr TEN_IRQ_NODE_GFEC10G_FRX_INTR,  ptr handler) */
/* Unregister a handler by using TEN_IRQ_NO_HANDLER as the      */
/* handler. CS_ERROR will be returned if there is no handler    */
/* registered.                                                  */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    TEN_INVALID_DEV_EXIT(dev_id) ;
    /* Don't allow a registration when a handler is already registered */
    if ((      handler != TEN_IRQ_NO_HANDLER) &&
        (node->handler != TEN_IRQ_NO_HANDLER))
        return CS_ERROR;
    /* Flag an error if unregistering a non-existent handler */
    if ((      handler == TEN_IRQ_NO_HANDLER) &&
        (node->handler == TEN_IRQ_NO_HANDLER))
        return CS_ERROR;
    node->handler = handler;
    return CS_OK;
}

/* This function is called recursively to print all of the enabled leaf interrupts */
cs_status ten_irq_walk_node_print_enabled(cs_uint16 dev_id, ten_irq_node_ptr node, cs_uint8 slice)
{
    cs_uint32              enable_reg_address;
    cs_uint16              enable_reg_data;
    ten_irq_node_ptr       child;
    cs_uint8               child_slice;
    int                    i;

    TEN_INVALID_DEV_EXIT(dev_id) ;
    if (slice > node->slices)
        return CS_ERROR;

    enable_reg_address = node->ereg + node->stride * slice;
    enable_reg_data = ten_reg_read(dev_id, enable_reg_address);
    for (i=0; i<16; i++)
    {
/*
        JUST_LOG_1(LOG_INFO, "T41", "PROCESSING          i %d\n", i);
*/
        if (enable_reg_data & 1)
        {
            /* Is this a leaf ot intermediate node? The entire register could be a leaf,
              * or just the bit in question */
            if ((node->children == TEN_IRQ_NODE_NO_NODE) ||
                /* Bug 20186 #4 start */
                (i >= node->num_children) ||
                /* Bug 20186 #4 end */
                ((i < node->num_children) && (*node->children)[i].child == TEN_IRQ_NODE_NO_NODE))
            {
                /* This is a leaf */
#if TEN_IRQ_PRINT_INTERRUPTS
                /* child_name is a variable-length array; make sure we don't go beyond the end of it */
/*
                JUST_LOG_1(LOG_INFO, "T41", "PROCESSING node->name %s\n", node->name);
                JUST_LOG_1(LOG_INFO, "T41", "PROCESSING node->child_name[i] '%s'\n", node->child_name[i]);
*/
                if ((i <= node->last_child)  && (strlen(node->child_name[i]) > 0))
                    CS_PRINT("Interrupt '%s : %s' slice %d is enabled at address 0x%05X bit %d\n",
                        node->name, node->child_name[i], slice,
                        enable_reg_address, i);
#endif
            }
            else
            {
/*
                JUST_LOG(LOG_INFO, "T41", "PROCESSING intermediate node\n");
*/
                /* children is a variable-length array; check the index against the length */
                if (i < node->num_children)
                {
                    child = (*node->children)[i].child;
                    /* If the parent node was not slice 0 but the child node is,
                     * then the child is a slice-off-of-a-slice and the child slice
                     * should be the same as the parent slice */
                    child_slice = (*node->children)[i].slice;
                    if (slice > 0 && child_slice == 0)
                        child_slice = slice;
                    /* Bug 20186 start */
                    if (child != TEN_IRQ_NODE_NO_NODE)
                    /* Bug 20186 end */
                        ten_irq_walk_node_print_enabled(dev_id, child, child_slice);
                }
            }
        }
        enable_reg_data >>= 1;
    }
    return CS_OK;
}

/****************************************************************/
/* $rtn_hdr_start  PRINT ENABLED INTERRUPTS                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : IRQ                                             */
/* CHIP       : Tenabo                                          */
cs_status ten_irq_print_enabled_interrupts(cs_uint16 dev_id)
/* INPUTS     : o Device ID                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Walks the interrupt tree and prints all of the enabled leaf  */
/* interrupts.                                                  */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
    return ten_irq_walk_node_print_enabled(dev_id, &TEN_IRQ_TOP, 0);
}

