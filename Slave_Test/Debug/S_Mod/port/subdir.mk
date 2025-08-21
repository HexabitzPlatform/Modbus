################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S_Mod/port/portevent.c \
../S_Mod/port/portserial.c \
../S_Mod/port/porttimer.c 

OBJS += \
./S_Mod/port/portevent.o \
./S_Mod/port/portserial.o \
./S_Mod/port/porttimer.o 

C_DEPS += \
./S_Mod/port/portevent.d \
./S_Mod/port/portserial.d \
./S_Mod/port/porttimer.d 


# Each subdirectory must supply rules for building sources it contributes
S_Mod/port/%.o S_Mod/port/%.su S_Mod/port/%.cyclo: ../S_Mod/port/%.c S_Mod/port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/functions" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/include" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/port" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/rtu" -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-S_Mod-2f-port

clean-S_Mod-2f-port:
	-$(RM) ./S_Mod/port/portevent.cyclo ./S_Mod/port/portevent.d ./S_Mod/port/portevent.o ./S_Mod/port/portevent.su ./S_Mod/port/portserial.cyclo ./S_Mod/port/portserial.d ./S_Mod/port/portserial.o ./S_Mod/port/portserial.su ./S_Mod/port/porttimer.cyclo ./S_Mod/port/porttimer.d ./S_Mod/port/porttimer.o ./S_Mod/port/porttimer.su

.PHONY: clean-S_Mod-2f-port

