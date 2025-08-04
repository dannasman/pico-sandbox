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
        KEEP(*(.reset))
        *(.text*)
        *(.rodata*)
        __text_end = .;
    } > FLASH

    .data : {
        . = ALIGN(4);
        __data_lma = LOADADDR(.data);
        __data_start = .;
        KEEP(*(.data.vectors))
        KEEP(*(.data))
        *(.data*)
        . = ALIGN(4);
        __data_end = .;
    } > RAM AT> FLASH

    .bss : {
        . = ALIGN(4);
        __bss_start = .;
        *(.bss*)
        . = ALIGN(4);
        __bss_end = .;
    } > RAM
    __end = .;

    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
