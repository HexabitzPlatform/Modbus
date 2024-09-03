################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../H1DR1/H1DR1.c \
../H1DR1/Messaging_Slave.c 

OBJS += \
./H1DR1/H1DR1.o \
./H1DR1/Messaging_Slave.o 

C_DEPS += \
./H1DR1/H1DR1.d \
./H1DR1/Messaging_Slave.d 


# Each subdirectory must supply rules for building sources it contributes
H1DR1/%.o H1DR1/%.su: ../H1DR1/%.c H1DR1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/Modbus_Slave/Inc" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/Modbus_Slave" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/H1DR1" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/Modbus_Slave_CubIDE_Final3/other" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-H1DR1

clean-H1DR1:
	-$(RM) ./H1DR1/H1DR1.d ./H1DR1/H1DR1.o ./H1DR1/H1DR1.su ./H1DR1/Messaging_Slave.d ./H1DR1/Messaging_Slave.o ./H1DR1/Messaging_Slave.su

.PHONY: clean-H1DR1

