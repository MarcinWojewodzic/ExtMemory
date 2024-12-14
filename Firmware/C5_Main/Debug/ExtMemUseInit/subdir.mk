################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ExtMemUseInit/ExtMemUseInit.c 

OBJS += \
./ExtMemUseInit/ExtMemUseInit.o 

C_DEPS += \
./ExtMemUseInit/ExtMemUseInit.d 


# Each subdirectory must supply rules for building sources it contributes
ExtMemUseInit/%.o ExtMemUseInit/%.su ExtMemUseInit/%.cyclo: ../ExtMemUseInit/%.c ExtMemUseInit/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -DUSER_VECT_TAB_ADDRESS=0x0800A000 -c -I../Core/Inc -I../Application/ISM330ISN -I../ExtMem/ -I../ExtMemUseInit/ -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ExtMemUseInit

clean-ExtMemUseInit:
	-$(RM) ./ExtMemUseInit/ExtMemUseInit.cyclo ./ExtMemUseInit/ExtMemUseInit.d ./ExtMemUseInit/ExtMemUseInit.o ./ExtMemUseInit/ExtMemUseInit.su

.PHONY: clean-ExtMemUseInit

