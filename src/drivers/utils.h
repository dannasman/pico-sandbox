#ifndef UTILS_H
#define UTILS_H

static inline void nop(void) __attribute__((always_inline));
static inline void delay(uint32_t) __attribute__((always_inline));

static inline void nop(void)
{
    __asm__ volatile ("nop");
}

static inline void delay(uint32_t n)
{
    for (uint32_t i=0; i<n; i++)
        __asm__ volatile ("nop");
}

#endif
