################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lwip-2.1.2/src/netif/bridgeif.c \
../Drivers/lwip-2.1.2/src/netif/bridgeif_fdb.c \
../Drivers/lwip-2.1.2/src/netif/ethernet.c \
../Drivers/lwip-2.1.2/src/netif/lowpan6.c \
../Drivers/lwip-2.1.2/src/netif/lowpan6_ble.c \
../Drivers/lwip-2.1.2/src/netif/lowpan6_common.c \
../Drivers/lwip-2.1.2/src/netif/slipif.c \
../Drivers/lwip-2.1.2/src/netif/zepif.c 

C_DEPS += \
./Drivers/lwip-2.1.2/src/netif/bridgeif.d \
./Drivers/lwip-2.1.2/src/netif/bridgeif_fdb.d \
./Drivers/lwip-2.1.2/src/netif/ethernet.d \
./Drivers/lwip-2.1.2/src/netif/lowpan6.d \
./Drivers/lwip-2.1.2/src/netif/lowpan6_ble.d \
./Drivers/lwip-2.1.2/src/netif/lowpan6_common.d \
./Drivers/lwip-2.1.2/src/netif/slipif.d \
./Drivers/lwip-2.1.2/src/netif/zepif.d 

OBJS += \
./Drivers/lwip-2.1.2/src/netif/bridgeif.o \
./Drivers/lwip-2.1.2/src/netif/bridgeif_fdb.o \
./Drivers/lwip-2.1.2/src/netif/ethernet.o \
./Drivers/lwip-2.1.2/src/netif/lowpan6.o \
./Drivers/lwip-2.1.2/src/netif/lowpan6_ble.o \
./Drivers/lwip-2.1.2/src/netif/lowpan6_common.o \
./Drivers/lwip-2.1.2/src/netif/slipif.o \
./Drivers/lwip-2.1.2/src/netif/zepif.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lwip-2.1.2/src/netif/%.o Drivers/lwip-2.1.2/src/netif/%.su Drivers/lwip-2.1.2/src/netif/%.cyclo: ../Drivers/lwip-2.1.2/src/netif/%.c Drivers/lwip-2.1.2/src/netif/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-netif

clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-netif:
	-$(RM) ./Drivers/lwip-2.1.2/src/netif/bridgeif.cyclo ./Drivers/lwip-2.1.2/src/netif/bridgeif.d ./Drivers/lwip-2.1.2/src/netif/bridgeif.o ./Drivers/lwip-2.1.2/src/netif/bridgeif.su ./Drivers/lwip-2.1.2/src/netif/bridgeif_fdb.cyclo ./Drivers/lwip-2.1.2/src/netif/bridgeif_fdb.d ./Drivers/lwip-2.1.2/src/netif/bridgeif_fdb.o ./Drivers/lwip-2.1.2/src/netif/bridgeif_fdb.su ./Drivers/lwip-2.1.2/src/netif/ethernet.cyclo ./Drivers/lwip-2.1.2/src/netif/ethernet.d ./Drivers/lwip-2.1.2/src/netif/ethernet.o ./Drivers/lwip-2.1.2/src/netif/ethernet.su ./Drivers/lwip-2.1.2/src/netif/lowpan6.cyclo ./Drivers/lwip-2.1.2/src/netif/lowpan6.d ./Drivers/lwip-2.1.2/src/netif/lowpan6.o ./Drivers/lwip-2.1.2/src/netif/lowpan6.su ./Drivers/lwip-2.1.2/src/netif/lowpan6_ble.cyclo ./Drivers/lwip-2.1.2/src/netif/lowpan6_ble.d ./Drivers/lwip-2.1.2/src/netif/lowpan6_ble.o ./Drivers/lwip-2.1.2/src/netif/lowpan6_ble.su ./Drivers/lwip-2.1.2/src/netif/lowpan6_common.cyclo ./Drivers/lwip-2.1.2/src/netif/lowpan6_common.d ./Drivers/lwip-2.1.2/src/netif/lowpan6_common.o ./Drivers/lwip-2.1.2/src/netif/lowpan6_common.su ./Drivers/lwip-2.1.2/src/netif/slipif.cyclo ./Drivers/lwip-2.1.2/src/netif/slipif.d ./Drivers/lwip-2.1.2/src/netif/slipif.o ./Drivers/lwip-2.1.2/src/netif/slipif.su ./Drivers/lwip-2.1.2/src/netif/zepif.cyclo ./Drivers/lwip-2.1.2/src/netif/zepif.d ./Drivers/lwip-2.1.2/src/netif/zepif.o ./Drivers/lwip-2.1.2/src/netif/zepif.su

.PHONY: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-netif

