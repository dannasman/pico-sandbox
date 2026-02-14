#include "lib/string.h"

int32_t strlen(const char *s) {
    const char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}

int32_t strcmp(const char *s, const char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
