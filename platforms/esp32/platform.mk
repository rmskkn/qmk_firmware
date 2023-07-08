# Compiler settings

TOOLCHAIN := /home/roman/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-
CC = $(CC_PREFIX) $(TOOLCHAIN)gcc
OBJCOPY = $(TOOLCHAIN)objcopy
OBJDUMP = $(TOOLCHAIN)objdump
SIZE = $(TOOLCHAIN)size
AR = $(TOOLCHAIN)ar
NM = $(TOOLCHAIN)nm
BIN = $(OBJCOPY) -O binary

CFLAGS := -ffreestanding -mlongcalls -DMATRIX_INPUT_PRESSED_STATE=0
CXXFLAGS := -mlongcalls -fno-rtti
LDFLAGS := -specs=nosys.specs

PLATFORM_SRC = \
		$(PLATFORM_COMMON_DIR)/port.c \
		$(PLATFORM_COMMON_DIR)/syscall-fallbacks.c

#
%.bin: %..elf sizeafter
	echo "Custom elf->bin"