################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Slave/Scr/mbportevent.c \
../Modbus_Slave/Scr/mbportother.c \
../Modbus_Slave/Scr/mbportserial.c \
../Modbus_Slave/Scr/mbporttimer.c \
../Modbus_Slave/Scr/mbs.c \
../Modbus_Slave/Scr/mbsascii.c \
../Modbus_Slave/Scr/mbscrc.c \
../Modbus_Slave/Scr/mbsfunccoils.c \
../Modbus_Slave/Scr/mbsfuncdiag.c \
../Modbus_Slave/Scr/mbsfuncdisc.c \
../Modbus_Slave/Scr/mbsfuncfilerecord.c \
../Modbus_Slave/Scr/mbsfuncholding.c \
../Modbus_Slave/Scr/mbsfuncinput.c \
../Modbus_Slave/Scr/mbsrtu.c \
../Modbus_Slave/Scr/mbsslaveid.c \
../Modbus_Slave/Scr/mbutils.c 

OBJS += \
./Modbus_Slave/Scr/mbportevent.o \
./Modbus_Slave/Scr/mbportother.o \
./Modbus_Slave/Scr/mbportserial.o \
./Modbus_Slave/Scr/mbporttimer.o \
./Modbus_Slave/Scr/mbs.o \
./Modbus_Slave/Scr/mbsascii.o \
./Modbus_Slave/Scr/mbscrc.o \
./Modbus_Slave/Scr/mbsfunccoils.o \
./Modbus_Slave/Scr/mbsfuncdiag.o \
./Modbus_Slave/Scr/mbsfuncdisc.o \
./Modbus_Slave/Scr/mbsfuncfilerecord.o \
./Modbus_Slave/Scr/mbsfuncholding.o \
./Modbus_Slave/Scr/mbsfuncinput.o \
./Modbus_Slave/Scr/mbsrtu.o \
./Modbus_Slave/Scr/mbsslaveid.o \
./Modbus_Slave/Scr/mbutils.o 

C_DEPS += \
./Modbus_Slave/Scr/mbportevent.d \
./Modbus_Slave/Scr/mbportother.d \
./Modbus_Slave/Scr/mbportserial.d \
./Modbus_Slave/Scr/mbporttimer.d \
./Modbus_Slave/Scr/mbs.d \
./Modbus_Slave/Scr/mbsascii.d \
./Modbus_Slave/Scr/mbscrc.d \
./Modbus_Slave/Scr/mbsfunccoils.d \
./Modbus_Slave/Scr/mbsfuncdiag.d \
./Modbus_Slave/Scr/mbsfuncdisc.d \
./Modbus_Slave/Scr/mbsfuncfilerecord.d \
./Modbus_Slave/Scr/mbsfuncholding.d \
./Modbus_Slave/Scr/mbsfuncinput.d \
./Modbus_Slave/Scr/mbsrtu.d \
./Modbus_Slave/Scr/mbsslaveid.d \
./Modbus_Slave/Scr/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Slave/Scr/%.o Modbus_Slave/Scr/%.su: ../Modbus_Slave/Scr/%.c Modbus_Slave/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/Modbus_Slave/Inc" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/Modbus_Slave" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/H1DR1" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/other" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Slave-2f-Scr

clean-Modbus_Slave-2f-Scr:
	-$(RM) ./Modbus_Slave/Scr/mbportevent.d ./Modbus_Slave/Scr/mbportevent.o ./Modbus_Slave/Scr/mbportevent.su ./Modbus_Slave/Scr/mbportother.d ./Modbus_Slave/Scr/mbportother.o ./Modbus_Slave/Scr/mbportother.su ./Modbus_Slave/Scr/mbportserial.d ./Modbus_Slave/Scr/mbportserial.o ./Modbus_Slave/Scr/mbportserial.su ./Modbus_Slave/Scr/mbporttimer.d ./Modbus_Slave/Scr/mbporttimer.o ./Modbus_Slave/Scr/mbporttimer.su ./Modbus_Slave/Scr/mbs.d ./Modbus_Slave/Scr/mbs.o ./Modbus_Slave/Scr/mbs.su ./Modbus_Slave/Scr/mbsascii.d ./Modbus_Slave/Scr/mbsascii.o ./Modbus_Slave/Scr/mbsascii.su ./Modbus_Slave/Scr/mbscrc.d ./Modbus_Slave/Scr/mbscrc.o ./Modbus_Slave/Scr/mbscrc.su ./Modbus_Slave/Scr/mbsfunccoils.d ./Modbus_Slave/Scr/mbsfunccoils.o ./Modbus_Slave/Scr/mbsfunccoils.su ./Modbus_Slave/Scr/mbsfuncdiag.d ./Modbus_Slave/Scr/mbsfuncdiag.o ./Modbus_Slave/Scr/mbsfuncdiag.su ./Modbus_Slave/Scr/mbsfuncdisc.d ./Modbus_Slave/Scr/mbsfuncdisc.o ./Modbus_Slave/Scr/mbsfuncdisc.su ./Modbus_Slave/Scr/mbsfuncfilerecord.d ./Modbus_Slave/Scr/mbsfuncfilerecord.o ./Modbus_Slave/Scr/mbsfuncfilerecord.su ./Modbus_Slave/Scr/mbsfuncholding.d ./Modbus_Slave/Scr/mbsfuncholding.o ./Modbus_Slave/Scr/mbsfuncholding.su ./Modbus_Slave/Scr/mbsfuncinput.d ./Modbus_Slave/Scr/mbsfuncinput.o ./Modbus_Slave/Scr/mbsfuncinput.su ./Modbus_Slave/Scr/mbsrtu.d ./Modbus_Slave/Scr/mbsrtu.o ./Modbus_Slave/Scr/mbsrtu.su ./Modbus_Slave/Scr/mbsslaveid.d ./Modbus_Slave/Scr/mbsslaveid.o ./Modbus_Slave/Scr/mbsslaveid.su ./Modbus_Slave/Scr/mbutils.d ./Modbus_Slave/Scr/mbutils.o ./Modbus_Slave/Scr/mbutils.su

.PHONY: clean-Modbus_Slave-2f-Scr

