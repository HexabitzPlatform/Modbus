################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EMS_C/EMS_dma.c \
../EMS_C/EMS_gpio.c \
../EMS_C/EMS_tmr.c \
../EMS_C/EMS_uart.c 

OBJS += \
./EMS_C/EMS_dma.o \
./EMS_C/EMS_gpio.o \
./EMS_C/EMS_tmr.o \
./EMS_C/EMS_uart.o 

C_DEPS += \
./EMS_C/EMS_dma.d \
./EMS_C/EMS_gpio.d \
./EMS_C/EMS_tmr.d \
./EMS_C/EMS_uart.d 


# Each subdirectory must supply rules for building sources it contributes
EMS_C/%.o EMS_C/%.su: ../EMS_C/%.c EMS_C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/test_7/other" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/test_7/Modbus_H" -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.9.0/test_7/EMS_H" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-EMS_C

clean-EMS_C:
	-$(RM) ./EMS_C/EMS_dma.d ./EMS_C/EMS_dma.o ./EMS_C/EMS_dma.su ./EMS_C/EMS_gpio.d ./EMS_C/EMS_gpio.o ./EMS_C/EMS_gpio.su ./EMS_C/EMS_tmr.d ./EMS_C/EMS_tmr.o ./EMS_C/EMS_tmr.su ./EMS_C/EMS_uart.d ./EMS_C/EMS_uart.o ./EMS_C/EMS_uart.su

.PHONY: clean-EMS_C

