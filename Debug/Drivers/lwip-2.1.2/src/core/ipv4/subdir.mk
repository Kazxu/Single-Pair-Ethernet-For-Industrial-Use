################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lwip-2.1.2/src/core/ipv4/autoip.c \
../Drivers/lwip-2.1.2/src/core/ipv4/dhcp.c \
../Drivers/lwip-2.1.2/src/core/ipv4/etharp.c \
../Drivers/lwip-2.1.2/src/core/ipv4/icmp.c \
../Drivers/lwip-2.1.2/src/core/ipv4/igmp.c \
../Drivers/lwip-2.1.2/src/core/ipv4/ip4.c \
../Drivers/lwip-2.1.2/src/core/ipv4/ip4_addr.c \
../Drivers/lwip-2.1.2/src/core/ipv4/ip4_frag.c 

C_DEPS += \
./Drivers/lwip-2.1.2/src/core/ipv4/autoip.d \
./Drivers/lwip-2.1.2/src/core/ipv4/dhcp.d \
./Drivers/lwip-2.1.2/src/core/ipv4/etharp.d \
./Drivers/lwip-2.1.2/src/core/ipv4/icmp.d \
./Drivers/lwip-2.1.2/src/core/ipv4/igmp.d \
./Drivers/lwip-2.1.2/src/core/ipv4/ip4.d \
./Drivers/lwip-2.1.2/src/core/ipv4/ip4_addr.d \
./Drivers/lwip-2.1.2/src/core/ipv4/ip4_frag.d 

OBJS += \
./Drivers/lwip-2.1.2/src/core/ipv4/autoip.o \
./Drivers/lwip-2.1.2/src/core/ipv4/dhcp.o \
./Drivers/lwip-2.1.2/src/core/ipv4/etharp.o \
./Drivers/lwip-2.1.2/src/core/ipv4/icmp.o \
./Drivers/lwip-2.1.2/src/core/ipv4/igmp.o \
./Drivers/lwip-2.1.2/src/core/ipv4/ip4.o \
./Drivers/lwip-2.1.2/src/core/ipv4/ip4_addr.o \
./Drivers/lwip-2.1.2/src/core/ipv4/ip4_frag.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lwip-2.1.2/src/core/ipv4/%.o Drivers/lwip-2.1.2/src/core/ipv4/%.su Drivers/lwip-2.1.2/src/core/ipv4/%.cyclo: ../Drivers/lwip-2.1.2/src/core/ipv4/%.c Drivers/lwip-2.1.2/src/core/ipv4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core-2f-ipv4

clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core-2f-ipv4:
	-$(RM) ./Drivers/lwip-2.1.2/src/core/ipv4/autoip.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/autoip.d ./Drivers/lwip-2.1.2/src/core/ipv4/autoip.o ./Drivers/lwip-2.1.2/src/core/ipv4/autoip.su ./Drivers/lwip-2.1.2/src/core/ipv4/dhcp.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/dhcp.d ./Drivers/lwip-2.1.2/src/core/ipv4/dhcp.o ./Drivers/lwip-2.1.2/src/core/ipv4/dhcp.su ./Drivers/lwip-2.1.2/src/core/ipv4/etharp.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/etharp.d ./Drivers/lwip-2.1.2/src/core/ipv4/etharp.o ./Drivers/lwip-2.1.2/src/core/ipv4/etharp.su ./Drivers/lwip-2.1.2/src/core/ipv4/icmp.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/icmp.d ./Drivers/lwip-2.1.2/src/core/ipv4/icmp.o ./Drivers/lwip-2.1.2/src/core/ipv4/icmp.su ./Drivers/lwip-2.1.2/src/core/ipv4/igmp.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/igmp.d ./Drivers/lwip-2.1.2/src/core/ipv4/igmp.o ./Drivers/lwip-2.1.2/src/core/ipv4/igmp.su ./Drivers/lwip-2.1.2/src/core/ipv4/ip4.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/ip4.d ./Drivers/lwip-2.1.2/src/core/ipv4/ip4.o ./Drivers/lwip-2.1.2/src/core/ipv4/ip4.su ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_addr.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_addr.d ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_addr.o ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_addr.su ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_frag.cyclo ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_frag.d ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_frag.o ./Drivers/lwip-2.1.2/src/core/ipv4/ip4_frag.su

.PHONY: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core-2f-ipv4

