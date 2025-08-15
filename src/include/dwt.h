#ifndef DWT_H
#define DWT_H

#include <rp2350/arm/m33.h>

void dwt_init(void);
static inline uint32_t dwt_cycle_count(void);

static inline uint32_t dwt_cycle_count(void)
{
    return m33.dwt_cyccnt;
}

#endif
