################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Robocup/Timer/src/Timer_InputCapture.c \
../Drivers/Robocup/Timer/src/Timer_PWM.c 

OBJS += \
./Drivers/Robocup/Timer/src/Timer_InputCapture.o \
./Drivers/Robocup/Timer/src/Timer_PWM.o 

C_DEPS += \
./Drivers/Robocup/Timer/src/Timer_InputCapture.d \
./Drivers/Robocup/Timer/src/Timer_PWM.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Robocup/Timer/src/Timer_InputCapture.o: ../Drivers/Robocup/Timer/src/Timer_InputCapture.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Robocup/Timer/src/Timer_InputCapture.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/Robocup/Timer/src/Timer_PWM.o: ../Drivers/Robocup/Timer/src/Timer_PWM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Robocup/Timer/src/Timer_PWM.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

