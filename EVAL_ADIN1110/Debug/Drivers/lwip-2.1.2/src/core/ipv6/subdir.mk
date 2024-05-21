################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lwip-2.1.2/src/core/ipv6/dhcp6.c \
../Drivers/lwip-2.1.2/src/core/ipv6/ethip6.c \
../Drivers/lwip-2.1.2/src/core/ipv6/icmp6.c \
../Drivers/lwip-2.1.2/src/core/ipv6/inet6.c \
../Drivers/lwip-2.1.2/src/core/ipv6/ip6.c \
../Drivers/lwip-2.1.2/src/core/ipv6/ip6_addr.c \
../Drivers/lwip-2.1.2/src/core/ipv6/ip6_frag.c \
../Drivers/lwip-2.1.2/src/core/ipv6/mld6.c \
../Drivers/lwip-2.1.2/src/core/ipv6/nd6.c 

C_DEPS += \
./Drivers/lwip-2.1.2/src/core/ipv6/dhcp6.d \
./Drivers/lwip-2.1.2/src/core/ipv6/ethip6.d \
./Drivers/lwip-2.1.2/src/core/ipv6/icmp6.d \
./Drivers/lwip-2.1.2/src/core/ipv6/inet6.d \
./Drivers/lwip-2.1.2/src/core/ipv6/ip6.d \
./Drivers/lwip-2.1.2/src/core/ipv6/ip6_addr.d \
./Drivers/lwip-2.1.2/src/core/ipv6/ip6_frag.d \
./Drivers/lwip-2.1.2/src/core/ipv6/mld6.d \
./Drivers/lwip-2.1.2/src/core/ipv6/nd6.d 

OBJS += \
./Drivers/lwip-2.1.2/src/core/ipv6/dhcp6.o \
./Drivers/lwip-2.1.2/src/core/ipv6/ethip6.o \
./Drivers/lwip-2.1.2/src/core/ipv6/icmp6.o \
./Drivers/lwip-2.1.2/src/core/ipv6/inet6.o \
./Drivers/lwip-2.1.2/src/core/ipv6/ip6.o \
./Drivers/lwip-2.1.2/src/core/ipv6/ip6_addr.o \
./Drivers/lwip-2.1.2/src/core/ipv6/ip6_frag.o \
./Drivers/lwip-2.1.2/src/core/ipv6/mld6.o \
./Drivers/lwip-2.1.2/src/core/ipv6/nd6.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lwip-2.1.2/src/core/ipv6/%.o Drivers/lwip-2.1.2/src/core/ipv6/%.su Drivers/lwip-2.1.2/src/core/ipv6/%.cyclo: ../Drivers/lwip-2.1.2/src/core/ipv6/%.c Drivers/lwip-2.1.2/src/core/ipv6/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core-2f-ipv6

clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core-2f-ipv6:
	-$(RM) ./Drivers/lwip-2.1.2/src/core/ipv6/dhcp6.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/dhcp6.d ./Drivers/lwip-2.1.2/src/core/ipv6/dhcp6.o ./Drivers/lwip-2.1.2/src/core/ipv6/dhcp6.su ./Drivers/lwip-2.1.2/src/core/ipv6/ethip6.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/ethip6.d ./Drivers/lwip-2.1.2/src/core/ipv6/ethip6.o ./Drivers/lwip-2.1.2/src/core/ipv6/ethip6.su ./Drivers/lwip-2.1.2/src/core/ipv6/icmp6.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/icmp6.d ./Drivers/lwip-2.1.2/src/core/ipv6/icmp6.o ./Drivers/lwip-2.1.2/src/core/ipv6/icmp6.su ./Drivers/lwip-2.1.2/src/core/ipv6/inet6.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/inet6.d ./Drivers/lwip-2.1.2/src/core/ipv6/inet6.o ./Drivers/lwip-2.1.2/src/core/ipv6/inet6.su ./Drivers/lwip-2.1.2/src/core/ipv6/ip6.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/ip6.d ./Drivers/lwip-2.1.2/src/core/ipv6/ip6.o ./Drivers/lwip-2.1.2/src/core/ipv6/ip6.su ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_addr.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_addr.d ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_addr.o ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_addr.su ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_frag.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_frag.d ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_frag.o ./Drivers/lwip-2.1.2/src/core/ipv6/ip6_frag.su ./Drivers/lwip-2.1.2/src/core/ipv6/mld6.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/mld6.d ./Drivers/lwip-2.1.2/src/core/ipv6/mld6.o ./Drivers/lwip-2.1.2/src/core/ipv6/mld6.su ./Drivers/lwip-2.1.2/src/core/ipv6/nd6.cyclo ./Drivers/lwip-2.1.2/src/core/ipv6/nd6.d ./Drivers/lwip-2.1.2/src/core/ipv6/nd6.o ./Drivers/lwip-2.1.2/src/core/ipv6/nd6.su

.PHONY: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core-2f-ipv6

