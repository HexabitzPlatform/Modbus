################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../M_Mod/mb_master_API.c 

OBJS += \
./M_Mod/mb_master_API.o 

C_DEPS += \
./M_Mod/mb_master_API.d 


# Each subdirectory must supply rules for building sources it contributes
M_Mod/%.o M_Mod/%.su M_Mod/%.cyclo: ../M_Mod/%.c M_Mod/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G0B1xx -c -I../Core/Inc -I"C:/Users/MAHMOOD_REDA/STM32CubeIDE/workspace_1.17.0/Master_Test/M_Mod/Inc" -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-M_Mod

clean-M_Mod:
	-$(RM) ./M_Mod/mb_master_API.cyclo ./M_Mod/mb_master_API.d ./M_Mod/mb_master_API.o ./M_Mod/mb_master_API.su

.PHONY: clean-M_Mod

