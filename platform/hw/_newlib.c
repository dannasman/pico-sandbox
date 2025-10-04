#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t quotient;
    uint64_t remainder;
} udivmod64_t;

udivmod64_t __aeabi_uldivmod(uint64_t, uint64_t);
uint64_t __umdivdi3(uint64_t, uint64_t);
uint64_t __umoddi3(uint64_t, uint64_t);
void *memcpy(void *, const void *, size_t);

void *memcpy(void *to, const void *from, size_t n) {
    uint8_t *t = (uint8_t *)to;
    const uint8_t *f = (const uint8_t *)from;
    while (n--) {
        *t++ = *f++;
    }
    return to;
}

udivmod64_t __aeabi_uldivmod(uint64_t n, uint64_t d)
{
    udivmod64_t res;
    res.quotient = n / d;
    res.remainder = n % d;
    return res;
}

uint64_t __udivdi3(uint64_t n, uint64_t d)
{
    uint64_t res = n / d;
    return res;
}

uint64_t __umoddi3(uint64_t n, uint64_t d)
{
    uint64_t res = n % d;
    return res;
}
