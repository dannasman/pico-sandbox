#ifndef CPU_UTILS_H
#define CPU_UTILS_H

#if defined(CONFIG_MACH_RISCV)
#include <csr.h>
#else
#include <rp2350/arm/m33.h>
#endif

static inline uint32_t cycle_count(void);
static inline void nop(void) __attribute__((always_inline));
static inline void delay(uint32_t) __attribute__((always_inline));
static inline void tight_loop_contents(void) __attribute__((always_inline));

// cpu registers need to be initialized before calling
static inline uint32_t cycle_count(void)
{
#if defined(CONFIG_MACH_RISCV)
    uint32_t ret;
    __asm__ volatile ("csrr %0, 0xb00" : "=r"(ret));
    return ret;
#else
    return m33.dwt_cyccnt;
#endif
}

static inline void nop(void)
{
    __asm__ volatile ("nop");
}

static inline void delay(uint32_t n)
{
    for (uint32_t i=0; i<n; i++)
        __asm__ volatile ("nop");
}

static inline void tight_loop_contents(void) {}

#endif
