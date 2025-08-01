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

#ifndef RP2350_TICKS_H
#define RP2350_TICKS_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct {
    uint32_t proc0_ctrl;
    uint32_t proc0_cycles;
    uint32_t proc0_count;
    uint32_t proc1_ctrl;
    uint32_t proc1_cycles;
    uint32_t proc1_count;
    uint32_t timer0_ctrl;
    uint32_t timer0_cycles;
    uint32_t timer0_count;
    uint32_t timer1_ctrl;
    uint32_t timer1_cycles;
    uint32_t timer1_count;
    uint32_t watchdog_ctrl;
    uint32_t watchdog_cycles;
    uint32_t watchdog_count;
    uint32_t riscv_ctrl;
    uint32_t riscv_cycles;
    uint32_t riscv_count;
    uint32_t RSVD0[1006];
    uint32_t proc0_ctrl_xor;
    uint32_t proc0_cycles_xor;
    uint32_t proc0_count_xor;
    uint32_t proc1_ctrl_xor;
    uint32_t proc1_cycles_xor;
    uint32_t proc1_count_xor;
    uint32_t timer0_ctrl_xor;
    uint32_t timer0_cycles_xor;
    uint32_t timer0_count_xor;
    uint32_t timer1_ctrl_xor;
    uint32_t timer1_cycles_xor;
    uint32_t timer1_count_xor;
    uint32_t watchdog_ctrl_xor;
    uint32_t watchdog_cycles_xor;
    uint32_t watchdog_count_xor;
    uint32_t riscv_ctrl_xor;
    uint32_t riscv_cycles_xor;
    uint32_t riscv_count_xor;
    uint32_t RSVDxor_0[1006];
    uint32_t proc0_ctrl_set;
    uint32_t proc0_cycles_set;
    uint32_t proc0_count_set;
    uint32_t proc1_ctrl_set;
    uint32_t proc1_cycles_set;
    uint32_t proc1_count_set;
    uint32_t timer0_ctrl_set;
    uint32_t timer0_cycles_set;
    uint32_t timer0_count_set;
    uint32_t timer1_ctrl_set;
    uint32_t timer1_cycles_set;
    uint32_t timer1_count_set;
    uint32_t watchdog_ctrl_set;
    uint32_t watchdog_cycles_set;
    uint32_t watchdog_count_set;
    uint32_t riscv_ctrl_set;
    uint32_t riscv_cycles_set;
    uint32_t riscv_count_set;
    uint32_t RSVDset_0[1006];
    uint32_t proc0_ctrl_clr;
    uint32_t proc0_cycles_clr;
    uint32_t proc0_count_clr;
    uint32_t proc1_ctrl_clr;
    uint32_t proc1_cycles_clr;
    uint32_t proc1_count_clr;
    uint32_t timer0_ctrl_clr;
    uint32_t timer0_cycles_clr;
    uint32_t timer0_count_clr;
    uint32_t timer1_ctrl_clr;
    uint32_t timer1_cycles_clr;
    uint32_t timer1_count_clr;
    uint32_t watchdog_ctrl_clr;
    uint32_t watchdog_cycles_clr;
    uint32_t watchdog_count_clr;
    uint32_t riscv_ctrl_clr;
    uint32_t riscv_cycles_clr;
    uint32_t riscv_count_clr;
    uint32_t RSVDclr_0[1006];
} ticks_regs;

#define ticks (*(volatile ticks_regs *)(_u(0x40108000)))

#define TICKS_TIMER0_CTRL_RUNNING(v)    ((_u(v) & 0x1) << _u(1))
#define TICKS_TIMER0_CTRL_RUNNING_MASK  TICKS_TIMER0_CTRL_RUNNING(ALL1)
#define TICKS_TIMER0_CTRL_ENABLE(v)     ((_u(v) & 0x1) << _u(0))
#define TICKS_TIMER0_CTRL_ENABLE_MASK   TICKS_TIMER0_CTRL_ENABLE(ALL1)

#define TICKS_TIMER0_CYCLES(v)    ((_u(v) & 0x1ffff) << _u(0))

#endif

