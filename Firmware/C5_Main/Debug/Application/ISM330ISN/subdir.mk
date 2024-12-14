################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/ISM330ISN/ISM330ISN.c 

OBJS += \
./Application/ISM330ISN/ISM330ISN.o 

C_DEPS += \
./Application/ISM330ISN/ISM330ISN.d 


# Each subdirectory must supply rules for building sources it contributes
Application/ISM330ISN/%.o Application/ISM330ISN/%.su Application/ISM330ISN/%.cyclo: ../Application/ISM330ISN/%.c Application/ISM330ISN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -DUSER_VECT_TAB_ADDRESS=0x0800A000 -c -I../Core/Inc -I../Application/ISM330ISN -I../ExtMem/ -I../ExtMemUseInit/ -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-ISM330ISN

clean-Application-2f-ISM330ISN:
	-$(RM) ./Application/ISM330ISN/ISM330ISN.cyclo ./Application/ISM330ISN/ISM330ISN.d ./Application/ISM330ISN/ISM330ISN.o ./Application/ISM330ISN/ISM330ISN.su

.PHONY: clean-Application-2f-ISM330ISN

