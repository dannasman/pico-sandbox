MEMORY
{
    FLASH   (rw)    : ORIGIN = 0x10000000, LENGTH = 4M
    RAM     (rwx)   : ORIGIN = 0x20000000, LENGTH = 520K
}

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
        __data_lma = LOADADDR(.data);
        __data_start = .;
        KEEP(*(.data))
        *(.data*)
        __data_end = .;
    } > RAM AT> FLASH

    .bss : {
        __bss_start = .;
        *(.bss)
        *(.bss.*)
        PROVIDE(__global_pointer$ = . + 2K);
        *(.sbss)
        *(.sbss.*)
        __bss_end = .;
    } > RAM

    .heap (NOLOAD) : {
        . = ALIGN(8);
        __heap_start = .;
        KEEP(*(.heap))
        . += 0x10000;
        __heap_end = .;
    } > RAM

    __end = .;

    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
