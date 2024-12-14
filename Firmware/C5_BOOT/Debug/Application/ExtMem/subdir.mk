################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/ExtMem/APSXX04L.c 

OBJS += \
./Application/ExtMem/APSXX04L.o 

C_DEPS += \
./Application/ExtMem/APSXX04L.d 


# Each subdirectory must supply rules for building sources it contributes
Application/ExtMem/%.o Application/ExtMem/%.su Application/ExtMem/%.cyclo: ../Application/ExtMem/%.c Application/ExtMem/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -DVECT_TAB_OFFSET=0x0 -DUSER_VECT_TAB_ADDRESS -c -I../Core/Inc -I../Application/ExtMem/ -I../Application/Bootloader -I../APSXX04L/ -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-ExtMem

clean-Application-2f-ExtMem:
	-$(RM) ./Application/ExtMem/APSXX04L.cyclo ./Application/ExtMem/APSXX04L.d ./Application/ExtMem/APSXX04L.o ./Application/ExtMem/APSXX04L.su

.PHONY: clean-Application-2f-ExtMem
