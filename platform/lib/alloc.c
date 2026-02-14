#include <stdint.h>

#include "lib/alloc.h"

#include <pl011.h>
#include <lib/string.h>

#define HEAPSIZE (0x10000)

extern char __heap_start[HEAPSIZE];
extern char __heap_end[];

static size_t heap_next = 0;

void *p2s_alloc(size_t sz) {
    sz = (sz + 7) & ~7;

    if (heap_next + sz > HEAPSIZE) {
        return NULL;
    }

    void *p = (void *)&__heap_start[heap_next];
    heap_next += sz;

    return p;
}
