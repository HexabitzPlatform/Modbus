################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_C/mbs.c \
../Modbus_C/mbsascii.c \
../Modbus_C/mbscrc.c \
../Modbus_C/mbsfunccoils.c \
../Modbus_C/mbsfuncdiag.c \
../Modbus_C/mbsfuncdisc.c \
../Modbus_C/mbsfuncfilerecord.c \
../Modbus_C/mbsfuncholding.c \
../Modbus_C/mbsfuncinput.c \
../Modbus_C/mbsrtu.c \
../Modbus_C/mbsslaveid.c \
../Modbus_C/mbutils.c 

OBJS += \
./Modbus_C/mbs.o \
./Modbus_C/mbsascii.o \
./Modbus_C/mbscrc.o \
./Modbus_C/mbsfunccoils.o \
./Modbus_C/mbsfuncdiag.o \
./Modbus_C/mbsfuncdisc.o \
./Modbus_C/mbsfuncfilerecord.o \
./Modbus_C/mbsfuncholding.o \
./Modbus_C/mbsfuncinput.o \
./Modbus_C/mbsrtu.o \
./Modbus_C/mbsslaveid.o \
./Modbus_C/mbutils.o 

C_DEPS += \
./Modbus_C/mbs.d \
./Modbus_C/mbsascii.d \
./Modbus_C/mbscrc.d \
./Modbus_C/mbsfunccoils.d \
./Modbus_C/mbsfuncdiag.d \
./Modbus_C/mbsfuncdisc.d \
./Modbus_C/mbsfuncfilerecord.d \
./Modbus_C/mbsfuncholding.d \
./Modbus_C/mbsfuncinput.d \
./Modbus_C/mbsrtu.d \
./Modbus_C/mbsslaveid.d \
./Modbus_C/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_C/%.o Modbus_C/%.su: ../Modbus_C/%.c Modbus_C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE/H1DR1" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE/other" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE/Modbus_H" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE/EMS_H" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_C

clean-Modbus_C:
	-$(RM) ./Modbus_C/mbs.d ./Modbus_C/mbs.o ./Modbus_C/mbs.su ./Modbus_C/mbsascii.d ./Modbus_C/mbsascii.o ./Modbus_C/mbsascii.su ./Modbus_C/mbscrc.d ./Modbus_C/mbscrc.o ./Modbus_C/mbscrc.su ./Modbus_C/mbsfunccoils.d ./Modbus_C/mbsfunccoils.o ./Modbus_C/mbsfunccoils.su ./Modbus_C/mbsfuncdiag.d ./Modbus_C/mbsfuncdiag.o ./Modbus_C/mbsfuncdiag.su ./Modbus_C/mbsfuncdisc.d ./Modbus_C/mbsfuncdisc.o ./Modbus_C/mbsfuncdisc.su ./Modbus_C/mbsfuncfilerecord.d ./Modbus_C/mbsfuncfilerecord.o ./Modbus_C/mbsfuncfilerecord.su ./Modbus_C/mbsfuncholding.d ./Modbus_C/mbsfuncholding.o ./Modbus_C/mbsfuncholding.su ./Modbus_C/mbsfuncinput.d ./Modbus_C/mbsfuncinput.o ./Modbus_C/mbsfuncinput.su ./Modbus_C/mbsrtu.d ./Modbus_C/mbsrtu.o ./Modbus_C/mbsrtu.su ./Modbus_C/mbsslaveid.d ./Modbus_C/mbsslaveid.o ./Modbus_C/mbsslaveid.su ./Modbus_C/mbutils.d ./Modbus_C/mbutils.o ./Modbus_C/mbutils.su

.PHONY: clean-Modbus_C

