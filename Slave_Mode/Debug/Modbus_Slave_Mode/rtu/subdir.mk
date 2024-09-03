################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Slave_Mode/rtu/mbcrc.c \
../Modbus_Slave_Mode/rtu/mbrtu.c 

OBJS += \
./Modbus_Slave_Mode/rtu/mbcrc.o \
./Modbus_Slave_Mode/rtu/mbrtu.o 

C_DEPS += \
./Modbus_Slave_Mode/rtu/mbcrc.d \
./Modbus_Slave_Mode/rtu/mbrtu.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Slave_Mode/rtu/%.o Modbus_Slave_Mode/rtu/%.su Modbus_Slave_Mode/rtu/%.cyclo: ../Modbus_Slave_Mode/rtu/%.c Modbus_Slave_Mode/rtu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/functions" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/include" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/port" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/rtu" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Slave_Mode-2f-rtu

clean-Modbus_Slave_Mode-2f-rtu:
	-$(RM) ./Modbus_Slave_Mode/rtu/mbcrc.cyclo ./Modbus_Slave_Mode/rtu/mbcrc.d ./Modbus_Slave_Mode/rtu/mbcrc.o ./Modbus_Slave_Mode/rtu/mbcrc.su ./Modbus_Slave_Mode/rtu/mbrtu.cyclo ./Modbus_Slave_Mode/rtu/mbrtu.d ./Modbus_Slave_Mode/rtu/mbrtu.o ./Modbus_Slave_Mode/rtu/mbrtu.su

.PHONY: clean-Modbus_Slave_Mode-2f-rtu

