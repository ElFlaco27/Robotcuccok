################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Middlewares/Robocup/WheelSpeedProvider/src/subdir.mk
-include Middlewares/Robocup/WheelSpeedCalculation/src/subdir.mk
-include Middlewares/Robocup/RemoteControl/src/subdir.mk
-include Middlewares/Robocup/MotorController/src/subdir.mk
-include Middlewares/Robocup/CommunicationHandler/src/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Drivers/Robocup/UART/src/subdir.mk
-include Drivers/Robocup/Timer/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
robocup3.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
robocup3.list \


# All Target
all: robocup3.elf secondary-outputs

# Tool invocations
robocup3.elf: $(OBJS) $(USER_OBJS) /Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/STM32L476RGTX_FLASH.ld
	arm-none-eabi-gcc -o "robocup3.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="robocup3.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

robocup3.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "robocup3.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
