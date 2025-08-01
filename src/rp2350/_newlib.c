#include <stddef.h>
#include <stdint.h>

void *memcpy(void *, const void *, size_t);

void *memcpy(void *to, const void *from, size_t n) {
    uint8_t *t = (uint8_t *)to;
    const uint8_t *f = (const uint8_t *)from;
    while (n--) {
        *t++ = *f++;
    }
    return to;
}
