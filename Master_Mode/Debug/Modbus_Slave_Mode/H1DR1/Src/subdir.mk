################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_Slave_Mode/H1DR1/Src/H1DR1_Slave.c \
../Modbus_Slave_Mode/H1DR1/Src/Messaging_Slave.c \
../Modbus_Slave_Mode/H1DR1/Src/Modbus_Slave_Mode.c 

OBJS += \
./Modbus_Slave_Mode/H1DR1/Src/H1DR1_Slave.o \
./Modbus_Slave_Mode/H1DR1/Src/Messaging_Slave.o \
./Modbus_Slave_Mode/H1DR1/Src/Modbus_Slave_Mode.o 

C_DEPS += \
./Modbus_Slave_Mode/H1DR1/Src/H1DR1_Slave.d \
./Modbus_Slave_Mode/H1DR1/Src/Messaging_Slave.d \
./Modbus_Slave_Mode/H1DR1/Src/Modbus_Slave_Mode.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_Slave_Mode/H1DR1/Src/%.o Modbus_Slave_Mode/H1DR1/Src/%.su Modbus_Slave_Mode/H1DR1/Src/%.cyclo: ../Modbus_Slave_Mode/H1DR1/Src/%.c Modbus_Slave_Mode/H1DR1/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F091xC -c -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Scr" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/other" -I"F:/HDD/Modbus_free/Master_Mode/Core/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Device" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/CMSIS/Include" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Drivers/STM32F0xx_HAL_Driver/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode/Modbus_Master/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/H1DR1/Src" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Inc" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/Modbus_Slave/Scr" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Slave_Mode/other" -I"F:/HDD/Modbus_free/Master_Mode/Modbus_Master_Mode" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_Slave_Mode-2f-H1DR1-2f-Src

clean-Modbus_Slave_Mode-2f-H1DR1-2f-Src:
	-$(RM) ./Modbus_Slave_Mode/H1DR1/Src/H1DR1_Slave.cyclo ./Modbus_Slave_Mode/H1DR1/Src/H1DR1_Slave.d ./Modbus_Slave_Mode/H1DR1/Src/H1DR1_Slave.o ./Modbus_Slave_Mode/H1DR1/Src/H1DR1_Slave.su ./Modbus_Slave_Mode/H1DR1/Src/Messaging_Slave.cyclo ./Modbus_Slave_Mode/H1DR1/Src/Messaging_Slave.d ./Modbus_Slave_Mode/H1DR1/Src/Messaging_Slave.o ./Modbus_Slave_Mode/H1DR1/Src/Messaging_Slave.su ./Modbus_Slave_Mode/H1DR1/Src/Modbus_Slave_Mode.cyclo ./Modbus_Slave_Mode/H1DR1/Src/Modbus_Slave_Mode.d ./Modbus_Slave_Mode/H1DR1/Src/Modbus_Slave_Mode.o ./Modbus_Slave_Mode/H1DR1/Src/Modbus_Slave_Mode.su

.PHONY: clean-Modbus_Slave_Mode-2f-H1DR1-2f-Src

