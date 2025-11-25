cmake_minimum_required(VERSION 3.22)

project(pico2_sandbox)

if(TOOLCHAIN STREQUAL "clang")
    set(TOOLCHAIN_PATH "${CMAKE_SOURCE_DIR}/toolchain/llvm/bin")
    set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/clang")
    set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/clang")
    if(TARGET_CORE STREQUAL "cortex-m33")
        set(COPTS
            -mcpu=cortex-m33
            --target=armv8m.main-none-eabi
            -mfloat-abi=softfp
            -march=armv8m.main+fp+dsp
            -Oz
            -DNDEBUG
            -ffreestanding
            -ffunction-sections
            -fdata-sections
            -nostdlib
            -pedantic)
    elseif(TARGET_CORE STREQUAL "hazard3")
        set(COPTS
            --target=riscv32-unknown-elf
            -mcpu=rp2350-hazard3
            #-march=rv32imac_zicsr_zifencei_zba_zbb_zbs_zbkb
            -Oz
            -DNDEBUG
            -mabi=ilp32
            -ffreestanding
            -ffunction-sections
            -fdata-sections
            -nostdlib
            -pedantic)
    else()
        message(FATAL_ERROR "Unknown TARGET_CORE: ${TARGET_CORE}. Use cortex-m33 or hazard3.")
    endif()
elseif(TOOLCHAIN STREQUAL "gcc")
    if(TARGET_CORE STREQUAL "cortex-m33")
        set(TOOLCHAIN_PATH "${CMAKE_SOURCE_DIR}/toolchain/gcc-arm/bin")
        set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/arm-none-eabi-gcc")
        set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/arm-none-eabi-gcc")
        set(COPTS
            -mcpu=cortex-m33
            -mthumb
            -march=armv8-m.main+fp+dsp
            -mfloat-abi=softfp
            -Oz
            -DNDEBUG
            -ffreestanding
            -ffunction-sections
            -fdata-sections
            -nostdlib
            -pedantic)
    elseif(TARGET_CORE STREQUAL "hazard3")   
        set(TOOLCHAIN_PATH "${CMAKE_SOURCE_DIR}/toolchain/gcc-riscv/bin")
        set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/riscv32-unknown-elf-gcc")
        set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/riscv32-unknown-elf-gcc")
        set(COPTS
            -march=rv32ima_zicsr_zifencei_zba_zbb_zbs_zbkb_zca_zcb_zcmp
            #-march=rv32imac_zicsr_zifencei_zba_zbb_zbs_zbkb
            -mabi=ilp32
            -Oz
            -DNDEBUG
            -ffreestanding
            -ffunction-sections
            -fdata-sections
            -nostdlib
            -pedantic)
    else()
        message(FATAL_ERROR "Unknown TARGET_CORE: ${TARGET_CORE}. Use cortex-m33 or hazard3.")
    endif()
else()
    message(FATAL_ERROR "Unknown TOOLCHAIN: ${TOOLCHAIN}. Use gcc or clang.")
endif()

option(TARGET_CORE "Target core architecture: cortex-m33 or hazard3" "cortex-m33")

if(TARGET_CORE STREQUAL "cortex-m33")
    add_definitions(-DCONFIG_MACH_ARM)
    file(GLOB SOURCES
        ${CMAKE_SOURCE_DIR}/platform/hw/arm/*c
        ${CMAKE_SOURCE_DIR}/platform/hw/*c
        ${CMAKE_SOURCE_DIR}/platform/drivers/*c
        ${CMAKE_SOURCE_DIR}/platform/drivers/arm/*c
        ${CMAKE_SOURCE_DIR}/platform/utils/*c
        ${CMAKE_SOURCE_DIR}/platform/*c
    )

    add_executable(sandbox.elf ${SOURCES})
    target_include_directories(sandbox.elf PRIVATE
        ${CMAKE_SOURCE_DIR}/platform/include/arm
    )

    message(STATUS "Configuring for Cortex-M33")
    target_compile_options(sandbox.elf PRIVATE ${COPTS})
elseif(TARGET_CORE STREQUAL "hazard3")
    add_definitions(-DCONFIG_MACH_RISCV)
    file(GLOB SOURCES
        ${CMAKE_SOURCE_DIR}/platform/hw/riscv/*c
        ${CMAKE_SOURCE_DIR}/platform/hw/*c
        ${CMAKE_SOURCE_DIR}/platform/drivers/*c
        ${CMAKE_SOURCE_DIR}/platform/drivers/riscv/*c
        ${CMAKE_SOURCE_DIR}/platform/utils/*c
        ${CMAKE_SOURCE_DIR}/platform/*c
    )

    add_executable(sandbox.elf ${SOURCES})
    target_include_directories(sandbox.elf PRIVATE
        ${CMAKE_SOURCE_DIR}/platform/include/riscv
    )

    message(STATUS "Configuring for Hazard3 (RISC-V)")
    target_compile_options(sandbox.elf PRIVATE ${COPTS})
else()
    message(FATAL_ERROR "Unknown TARGET_CORE: ${TARGET_CORE}. Use cortex-m33 or hazard3.")
endif()

target_include_directories(sandbox.elf PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/include
    ${CMAKE_SOURCE_DIR}/platform/include
)

target_link_options(sandbox.elf PRIVATE
    -nostartfiles
    -nostdlib
    -Wl,--gc-sections
    -T${CMAKE_SOURCE_DIR}/platform/hw/linker.ld
)
