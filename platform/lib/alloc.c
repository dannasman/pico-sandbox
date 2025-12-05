#include <stddef.h>
#include <stdint.h>

#include "lib/alloc.h"

extern uint8_t heap_begin[];
extern uint8_t heap_end[];

static uint8_t* heap_next = heap_begin;

void *p2s_alloc(size_t sz) {
    if (heap_next + sz > heap_end) {
        return NULL;
    }

    void *p = heap_next + sz;
    heap_next += sz;
    return p;
}
