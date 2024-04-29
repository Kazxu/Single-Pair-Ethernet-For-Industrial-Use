################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lwip-2.1.2/src/netif/ppp/polarssl/arc4.c \
../Drivers/lwip-2.1.2/src/netif/ppp/polarssl/des.c \
../Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md4.c \
../Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md5.c \
../Drivers/lwip-2.1.2/src/netif/ppp/polarssl/sha1.c 

C_DEPS += \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/arc4.d \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/des.d \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md4.d \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md5.d \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/sha1.d 

OBJS += \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/arc4.o \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/des.o \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md4.o \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md5.o \
./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/sha1.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lwip-2.1.2/src/netif/ppp/polarssl/%.o Drivers/lwip-2.1.2/src/netif/ppp/polarssl/%.su Drivers/lwip-2.1.2/src/netif/ppp/polarssl/%.cyclo: ../Drivers/lwip-2.1.2/src/netif/ppp/polarssl/%.c Drivers/lwip-2.1.2/src/netif/ppp/polarssl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -DADIN1110 -DEVAL_ADIN1110EBZ -DADI_MAC_ENABLE_RX_QUEUE_HI_PRIO -DSPI_OA_EN -DSPI_PROT_EN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/lwip-2.1.2/src/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-netif-2f-ppp-2f-polarssl

clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-netif-2f-ppp-2f-polarssl:
	-$(RM) ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/arc4.cyclo ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/arc4.d ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/arc4.o ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/arc4.su ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/des.cyclo ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/des.d ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/des.o ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/des.su ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md4.cyclo ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md4.d ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md4.o ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md4.su ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md5.cyclo ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md5.d ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md5.o ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/md5.su ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/sha1.cyclo ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/sha1.d ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/sha1.o ./Drivers/lwip-2.1.2/src/netif/ppp/polarssl/sha1.su

.PHONY: clean-Drivers-2f-lwip-2d-2-2e-1-2e-2-2f-src-2f-netif-2f-ppp-2f-polarssl

