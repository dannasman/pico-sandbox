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

#ifndef RP2350_TIMER_H
#define RP2350_TIMER_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct {
    uint32_t timehw;
    uint32_t timelw;
    uint32_t timehr;
    uint32_t timelr;
    uint32_t alarm0;
    uint32_t alarm1;
    uint32_t alarm2;
    uint32_t alarm3;
    uint32_t armed;
    uint32_t timerawh;
    uint32_t timerawl;
    uint32_t dbgpause;
    uint32_t pause;
    uint32_t locked;
    uint32_t source;
    uint32_t intr;
    uint32_t inte;
    uint32_t intf;
    uint32_t ints;
    uint32_t RSVD0[1005];
    uint32_t timehw_xor;
    uint32_t timelw_xor;
    uint32_t timehr_xor;
    uint32_t timelr_xor;
    uint32_t alarm0_xor;
    uint32_t alarm1_xor;
    uint32_t alarm2_xor;
    uint32_t alarm3_xor;
    uint32_t armed_xor;
    uint32_t timerawh_xor;
    uint32_t timerawl_xor;
    uint32_t dbgpause_xor;
    uint32_t pause_xor;
    uint32_t locked_xor;
    uint32_t source_xor;
    uint32_t intr_xor;
    uint32_t inte_xor;
    uint32_t intf_xor;
    uint32_t ints_xor;
    uint32_t RSVDxor_0[1005];
    uint32_t timehw_set;
    uint32_t timelw_set;
    uint32_t timehr_set;
    uint32_t timelr_set;
    uint32_t alarm0_set;
    uint32_t alarm1_set;
    uint32_t alarm2_set;
    uint32_t alarm3_set;
    uint32_t armed_set;
    uint32_t timerawh_set;
    uint32_t timerawl_set;
    uint32_t dbgpause_set;
    uint32_t pause_set;
    uint32_t locked_set;
    uint32_t source_set;
    uint32_t intr_set;
    uint32_t inte_set;
    uint32_t intf_set;
    uint32_t ints_set;
    uint32_t RSVDset_0[1005];
    uint32_t timehw_clr;
    uint32_t timelw_clr;
    uint32_t timehr_clr;
    uint32_t timelr_clr;
    uint32_t alarm0_clr;
    uint32_t alarm1_clr;
    uint32_t alarm2_clr;
    uint32_t alarm3_clr;
    uint32_t armed_clr;
    uint32_t timerawh_clr;
    uint32_t timerawl_clr;
    uint32_t dbgpause_clr;
    uint32_t pause_clr;
    uint32_t locked_clr;
    uint32_t source_clr;
    uint32_t intr_clr;
    uint32_t inte_clr;
    uint32_t intf_clr;
    uint32_t ints_clr;
    uint32_t RSVDclr_0[1005];
} timer_regs;

#define timer0 (*(volatile timer_regs *)(_u(0x400b0000)))
#define timer1 (*(volatile timer_regs *)(_u(0x400b8000)))

#endif

