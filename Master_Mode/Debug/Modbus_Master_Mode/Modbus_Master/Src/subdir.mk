################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Master_Mode/Modbus_Master/Src/mbm.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmascii.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmcrc.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfunccoils.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfunccustom1.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfuncdisc.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfuncfiles.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfuncholding.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfuncinput.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfuncraw.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmfuncslaveid.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmrtu.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmtcp.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbmudp.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbportevent.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbportother.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbportserial.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbporttimer.c \
../Modbus_Master_Mode/Modbus_Master/Src/mbutils.c 

OBJS += \
./Modbus_Master_Mode/Modbus_Master/Src/mbm.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmascii.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmcrc.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccoils.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccustom1.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncdisc.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncfiles.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncholding.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncinput.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncraw.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncslaveid.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmrtu.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmtcp.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbmudp.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbportevent.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbportother.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbportserial.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbporttimer.o \
./Modbus_Master_Mode/Modbus_Master/Src/mbutils.o 

C_DEPS += \
./Modbus_Master_Mode/Modbus_Master/Src/mbm.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmascii.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmcrc.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccoils.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccustom1.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncdisc.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncfiles.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncholding.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncinput.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncraw.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncslaveid.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmrtu.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmtcp.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbmudp.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbportevent.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbportother.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbportserial.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbporttimer.d \
./Modbus_Master_Mode/Modbus_Master/Src/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Master_Mode/Modbus_Master/Src/%.o Modbus_Master_Mode/Modbus_Master/Src/%.su Modbus_Master_Mode/Modbus_Master/Src/%.cyclo: ../Modbus_Master_Mode/Modbus_Master/Src/%.c Modbus_Master_Mode/Modbus_Master/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Drivers" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Device" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Include" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Src" -I"F:/HDD/Modbus_free/Master_Mode/Debug" -I"F:/HDD/Modbus_free/Master_Mode/Drivers" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver" -I"F:/HDD/Modbus_free/Master_Mode/Middlewares" -I"F:/HDD/Modbus_free/Master_Mode/Middlewares/Third_Party" -I"F:/HDD/Modbus_free/Master_Mode/Core" -I"F:/HDD/Modbus_free/Master_Mode/Core/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Core/Src" -I"F:/HDD/Modbus_free/Master_Mode/Core/Startup" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/other" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Master_Mode-2f-Modbus_Master-2f-Src

clean-Modbus_Master_Mode-2f-Modbus_Master-2f-Src:
	-$(RM) ./Modbus_Master_Mode/Modbus_Master/Src/mbm.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbm.d ./Modbus_Master_Mode/Modbus_Master/Src/mbm.o ./Modbus_Master_Mode/Modbus_Master/Src/mbm.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmascii.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmascii.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmascii.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmascii.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmcrc.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmcrc.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmcrc.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmcrc.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccoils.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccoils.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccoils.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccoils.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccustom1.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccustom1.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccustom1.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfunccustom1.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncdisc.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncdisc.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncdisc.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncdisc.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncfiles.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncfiles.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncfiles.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncfiles.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncholding.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncholding.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncholding.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncholding.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncinput.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncinput.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncinput.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncinput.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncraw.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncraw.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncraw.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncraw.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncslaveid.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncslaveid.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncslaveid.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmfuncslaveid.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmrtu.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmrtu.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmrtu.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmrtu.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmtcp.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmtcp.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmtcp.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmtcp.su ./Modbus_Master_Mode/Modbus_Master/Src/mbmudp.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbmudp.d ./Modbus_Master_Mode/Modbus_Master/Src/mbmudp.o ./Modbus_Master_Mode/Modbus_Master/Src/mbmudp.su ./Modbus_Master_Mode/Modbus_Master/Src/mbportevent.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbportevent.d ./Modbus_Master_Mode/Modbus_Master/Src/mbportevent.o ./Modbus_Master_Mode/Modbus_Master/Src/mbportevent.su ./Modbus_Master_Mode/Modbus_Master/Src/mbportother.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbportother.d ./Modbus_Master_Mode/Modbus_Master/Src/mbportother.o ./Modbus_Master_Mode/Modbus_Master/Src/mbportother.su ./Modbus_Master_Mode/Modbus_Master/Src/mbportserial.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbportserial.d ./Modbus_Master_Mode/Modbus_Master/Src/mbportserial.o ./Modbus_Master_Mode/Modbus_Master/Src/mbportserial.su ./Modbus_Master_Mode/Modbus_Master/Src/mbporttimer.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbporttimer.d ./Modbus_Master_Mode/Modbus_Master/Src/mbporttimer.o ./Modbus_Master_Mode/Modbus_Master/Src/mbporttimer.su ./Modbus_Master_Mode/Modbus_Master/Src/mbutils.cyclo ./Modbus_Master_Mode/Modbus_Master/Src/mbutils.d ./Modbus_Master_Mode/Modbus_Master/Src/mbutils.o ./Modbus_Master_Mode/Modbus_Master/Src/mbutils.su

.PHONY: clean-Modbus_Master_Mode-2f-Modbus_Master-2f-Src

