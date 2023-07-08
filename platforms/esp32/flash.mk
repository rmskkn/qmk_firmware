
# Do not inherit elf->bin from common_rules to skip appending the DFU.
flash:
	$(BIN) $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin