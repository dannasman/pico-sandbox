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

#ifndef RP2350_CLOCKS_H
#define RP2350_CLOCKS_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct {
    uint32_t clk_gpout0_ctrl;
    uint32_t clk_gpout0_div;
    uint32_t clk_gpout0_selected;
    uint32_t clk_gpout1_ctrl;
    uint32_t clk_gpout1_div;
    uint32_t clk_gpout1_selected;
    uint32_t clk_gpout2_ctrl;
    uint32_t clk_gpout2_div;
    uint32_t clk_gpout2_selected;
    uint32_t clk_gpout3_ctrl;
    uint32_t clk_gpout3_div;
    uint32_t clk_gpout3_selected;
    uint32_t clk_ref_ctrl;
    uint32_t clk_ref_div;
    uint32_t clk_ref_selected;
    uint32_t clk_sys_ctrl;
    uint32_t clk_sys_div;
    uint32_t clk_sys_selected;
    uint32_t clk_peri_ctrl;
    uint32_t clk_peri_div;
    uint32_t clk_peri_selected;
    uint32_t clk_hstx_ctrl;
    uint32_t clk_hstx_div;
    uint32_t clk_hstx_selected;
    uint32_t clk_usb_ctrl;
    uint32_t clk_usb_div;
    uint32_t clk_usb_selected;
    uint32_t clk_adc_ctrl;
    uint32_t clk_adc_div;
    uint32_t clk_adc_selected;
    uint32_t dftclk_xosc_ctrl;
    uint32_t dftclk_rosc_ctrl;
    uint32_t dftclk_lposc_ctrl;
    uint32_t clk_sys_resus_ctrl;
    uint32_t clk_sys_resus_status;
    uint32_t fc0_ref_khz;
    uint32_t fc0_min_khz;
    uint32_t fc0_max_khz;
    uint32_t fc0_delay;
    uint32_t fc0_interval;
    uint32_t fc0_src;
    uint32_t fc0_status;
    uint32_t fc0_result;
    uint32_t wake_en0;
    uint32_t wake_en1;
    uint32_t sleep_en0;
    uint32_t sleep_en1;
    uint32_t enabled0;
    uint32_t enabled1;
    uint32_t intr;
    uint32_t inte;
    uint32_t intf;
    uint32_t ints;
    uint32_t RSVD0[971];
    uint32_t clk_gpout0_ctrl_xor;
    uint32_t clk_gpout0_div_xor;
    uint32_t clk_gpout0_selected_xor;
    uint32_t clk_gpout1_ctrl_xor;
    uint32_t clk_gpout1_div_xor;
    uint32_t clk_gpout1_selected_xor;
    uint32_t clk_gpout2_ctrl_xor;
    uint32_t clk_gpout2_div_xor;
    uint32_t clk_gpout2_selected_xor;
    uint32_t clk_gpout3_ctrl_xor;
    uint32_t clk_gpout3_div_xor;
    uint32_t clk_gpout3_selected_xor;
    uint32_t clk_ref_ctrl_xor;
    uint32_t clk_ref_div_xor;
    uint32_t clk_ref_selected_xor;
    uint32_t clk_sys_ctrl_xor;
    uint32_t clk_sys_div_xor;
    uint32_t clk_sys_selected_xor;
    uint32_t clk_peri_ctrl_xor;
    uint32_t clk_peri_div_xor;
    uint32_t clk_peri_selected_xor;
    uint32_t clk_hstx_ctrl_xor;
    uint32_t clk_hstx_div_xor;
    uint32_t clk_hstx_selected_xor;
    uint32_t clk_usb_ctrl_xor;
    uint32_t clk_usb_div_xor;
    uint32_t clk_usb_selected_xor;
    uint32_t clk_adc_ctrl_xor;
    uint32_t clk_adc_div_xor;
    uint32_t clk_adc_selected_xor;
    uint32_t dftclk_xosc_ctrl_xor;
    uint32_t dftclk_rosc_ctrl_xor;
    uint32_t dftclk_lposc_ctrl_xor;
    uint32_t clk_sys_resus_ctrl_xor;
    uint32_t clk_sys_resus_status_xor;
    uint32_t fc0_ref_khz_xor;
    uint32_t fc0_min_khz_xor;
    uint32_t fc0_max_khz_xor;
    uint32_t fc0_delay_xor;
    uint32_t fc0_interval_xor;
    uint32_t fc0_src_xor;
    uint32_t fc0_status_xor;
    uint32_t fc0_result_xor;
    uint32_t wake_en0_xor;
    uint32_t wake_en1_xor;
    uint32_t sleep_en0_xor;
    uint32_t sleep_en1_xor;
    uint32_t enabled0_xor;
    uint32_t enabled1_xor;
    uint32_t intr_xor;
    uint32_t inte_xor;
    uint32_t intf_xor;
    uint32_t ints_xor;
    uint32_t RSVDxor_0[971];
    uint32_t clk_gpout0_ctrl_set;
    uint32_t clk_gpout0_div_set;
    uint32_t clk_gpout0_selected_set;
    uint32_t clk_gpout1_ctrl_set;
    uint32_t clk_gpout1_div_set;
    uint32_t clk_gpout1_selected_set;
    uint32_t clk_gpout2_ctrl_set;
    uint32_t clk_gpout2_div_set;
    uint32_t clk_gpout2_selected_set;
    uint32_t clk_gpout3_ctrl_set;
    uint32_t clk_gpout3_div_set;
    uint32_t clk_gpout3_selected_set;
    uint32_t clk_ref_ctrl_set;
    uint32_t clk_ref_div_set;
    uint32_t clk_ref_selected_set;
    uint32_t clk_sys_ctrl_set;
    uint32_t clk_sys_div_set;
    uint32_t clk_sys_selected_set;
    uint32_t clk_peri_ctrl_set;
    uint32_t clk_peri_div_set;
    uint32_t clk_peri_selected_set;
    uint32_t clk_hstx_ctrl_set;
    uint32_t clk_hstx_div_set;
    uint32_t clk_hstx_selected_set;
    uint32_t clk_usb_ctrl_set;
    uint32_t clk_usb_div_set;
    uint32_t clk_usb_selected_set;
    uint32_t clk_adc_ctrl_set;
    uint32_t clk_adc_div_set;
    uint32_t clk_adc_selected_set;
    uint32_t dftclk_xosc_ctrl_set;
    uint32_t dftclk_rosc_ctrl_set;
    uint32_t dftclk_lposc_ctrl_set;
    uint32_t clk_sys_resus_ctrl_set;
    uint32_t clk_sys_resus_status_set;
    uint32_t fc0_ref_khz_set;
    uint32_t fc0_min_khz_set;
    uint32_t fc0_max_khz_set;
    uint32_t fc0_delay_set;
    uint32_t fc0_interval_set;
    uint32_t fc0_src_set;
    uint32_t fc0_status_set;
    uint32_t fc0_result_set;
    uint32_t wake_en0_set;
    uint32_t wake_en1_set;
    uint32_t sleep_en0_set;
    uint32_t sleep_en1_set;
    uint32_t enabled0_set;
    uint32_t enabled1_set;
    uint32_t intr_set;
    uint32_t inte_set;
    uint32_t intf_set;
    uint32_t ints_set;
    uint32_t RSVDset_0[971];
    uint32_t clk_gpout0_ctrl_clr;
    uint32_t clk_gpout0_div_clr;
    uint32_t clk_gpout0_selected_clr;
    uint32_t clk_gpout1_ctrl_clr;
    uint32_t clk_gpout1_div_clr;
    uint32_t clk_gpout1_selected_clr;
    uint32_t clk_gpout2_ctrl_clr;
    uint32_t clk_gpout2_div_clr;
    uint32_t clk_gpout2_selected_clr;
    uint32_t clk_gpout3_ctrl_clr;
    uint32_t clk_gpout3_div_clr;
    uint32_t clk_gpout3_selected_clr;
    uint32_t clk_ref_ctrl_clr;
    uint32_t clk_ref_div_clr;
    uint32_t clk_ref_selected_clr;
    uint32_t clk_sys_ctrl_clr;
    uint32_t clk_sys_div_clr;
    uint32_t clk_sys_selected_clr;
    uint32_t clk_peri_ctrl_clr;
    uint32_t clk_peri_div_clr;
    uint32_t clk_peri_selected_clr;
    uint32_t clk_hstx_ctrl_clr;
    uint32_t clk_hstx_div_clr;
    uint32_t clk_hstx_selected_clr;
    uint32_t clk_usb_ctrl_clr;
    uint32_t clk_usb_div_clr;
    uint32_t clk_usb_selected_clr;
    uint32_t clk_adc_ctrl_clr;
    uint32_t clk_adc_div_clr;
    uint32_t clk_adc_selected_clr;
    uint32_t dftclk_xosc_ctrl_clr;
    uint32_t dftclk_rosc_ctrl_clr;
    uint32_t dftclk_lposc_ctrl_clr;
    uint32_t clk_sys_resus_ctrl_clr;
    uint32_t clk_sys_resus_status_clr;
    uint32_t fc0_ref_khz_clr;
    uint32_t fc0_min_khz_clr;
    uint32_t fc0_max_khz_clr;
    uint32_t fc0_delay_clr;
    uint32_t fc0_interval_clr;
    uint32_t fc0_src_clr;
    uint32_t fc0_status_clr;
    uint32_t fc0_result_clr;
    uint32_t wake_en0_clr;
    uint32_t wake_en1_clr;
    uint32_t sleep_en0_clr;
    uint32_t sleep_en1_clr;
    uint32_t enabled0_clr;
    uint32_t enabled1_clr;
    uint32_t intr_clr;
    uint32_t inte_clr;
    uint32_t intf_clr;
    uint32_t ints_clr;
    uint32_t RSVDclr_0[971];
} clock_regs;

#define clocks (*(volatile clock_regs *)(_u(0x40010000)))

#define CLOCKS_CLK_REF_CTRL_AUXSRC(v)       ((_u(v) & _u(0x3)) << _u(5))
#define CLOCKS_CLK_REF_CTRL_AUXSRC_MASK     CLOCKS_CLK_REF_CTRL_AUXSRC(ALL1)
#define CLOCKS_CLK_REF_CTRL_SRC(v)          ((_u(v) & _u(0x3)) << _u(0))
#define CLOCKS_CLK_REF_CTRL_SRC_MASK        CLOCKS_CLK_REF_CTRL_SRC(ALL1)

#define CLOCKS_CLK_REF_DIV_INT(v)           ((_u(v) & _u(0xff)) << _u(16))
#define CLOCKS_CLK_REF_DIV_INT_MASK         CLOCKS_CLK_REF_DIV_INT(ALL1)

#define CLOCKS_CLK_SYS_CTRL_AUXSRC(v)       ((_u(v) & _u(0x7)) << _u(5))
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_MASK     CLOCKS_CLK_SYS_CTRL_AUXSRC(ALL1)
#define CLOCKS_CLK_SYS_CTRL_SRC(v)          ((_u(v) & _u(0x1)) << _u(0))
#define CLOCKS_CLK_SYS_CTRL_SRC_MASK        CLOCKS_CLK_SYS_CTRL_SRC(ALL1)

#define CLOCKS_CLK_SYS_DIV_INT(v)           ((_u(v) & _u(0xffff)) << _u(16))
#define CLOCKS_CLK_SYS_DIV_INT_MASK         CLOCKS_CLK_SYS_DIV_INT(ALL1)
#define CLOCKS_CLK_SYS_DIV_FRAC(v)          ((_u(v) & _u(0xffff)) << _u(0))
#define CLOCKS_CLK_SYS_DIV_FRAC_MASK        CLOCKS_CLK_SYS_DIV_FRAC(ALL1)

#define CLOCKS_CLK_PERI_CTRL_ENABLE(v)      ((_u(v) & _u(0x1)) << 11)
#define CLOCKS_CLK_PERI_CTRL_ENABLE_MASK    CLOCKS_CLK_PERI_CTRL_ENABLE(ALL1)
#define CLOCKS_CLK_PERI_CTRL_AUXSRC(v)      ((_u(v) & _u(0x7)) << _u(5))
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_MASK    CLOCKS_CLK_PERI_CTRL_AUXSRC(ALL1)

#define CLOCKS_CLK_PERI_DIV_INT(v)           ((_u(v) & _u(0x3)) << _u(16))
#define CLOCKS_CLK_PERI_DIV_INT_MASK         CLOCKS_CLK_PERI_DIV_INT(ALL1)

#endif
