################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_H/mbs.c \
../Modbus_H/mbsascii.c \
../Modbus_H/mbscrc.c \
../Modbus_H/mbsfunccoils.c \
../Modbus_H/mbsfuncdiag.c \
../Modbus_H/mbsfuncdisc.c \
../Modbus_H/mbsfuncfilerecord.c \
../Modbus_H/mbsfuncholding.c \
../Modbus_H/mbsfuncinput.c \
../Modbus_H/mbsrtu.c \
../Modbus_H/mbsslaveid.c \
../Modbus_H/mbutils.c 

OBJS += \
./Modbus_H/mbs.o \
./Modbus_H/mbsascii.o \
./Modbus_H/mbscrc.o \
./Modbus_H/mbsfunccoils.o \
./Modbus_H/mbsfuncdiag.o \
./Modbus_H/mbsfuncdisc.o \
./Modbus_H/mbsfuncfilerecord.o \
./Modbus_H/mbsfuncholding.o \
./Modbus_H/mbsfuncinput.o \
./Modbus_H/mbsrtu.o \
./Modbus_H/mbsslaveid.o \
./Modbus_H/mbutils.o 

C_DEPS += \
./Modbus_H/mbs.d \
./Modbus_H/mbsascii.d \
./Modbus_H/mbscrc.d \
./Modbus_H/mbsfunccoils.d \
./Modbus_H/mbsfuncdiag.d \
./Modbus_H/mbsfuncdisc.d \
./Modbus_H/mbsfuncfilerecord.d \
./Modbus_H/mbsfuncholding.d \
./Modbus_H/mbsfuncinput.d \
./Modbus_H/mbsrtu.d \
./Modbus_H/mbsslaveid.d \
./Modbus_H/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_H/%.o Modbus_H/%.su: ../Modbus_H/%.c Modbus_H/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE/H1DR1" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE/other" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE/Modbus_H" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_H

clean-Modbus_H:
	-$(RM) ./Modbus_H/mbs.d ./Modbus_H/mbs.o ./Modbus_H/mbs.su ./Modbus_H/mbsascii.d ./Modbus_H/mbsascii.o ./Modbus_H/mbsascii.su ./Modbus_H/mbscrc.d ./Modbus_H/mbscrc.o ./Modbus_H/mbscrc.su ./Modbus_H/mbsfunccoils.d ./Modbus_H/mbsfunccoils.o ./Modbus_H/mbsfunccoils.su ./Modbus_H/mbsfuncdiag.d ./Modbus_H/mbsfuncdiag.o ./Modbus_H/mbsfuncdiag.su ./Modbus_H/mbsfuncdisc.d ./Modbus_H/mbsfuncdisc.o ./Modbus_H/mbsfuncdisc.su ./Modbus_H/mbsfuncfilerecord.d ./Modbus_H/mbsfuncfilerecord.o ./Modbus_H/mbsfuncfilerecord.su ./Modbus_H/mbsfuncholding.d ./Modbus_H/mbsfuncholding.o ./Modbus_H/mbsfuncholding.su ./Modbus_H/mbsfuncinput.d ./Modbus_H/mbsfuncinput.o ./Modbus_H/mbsfuncinput.su ./Modbus_H/mbsrtu.d ./Modbus_H/mbsrtu.o ./Modbus_H/mbsrtu.su ./Modbus_H/mbsslaveid.d ./Modbus_H/mbsslaveid.o ./Modbus_H/mbsslaveid.su ./Modbus_H/mbutils.d ./Modbus_H/mbutils.o ./Modbus_H/mbutils.su

.PHONY: clean-Modbus_H

