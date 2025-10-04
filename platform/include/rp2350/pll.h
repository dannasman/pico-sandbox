/*
 * Copyright (c) 2022-2025 Douglas H. Summerville, Binghamton University 
 *
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef RP2350_PLL_H
#define RP2350_PLL_H

#include <stdint.h>

#define _u(v)   (uint32_t)(v)
#define ALL1    _u(0xffffffff)        

typedef struct {
    uint32_t cs;
    uint32_t pwr;
    uint32_t fbdiv_int;
    uint32_t prim;
    uint32_t intr;
    uint32_t inte;
    uint32_t intf;
    uint32_t ints;
    uint32_t RSVD0[1016];
    uint32_t cs_xor;
    uint32_t pwr_xor;
    uint32_t fbdiv_int_xor;
    uint32_t prim_xor;
    uint32_t intr_xor;
    uint32_t inte_xor;
    uint32_t intf_xor;
    uint32_t ints_xor;
    uint32_t RSVDxor_0[1016];
    uint32_t cs_set;
    uint32_t pwr_set;
    uint32_t fbdiv_int_set;
    uint32_t prim_set;
    uint32_t intr_set;
    uint32_t inte_set;
    uint32_t intf_set;
    uint32_t ints_set;
    uint32_t RSVDset_0[1016];
    uint32_t cs_clr;
    uint32_t pwr_clr;
    uint32_t fbdiv_int_clr;
    uint32_t prim_clr;
    uint32_t intr_clr;
    uint32_t inte_clr;
    uint32_t intf_clr;
    uint32_t ints_clr;
    uint32_t RSVDclr_0[1016];
} pll_regs;

#define pll_sys (*(volatile pll_regs *)(_u(0x40050000)))
#define pll_usb (*(volatile pll_regs *)(_u(0x40058000)))

#define PLL_CS_LOCK(v)      ((_u(v) & _u(0x1)) << _u(31))
#define PLL_CS_LOCK_MASK    PLL_CS_LOCK(ALL1)
#define PLL_CS_LOCK_N(v)    ((_u(v) & _u(0x1)) << _u(30))
#define PLL_CS_LOCK_N_MASK  PLL_CS_LOCK_N(ALL1)
#define PLL_CS_BYPASS(v)    ((_u(v) & _u(0x1)) << _u(8))
#define PLL_CS_BYPASS_MASK  PLL_CS_BYPASS(ALL1)
#define PLL_CS_REFDIV(v)    ((_u(v) & _u(0x3f)) << _u(0))
#define PLL_CS_REFDIV_MASK  PLL_CS_REFDIV(ALL1)

#define PLL_PWR_VCOPD(v)        ((_u(v) & _u(0x1)) << _u(5))
#define PLL_PWR_VCOPD_MASK      PLL_PWR_VCOPD(ALL1)
#define PLL_PWR_POSTDIVPD(v)    ((_u(v) & _u(0x1)) << _u(3))
#define PLL_PWR_POSTDIVPD_MASK  PLL_PWR_POSTDIVPD(ALL1)
#define PLL_PWR_DSMPD(v)        ((_u(v) & _u(0x1)) << _u(2))
#define PLL_PWR_DSMPD_MASK      PLL_PWR_DSMPD(ALL1)
#define PLL_PWR_PD(v)           ((_u(v) & _u(0x1)) << _u(0))
#define PLL_PWR_PD_MASK         PLL_PWR_PD(ALL1)

#define PLL_FBDIV_INT(v)    ((_u(v) & _u(0xfff)) << _u(0))
#define PLL_FBDIV_INT_MASK  PLL_FBDIV_INT(ALL1)

#define PLL_PRIM_POSTDIV1(v)    ((_u(v) & _u(0x7)) << _u(16))
#define PLL_PRIM_POSTDIV1_MASK  PLL_PRIM_POSTDIV1(ALL1)
#define PLL_PRIM_POSTDIV2(v)    ((_u(v) & _u(0x7)) << _u(12))
#define PLL_PRIM_POSTDIV2_MASK  PLL_PRIM_POSTDIV2(ALL1)

#endif
