################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/%.o Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/%.su Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/%.cyclo: ../Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/%.c Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Scr" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/other" -I"F:/HDD/Modbus_free/Master_Mode/Core/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Device" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Include" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Scr" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/other" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.d ./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.o ./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

