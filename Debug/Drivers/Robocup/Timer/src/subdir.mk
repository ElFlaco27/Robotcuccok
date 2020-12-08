################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Robocup/Timer/src/Timer_InputCapture.c \
../Drivers/Robocup/Timer/src/Timer_PWM.c \
../Drivers/Robocup/Timer/src/Timer_encoder.c 

OBJS += \
./Drivers/Robocup/Timer/src/Timer_InputCapture.o \
./Drivers/Robocup/Timer/src/Timer_PWM.o \
./Drivers/Robocup/Timer/src/Timer_encoder.o 

C_DEPS += \
./Drivers/Robocup/Timer/src/Timer_InputCapture.d \
./Drivers/Robocup/Timer/src/Timer_PWM.d \
./Drivers/Robocup/Timer/src/Timer_encoder.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Robocup/Timer/src/Timer_InputCapture.o: ../Drivers/Robocup/Timer/src/Timer_InputCapture.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedProvider/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/RemoteControl/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/Timer/Inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Robocup/Timer/src/Timer_InputCapture.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/Robocup/Timer/src/Timer_PWM.o: ../Drivers/Robocup/Timer/src/Timer_PWM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedProvider/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/RemoteControl/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/Timer/Inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Robocup/Timer/src/Timer_PWM.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/Robocup/Timer/src/Timer_encoder.o: ../Drivers/Robocup/Timer/src/Timer_encoder.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedProvider/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/RemoteControl/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/Timer/Inc" -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Robocup/Timer/src/Timer_encoder.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

