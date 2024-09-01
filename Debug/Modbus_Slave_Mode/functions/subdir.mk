################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Slave_Mode/functions/mbfunccoils.c \
../Modbus_Slave_Mode/functions/mbfuncdiag.c \
../Modbus_Slave_Mode/functions/mbfuncdisc.c \
../Modbus_Slave_Mode/functions/mbfuncholding.c \
../Modbus_Slave_Mode/functions/mbfuncinput.c \
../Modbus_Slave_Mode/functions/mbfuncother.c \
../Modbus_Slave_Mode/functions/mbutils.c 

OBJS += \
./Modbus_Slave_Mode/functions/mbfunccoils.o \
./Modbus_Slave_Mode/functions/mbfuncdiag.o \
./Modbus_Slave_Mode/functions/mbfuncdisc.o \
./Modbus_Slave_Mode/functions/mbfuncholding.o \
./Modbus_Slave_Mode/functions/mbfuncinput.o \
./Modbus_Slave_Mode/functions/mbfuncother.o \
./Modbus_Slave_Mode/functions/mbutils.o 

C_DEPS += \
./Modbus_Slave_Mode/functions/mbfunccoils.d \
./Modbus_Slave_Mode/functions/mbfuncdiag.d \
./Modbus_Slave_Mode/functions/mbfuncdisc.d \
./Modbus_Slave_Mode/functions/mbfuncholding.d \
./Modbus_Slave_Mode/functions/mbfuncinput.d \
./Modbus_Slave_Mode/functions/mbfuncother.d \
./Modbus_Slave_Mode/functions/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Slave_Mode/functions/%.o Modbus_Slave_Mode/functions/%.su Modbus_Slave_Mode/functions/%.cyclo: ../Modbus_Slave_Mode/functions/%.c Modbus_Slave_Mode/functions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/functions" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/include" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/port" -I"F:/HDD/Hexabiz_0.3.0/Modbus_Slave/Modbus_Slave_Mode/rtu" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Slave_Mode-2f-functions

clean-Modbus_Slave_Mode-2f-functions:
	-$(RM) ./Modbus_Slave_Mode/functions/mbfunccoils.cyclo ./Modbus_Slave_Mode/functions/mbfunccoils.d ./Modbus_Slave_Mode/functions/mbfunccoils.o ./Modbus_Slave_Mode/functions/mbfunccoils.su ./Modbus_Slave_Mode/functions/mbfuncdiag.cyclo ./Modbus_Slave_Mode/functions/mbfuncdiag.d ./Modbus_Slave_Mode/functions/mbfuncdiag.o ./Modbus_Slave_Mode/functions/mbfuncdiag.su ./Modbus_Slave_Mode/functions/mbfuncdisc.cyclo ./Modbus_Slave_Mode/functions/mbfuncdisc.d ./Modbus_Slave_Mode/functions/mbfuncdisc.o ./Modbus_Slave_Mode/functions/mbfuncdisc.su ./Modbus_Slave_Mode/functions/mbfuncholding.cyclo ./Modbus_Slave_Mode/functions/mbfuncholding.d ./Modbus_Slave_Mode/functions/mbfuncholding.o ./Modbus_Slave_Mode/functions/mbfuncholding.su ./Modbus_Slave_Mode/functions/mbfuncinput.cyclo ./Modbus_Slave_Mode/functions/mbfuncinput.d ./Modbus_Slave_Mode/functions/mbfuncinput.o ./Modbus_Slave_Mode/functions/mbfuncinput.su ./Modbus_Slave_Mode/functions/mbfuncother.cyclo ./Modbus_Slave_Mode/functions/mbfuncother.d ./Modbus_Slave_Mode/functions/mbfuncother.o ./Modbus_Slave_Mode/functions/mbfuncother.su ./Modbus_Slave_Mode/functions/mbutils.cyclo ./Modbus_Slave_Mode/functions/mbutils.d ./Modbus_Slave_Mode/functions/mbutils.o ./Modbus_Slave_Mode/functions/mbutils.su

.PHONY: clean-Modbus_Slave_Mode-2f-functions

