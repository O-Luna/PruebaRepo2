################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Drivers/PIT/pit_driver.c 

C_DEPS += \
./source/Drivers/PIT/pit_driver.d 

OBJS += \
./source/Drivers/PIT/pit_driver.o 


# Each subdirectory must supply rules for building sources it contributes
source/Drivers/PIT/%.o: ../source/Drivers/PIT/%.c source/Drivers/PIT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Embebidosk64\workspace\Displays\board" -I"C:\Embebidosk64\workspace\Displays\source" -I"C:\Embebidosk64\workspace\Displays\utilities" -I"C:\Embebidosk64\workspace\Displays\drivers" -I"C:\Embebidosk64\workspace\Displays\device" -I"C:\Embebidosk64\workspace\Displays\component\serial_manager" -I"C:\Embebidosk64\workspace\Displays\component\lists" -I"C:\Embebidosk64\workspace\Displays\CMSIS" -I"C:\Embebidosk64\workspace\Displays\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source-2f-Drivers-2f-PIT

clean-source-2f-Drivers-2f-PIT:
	-$(RM) ./source/Drivers/PIT/pit_driver.d ./source/Drivers/PIT/pit_driver.o

.PHONY: clean-source-2f-Drivers-2f-PIT

