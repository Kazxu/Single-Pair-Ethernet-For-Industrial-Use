################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lwip-2.1.2/src/core/altcp.c \
../Drivers/lwip-2.1.2/src/core/altcp_alloc.c \
../Drivers/lwip-2.1.2/src/core/altcp_tcp.c \
../Drivers/lwip-2.1.2/src/core/def.c \
../Drivers/lwip-2.1.2/src/core/dns.c \
../Drivers/lwip-2.1.2/src/core/inet_chksum.c \
../Drivers/lwip-2.1.2/src/core/init.c \
../Drivers/lwip-2.1.2/src/core/ip.c \
../Drivers/lwip-2.1.2/src/core/mem.c \
../Drivers/lwip-2.1.2/src/core/memp.c \
../Drivers/lwip-2.1.2/src/core/netif.c \
../Drivers/lwip-2.1.2/src/core/pbuf.c \
../Drivers/lwip-2.1.2/src/core/raw.c \
../Drivers/lwip-2.1.2/src/core/stats.c \
../Drivers/lwip-2.1.2/src/core/sys.c \
../Drivers/lwip-2.1.2/src/core/tcp.c \
../Drivers/lwip-2.1.2/src/core/tcp_in.c \
../Drivers/lwip-2.1.2/src/core/tcp_out.c \
../Drivers/lwip-2.1.2/src/core/timeouts.c \
../Drivers/lwip-2.1.2/src/core/udp.c 

C_DEPS += \
./Drivers/lwip-2.1.2/src/core/altcp.d \
./Drivers/lwip-2.1.2/src/core/altcp_alloc.d \
./Drivers/lwip-2.1.2/src/core/altcp_tcp.d \
./Drivers/lwip-2.1.2/src/core/def.d \
./Drivers/lwip-2.1.2/src/core/dns.d \
./Drivers/lwip-2.1.2/src/core/inet_chksum.d \
./Drivers/lwip-2.1.2/src/core/init.d \
./Drivers/lwip-2.1.2/src/core/ip.d \
./Drivers/lwip-2.1.2/src/core/mem.d \
./Drivers/lwip-2.1.2/src/core/memp.d \
./Drivers/lwip-2.1.2/src/core/netif.d \
./Drivers/lwip-2.1.2/src/core/pbuf.d \
./Drivers/lwip-2.1.2/src/core/raw.d \
./Drivers/lwip-2.1.2/src/core/stats.d \
./Drivers/lwip-2.1.2/src/core/sys.d \
./Drivers/lwip-2.1.2/src/core/tcp.d \
./Drivers/lwip-2.1.2/src/core/tcp_in.d \
./Drivers/lwip-2.1.2/src/core/tcp_out.d \
./Drivers/lwip-2.1.2/src/core/timeouts.d \
./Drivers/lwip-2.1.2/src/core/udp.d 

OBJS += \
./Drivers/lwip-2.1.2/src/core/altcp.o \
./Drivers/lwip-2.1.2/src/core/altcp_alloc.o \
./Drivers/lwip-2.1.2/src/core/altcp_tcp.o \
./Drivers/lwip-2.1.2/src/core/def.o \
./Drivers/lwip-2.1.2/src/core/dns.o \
./Drivers/lwip-2.1.2/src/core/inet_chksum.o \
./Drivers/lwip-2.1.2/src/core/init.o \
./Drivers/lwip-2.1.2/src/core/ip.o \
./Drivers/lwip-2.1.2/src/core/mem.o \
./Drivers/lwip-2.1.2/src/core/memp.o \
./Drivers/lwip-2.1.2/src/core/netif.o \
./Drivers/lwip-2.1.2/src/core/pbuf.o \
./Drivers/lwip-2.1.2/src/core/raw.o \
./Drivers/lwip-2.1.2/src/core/stats.o \
./Drivers/lwip-2.1.2/src/core/sys.o \
./Drivers/lwip-2.1.2/src/core/tcp.o \
./Drivers/lwip-2.1.2/src/core/tcp_in.o \
./Drivers/lwip-2.1.2/src/core/tcp_out.o \
./Drivers/lwip-2.1.2/src/core/timeouts.o \
./Drivers/lwip-2.1.2/src/core/udp.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lwip-2.1.2/src/core/%.o Drivers/lwip-2.1.2/src/core/%.su Drivers/lwip-2.1.2/src/core/%.cyclo: ../Drivers/lwip-2.1.2/src/core/%.c Drivers/lwip-2.1.2/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core

clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core:
	-$(RM) ./Drivers/lwip-2.1.2/src/core/altcp.cyclo ./Drivers/lwip-2.1.2/src/core/altcp.d ./Drivers/lwip-2.1.2/src/core/altcp.o ./Drivers/lwip-2.1.2/src/core/altcp.su ./Drivers/lwip-2.1.2/src/core/altcp_alloc.cyclo ./Drivers/lwip-2.1.2/src/core/altcp_alloc.d ./Drivers/lwip-2.1.2/src/core/altcp_alloc.o ./Drivers/lwip-2.1.2/src/core/altcp_alloc.su ./Drivers/lwip-2.1.2/src/core/altcp_tcp.cyclo ./Drivers/lwip-2.1.2/src/core/altcp_tcp.d ./Drivers/lwip-2.1.2/src/core/altcp_tcp.o ./Drivers/lwip-2.1.2/src/core/altcp_tcp.su ./Drivers/lwip-2.1.2/src/core/def.cyclo ./Drivers/lwip-2.1.2/src/core/def.d ./Drivers/lwip-2.1.2/src/core/def.o ./Drivers/lwip-2.1.2/src/core/def.su ./Drivers/lwip-2.1.2/src/core/dns.cyclo ./Drivers/lwip-2.1.2/src/core/dns.d ./Drivers/lwip-2.1.2/src/core/dns.o ./Drivers/lwip-2.1.2/src/core/dns.su ./Drivers/lwip-2.1.2/src/core/inet_chksum.cyclo ./Drivers/lwip-2.1.2/src/core/inet_chksum.d ./Drivers/lwip-2.1.2/src/core/inet_chksum.o ./Drivers/lwip-2.1.2/src/core/inet_chksum.su ./Drivers/lwip-2.1.2/src/core/init.cyclo ./Drivers/lwip-2.1.2/src/core/init.d ./Drivers/lwip-2.1.2/src/core/init.o ./Drivers/lwip-2.1.2/src/core/init.su ./Drivers/lwip-2.1.2/src/core/ip.cyclo ./Drivers/lwip-2.1.2/src/core/ip.d ./Drivers/lwip-2.1.2/src/core/ip.o ./Drivers/lwip-2.1.2/src/core/ip.su ./Drivers/lwip-2.1.2/src/core/mem.cyclo ./Drivers/lwip-2.1.2/src/core/mem.d ./Drivers/lwip-2.1.2/src/core/mem.o ./Drivers/lwip-2.1.2/src/core/mem.su ./Drivers/lwip-2.1.2/src/core/memp.cyclo ./Drivers/lwip-2.1.2/src/core/memp.d ./Drivers/lwip-2.1.2/src/core/memp.o ./Drivers/lwip-2.1.2/src/core/memp.su ./Drivers/lwip-2.1.2/src/core/netif.cyclo ./Drivers/lwip-2.1.2/src/core/netif.d ./Drivers/lwip-2.1.2/src/core/netif.o ./Drivers/lwip-2.1.2/src/core/netif.su ./Drivers/lwip-2.1.2/src/core/pbuf.cyclo ./Drivers/lwip-2.1.2/src/core/pbuf.d ./Drivers/lwip-2.1.2/src/core/pbuf.o ./Drivers/lwip-2.1.2/src/core/pbuf.su ./Drivers/lwip-2.1.2/src/core/raw.cyclo ./Drivers/lwip-2.1.2/src/core/raw.d ./Drivers/lwip-2.1.2/src/core/raw.o ./Drivers/lwip-2.1.2/src/core/raw.su ./Drivers/lwip-2.1.2/src/core/stats.cyclo ./Drivers/lwip-2.1.2/src/core/stats.d ./Drivers/lwip-2.1.2/src/core/stats.o ./Drivers/lwip-2.1.2/src/core/stats.su ./Drivers/lwip-2.1.2/src/core/sys.cyclo ./Drivers/lwip-2.1.2/src/core/sys.d ./Drivers/lwip-2.1.2/src/core/sys.o ./Drivers/lwip-2.1.2/src/core/sys.su ./Drivers/lwip-2.1.2/src/core/tcp.cyclo ./Drivers/lwip-2.1.2/src/core/tcp.d ./Drivers/lwip-2.1.2/src/core/tcp.o ./Drivers/lwip-2.1.2/src/core/tcp.su ./Drivers/lwip-2.1.2/src/core/tcp_in.cyclo ./Drivers/lwip-2.1.2/src/core/tcp_in.d ./Drivers/lwip-2.1.2/src/core/tcp_in.o ./Drivers/lwip-2.1.2/src/core/tcp_in.su ./Drivers/lwip-2.1.2/src/core/tcp_out.cyclo ./Drivers/lwip-2.1.2/src/core/tcp_out.d ./Drivers/lwip-2.1.2/src/core/tcp_out.o ./Drivers/lwip-2.1.2/src/core/tcp_out.su ./Drivers/lwip-2.1.2/src/core/timeouts.cyclo ./Drivers/lwip-2.1.2/src/core/timeouts.d ./Drivers/lwip-2.1.2/src/core/timeouts.o ./Drivers/lwip-2.1.2/src/core/timeouts.su ./Drivers/lwip-2.1.2/src/core/udp.cyclo ./Drivers/lwip-2.1.2/src/core/udp.d ./Drivers/lwip-2.1.2/src/core/udp.o ./Drivers/lwip-2.1.2/src/core/udp.su

.PHONY: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-core

