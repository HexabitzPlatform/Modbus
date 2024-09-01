################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Slave_Mode/port/portevent.c \
../Modbus_Slave_Mode/port/portserial.c \
../Modbus_Slave_Mode/port/porttimer.c 

OBJS += \
./Modbus_Slave_Mode/port/portevent.o \
./Modbus_Slave_Mode/port/portserial.o \
./Modbus_Slave_Mode/port/porttimer.o 

C_DEPS += \
./Modbus_Slave_Mode/port/portevent.d \
./Modbus_Slave_Mode/port/portserial.d \
./Modbus_Slave_Mode/port/porttimer.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Slave_Mode/port/%.o Modbus_Slave_Mode/port/%.su Modbus_Slave_Mode/port/%.cyclo: ../Modbus_Slave_Mode/port/%.c Modbus_Slave_Mode/port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/functions" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/include" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/port" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/rtu" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Slave_Mode-2f-port

clean-Modbus_Slave_Mode-2f-port:
	-$(RM) ./Modbus_Slave_Mode/port/portevent.cyclo ./Modbus_Slave_Mode/port/portevent.d ./Modbus_Slave_Mode/port/portevent.o ./Modbus_Slave_Mode/port/portevent.su ./Modbus_Slave_Mode/port/portserial.cyclo ./Modbus_Slave_Mode/port/portserial.d ./Modbus_Slave_Mode/port/portserial.o ./Modbus_Slave_Mode/port/portserial.su ./Modbus_Slave_Mode/port/porttimer.cyclo ./Modbus_Slave_Mode/port/porttimer.d ./Modbus_Slave_Mode/port/porttimer.o ./Modbus_Slave_Mode/port/porttimer.su

.PHONY: clean-Modbus_Slave_Mode-2f-port

