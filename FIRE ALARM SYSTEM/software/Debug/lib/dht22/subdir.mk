################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/dht22/dht22.c 

OBJS += \
./lib/dht22/dht22.o 

C_DEPS += \
./lib/dht22/dht22.d 


# Each subdirectory must supply rules for building sources it contributes
lib/dht22/%.o lib/dht22/%.su lib/dht22/%.cyclo: ../lib/dht22/%.c lib/dht22/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/delay" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/dht22" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/lcd16x2" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/modulesim" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/output" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/warning" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/flame" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.14.1/fire_alarm/lib/mq-2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-dht22

clean-lib-2f-dht22:
	-$(RM) ./lib/dht22/dht22.cyclo ./lib/dht22/dht22.d ./lib/dht22/dht22.o ./lib/dht22/dht22.su

.PHONY: clean-lib-2f-dht22

