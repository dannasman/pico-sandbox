#include <rp2350/resets.h>
#include <stdint.h>

extern void __stack_top(void);
extern void RESET_Handler(void);

static const uint32_t __attribute__((used, section(".embedded_block"))) __embedded_block[8] =
{
    0xffffded3,
    0x11010142,
    0x00000344,
    (uint32_t)(RESET_Handler),
    (uint32_t)(__stack_top),
    0x000004ff,
    0x00000000,
    0xab123579,
};

// TODO: figure out why DEFAULT_Handler can not be used...
#if CONFIG_COMPILER_GCC
__attribute__ ((interrupt("machine"), aligned(4)))
void default_handler(void);

__attribute__ ((interrupt("machine"), weak, alias("default_handler")))
void MTVEC_EXCEPTION_Handler(void);
__attribute__ ((interrupt("machine"), weak, alias("default_handler")))
void MTVEC_MSI_Handler(void);
__attribute__ ((interrupt("machine"), weak, alias("default_handler")))
void MTVEC_MTI_Handler(void);
__attribute__ ((interrupt("machine"), weak, alias("default_handler")))
void MTVEC_MEI_Handler(void);
#else
__attribute__ ((interrupt("machine"), section(".data"), aligned(4)))
void default_handler(void);

__attribute__ ((interrupt("machine"), weak, alias("default_handler"), section(".data")))
void MTVEC_EXCEPTION_Handler(void);
__attribute__ ((interrupt("machine"), weak, alias("default_handler"), section(".data")))
void MTVEC_MSI_Handler(void);
__attribute__ ((interrupt("machine"), weak, alias("default_handler"), section(".data")))
void MTVEC_MTI_Handler(void);
__attribute__ ((interrupt("machine"), weak, alias("default_handler"), section(".data")))
void MTVEC_MEI_Handler(void);
#endif

#if CONFIG_COMPILER_GCC
 __attribute__ ((naked, aligned(64)))
void __vector_table(void)
{
    __asm__ volatile (
            ".org       __vector_table + 0*4;"
            "jal        zero, MTVEC_EXCEPTION_Handler;"
            ".org       __vector_table + 3*4;"
            "jal        zero, MTVEC_MSI_Handler;"
            ".org       __vector_table + 7*4;"
            "jal        zero, MTVEC_MTI_Handler;"
            ".org       __vector_table + 11*4;"
            "jal        zero, MTVEC_MEI_Handler;"
            : /* no output */
            : /* immediate input */
            : /* no clobbers */);
}
#else
 __attribute__ ((naked, section(".data"), aligned(64)))
void __vector_table(void)
{
    __asm__ volatile (
            ".org       __vector_table + 0*4;"
            "jal        zero, MTVEC_EXCEPTION_Handler;"
            ".org       __vector_table + 3*4;"
            "jal        zero, MTVEC_MSI_Handler;"
            ".org       __vector_table + 7*4;"
            "jal        zero, MTVEC_MTI_Handler;"
            ".org       __vector_table + 11*4;"
            "jal        zero, MTVEC_MEI_Handler;"
            : /* no output */
            : /* immediate input */
            : /* no clobbers */);
}
#endif

void default_handler(void)
{
    resets.reset = 0x1ffffff;
    __asm__ volatile ("csrrc x0, mstatus, %0" :: "r"(0x8));
    while(1)
        __asm__ volatile ("wfi");
}

void __attribute__((used, section(".init" ))) _entry_point(void)
{
    RESET_Handler();
}
