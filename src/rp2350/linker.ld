MEMORY
{
    FLASH   (rw)    : ORIGIN = 0x10000000, LENGTH = 4M
    RAM     (rwx)   : ORIGIN = 0x20000000, LENGTH = 520K
}

ENTRY(_entry_point)

SECTIONS
{
    .text : {
        KEEP(*(.vectors))
        KEEP(*(.embedded_block))
        KEEP(*(.init))
        *(.text*)
        *(.rodata*)
        __text_end = .;
    } > FLASH

    .data : {
        __data_lma = LOADADDR(.data);
        __data_start = .;
        KEEP(*(.data))
        *(.data*)
        __data_end = .;
    } > RAM AT> FLASH

    .bss (NOLOAD) : {
        __bss_start = .;
        *(.bss*)
    }
    __bss_end = .;
    __end = .;

    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
