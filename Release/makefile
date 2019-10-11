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
UART_1_challenge.lss \

FLASH_IMAGE += \
UART_1_challenge.hex \

EEPROM_IMAGE += \
UART_1_challenge.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: UART_1_challenge.elf secondary-outputs

# Tool invocations
UART_1_challenge.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UART_1_challenge.map -mmcu=atmega16 -o "UART_1_challenge.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UART_1_challenge.lss: UART_1_challenge.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UART_1_challenge.elf  >"UART_1_challenge.lss"
	@echo 'Finished building: $@'
	@echo ' '

UART_1_challenge.hex: UART_1_challenge.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UART_1_challenge.elf  "UART_1_challenge.hex"
	@echo 'Finished building: $@'
	@echo ' '

UART_1_challenge.eep: UART_1_challenge.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex UART_1_challenge.elf  "UART_1_challenge.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UART_1_challenge.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 UART_1_challenge.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UART_1_challenge.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
