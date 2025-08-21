################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../M_Mod/Src/mbm.c \
../M_Mod/Src/mbmascii.c \
../M_Mod/Src/mbmcrc.c \
../M_Mod/Src/mbmfunccoils.c \
../M_Mod/Src/mbmfunccustom1.c \
../M_Mod/Src/mbmfuncdisc.c \
../M_Mod/Src/mbmfuncfiles.c \
../M_Mod/Src/mbmfuncholding.c \
../M_Mod/Src/mbmfuncinput.c \
../M_Mod/Src/mbmfuncraw.c \
../M_Mod/Src/mbmfuncslaveid.c \
../M_Mod/Src/mbmrtu.c \
../M_Mod/Src/mbmtcp.c \
../M_Mod/Src/mbmudp.c \
../M_Mod/Src/mbportevent.c \
../M_Mod/Src/mbportother.c \
../M_Mod/Src/mbportserial.c \
../M_Mod/Src/mbporttimer.c \
../M_Mod/Src/mbutils.c 

OBJS += \
./M_Mod/Src/mbm.o \
./M_Mod/Src/mbmascii.o \
./M_Mod/Src/mbmcrc.o \
./M_Mod/Src/mbmfunccoils.o \
./M_Mod/Src/mbmfunccustom1.o \
./M_Mod/Src/mbmfuncdisc.o \
./M_Mod/Src/mbmfuncfiles.o \
./M_Mod/Src/mbmfuncholding.o \
./M_Mod/Src/mbmfuncinput.o \
./M_Mod/Src/mbmfuncraw.o \
./M_Mod/Src/mbmfuncslaveid.o \
./M_Mod/Src/mbmrtu.o \
./M_Mod/Src/mbmtcp.o \
./M_Mod/Src/mbmudp.o \
./M_Mod/Src/mbportevent.o \
./M_Mod/Src/mbportother.o \
./M_Mod/Src/mbportserial.o \
./M_Mod/Src/mbporttimer.o \
./M_Mod/Src/mbutils.o 

C_DEPS += \
./M_Mod/Src/mbm.d \
./M_Mod/Src/mbmascii.d \
./M_Mod/Src/mbmcrc.d \
./M_Mod/Src/mbmfunccoils.d \
./M_Mod/Src/mbmfunccustom1.d \
./M_Mod/Src/mbmfuncdisc.d \
./M_Mod/Src/mbmfuncfiles.d \
./M_Mod/Src/mbmfuncholding.d \
./M_Mod/Src/mbmfuncinput.d \
./M_Mod/Src/mbmfuncraw.d \
./M_Mod/Src/mbmfuncslaveid.d \
./M_Mod/Src/mbmrtu.d \
./M_Mod/Src/mbmtcp.d \
./M_Mod/Src/mbmudp.d \
./M_Mod/Src/mbportevent.d \
./M_Mod/Src/mbportother.d \
./M_Mod/Src/mbportserial.d \
./M_Mod/Src/mbporttimer.d \
./M_Mod/Src/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
M_Mod/Src/%.o M_Mod/Src/%.su M_Mod/Src/%.cyclo: ../M_Mod/Src/%.c M_Mod/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Master_Test/M_Mod/Inc" -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-M_Mod-2f-Src

clean-M_Mod-2f-Src:
	-$(RM) ./M_Mod/Src/mbm.cyclo ./M_Mod/Src/mbm.d ./M_Mod/Src/mbm.o ./M_Mod/Src/mbm.su ./M_Mod/Src/mbmascii.cyclo ./M_Mod/Src/mbmascii.d ./M_Mod/Src/mbmascii.o ./M_Mod/Src/mbmascii.su ./M_Mod/Src/mbmcrc.cyclo ./M_Mod/Src/mbmcrc.d ./M_Mod/Src/mbmcrc.o ./M_Mod/Src/mbmcrc.su ./M_Mod/Src/mbmfunccoils.cyclo ./M_Mod/Src/mbmfunccoils.d ./M_Mod/Src/mbmfunccoils.o ./M_Mod/Src/mbmfunccoils.su ./M_Mod/Src/mbmfunccustom1.cyclo ./M_Mod/Src/mbmfunccustom1.d ./M_Mod/Src/mbmfunccustom1.o ./M_Mod/Src/mbmfunccustom1.su ./M_Mod/Src/mbmfuncdisc.cyclo ./M_Mod/Src/mbmfuncdisc.d ./M_Mod/Src/mbmfuncdisc.o ./M_Mod/Src/mbmfuncdisc.su ./M_Mod/Src/mbmfuncfiles.cyclo ./M_Mod/Src/mbmfuncfiles.d ./M_Mod/Src/mbmfuncfiles.o ./M_Mod/Src/mbmfuncfiles.su ./M_Mod/Src/mbmfuncholding.cyclo ./M_Mod/Src/mbmfuncholding.d ./M_Mod/Src/mbmfuncholding.o ./M_Mod/Src/mbmfuncholding.su ./M_Mod/Src/mbmfuncinput.cyclo ./M_Mod/Src/mbmfuncinput.d ./M_Mod/Src/mbmfuncinput.o ./M_Mod/Src/mbmfuncinput.su ./M_Mod/Src/mbmfuncraw.cyclo ./M_Mod/Src/mbmfuncraw.d ./M_Mod/Src/mbmfuncraw.o ./M_Mod/Src/mbmfuncraw.su ./M_Mod/Src/mbmfuncslaveid.cyclo ./M_Mod/Src/mbmfuncslaveid.d ./M_Mod/Src/mbmfuncslaveid.o ./M_Mod/Src/mbmfuncslaveid.su ./M_Mod/Src/mbmrtu.cyclo ./M_Mod/Src/mbmrtu.d ./M_Mod/Src/mbmrtu.o ./M_Mod/Src/mbmrtu.su ./M_Mod/Src/mbmtcp.cyclo ./M_Mod/Src/mbmtcp.d ./M_Mod/Src/mbmtcp.o ./M_Mod/Src/mbmtcp.su ./M_Mod/Src/mbmudp.cyclo ./M_Mod/Src/mbmudp.d ./M_Mod/Src/mbmudp.o ./M_Mod/Src/mbmudp.su ./M_Mod/Src/mbportevent.cyclo ./M_Mod/Src/mbportevent.d ./M_Mod/Src/mbportevent.o ./M_Mod/Src/mbportevent.su ./M_Mod/Src/mbportother.cyclo ./M_Mod/Src/mbportother.d ./M_Mod/Src/mbportother.o ./M_Mod/Src/mbportother.su ./M_Mod/Src/mbportserial.cyclo ./M_Mod/Src/mbportserial.d ./M_Mod/Src/mbportserial.o ./M_Mod/Src/mbportserial.su ./M_Mod/Src/mbporttimer.cyclo ./M_Mod/Src/mbporttimer.d ./M_Mod/Src/mbporttimer.o ./M_Mod/Src/mbporttimer.su ./M_Mod/Src/mbutils.cyclo ./M_Mod/Src/mbutils.d ./M_Mod/Src/mbutils.o ./M_Mod/Src/mbutils.su

.PHONY: clean-M_Mod-2f-Src

