################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/crc.c \
../Core/Src/dma.c \
../Core/Src/eeprom.c \
../Core/Src/freertos.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_hal_timebase_tim.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/system_stm32f0xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/crc.o \
./Core/Src/dma.o \
./Core/Src/eeprom.o \
./Core/Src/freertos.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_hal_timebase_tim.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/system_stm32f0xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/crc.d \
./Core/Src/dma.d \
./Core/Src/eeprom.d \
./Core/Src/freertos.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_hal_timebase_tim.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/system_stm32f0xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/other" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/H1DR1" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/H1DR1/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/H1DR1/Src" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/Modbus_Master" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/Modbus_Master/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/Modbus_Master/Src" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/Modbus_Slave/Scr" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/crc.cyclo ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/crc.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/eeprom.cyclo ./Core/Src/eeprom.d ./Core/Src/eeprom.o ./Core/Src/eeprom.su ./Core/Src/freertos.cyclo ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f0xx_hal_msp.cyclo ./Core/Src/stm32f0xx_hal_msp.d ./Core/Src/stm32f0xx_hal_msp.o ./Core/Src/stm32f0xx_hal_msp.su ./Core/Src/stm32f0xx_hal_timebase_tim.cyclo ./Core/Src/stm32f0xx_hal_timebase_tim.d ./Core/Src/stm32f0xx_hal_timebase_tim.o ./Core/Src/stm32f0xx_hal_timebase_tim.su ./Core/Src/stm32f0xx_it.cyclo ./Core/Src/stm32f0xx_it.d ./Core/Src/stm32f0xx_it.o ./Core/Src/stm32f0xx_it.su ./Core/Src/system_stm32f0xx.cyclo ./Core/Src/system_stm32f0xx.d ./Core/Src/system_stm32f0xx.o ./Core/Src/system_stm32f0xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

