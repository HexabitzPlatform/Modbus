################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S_Mod/rtu/mbcrc.c \
../S_Mod/rtu/mbrtu.c 

OBJS += \
./S_Mod/rtu/mbcrc.o \
./S_Mod/rtu/mbrtu.o 

C_DEPS += \
./S_Mod/rtu/mbcrc.d \
./S_Mod/rtu/mbrtu.d 


# Each subdirectory must supply rules for building sources it contributes
S_Mod/rtu/%.o S_Mod/rtu/%.su S_Mod/rtu/%.cyclo: ../S_Mod/rtu/%.c S_Mod/rtu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/functions" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/include" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/port" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/rtu" -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-S_Mod-2f-rtu

clean-S_Mod-2f-rtu:
	-$(RM) ./S_Mod/rtu/mbcrc.cyclo ./S_Mod/rtu/mbcrc.d ./S_Mod/rtu/mbcrc.o ./S_Mod/rtu/mbcrc.su ./S_Mod/rtu/mbrtu.cyclo ./S_Mod/rtu/mbrtu.d ./S_Mod/rtu/mbrtu.o ./S_Mod/rtu/mbrtu.su

.PHONY: clean-S_Mod-2f-rtu

