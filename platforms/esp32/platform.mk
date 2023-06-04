# Compiler settings

TOOLCHAIN := /home/roman/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-
CC = $(CC_PREFIX) $(TOOLCHAIN)gcc
OBJCOPY = $(TOOLCHAIN)objcopy
OBJDUMP = $(TOOLCHAIN)objdump
SIZE = $(TOOLCHAIN)size
AR = $(TOOLCHAIN)ar
NM = $(TOOLCHAIN)nm

CFLAGS := -mlongcalls
CXXFLAGS := -mlongcalls