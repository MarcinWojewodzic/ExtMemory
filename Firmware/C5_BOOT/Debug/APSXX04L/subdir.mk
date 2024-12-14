################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APSXX04L/APSXX04L.c 

OBJS += \
./APSXX04L/APSXX04L.o 

C_DEPS += \
./APSXX04L/APSXX04L.d 


# Each subdirectory must supply rules for building sources it contributes
APSXX04L/%.o APSXX04L/%.su APSXX04L/%.cyclo: ../APSXX04L/%.c APSXX04L/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Application/Bootloader -I../APSXX04L/ -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-APSXX04L

clean-APSXX04L:
	-$(RM) ./APSXX04L/APSXX04L.cyclo ./APSXX04L/APSXX04L.d ./APSXX04L/APSXX04L.o ./APSXX04L/APSXX04L.su

.PHONY: clean-APSXX04L

