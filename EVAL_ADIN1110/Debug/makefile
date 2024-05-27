################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/lwip-2.1.2/src/netif/ppp/polarssl/subdir.mk
-include Drivers/lwip-2.1.2/src/netif/ppp/subdir.mk
-include Drivers/lwip-2.1.2/src/netif/subdir.mk
-include Drivers/lwip-2.1.2/src/core/ipv6/subdir.mk
-include Drivers/lwip-2.1.2/src/core/ipv4/subdir.mk
-include Drivers/lwip-2.1.2/src/core/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/tftp/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/sntp/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/snmp/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/smtp/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/netbiosns/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/mqtt/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/mdns/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/lwiperf/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/http/subdir.mk
-include Drivers/lwip-2.1.2/src/apps/altcp_tls/subdir.mk
-include Drivers/lwip-2.1.2/src/api/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := EVAL-ADIN1110-FW_96_ADC
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
EVAL-ADIN1110-FW_96_ADC.elf \

MAP_FILES += \
EVAL-ADIN1110-FW_96_ADC.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
EVAL-ADIN1110-FW_96_ADC.list \


# All Target
all: main-build

# Main-build Target
main-build: EVAL-ADIN1110-FW_96_ADC.elf secondary-outputs

# Tool invocations
EVAL-ADIN1110-FW_96_ADC.elf EVAL-ADIN1110-FW_96_ADC.map: $(OBJS) $(USER_OBJS) /home/ikasu/STM32CubeIDE/workspace_1.14.0/EVAL-ADIN1110-FW_96_ADC/STM32L4S5QIIX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "EVAL-ADIN1110-FW_96_ADC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/ikasu/STM32CubeIDE/workspace_1.14.0/EVAL-ADIN1110-FW_96_ADC/STM32L4S5QIIX_FLASH.ld" --specs=nosys.specs -Wl,-Map="EVAL-ADIN1110-FW_96_ADC.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

EVAL-ADIN1110-FW_96_ADC.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "EVAL-ADIN1110-FW_96_ADC.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) EVAL-ADIN1110-FW_96_ADC.elf EVAL-ADIN1110-FW_96_ADC.list EVAL-ADIN1110-FW_96_ADC.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
