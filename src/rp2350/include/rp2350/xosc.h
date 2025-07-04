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

#ifndef RP2350_XOSC_H
#define RP2350_XOSC_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct {
    uint32_t ctrl;
    uint32_t status;
    uint32_t dormant;
    uint32_t startup;
    uint32_t count;
    uint32_t RSVD0[1019];
    uint32_t ctrl_xor;
    uint32_t status_xor;
    uint32_t dormant_xor;
    uint32_t startup_xor;
    uint32_t count_xor;
    uint32_t RSVDxor_0[1019];
    uint32_t ctrl_set;
    uint32_t status_set;
    uint32_t dormant_set;
    uint32_t startup_set;
    uint32_t count_set;
    uint32_t RSVDset_0[1019];
    uint32_t ctrl_clr;
    uint32_t status_clr;
    uint32_t dormant_clr;
    uint32_t startup_clr;
    uint32_t count_clr;
    uint32_t RSVDclr_0[1019];
} xosc_regs;

#define xosc (*(volatile xosc_regs *)(_u(0x40048000)))

#define XOSC_CTRL_ENABLE(v)         ((_u(v) & _u(0xfff)) << _u(12))
#define XOSC_CTRL_ENABLE_MASK       XOSC_CTRL_ENABLE(ALL1)
#define XOSC_CTRL_FREQ_RANGE(v)     ((_u(v) & _u(0xfff)) << _u(0))
#define XOSC_CTRL_FREQ_RANGE_MASK   XOSC_CTRL_FREQ_RANGE(ALL1)

#define XOSC_STATUS_STABLE(v)       ((_u(v) & _u(0x1)) << _u(31))
#define XOSC_STATUS_STABLE_MASK     XOSC_STATUS_STABLE(ALL1)

#define XOSC_STARTUP_DELAY(v)       ((_u(v) & _u(0x3fff)) << _u(0))
#define XOSC_STARTUP_DELAY_MASK     XOSC_STARTUP_DELAY(ALL1)

#endif
