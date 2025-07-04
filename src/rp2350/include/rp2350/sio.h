
/* Copyright (c) 2024-2025 Douglas H. Summerville (dsummer@binghamton.edu) 
 *
 * Created from scraped data which is Copyright (c) 2024 Raspberry Pi
 * (Trading) Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef RP2350_SIO_H
#define RP2350_SIO_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct{
		uint32_t cpuid;
		uint32_t gpio_in;
		uint32_t gpio_hi_in;
		uint32_t RSVD0;
		uint32_t gpio_out;
		uint32_t gpio_hi_out;
		uint32_t gpio_out_set;
		uint32_t gpio_hi_out_set;
		uint32_t gpio_out_clr;
		uint32_t gpio_hi_out_clr;
		uint32_t gpio_out_xor;
		uint32_t gpio_hi_out_xor;
		uint32_t gpio_oe;
		uint32_t gpio_hi_oe;
		uint32_t gpio_oe_set;
		uint32_t gpio_hi_oe_set;
		uint32_t gpio_oe_clr;
		uint32_t gpio_hi_oe_clr;
		uint32_t gpio_oe_xor;
		uint32_t gpio_hi_oe_xor;
		uint32_t fifo_st;
		uint32_t fifo_wr;
		uint32_t fifo_rd;
		uint32_t spinlock_st;
		uint32_t RSVD1[8];
		uint32_t interp0_accum0;
		uint32_t interp0_accum1;
		uint32_t interp0_base0;
		uint32_t interp0_base1;
		uint32_t interp0_base2;
		uint32_t interp0_pop_lane0;
		uint32_t interp0_pop_lane1;
		uint32_t interp0_pop_full;
		uint32_t interp0_peek_lane0;
		uint32_t interp0_peek_lane1;
		uint32_t interp0_peek_full;
		uint32_t interp0_ctrl_lane0;
		uint32_t interp0_ctrl_lane1;
		uint32_t interp0_accum0_add;
		uint32_t interp0_accum1_add;
		uint32_t interp0_base_1and0;
		uint32_t interp1_accum0;
		uint32_t interp1_accum1;
		uint32_t interp1_base0;
		uint32_t interp1_base1;
		uint32_t interp1_base2;
		uint32_t interp1_pop_lane0;
		uint32_t interp1_pop_lane1;
		uint32_t interp1_pop_full;
		uint32_t interp1_peek_lane0;
		uint32_t interp1_peek_lane1;
		uint32_t interp1_peek_full;
		uint32_t interp1_ctrl_lane0;
		uint32_t interp1_ctrl_lane1;
		uint32_t interp1_accum0_add;
		uint32_t interp1_accum1_add;
		uint32_t interp1_base_1and0;
		uint32_t spinlock0;
		uint32_t spinlock1;
		uint32_t spinlock2;
		uint32_t spinlock3;
		uint32_t spinlock4;
		uint32_t spinlock5;
		uint32_t spinlock6;
		uint32_t spinlock7;
		uint32_t spinlock8;
		uint32_t spinlock9;
		uint32_t spinlock10;
		uint32_t spinlock11;
		uint32_t spinlock12;
		uint32_t spinlock13;
		uint32_t spinlock14;
		uint32_t spinlock15;
		uint32_t spinlock16;
		uint32_t spinlock17;
		uint32_t spinlock18;
		uint32_t spinlock19;
		uint32_t spinlock20;
		uint32_t spinlock21;
		uint32_t spinlock22;
		uint32_t spinlock23;
		uint32_t spinlock24;
		uint32_t spinlock25;
		uint32_t spinlock26;
		uint32_t spinlock27;
		uint32_t spinlock28;
		uint32_t spinlock29;
		uint32_t spinlock30;
		uint32_t spinlock31;
		uint32_t doorbell_out_set;
		uint32_t doorbell_out_clr;
		uint32_t doorbell_in_set;
		uint32_t doorbell_in_clr;
		uint32_t peri_nonsec;
		uint32_t RSVD2[3];
		uint32_t riscv_softirq;
		uint32_t mtime_ctrl;
		uint32_t RSVD3[2];
		uint32_t mtime;
		uint32_t mtimeh;
		uint32_t mtimecmp;
		uint32_t mtimecmph;
		uint32_t tmds_ctrl;
		uint32_t tmds_wdata;
		uint32_t tmds_peek_single;
		uint32_t tmds_pop_single;
		uint32_t tmds_peek_double_l0;
		uint32_t tmds_pop_double_l0;
		uint32_t tmds_peek_double_l1;
		uint32_t tmds_pop_double_l1;
		uint32_t tmds_peek_double_l2;
		uint32_t tmds_pop_double_l2;
} sio_regs;

#define sio (*(volatile sio_regs *)0xd0000000)
#define sio_nonsec (*(volatile sio_regs *)0xd0020000)

#endif
