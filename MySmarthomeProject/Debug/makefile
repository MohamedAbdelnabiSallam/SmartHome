################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MySmarthomeProject.lss \

FLASH_IMAGE += \
MySmarthomeProject.hex \

EEPROM_IMAGE += \
MySmarthomeProject.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: MySmarthomeProject.elf secondary-outputs

# Tool invocations
MySmarthomeProject.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MySmarthomeProject.map -mmcu=atmega32 -o "MySmarthomeProject.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MySmarthomeProject.lss: MySmarthomeProject.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MySmarthomeProject.elf  >"MySmarthomeProject.lss"
	@echo 'Finished building: $@'
	@echo ' '

MySmarthomeProject.hex: MySmarthomeProject.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MySmarthomeProject.elf  "MySmarthomeProject.hex"
	@echo 'Finished building: $@'
	@echo ' '

MySmarthomeProject.eep: MySmarthomeProject.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex MySmarthomeProject.elf  "MySmarthomeProject.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MySmarthomeProject.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MySmarthomeProject.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MySmarthomeProject.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
