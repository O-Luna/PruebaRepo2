################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Drivers/GPIO_Display/display_driver.c 

C_DEPS += \
./source/Drivers/GPIO_Display/display_driver.d 

OBJS += \
./source/Drivers/GPIO_Display/display_driver.o 


# Each subdirectory must supply rules for building sources it contributes
source/Drivers/GPIO_Display/%.o: ../source/Drivers/GPIO_Display/%.c source/Drivers/GPIO_Display/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Embebidosk64\workspace\Test2RepoGit\board" -I"C:\Embebidosk64\workspace\Test2RepoGit\source" -I"C:\Embebidosk64\workspace\Test2RepoGit\utilities" -I"C:\Embebidosk64\workspace\Test2RepoGit\drivers" -I"C:\Embebidosk64\workspace\Test2RepoGit\device" -I"C:\Embebidosk64\workspace\Test2RepoGit\component\serial_manager" -I"C:\Embebidosk64\workspace\Test2RepoGit\component\lists" -I"C:\Embebidosk64\workspace\Test2RepoGit\CMSIS" -I"C:\Embebidosk64\workspace\Test2RepoGit\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source-2f-Drivers-2f-GPIO_Display

clean-source-2f-Drivers-2f-GPIO_Display:
	-$(RM) ./source/Drivers/GPIO_Display/display_driver.d ./source/Drivers/GPIO_Display/display_driver.o

.PHONY: clean-source-2f-Drivers-2f-GPIO_Display

