# Compiler settings
ifeq ($(ESP32C3),y)
TOOLCHAIN := /home/roman/.espressif/tools/riscv32-esp-elf/esp-12.2.0_20230208/riscv32-esp-elf/bin/riscv32-esp-elf-
else ifeq ($(ESP32S3),y)
TOOLCHAIN := /home/roman/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-
else
$(error "Undefined ESP32 platfrom")
endif

CC = $(CC_PREFIX) $(TOOLCHAIN)gcc
OBJCOPY = $(TOOLCHAIN)objcopy
OBJDUMP = $(TOOLCHAIN)objdump
SIZE = $(TOOLCHAIN)size
AR = $(TOOLCHAIN)ar
NM = $(TOOLCHAIN)nm
BIN = $(OBJCOPY) -O binary

#LDSCRIPT_PATH ?= "/home/roman/projects/jorne_esp32/build/esp-idf/esp_system/ld"
LDSCRIPT_PATH ?= "/home/roman/projects/jorne_esp32/ble_hid_example/build/esp-idf/esp_system/ld"
ifneq ("$(LDSCRIPT_PATH)",)
$(info "Using external LD scripts at $(LDSCRIPT)")
endif

STATIC_LIB_DIR ?= /home/roman/projects/jorne_esp32/build/esp-idf

STATIC_LIBS = $(STATIC_LIB_DIR)/esp_system/libesp_system.a \
			  $(STATIC_LIB_DIR)/heap/libheap.a \
			  $(STATIC_LIB_DIR)/esp_bootloader_format/libesp_bootloader_format.a \
			  $(STATIC_LIB_DIR)/esp_partition/libesp_partition.a \
			  $(STATIC_LIB_DIR)/esp_hw_support/libesp_hw_support.a \
			  $(STATIC_LIB_DIR)/esp_pm/libesp_pm.a \
			  $(STATIC_LIB_DIR)/log/liblog.a \
			  $(STATIC_LIB_DIR)/efuse/libefuse.a \
			  $(STATIC_LIB_DIR)/esp_rom/libesp_rom.a \
			  $(STATIC_LIB_DIR)/esp_mm/libesp_mm.a \
			  $(STATIC_LIB_DIR)/esp_timer/libesp_timer.a \
			  $(STATIC_LIB_DIR)/soc/libsoc.a \
			  $(STATIC_LIB_DIR)/esp_ringbuf/libesp_ringbuf.a \
			  $(STATIC_LIB_DIR)/esp_app_format/libesp_app_format.a \
			  $(STATIC_LIB_DIR)/freertos/libfreertos.a \
			  $(STATIC_LIB_DIR)/pthread/libpthread.a \
			  $(STATIC_LIB_DIR)/cxx/libcxx.a \
			  $(STATIC_LIB_DIR)/spi_flash/libspi_flash.a \
			  $(STATIC_LIB_DIR)/driver/libdriver.a \
			  $(STATIC_LIB_DIR)/bootloader_support/libbootloader_support.a \
			  $(STATIC_LIB_DIR)/newlib/libnewlib.a \
			  $(STATIC_LIB_DIR)/xtensa/libxtensa.a \
			  $(STATIC_LIB_DIR)/esp_common/libesp_common.a \
			  $(STATIC_LIB_DIR)/app_update/libapp_update.a \
			  $(STATIC_LIB_DIR)/hal/libhal.a \
			  $(STATIC_LIB_DIR)/mbedtls/libmbedtls.a \
			  $(STATIC_LIB_DIR)/mbedtls/mbedtls/library/libmbedcrypto.a \
			  $(STATIC_LIB_DIR)/mbedtls/mbedtls/library/libmbedtls.a \
			  $(STATIC_LIB_DIR)/mbedtls/mbedtls/library/libmbedx509.a

LIBS := $(addprefix -l, $(notdir $(STATIC_LIBS)))
$(info "LIBS: $(LIBS)")
LIB_DIRS := $(addprefix -L, $(dir $(STATIC_LIBS)))

LINKER_FLAGS := \
-fno-rtti -fno-lto -Wl,--gc-sections -Wl,--warn-common -T esp32s3.peripherals.ld \
-T esp32s3.rom.ld -T esp32s3.rom.api.ld -T esp32s3.rom.libgcc.ld -T esp32s3.rom.newlib.ld \
-T esp32s3.rom.version.ld -T memory.ld -T sections.ld \
-L/home/roman/projects/esp-idf/components/soc/esp32s3/ld \
-L/home/roman/projects/esp-idf/components/esp_rom/esp32s3/ld \
-L$(LDSCRIPT_PATH)

CFLAGS := -DMATRIX_INPUT_PRESSED_STATE=0

ifeq ($(ESP32C3),y)
CFLAGS += -march=rv32imc_zicsr_zifencei  -Wall -Wextra -Wwrite-strings \
-Wformat=2 -Wno-format-nonliteral -Wvla -Wlogical-op -Wshadow \
-Wformat-signedness -Wformat-overflow=2 -Wformat-truncation -Werror \
-ffunction-sections -fdata-sections -Wall -Wno-error=unused-function \
-Wno-error=unused-variable -Wno-error=unused-but-set-variable \
-Wno-error=deprecated-declarations -Wextra -Wno-unused-parameter \
-Wno-sign-compare -Wno-enum-conversion -Wno-override-init -Wno-shadow \
-DESP32C3
else
CFLAGS += -ffreestanding -mlongcalls
endif

CXXFLAGS := -mlongcalls -fno-rtti
LDFLAGS := -specs=nosys.specs -Wl,--gc-sections -fno-lto
PLATFORM_SRC = \
		$(PLATFORM_COMMON_DIR)/port.c \
		$(PLATFORM_COMMON_DIR)/syscall-fallbacks.c

lib: $(BUILD_DIR)/$(TARGET).elf
	$(V)echo "Building a static library"
	$(TOOLCHAIN)ar rcs $(BUILD_DIR)/$(TARGET).a $(OBJ)
