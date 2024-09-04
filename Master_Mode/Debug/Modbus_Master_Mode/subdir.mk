################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Master_Mode/mb_master_API.c 

OBJS += \
./Modbus_Master_Mode/mb_master_API.o 

C_DEPS += \
./Modbus_Master_Mode/mb_master_API.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Master_Mode/%.o Modbus_Master_Mode/%.su Modbus_Master_Mode/%.cyclo: ../Modbus_Master_Mode/%.c Modbus_Master_Mode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Drivers" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Device" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Include" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Src" -I"F:/HDD/Modbus_free/Master_Mode/Debug" -I"F:/HDD/Modbus_free/Master_Mode/Drivers" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver" -I"F:/HDD/Modbus_free/Master_Mode/Middlewares" -I"F:/HDD/Modbus_free/Master_Mode/Middlewares/Third_Party" -I"F:/HDD/Modbus_free/Master_Mode/Core" -I"F:/HDD/Modbus_free/Master_Mode/Core/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Core/Src" -I"F:/HDD/Modbus_free/Master_Mode/Core/Startup" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/other" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Master_Mode

clean-Modbus_Master_Mode:
	-$(RM) ./Modbus_Master_Mode/mb_master_API.cyclo ./Modbus_Master_Mode/mb_master_API.d ./Modbus_Master_Mode/mb_master_API.o ./Modbus_Master_Mode/mb_master_API.su

.PHONY: clean-Modbus_Master_Mode

