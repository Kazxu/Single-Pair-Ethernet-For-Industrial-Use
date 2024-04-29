################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lwip-2.1.2/src/api/api_lib.c \
../Drivers/lwip-2.1.2/src/api/api_msg.c \
../Drivers/lwip-2.1.2/src/api/err.c \
../Drivers/lwip-2.1.2/src/api/if_api.c \
../Drivers/lwip-2.1.2/src/api/netbuf.c \
../Drivers/lwip-2.1.2/src/api/netdb.c \
../Drivers/lwip-2.1.2/src/api/netifapi.c \
../Drivers/lwip-2.1.2/src/api/sockets.c \
../Drivers/lwip-2.1.2/src/api/tcpip.c 

C_DEPS += \
./Drivers/lwip-2.1.2/src/api/api_lib.d \
./Drivers/lwip-2.1.2/src/api/api_msg.d \
./Drivers/lwip-2.1.2/src/api/err.d \
./Drivers/lwip-2.1.2/src/api/if_api.d \
./Drivers/lwip-2.1.2/src/api/netbuf.d \
./Drivers/lwip-2.1.2/src/api/netdb.d \
./Drivers/lwip-2.1.2/src/api/netifapi.d \
./Drivers/lwip-2.1.2/src/api/sockets.d \
./Drivers/lwip-2.1.2/src/api/tcpip.d 

OBJS += \
./Drivers/lwip-2.1.2/src/api/api_lib.o \
./Drivers/lwip-2.1.2/src/api/api_msg.o \
./Drivers/lwip-2.1.2/src/api/err.o \
./Drivers/lwip-2.1.2/src/api/if_api.o \
./Drivers/lwip-2.1.2/src/api/netbuf.o \
./Drivers/lwip-2.1.2/src/api/netdb.o \
./Drivers/lwip-2.1.2/src/api/netifapi.o \
./Drivers/lwip-2.1.2/src/api/sockets.o \
./Drivers/lwip-2.1.2/src/api/tcpip.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lwip-2.1.2/src/api/%.o Drivers/lwip-2.1.2/src/api/%.su Drivers/lwip-2.1.2/src/api/%.cyclo: ../Drivers/lwip-2.1.2/src/api/%.c Drivers/lwip-2.1.2/src/api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-api

clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-api:
	-$(RM) ./Drivers/lwip-2.1.2/src/api/api_lib.cyclo ./Drivers/lwip-2.1.2/src/api/api_lib.d ./Drivers/lwip-2.1.2/src/api/api_lib.o ./Drivers/lwip-2.1.2/src/api/api_lib.su ./Drivers/lwip-2.1.2/src/api/api_msg.cyclo ./Drivers/lwip-2.1.2/src/api/api_msg.d ./Drivers/lwip-2.1.2/src/api/api_msg.o ./Drivers/lwip-2.1.2/src/api/api_msg.su ./Drivers/lwip-2.1.2/src/api/err.cyclo ./Drivers/lwip-2.1.2/src/api/err.d ./Drivers/lwip-2.1.2/src/api/err.o ./Drivers/lwip-2.1.2/src/api/err.su ./Drivers/lwip-2.1.2/src/api/if_api.cyclo ./Drivers/lwip-2.1.2/src/api/if_api.d ./Drivers/lwip-2.1.2/src/api/if_api.o ./Drivers/lwip-2.1.2/src/api/if_api.su ./Drivers/lwip-2.1.2/src/api/netbuf.cyclo ./Drivers/lwip-2.1.2/src/api/netbuf.d ./Drivers/lwip-2.1.2/src/api/netbuf.o ./Drivers/lwip-2.1.2/src/api/netbuf.su ./Drivers/lwip-2.1.2/src/api/netdb.cyclo ./Drivers/lwip-2.1.2/src/api/netdb.d ./Drivers/lwip-2.1.2/src/api/netdb.o ./Drivers/lwip-2.1.2/src/api/netdb.su ./Drivers/lwip-2.1.2/src/api/netifapi.cyclo ./Drivers/lwip-2.1.2/src/api/netifapi.d ./Drivers/lwip-2.1.2/src/api/netifapi.o ./Drivers/lwip-2.1.2/src/api/netifapi.su ./Drivers/lwip-2.1.2/src/api/sockets.cyclo ./Drivers/lwip-2.1.2/src/api/sockets.d ./Drivers/lwip-2.1.2/src/api/sockets.o ./Drivers/lwip-2.1.2/src/api/sockets.su ./Drivers/lwip-2.1.2/src/api/tcpip.cyclo ./Drivers/lwip-2.1.2/src/api/tcpip.d ./Drivers/lwip-2.1.2/src/api/tcpip.o ./Drivers/lwip-2.1.2/src/api/tcpip.su

.PHONY: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-api

