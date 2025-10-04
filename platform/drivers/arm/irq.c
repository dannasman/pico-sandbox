#include <arm/rp2350/m33.h>

#include "irq.h"

#define IRQ_IPR_PRI(n, v)       ((v) << (4 + (n) * 8))
#define IRQ_IPR_PRI_MASK(n)     (0xfU << (4 + (n) * 8))

void irq_enable(uint32_t irq_no, uint32_t pri)
{
    /* FIXME: assertions... */
    if (irq_no >= 64 || pri > 15) return;

    const uint32_t ipr_no = irq_no / 4U;
    const uint32_t pri_no = irq_no % 4U;

    if (irq_no < 32U) {
        m33.nvic_iser0 = (1U << irq_no);
    } else {
        m33.nvic_iser1 = (1U << (irq_no - 32U));
    }

    switch (ipr_no) {
        case 0:
            m33.nvic_ipr0 = (m33.nvic_ipr0 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 1:
            m33.nvic_ipr1 = (m33.nvic_ipr1 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 2:
            m33.nvic_ipr2 = (m33.nvic_ipr2 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 3:
            m33.nvic_ipr3 = (m33.nvic_ipr4 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 4:
            m33.nvic_ipr4 = (m33.nvic_ipr4 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 5:
            m33.nvic_ipr5 = (m33.nvic_ipr5 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 6:
            m33.nvic_ipr6 = (m33.nvic_ipr6 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 7:
            m33.nvic_ipr7 = (m33.nvic_ipr7 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 8:
            m33.nvic_ipr8 = (m33.nvic_ipr8 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 9:
            m33.nvic_ipr9 = (m33.nvic_ipr9 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 10:
            m33.nvic_ipr10 = (m33.nvic_ipr10 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 11:
            m33.nvic_ipr11 = (m33.nvic_ipr11 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 12:
            m33.nvic_ipr12 = (m33.nvic_ipr12 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 13:
            m33.nvic_ipr13 = (m33.nvic_ipr13 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 14:
            m33.nvic_ipr14 = (m33.nvic_ipr14 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        case 15:
            m33.nvic_ipr15 = (m33.nvic_ipr15 & ~IRQ_IPR_PRI_MASK(pri_no)) | IRQ_IPR_PRI(pri_no, pri);
            break;
        default:
            break;
    }

    if (irq_no < 32U) {
        m33.nvic_icpr0 = (1U << irq_no);
    } else {
        m33.nvic_icpr1 = (1U << (irq_no - 32U));
    }

}
