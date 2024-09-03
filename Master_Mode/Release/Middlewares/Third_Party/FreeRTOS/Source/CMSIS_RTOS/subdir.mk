################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.o Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.su Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.cyclo: ../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.c Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F091xC -c -I../Core/Inc -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/other" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/H1DR1" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/H1DR1/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/H1DR1/Src" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/Modbus_Master" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/Modbus_Master/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Master_Mode/Modbus_Master/Src" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Hexabiz_0.3.4/H1DR1_Modbus_Firmware/Modbus_Slave_Mode/Modbus_Slave/Scr" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d ./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o ./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS

