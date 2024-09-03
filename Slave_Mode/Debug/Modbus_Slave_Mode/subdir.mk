################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Slave_Mode/mb.c \
../Modbus_Slave_Mode/mb_API.c \
../Modbus_Slave_Mode/mb_slave_API.c \
../Modbus_Slave_Mode/mbtask.c 

OBJS += \
./Modbus_Slave_Mode/mb.o \
./Modbus_Slave_Mode/mb_API.o \
./Modbus_Slave_Mode/mb_slave_API.o \
./Modbus_Slave_Mode/mbtask.o 

C_DEPS += \
./Modbus_Slave_Mode/mb.d \
./Modbus_Slave_Mode/mb_API.d \
./Modbus_Slave_Mode/mb_slave_API.d \
./Modbus_Slave_Mode/mbtask.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Slave_Mode/%.o Modbus_Slave_Mode/%.su Modbus_Slave_Mode/%.cyclo: ../Modbus_Slave_Mode/%.c Modbus_Slave_Mode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/functions" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/include" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/port" -I"F:/HDD/Modbus_free/Slave_Mode/Modbus_Slave_Mode/rtu" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Slave_Mode

clean-Modbus_Slave_Mode:
	-$(RM) ./Modbus_Slave_Mode/mb.cyclo ./Modbus_Slave_Mode/mb.d ./Modbus_Slave_Mode/mb.o ./Modbus_Slave_Mode/mb.su ./Modbus_Slave_Mode/mb_API.cyclo ./Modbus_Slave_Mode/mb_API.d ./Modbus_Slave_Mode/mb_API.o ./Modbus_Slave_Mode/mb_API.su ./Modbus_Slave_Mode/mb_slave_API.cyclo ./Modbus_Slave_Mode/mb_slave_API.d ./Modbus_Slave_Mode/mb_slave_API.o ./Modbus_Slave_Mode/mb_slave_API.su ./Modbus_Slave_Mode/mbtask.cyclo ./Modbus_Slave_Mode/mbtask.d ./Modbus_Slave_Mode/mbtask.o ./Modbus_Slave_Mode/mbtask.su

.PHONY: clean-Modbus_Slave_Mode

