################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lwip-2.1.2/src/apps/sntp/sntp.c 

C_DEPS += \
./Drivers/lwip-2.1.2/src/apps/sntp/sntp.d 

OBJS += \
./Drivers/lwip-2.1.2/src/apps/sntp/sntp.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lwip-2.1.2/src/apps/sntp/%.o Drivers/lwip-2.1.2/src/apps/sntp/%.su Drivers/lwip-2.1.2/src/apps/sntp/%.cyclo: ../Drivers/lwip-2.1.2/src/apps/sntp/%.c Drivers/lwip-2.1.2/src/apps/sntp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-apps-2f-sntp

clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-apps-2f-sntp:
	-$(RM) ./Drivers/lwip-2.1.2/src/apps/sntp/sntp.cyclo ./Drivers/lwip-2.1.2/src/apps/sntp/sntp.d ./Drivers/lwip-2.1.2/src/apps/sntp/sntp.o ./Drivers/lwip-2.1.2/src/apps/sntp/sntp.su

.PHONY: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-apps-2f-sntp

