################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S_Mod/functions/mbfunccoils.c \
../S_Mod/functions/mbfuncdiag.c \
../S_Mod/functions/mbfuncdisc.c \
../S_Mod/functions/mbfuncholding.c \
../S_Mod/functions/mbfuncinput.c \
../S_Mod/functions/mbfuncother.c \
../S_Mod/functions/mbutils.c 

OBJS += \
./S_Mod/functions/mbfunccoils.o \
./S_Mod/functions/mbfuncdiag.o \
./S_Mod/functions/mbfuncdisc.o \
./S_Mod/functions/mbfuncholding.o \
./S_Mod/functions/mbfuncinput.o \
./S_Mod/functions/mbfuncother.o \
./S_Mod/functions/mbutils.o 

C_DEPS += \
./S_Mod/functions/mbfunccoils.d \
./S_Mod/functions/mbfuncdiag.d \
./S_Mod/functions/mbfuncdisc.d \
./S_Mod/functions/mbfuncholding.d \
./S_Mod/functions/mbfuncinput.d \
./S_Mod/functions/mbfuncother.d \
./S_Mod/functions/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
S_Mod/functions/%.o S_Mod/functions/%.su S_Mod/functions/%.cyclo: ../S_Mod/functions/%.c S_Mod/functions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/functions" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/include" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/port" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/rtu" -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-S_Mod-2f-functions

clean-S_Mod-2f-functions:
	-$(RM) ./S_Mod/functions/mbfunccoils.cyclo ./S_Mod/functions/mbfunccoils.d ./S_Mod/functions/mbfunccoils.o ./S_Mod/functions/mbfunccoils.su ./S_Mod/functions/mbfuncdiag.cyclo ./S_Mod/functions/mbfuncdiag.d ./S_Mod/functions/mbfuncdiag.o ./S_Mod/functions/mbfuncdiag.su ./S_Mod/functions/mbfuncdisc.cyclo ./S_Mod/functions/mbfuncdisc.d ./S_Mod/functions/mbfuncdisc.o ./S_Mod/functions/mbfuncdisc.su ./S_Mod/functions/mbfuncholding.cyclo ./S_Mod/functions/mbfuncholding.d ./S_Mod/functions/mbfuncholding.o ./S_Mod/functions/mbfuncholding.su ./S_Mod/functions/mbfuncinput.cyclo ./S_Mod/functions/mbfuncinput.d ./S_Mod/functions/mbfuncinput.o ./S_Mod/functions/mbfuncinput.su ./S_Mod/functions/mbfuncother.cyclo ./S_Mod/functions/mbfuncother.d ./S_Mod/functions/mbfuncother.o ./S_Mod/functions/mbfuncother.su ./S_Mod/functions/mbutils.cyclo ./S_Mod/functions/mbutils.d ./S_Mod/functions/mbutils.o ./S_Mod/functions/mbutils.su

.PHONY: clean-S_Mod-2f-functions

