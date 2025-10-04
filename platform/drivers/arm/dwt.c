#include <arm/rp2350/m33.h>

void dwt_init(void)
{
    uint32_t reg;

    reg = m33.demcr;
    reg |= M33_DEMCR_TRCENA_MASK;
    m33.demcr = reg;

    reg = m33.dwt_ctrl;
    reg |= M33_DWT_CTRL_CYCCNTENA_MASK;
    m33.dwt_ctrl = reg;
}
