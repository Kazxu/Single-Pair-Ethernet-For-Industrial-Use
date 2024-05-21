################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adi_mac.c \
../Core/Src/adi_phy.c \
../Core/Src/adi_spi_oa.c \
../Core/Src/adin1110.c \
../Core/Src/boardsupport.c \
../Core/Src/dma.c \
../Core/Src/fcs.c \
../Core/Src/gpio.c \
../Core/Src/hal.c \
../Core/Src/lwIP_adin1110_app.c \
../Core/Src/main.c \
../Core/Src/spi.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysclock.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c \
../Core/Src/tcpecho_raw.c \
../Core/Src/usart.c 

C_DEPS += \
./Core/Src/adi_mac.d \
./Core/Src/adi_phy.d \
./Core/Src/adi_spi_oa.d \
./Core/Src/adin1110.d \
./Core/Src/boardsupport.d \
./Core/Src/dma.d \
./Core/Src/fcs.d \
./Core/Src/gpio.d \
./Core/Src/hal.d \
./Core/Src/lwIP_adin1110_app.d \
./Core/Src/main.d \
./Core/Src/spi.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysclock.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d \
./Core/Src/tcpecho_raw.d \
./Core/Src/usart.d 

OBJS += \
./Core/Src/adi_mac.o \
./Core/Src/adi_phy.o \
./Core/Src/adi_spi_oa.o \
./Core/Src/adin1110.o \
./Core/Src/boardsupport.o \
./Core/Src/dma.o \
./Core/Src/fcs.o \
./Core/Src/gpio.o \
./Core/Src/hal.o \
./Core/Src/lwIP_adin1110_app.o \
./Core/Src/main.o \
./Core/Src/spi.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysclock.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o \
./Core/Src/tcpecho_raw.o \
./Core/Src/usart.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adi_mac.cyclo ./Core/Src/adi_mac.d ./Core/Src/adi_mac.o ./Core/Src/adi_mac.su ./Core/Src/adi_phy.cyclo ./Core/Src/adi_phy.d ./Core/Src/adi_phy.o ./Core/Src/adi_phy.su ./Core/Src/adi_spi_oa.cyclo ./Core/Src/adi_spi_oa.d ./Core/Src/adi_spi_oa.o ./Core/Src/adi_spi_oa.su ./Core/Src/adin1110.cyclo ./Core/Src/adin1110.d ./Core/Src/adin1110.o ./Core/Src/adin1110.su ./Core/Src/boardsupport.cyclo ./Core/Src/boardsupport.d ./Core/Src/boardsupport.o ./Core/Src/boardsupport.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/fcs.cyclo ./Core/Src/fcs.d ./Core/Src/fcs.o ./Core/Src/fcs.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/hal.cyclo ./Core/Src/hal.d ./Core/Src/hal.o ./Core/Src/hal.su ./Core/Src/lwIP_adin1110_app.cyclo ./Core/Src/lwIP_adin1110_app.d ./Core/Src/lwIP_adin1110_app.o ./Core/Src/lwIP_adin1110_app.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/spi.cyclo ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32l4xx_hal_msp.cyclo ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.cyclo ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysclock.cyclo ./Core/Src/sysclock.d ./Core/Src/sysclock.o ./Core/Src/sysclock.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.cyclo ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su ./Core/Src/tcpecho_raw.cyclo ./Core/Src/tcpecho_raw.d ./Core/Src/tcpecho_raw.o ./Core/Src/tcpecho_raw.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

