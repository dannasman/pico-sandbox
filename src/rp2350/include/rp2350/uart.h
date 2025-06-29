#ifndef RP2350_UART_H
#define RP2350_UART_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct {
    uint32_t uartdr;
    uint32_t uartrsr;
    uint32_t RSVD0[4];
    uint32_t uartfr;
    uint32_t uartilpr;
    uint32_t RSVD1;
    uint32_t uartibrd;
    uint32_t uartfbrd;
    uint32_t uartlcr_h;
    uint32_t uartcr;
    uint32_t uartifls;
    uint32_t uartimsc;
    uint32_t uartris;
    uint32_t uartmis;
    uint32_t uarticr;
    uint32_t uartdmacr;
    uint32_t RSVD2[997];
    uint32_t uartperiphid0;
    uint32_t uartperiphid1;
    uint32_t uartperiphid2;
    uint32_t uartperiphid3;
    uint32_t uartpcellid0;
    uint32_t uartpcellid1;
    uint32_t uartpcellid2;
    uint32_t uartpcellid3;
    uint32_t uartdr_xor;
    uint32_t uartrsr_xor;
    uint32_t RSVDxor_0[4];
    uint32_t uartfr_xor;
    uint32_t uartilpr_xor;
    uint32_t RSVDxor_1;
    uint32_t uartibrd_xor;
    uint32_t uartfbrd_xor;
    uint32_t uartlcr_h_xor;
    uint32_t uartcr_xor;
    uint32_t uartifls_xor;
    uint32_t uartimsc_xor;
    uint32_t uartris_xor;
    uint32_t uartmis_xor;
    uint32_t uarticr_xor;
    uint32_t uartdmacr_xor;
    uint32_t RSVDxor_2[997];
    uint32_t uartperiphid0_xor;
    uint32_t uartperiphid1_xor;
    uint32_t uartperiphid2_xor;
    uint32_t uartperiphid3_xor;
    uint32_t uartpcellid0_xor;
    uint32_t uartpcellid1_xor;
    uint32_t uartpcellid2_xor;
    uint32_t uartpcellid3_xor;
    uint32_t uartdr_set;
    uint32_t uartrsr_set;
    uint32_t RSVDset_0[4];
    uint32_t uartfr_set;
    uint32_t uartilpr_set;
    uint32_t RSVDset_1;
    uint32_t uartibrd_set;
    uint32_t uartfbrd_set;
    uint32_t uartlcr_h_set;
    uint32_t uartcr_set;
    uint32_t uartifls_set;
    uint32_t uartimsc_set;
    uint32_t uartris_set;
    uint32_t uartmis_set;
    uint32_t uarticr_set;
    uint32_t uartdmacr_set;
    uint32_t RSVDset_2[997];
    uint32_t uartperiphid0_set;
    uint32_t uartperiphid1_set;
    uint32_t uartperiphid2_set;
    uint32_t uartperiphid3_set;
    uint32_t uartpcellid0_set;
    uint32_t uartpcellid1_set;
    uint32_t uartpcellid2_set;
    uint32_t uartpcellid3_set;
    uint32_t uartdr_clr;
    uint32_t uartrsr_clr;
    uint32_t RSVDclr_0[4];
    uint32_t uartfr_clr;
    uint32_t uartilpr_clr;
    uint32_t RSVDclr_1;
    uint32_t uartibrd_clr;
    uint32_t uartfbrd_clr;
    uint32_t uartlcr_h_clr;
    uint32_t uartcr_clr;
    uint32_t uartifls_clr;
    uint32_t uartimsc_clr;
    uint32_t uartris_clr;
    uint32_t uartmis_clr;
    uint32_t uarticr_clr;
    uint32_t uartdmacr_clr;
    uint32_t RSVDclr_2[997];
    uint32_t uartperiphid0_clr;
    uint32_t uartperiphid1_clr;
    uint32_t uartperiphid2_clr;
    uint32_t uartperiphid3_clr;
    uint32_t uartpcellid0_clr;
    uint32_t uartpcellid1_clr;
    uint32_t uartpcellid2_clr;
    uint32_t uartpcellid3_clr;
} uart_regs;

#define uart0 (*(volatile uart_regs *)(_u(0x40070000)))
#define uart1 (*(volatile uart_regs *)(_u(0x40078000)))

#define UART_UARTDR_OE(v)       ((_u(v) & 0x1) << _u(11))
#define UART_UARTDF_OE_MASK     UART_UARTDR_OE(ALL1)
#define UART_UARTDR_BE(v)       ((_u(v) & 0x1) << _u(10))
#define UART_UARTDR_BE_MASK     UART_UARTDR_BE(ALL1)
#define UART_UARTDR_PE(v)       ((_u(v) & 0x1) << _u(9))
#define UART_UARTDR_PE_MASK     UART_UARTDR_PE(ALL1)
#define UART_UARTDR_FE(v)       ((_u(v) & 0x1) << _u(8))
#define UART_UARTDR_FE_MASK     UART_UARTDR_FE(ALL1)
#define UART_UARTDR_DATA(v)     ((_u(v) & 0xff) << _u(0))

#define UART_UARTRSR_OE(v)      ((_u(v) & 0x1) << _u(3))
#define UART_UARTRSR_OE_MASK    UART_UARTSRS_OE(ALL1)
#define UART_UARTSRS_BE(v)      ((_u(v) & 0x1) << _u(2))
#define UART_UARTSRS_BE_MASK    UART_UARTSRS_BE(ALL1)
#define UART_UARTSRS_PE(v)      ((_u(v) & 0x1) << _u(1))
#define UART_UARTSRS_PE_MASK    UART_UARTSRS_PE(ALL1)
#define UART_UARTSRS_FE(v)      ((_u(v) & 0x1) << _u(0))
#define UART_UARTSRS_FE_MASK    UART_UARTSRS_FE(ALL1)

#define UART_UARTFR_RI(v)       ((_u(v) & 0x1) << _u(8))
#define UART_UARTFR_RI_MASK     UART_UARTFR_RI(ALL1)
#define UART_UARTFR_TXFE(v)     ((_u(v) & 0x1) << _u(7))
#define UART_UARTFR_TXFE_MASK   UART_UARTFR_TXFE(ALL1)
#define UART_UARTFR_RXFF(v)     ((_u(v) & 0x1) << _u(6))
#define UART_UARTFR_RXFF_MASK   UART_UARTFR_RXFF(ALL1)
#define UART_UARTFR_TXFF(v)     ((_u(v) & 0x1) << _u(5))
#define UART_UARTFR_TXFF_MASK   UART_UARTFR_TXFF(ALL1)
#define UART_UARTFR_RXFE(v)     ((_u(v) & 0x1) << _u(4))
#define UART_UARTFR_RXFE_MASK   UART_UARTFR_RXFE(ALL1)
#define UART_UARTFR_BUSY(v)     ((_u(v) & 0x1) << _u(3))
#define UART_UARTFR_BUSY_MASK   UART_UARTFR_BUSY(ALL1)
#define UART_UARTFR_DCD(v)      ((_u(v) & 0x1) << _u(2))
#define UART_UARTFR_DCD_MASK    UART_UARTFR_DCD(ALL1)
#define UART_UARTFR_DSR(v)      ((_u(v) & 0x1) << _u(1))
#define UART_UARTFR_DSR_MASK    UART_UARTFR_DSR(ALL1)
#define UART_UARTFR_DSR(v)      ((_u(v) & 0x1) << _u(1))
#define UART_UARTFR_DSR_MASK    UART_UARTFR_DSR(ALL1)
#define UART_UARTFR_CTS(v)      ((_u(v) & 0x1) << _u(0))
#define UART_UARTFR_CTS_MASK    UART_UARTFR_CTS(ALL1)

#define UART_UARTILPR_IPDVSR(v)     ((_u(v) & 0xff) << _u(0))

#define UART_UARTIBRD_BAUD_DIVINT(v)    ((_u(v) & 0xffff) << _u(0))

#define UART_UARTFBRD_BAUD_DIVFRAC(v)   ((_u(v) & 0x3f) << _u(0))

#define UART_UARTLCR_H_SPS(v)       ((_u(v) & 0x1) << _u(7))
#define UART_UARTLCR_H_SPS_MASK     UART_UARTLCR_H_SPS(ALL1)
#define UART_UARTLCR_H_WLEN(v)      ((_u(v) & 0x3) << _u(5))
#define UART_UARTLCR_H_FEN(v)       ((_u(v) & 0x1) << _u(4))
#define UART_UARTLCR_H_FEN_MASK     UART_UARTLCR_H_FEN(ALL1)
#define UART_UARTLCR_H_STP2(v)      ((_u(v) & 0x1) << _u(3))
#define UART_UARTLCR_H_STP2_MASK    UART_UARTLCR_H_STP2(ALL1)
#define UART_UARTLCR_H_EPS(v)       ((_u(v) & 0x1) << _u(2))
#define UART_UARTLCR_H_EPS_MASK     UART_UARTLCR_H_EPS(ALL1)
#define UART_UARTLCR_H_PEN(v)       ((_u(v) & 0x1) << _u(1))
#define UART_UARTLCR_H_PEN_MASK     UART_UARTLCR_H_PEN(ALL1)
#define UART_UARTLCR_H_BRK(v)       ((_u(v) & 0x1) << _u(0))
#define UART_UARTLCR_H_BRK_MASK     UART_UARTLCR_H_BRK(ALL1)

#define UART_UARTCR_CTSEN(v)        ((_u(v) & 0x1) << _u(15))
#define UART_UARTCR_CTSEN_MASK      UART_UARTCR_CTSEN(ALL1)
#define UART_UARTCR_RTSEN(v)        ((_u(v) & 0x1) << _u(14))
#define UART_UARTCR_RTSEN_MASK      UART_UARTCR_RTSEN(ALL1)
#define UART_UARTCR_OUT2(v)         ((_u(v) & 0x1) << _u(13))
#define UART_UARTCR_OUT2_MASK       UART_UARTCR_OUT2(ALL1)
#define UART_UARTCR_OUT1(v)         ((_u(v) & 0x1) << _u(12))
#define UART_UARTCR_OUT1_MASK       UART_UARTCR_OUT1(ALL1)
#define UART_UARTCR_RTS(v)          ((_u(v) & 0x1) << _u(11))
#define UART_UARTCR_RTS_MASK        UART_UARTCR_RTS(ALL1)
#define UART_UARTCR_DTR(v)          ((_u(v) & 0x1) << _u(10))
#define UART_UARTCR_DTR_MASK        UART_UARTCR_DTR(ALL1)
#define UART_UARTCR_RXE(v)          ((_u(v) & 0x1) << _u(9))
#define UART_UARTCR_RXE_MASK        UART_UARTCR_RXE(ALL1)
#define UART_UARTCR_TXE(v)          ((_u(v) & 0x1) << _u(8))
#define UART_UARTCR_TXE_MASK        UART_UARTCR_TXE(ALL1)
#define UART_UARTCR_LBE(v)          ((_u(v) & 0x1) << _u(7))
#define UART_UARTCR_LBE_MASK        UART_UARTCR_LBE(ALL1)
#define UART_UARTCR_SIRLP(v)        ((_u(v) & 0x1) << _u(2))
#define UART_UARTCR_SIRLP_MASK      UART_UARTCR_SIRLP(ALL1)
#define UART_UARTCR_SIREN(v)        ((_u(v) & 0x1) << _u(1))
#define UART_UARTCR_SIREN_MASK      UART_UARTCR_SIREN(ALL1)
#define UART_UARTCR_UARTEN(v)       ((_u(v) & 0x1) << _u(0))
#define UART_UARTCR_UARTEN_MASK     UART_UARTCR_UARTEN(ALL1)

#define UART_UARTIFLS_RXIFLSEL      ((_u(v) & 0x7) << _u(3))
#define UART_UARTIFLS_TXIFLSEL      ((_u(v) & 0x7) << _u(0))

#define UART_UARTIMSC_OEIM          ((_u(v) & 0x1) << _u(10))
#define UART_UARTIMSC_OEIM_MASK     UART_UARTIMSC_OEIM(ALL1)
#define UART_UARTIMSC_BEIM          ((_u(v) & 0x1) << _u(9))
#define UART_UARTIMSC_BEIM_MASK     UART_UARTIMSC_BEIM(ALL1)
#define UART_UARTIMSC_PEIM          ((_u(v) & 0x1) << _u(8))
#define UART_UARTIMSC_PEIM_MASK     UART_UARTIMSC_PEIM(ALL1)
#define UART_UARTIMSC_FEIM          ((_u(v) & 0x1) << _u(7))
#define UART_UARTIMSC_FEIM_MASK     UART_UARTIMSC_FEIM(ALL1)
#define UART_UARTIMSC_RTIM          ((_u(v) & 0x1) << _u(6))
#define UART_UARTIMSC_RTIM_MASK     UART_UARTIMSC_RTIM(ALL1)
#define UART_UARTIMSC_TXIM          ((_u(v) & 0x1) << _u(5))
#define UART_UARTIMSC_TXIM_MASK     UART_UARTIMSC_TXIM(ALL1)
#define UART_UARTIMSC_RXIM          ((_u(v) & 0x1) << _u(4))
#define UART_UARTIMSC_RXIM_MASK     UART_UARTIMSC_RXIM(ALL1)
#define UART_UARTIMSC_DSRMIM        ((_u(v) & 0x1) << _u(3))
#define UART_UARTIMSC_DSRMIM_MASK   UART_UARTIMSC_DSRMIM(ALL1)
#define UART_UARTIMSC_DCDMIM        ((_u(v) & 0x1) << _u(2))
#define UART_UARTIMSC_DCDMIM_MASK   UART_UARTIMSC_DCDMIM(ALL1)
#define UART_UARTIMSC_CTSMIM        ((_u(v) & 0x1) << _u(1))
#define UART_UARTIMSC_CTSMIM_MASK   UART_UARTIMSC_CTSMIM(ALL1)
#define UART_UARTIMSC_RIMIM         ((_u(v) & 0x1) << _u(0))
#define UART_UARTIMSC_RIMIM_MASK    UART_UARTIMSC_RIMIM(ALL1)

#endif
