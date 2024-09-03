################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbportevent.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbportother.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbportserial.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbporttimer.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbs.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsascii.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbscrc.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfunccoils.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdiag.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdisc.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncfilerecord.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncholding.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncinput.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsrtu.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbsslaveid.c \
../Modbus_Slave_Mode/Modbus_Slave/Scr/mbutils.c 

OBJS += \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportevent.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportother.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportserial.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbporttimer.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbs.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsascii.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbscrc.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfunccoils.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdiag.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdisc.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncfilerecord.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncholding.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncinput.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsrtu.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsslaveid.o \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbutils.o 

C_DEPS += \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportevent.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportother.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportserial.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbporttimer.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbs.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsascii.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbscrc.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfunccoils.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdiag.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdisc.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncfilerecord.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncholding.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncinput.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsrtu.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsslaveid.d \
./Modbus_Slave_Mode/Modbus_Slave/Scr/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Slave_Mode/Modbus_Slave/Scr/%.o Modbus_Slave_Mode/Modbus_Slave/Scr/%.su Modbus_Slave_Mode/Modbus_Slave/Scr/%.cyclo: ../Modbus_Slave_Mode/Modbus_Slave/Scr/%.c Modbus_Slave_Mode/Modbus_Slave/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Scr" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/other" -I"F:/HDD/Modbus_free/Master_Mode/Core/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Device" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Include" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Scr" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/other" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Slave_Mode-2f-Modbus_Slave-2f-Scr

clean-Modbus_Slave_Mode-2f-Modbus_Slave-2f-Scr:
	-$(RM) ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportevent.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportevent.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportevent.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportevent.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportother.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportother.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportother.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportother.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportserial.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportserial.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportserial.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbportserial.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbporttimer.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbporttimer.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbporttimer.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbporttimer.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbs.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbs.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbs.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbs.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsascii.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsascii.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsascii.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsascii.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbscrc.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbscrc.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbscrc.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbscrc.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfunccoils.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfunccoils.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfunccoils.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfunccoils.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdiag.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdiag.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdiag.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdiag.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdisc.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdisc.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdisc.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncdisc.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncfilerecord.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncfilerecord.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncfilerecord.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncfilerecord.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncholding.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncholding.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncholding.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncholding.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncinput.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncinput.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncinput.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsfuncinput.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsrtu.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsrtu.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsrtu.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsrtu.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsslaveid.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsslaveid.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsslaveid.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbsslaveid.su ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbutils.cyclo ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbutils.d ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbutils.o ./Modbus_Slave_Mode/Modbus_Slave/Scr/mbutils.su

.PHONY: clean-Modbus_Slave_Mode-2f-Modbus_Slave-2f-Scr

