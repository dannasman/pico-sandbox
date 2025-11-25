#include <stdint.h>
#include <riscv/csr.h>
#include <rp2350/resets.h>
#include <utils/cpu.h>

#include "irq.h"
#include "pl011.h"

extern void __vector_table(void);

__attribute__ ((section(".data.soft_vectors"), aligned(16)))
void (*const irq_handlers[52])(void) = {
    [33] = &UART0_IRQ_Handler,
};

void irq_init(void) {
    csr_clr_bits_mstatus(0x8U);
    csr_write_mie(0);
    csr_write_mtvec((uint32_t)__vector_table | 0x1U);
    csr_set_bits_mie(0x800);
    csr_set_bits_mstatus(0x8);
}

void irq_enable(uint32_t irq_no, uint32_t pri)
{
    uint32_t index = irq_no / 16U;
    uint32_t mask = 1U << (irq_no % 16U);
    __asm__ volatile ("csrs 0xbe0, %0" : : "r" (index | (mask << 16)));
}

static inline void irq_save_context(void)
{
    __asm__ volatile (
            "addi sp, sp, -64;"
            "sw ra, 0(sp);"
            "sw t0, 4(sp);"
            "sw t1, 8(sp);"
            "sw t2, 12(sp);"
            "sw a0, 16(sp);"
            "sw a1, 20(sp);"
            "sw a2, 24(sp);"
            "sw a3, 28(sp);"
            "sw a4, 32(sp);"
            "sw a5, 36(sp);"
            "sw a6, 40(sp);"
            "sw a7, 44(sp);"
            "sw t3, 48(sp);"
            "sw t4, 52(sp);"
            "sw t5, 56(sp);"
            "sw t6, 60(sp);");
}

static inline void irq_restore_context(void)
{
    __asm__ volatile (
            "lw ra, 0(sp);"
            "lw t0, 4(sp);"
            "lw t1, 8(sp);"
            "lw t2, 12(sp);"
            "lw a0, 16(sp);"
            "lw a1, 20(sp);"
            "lw a2, 24(sp);"
            "lw a3, 28(sp);"
            "lw a4, 32(sp);"
            "lw a5, 36(sp);"
            "lw a6, 40(sp);"
            "lw a7, 44(sp);"
            "lw t3, 48(sp);"
            "lw t4, 52(sp);"
            "lw t5, 56(sp);"
            "lw t6, 60(sp);"
            "addi sp, sp, 64;");
}

void __attribute__ ((interrupt ("machine"), section(".data"), aligned(4))) MTVEC_MEI_Handler(void)
{
    irq_save_context();

    uint32_t val = csr_read_meinext();
    while ((val & (1U << 31)) == 0) {
        uint32_t irq_no = val >> 2;
        if (irq_handlers[irq_no] != 0x0)
            (irq_handlers[irq_no])();
        val = csr_read_meinext();
    }

    irq_restore_context();
}

