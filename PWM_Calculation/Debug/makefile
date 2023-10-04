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
PWM_Calculation.lss \

FLASH_IMAGE += \
PWM_Calculation.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PWM_Calculation.elf secondary-outputs

# Tool invocations
PWM_Calculation.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PWM_Calculation.map -mmcu=atmega32 -o "PWM_Calculation.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PWM_Calculation.lss: PWM_Calculation.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PWM_Calculation.elf  >"PWM_Calculation.lss"
	@echo 'Finished building: $@'
	@echo ' '

PWM_Calculation.hex: PWM_Calculation.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PWM_Calculation.elf  "PWM_Calculation.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PWM_Calculation.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PWM_Calculation.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PWM_Calculation.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
