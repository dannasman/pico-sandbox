LSCRIPT := platform/hw/linker.ld
LDFLAGS	:= -nostartfiles \
		   -nostdlib \
		   -Wl,--gc-sections \
		   -T$(LSCRIPT)

ifeq ($(TOOLCHAIN), clang)
TC_PATH	:= toolchain/llvm/bin
CC		:= $(TC_PATH)/clang
AS		:= $(TC_PATH)/clang
CONF	:= -DCONFIG_COMPILER_CLANG
ifeq ($(TARGET), cortex-m33)
CONF	+= -DCONFIG_MACH_ARM
BUILDDIR:= build/cortex-m33
LD		:= toolchain/gcc-arm/bin/arm-none-eabi-ld
COPTS	:= -mcpu=cortex-m33 \
		   --target=armv8m.main-none-eabi \
		   -mfloat-abi=softfp \
		   -march=armv8m.main+fp+dsp \
		   -Oz \
		   -DNDEBUG \
		   -ffreestanding \
		   -ffunction-sections \
		   -fdata-sections \
		   -nostdlib \
		   -pedantic \
		   -Weverything
else ifeq ($(TARGET), hazard3)
CONF	+= -DCONFIG_MACH_RISCV
BUILDDIR:= build/hazard3
LD		:= toolchain/gcc-riscv/bin/riscv32-unknown-elf-ld
COPTS	:= --target=riscv32-unknown-elf \
		   -mcpu=rp2350-hazard3 \
		   -Oz \
		   -DNDEBUG \
		   -mabi=ilp32 \
		   -ffreestanding \
		   -ffunction-sections \
		   -fdata-sections \
		   -nostdlib \
		   -pedantic \
		   -Weverything \
		  #-march=rv32imac_zicsr_zifencei_zba_zbb_zbs_zbkb
endif
else ifeq ($(TOOLCHAIN), gcc)
CONF	:= -DCONFIG_COMPILER_GCC
ifeq ($(TARGET), cortex-m33)
CONF	+= -DCONFIG_MACH_ARM
BUILDDIR:= build/cortex-m33
TC_PATH	:= toolchain/gcc-arm/bin
CC 		:= $(TC_PATH)/arm-none-eabi-gcc
AS 		:= $(TC_PATH)/arm-none-eabi-as
LD		:= toolchain/gcc-arm/bin/arm-none-eabi-ld
COPTS	:= -mcpu=cortex-m33 \
		   -mthumb \
		   -march=armv8-m.main+fp+dsp \
		   -mfloat-abi=softfp \
		   -Oz \
		   -DNDEBUG \
		   -ffreestanding \
		   -ffunction-sections \
		   -fdata-sections \
		   -nostdlib \
		   -pedantic \
		   -Wall \
		   -Wextra
else ifeq ($(TARGET), hazard3)
CONF	+= -DCONFIG_MACH_RISCV
BUILDDIR:= build/hazard3
TC_PATH	:= toolchain/gcc-riscv/bin
CC		:= $(TC_PATH)/riscv32-unknown-elf-gcc
AS		:= $(TC_PATH)/riscv32-unknown-elf-as
LD		:= toolchain/gcc-riscv/bin/riscv32-unknown-elf-ld
COPTS	:= -march=rv32ima_zicsr_zifencei_zba_zbb_zbs_zbkb_zca_zcb_zcmp \
		   -mabi=ilp32 \
		   -Oz \
		   -DNDEBUG \
		   -ffreestanding \
		   -ffunction-sections \
		   -fdata-sections \
		   -nostdlib \
		   -pedantic \
		   -Wall \
		   -Wextra \
		  #-march=rv32imac_zicsr_zifencei_zba_zbb_zbs_zbkb
endif
endif

INCLUDE	:= platform/include \
		   platform/include/lib \
		   platform/include/rp2350 \

ifeq ($(TARGET), cortex-m33)
INCLUDE	+= platform/include/arm
INCLUDE	+= platform/include/arm/rp2350
else ifeq ($(TARGET), hazard3)
INCLUDE	+= platform/include/riscv
endif

IFLAGS	:= $(addprefix -I, $(INCLUDE))

CFLAGS	:= $(COPTS) $(IFLAGS) $(CONF)

CFILES	:= $(wildcard platform/*.c) \
		   $(wildcard platform/drivers/*.c) \
		   $(wildcard platform/fs/*.c) \
		   $(wildcard platform/lib/*.c) \
		   $(wildcard platform/shell/*.c)

ifeq ($(TARGET), cortex-m33)
CFILES	+= $(wildcard platform/drivers/arm/*.c) \
		   $(wildcard platform/hw/arm/*.c)
else ifeq ($(TARGET), hazard3)
CFILES 	+= $(wildcard platform/drivers/riscv/*.c) \
		   $(wildcard platform/hw/riscv/*.c)
endif

OBJECTS := $(patsubst platform/%.c,$(BUILDDIR)/%.o,$(CFILES))

OUTPUT	:= sandbox.elf

all: $(OUTPUT)

analyze: clean
	mkdir -p $(BUILDDIR)/html
	toolchain/llvm/bin/clang \
		$(CFLAGS) \
		--analyze \
		-Xanalyzer \
		-analyzer-output=html \
		$(CFILES)
	mv *.plist $(BUILDDIR)/html/

$(BUILDDIR)/%.o: platform/%.c
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/drivers/%.o: platform/drivers/%.c
	mkdir -p $(BUILDDIR)/drivers
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/drivers/arm/%.o: platform/drivers/arm/%.c
	mkdir -p $(BUILDDIR)/drivers/arm
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/drivers/riscv/%.o: platform/drivers/riscv/%.c
	mkdir -p $(BUILDDIR)/drivers/riscv
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/fs/%.o: platform/fs/%.c
	mkdir -p $(BUILDDIR)/fs
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/lib/%.o: platform/lib/%.c
	mkdir -p $(BUILDDIR)/lib
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/shell/%.o: platform/shell/%.c
	mkdir -p $(BUILDDIR)/shell
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/hw/arm/%.o: platform/hw/arm/%.c
	mkdir -p $(BUILDDIR)/hw/arm
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/hw/riscv/%.o: platform/hw/riscv/%.c
	mkdir -p $(BUILDDIR)/hw/riscv
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT): $(OBJECTS)
	$(CC) $(IFLAGS) -o $(BUILDDIR)/$@ $(OBJECTS) $(LDFLAGS)

clean:
	rm -rf build/$(TARGET)

