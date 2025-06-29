#include <rp2350/arm/m33.h>

#include <stdint.h>

#define RAMSIZE (520*1024)

extern char __bss_start[RAMSIZE], __bss_end[];
extern char __data_start[RAMSIZE], __data_end[], __data_lma[RAMSIZE];

extern void main();
extern void __vector_table();

// TODO: configure clocks
void RESET_Handler() {
    // copy data section to SRAM
    char *to = __data_start;
    char *from = __data_lma;
    while (to < __data_end)
        *to++ = *from++;

    // zero out the BSS section
    to = __bss_start;
    while (to < __bss_end)
        *to++ = 0;

    main();
}

void _entry_point() {
    m33.vtor = (uint32_t)(&__vector_table);
    RESET_Handler();
}

