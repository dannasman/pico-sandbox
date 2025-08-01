project(pico2_sandbox)

cmake_minimum_required(VERSION 3.22)

set(TOOLCHAIN_PATH "${CMAKE_SOURCE_DIR}/toolchain/llvm/bin")

set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/clang")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/clang")

option(TARGET_CORE "Target core architecture: cortex-m33 or hazard3" "cortex-m33")

if(TARGET_CORE STREQUAL "cortex-m33")
    add_definitions(-DCONFIG_MACH_ARM)
    file(GLOB SOURCES
        ${CMAKE_SOURCE_DIR}/src/rp2350/arm/*c
        ${CMAKE_SOURCE_DIR}/src/rp2350/*c
        ${CMAKE_SOURCE_DIR}/src/drivers/*c
        ${CMAKE_SOURCE_DIR}/src/*c
    )

    add_executable(sandbox.elf ${SOURCES})

    message(STATUS "Configuring for Cortex-M33")
    target_compile_options(sandbox.elf PRIVATE
        -march=armv8m.main+fp+dsp
        -mcpu=cortex-m33
        -mfloat-abi=softfp
        -Oz
        -DNDEBUG
        -ffreestanding
        -nostdlib
        -pedantic
    )
elseif(TARGET_CORE STREQUAL "hazard3")
    add_definitions(-DCONFIG_MACH_RISCV)
    file(GLOB SOURCES
        ${CMAKE_SOURCE_DIR}/src/rp2350/riscv/*c
        ${CMAKE_SOURCE_DIR}/src/rp2350/*c
        ${CMAKE_SOURCE_DIR}/src/drivers/*c
        ${CMAKE_SOURCE_DIR}/src/*c
    )

    add_executable(sandbox.elf ${SOURCES})

    message(STATUS "Configuring for Hazard3 (RISC-V)")
    target_compile_options(sandbox.elf PRIVATE
        --target=riscv32-unknown-elf
        -mcpu=rp2350-hazard3
        #-march=rv32imac_zicsr_zifencei_zba_zbb_zbs_zbkb
        -Oz
        -DNDEBUG
        -mabi=ilp32
        -ffreestanding
        -nostdlib
        -pedantic
     )
else()
    message(FATAL_ERROR "Unknown TARGET_CORE: ${TARGET_CORE}. Use cortex-m33 or hazard3.")
endif()

target_include_directories(sandbox.elf PRIVATE
    ${CMAKE_SOURCE_DIR}/src/rp2350/include
    ${CMAKE_SOURCE_DIR}/src/drivers
)

target_link_options(sandbox.elf PRIVATE
    -nostartfiles
    -nostdlib
    -Wl,--gc-sections
    -ffunction-sections
    -fdata-sections
    -Xlinker
    -T${CMAKE_SOURCE_DIR}/src/rp2350/linker.ld
)
