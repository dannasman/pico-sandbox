#ifndef RP2350_PADS_BANK0_H
#define RP2350_PADS_BANK0_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct {
    uint32_t voltage_select;
    uint32_t gpio0;
    uint32_t gpio1;
    uint32_t gpio2;
    uint32_t gpio3;
    uint32_t gpio4;
    uint32_t gpio5;
    uint32_t gpio6;
    uint32_t gpio7;
    uint32_t gpio8;
    uint32_t gpio9;
    uint32_t gpio10;
    uint32_t gpio11;
    uint32_t gpio12;
    uint32_t gpio13;
    uint32_t gpio14;
    uint32_t gpio15;
    uint32_t gpio16;
    uint32_t gpio17;
    uint32_t gpio18;
    uint32_t gpio19;
    uint32_t gpio20;
    uint32_t gpio21;
    uint32_t gpio22;
    uint32_t gpio23;
    uint32_t gpio24;
    uint32_t gpio25;
    uint32_t gpio26;
    uint32_t gpio27;
    uint32_t gpio28;
    uint32_t gpio29;
    uint32_t gpio30;
    uint32_t gpio31;
    uint32_t gpio32;
    uint32_t gpio33;
    uint32_t gpio34;
    uint32_t gpio35;
    uint32_t gpio36;
    uint32_t gpio37;
    uint32_t gpio38;
    uint32_t gpio39;
    uint32_t gpio40;
    uint32_t gpio41;
    uint32_t gpio42;
    uint32_t gpio43;
    uint32_t gpio44;
    uint32_t gpio45;
    uint32_t gpio46;
    uint32_t gpio47;
    uint32_t swclk;
    uint32_t swd;
    uint32_t RSVD_0[973];
    uint32_t voltage_select_xor;
    uint32_t gpio0_xor;
    uint32_t gpio1_xor;
    uint32_t gpio2_xor;
    uint32_t gpio3_xor;
    uint32_t gpio4_xor;
    uint32_t gpio5_xor;
    uint32_t gpio6_xor;
    uint32_t gpio7_xor;
    uint32_t gpio8_xor;
    uint32_t gpio9_xor;
    uint32_t gpio10_xor;
    uint32_t gpio11_xor;
    uint32_t gpio12_xor;
    uint32_t gpio13_xor;
    uint32_t gpio14_xor;
    uint32_t gpio15_xor;
    uint32_t gpio16_xor;
    uint32_t gpio17_xor;
    uint32_t gpio18_xor;
    uint32_t gpio19_xor;
    uint32_t gpio20_xor;
    uint32_t gpio21_xor;
    uint32_t gpio22_xor;
    uint32_t gpio23_xor;
    uint32_t gpio24_xor;
    uint32_t gpio25_xor;
    uint32_t gpio26_xor;
    uint32_t gpio27_xor;
    uint32_t gpio28_xor;
    uint32_t gpio29_xor;
    uint32_t gpio30_xor;
    uint32_t gpio31_xor;
    uint32_t gpio32_xor;
    uint32_t gpio33_xor;
    uint32_t gpio34_xor;
    uint32_t gpio35_xor;
    uint32_t gpio36_xor;
    uint32_t gpio37_xor;
    uint32_t gpio38_xor;
    uint32_t gpio39_xor;
    uint32_t gpio40_xor;
    uint32_t gpio41_xor;
    uint32_t gpio42_xor;
    uint32_t gpio43_xor;
    uint32_t gpio44_xor;
    uint32_t gpio45_xor;
    uint32_t gpio46_xor;
    uint32_t gpio47_xor;
    uint32_t swclk_xor;
    uint32_t swd_xor;
    uint32_t RSVDxor_0[973];
    uint32_t voltage_select_set;
    uint32_t gpio0_set;
    uint32_t gpio1_set;
    uint32_t gpio2_set;
    uint32_t gpio3_set;
    uint32_t gpio4_set;
    uint32_t gpio5_set;
    uint32_t gpio6_set;
    uint32_t gpio7_set;
    uint32_t gpio8_set;
    uint32_t gpio9_set;
    uint32_t gpio10_set;
    uint32_t gpio11_set;
    uint32_t gpio12_set;
    uint32_t gpio13_set;
    uint32_t gpio14_set;
    uint32_t gpio15_set;
    uint32_t gpio16_set;
    uint32_t gpio17_set;
    uint32_t gpio18_set;
    uint32_t gpio19_set;
    uint32_t gpio20_set;
    uint32_t gpio21_set;
    uint32_t gpio22_set;
    uint32_t gpio23_set;
    uint32_t gpio24_set;
    uint32_t gpio25_set;
    uint32_t gpio26_set;
    uint32_t gpio27_set;
    uint32_t gpio28_set;
    uint32_t gpio29_set;
    uint32_t gpio30_set;
    uint32_t gpio31_set;
    uint32_t gpio32_set;
    uint32_t gpio33_set;
    uint32_t gpio34_set;
    uint32_t gpio35_set;
    uint32_t gpio36_set;
    uint32_t gpio37_set;
    uint32_t gpio38_set;
    uint32_t gpio39_set;
    uint32_t gpio40_set;
    uint32_t gpio41_set;
    uint32_t gpio42_set;
    uint32_t gpio43_set;
    uint32_t gpio44_set;
    uint32_t gpio45_set;
    uint32_t gpio46_set;
    uint32_t gpio47_set;
    uint32_t swclk_set;
    uint32_t swd_set;
    uint32_t RSVDset_0[973];
    uint32_t voltage_select_clr;
    uint32_t gpio0_clr;
    uint32_t gpio1_clr;
    uint32_t gpio2_clr;
    uint32_t gpio3_clr;
    uint32_t gpio4_clr;
    uint32_t gpio5_clr;
    uint32_t gpio6_clr;
    uint32_t gpio7_clr;
    uint32_t gpio8_clr;
    uint32_t gpio9_clr;
    uint32_t gpio10_clr;
    uint32_t gpio11_clr;
    uint32_t gpio12_clr;
    uint32_t gpio13_clr;
    uint32_t gpio14_clr;
    uint32_t gpio15_clr;
    uint32_t gpio16_clr;
    uint32_t gpio17_clr;
    uint32_t gpio18_clr;
    uint32_t gpio19_clr;
    uint32_t gpio20_clr;
    uint32_t gpio21_clr;
    uint32_t gpio22_clr;
    uint32_t gpio23_clr;
    uint32_t gpio24_clr;
    uint32_t gpio25_clr;
    uint32_t gpio26_clr;
    uint32_t gpio27_clr;
    uint32_t gpio28_clr;
    uint32_t gpio29_clr;
    uint32_t gpio30_clr;
    uint32_t gpio31_clr;
    uint32_t gpio32_clr;
    uint32_t gpio33_clr;
    uint32_t gpio34_clr;
    uint32_t gpio35_clr;
    uint32_t gpio36_clr;
    uint32_t gpio37_clr;
    uint32_t gpio38_clr;
    uint32_t gpio39_clr;
    uint32_t gpio40_clr;
    uint32_t gpio41_clr;
    uint32_t gpio42_clr;
    uint32_t gpio43_clr;
    uint32_t gpio44_clr;
    uint32_t gpio45_clr;
    uint32_t gpio46_clr;
    uint32_t gpio47_clr;
    uint32_t swclk_clr;
    uint32_t swd_clr;
    uint32_t RSVDclr_0[973];
} pads_bank0_regs;

#define pads_bank0 (*(volatile pads_bank0_regs *)(_u(0x40038000)))

#define PADS_BANK0_GPIO0_ISO(v)         ((_u(v) & _u(0x1)) << _u(8))
#define PADS_BANK0_GPIO0_ISO_MASK       PADS_BANK0_GPIO0_ISO(ALL1)
#define PADS_BANK0_GPIO0_OD(v)          ((_u(v) & _u(0x1)) << _u(7))
#define PADS_BANK0_GPIO0_OD_MASK        PADS_BANK0_GPIO0_OD(ALL1)
#define PADS_BANK0_GPIO0_IE(v)          ((_u(v) & _u(0x1)) << _u(6))
#define PADS_BANK0_GPIO0_IE_MASK        PADS_BANK0_GPIO0_IE(ALL1)
#define PADS_BANK0_GPIO0_DRIVE(v)       ((_u(v) & _u(0x3)) << _u(4))
#define PADS_BANK0_GPIO0_PUE(v)         ((_u(v) & _u(0x1)) << _u(3))
#define PADS_BANK0_GPIO0_PUE_MASK       PADS_BANK0_GPIO0_PUE(ALL1)
#define PADS_BANK0_GPIO0_PDE(v)         ((_u(v) & _u(0x1)) << _u(2))
#define PADS_BANK0_GPIO0_PDE_MASK       PADS_BANK0_GPIO0_PDE(ALL1)
#define PADS_BANK0_GPIO0_SCHMITT(v)     ((_u(v) & _u(0x1)) << _u(1))
#define PADS_BANK0_GPIO0_SCHMITT_MASK   PADS_BANK0_GPIO0_SCHMITT(ALL1)
#define PADS_BANK0_GPIO0_SLEWFAST(v)    ((_u(v) & _u(0x1)) << _u(0))
#define PADS_BANK0_GPIO0_SLEWFAST_MASK  PADS_BANK0_GPIO0_SLEWFAST(ALL1)

#define PADS_BANK0_GPIO1_ISO(v)         ((_u(v) & _u(0x1)) << _u(8))
#define PADS_BANK0_GPIO1_ISO_MASK       PADS_BANK0_GPIO1_ISO(ALL1)
#define PADS_BANK0_GPIO1_OD(v)          ((_u(v) & _u(0x1)) << _u(7))
#define PADS_BANK0_GPIO1_OD_MASK        PADS_BANK0_GPIO1_OD(ALL1)
#define PADS_BANK0_GPIO1_IE(v)          ((_u(v) & _u(0x1)) << _u(6))
#define PADS_BANK0_GPIO1_IE_MASK        PADS_BANK0_GPIO1_IE(ALL1)
#define PADS_BANK0_GPIO1_DRIVE(v)       ((_u(v) & _u(0x3)) << _u(4))
#define PADS_BANK0_GPIO1_PUE(v)         ((_u(v) & _u(0x1)) << _u(3))
#define PADS_BANK0_GPIO1_PUE_MASK       PADS_BANK0_GPIO1_PUE(ALL1)
#define PADS_BANK0_GPIO1_PDE(v)         ((_u(v) & _u(0x1)) << _u(2))
#define PADS_BANK0_GPIO1_PDE_MASK       PADS_BANK0_GPIO1_PDE(ALL1)
#define PADS_BANK0_GPIO1_SCHMITT(v)     ((_u(v) & _u(0x1)) << _u(1))
#define PADS_BANK0_GPIO1_SCHMITT_MASK   PADS_BANK0_GPIO1_SCHMITT(ALL1)
#define PADS_BANK0_GPIO1_SLEWFAST(v)    ((_u(v) & _u(0x1)) << _u(0))
#define PADS_BANK0_GPIO1_SLEWFAST_MASK  PADS_BANK0_GPIO1_SLEWFAST(ALL1)

#endif
