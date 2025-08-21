################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../S_Mod/mb.c \
../S_Mod/mb_API.c \
../S_Mod/mb_slave_API.c \
../S_Mod/mbtask.c 

OBJS += \
./S_Mod/mb.o \
./S_Mod/mb_API.o \
./S_Mod/mb_slave_API.o \
./S_Mod/mbtask.o 

C_DEPS += \
./S_Mod/mb.d \
./S_Mod/mb_API.d \
./S_Mod/mb_slave_API.d \
./S_Mod/mbtask.d 


# Each subdirectory must supply rules for building sources it contributes
S_Mod/%.o S_Mod/%.su S_Mod/%.cyclo: ../S_Mod/%.c S_Mod/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/functions" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/include" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/port" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Slave_Test/S_Mod/rtu" -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-S_Mod

clean-S_Mod:
	-$(RM) ./S_Mod/mb.cyclo ./S_Mod/mb.d ./S_Mod/mb.o ./S_Mod/mb.su ./S_Mod/mb_API.cyclo ./S_Mod/mb_API.d ./S_Mod/mb_API.o ./S_Mod/mb_API.su ./S_Mod/mb_slave_API.cyclo ./S_Mod/mb_slave_API.d ./S_Mod/mb_slave_API.o ./S_Mod/mb_slave_API.su ./S_Mod/mbtask.cyclo ./S_Mod/mbtask.d ./S_Mod/mbtask.o ./S_Mod/mbtask.su

.PHONY: clean-S_Mod

