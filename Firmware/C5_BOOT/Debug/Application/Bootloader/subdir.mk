################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Bootloader/Bootloader.c 

OBJS += \
./Application/Bootloader/Bootloader.o 

C_DEPS += \
./Application/Bootloader/Bootloader.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Bootloader/%.o Application/Bootloader/%.su Application/Bootloader/%.cyclo: ../Application/Bootloader/%.c Application/Bootloader/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -DVECT_TAB_OFFSET=0x0 -DUSER_VECT_TAB_ADDRESS -c -I../Core/Inc -I../Application/ExtMem/ -I../Application/Bootloader -I../APSXX04L/ -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Bootloader

clean-Application-2f-Bootloader:
	-$(RM) ./Application/Bootloader/Bootloader.cyclo ./Application/Bootloader/Bootloader.d ./Application/Bootloader/Bootloader.o ./Application/Bootloader/Bootloader.su

.PHONY: clean-Application-2f-Bootloader

