################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Robocup/CommunicationHandler/src/CommunicationRxWrapper.c \
../Middlewares/Robocup/CommunicationHandler/src/CommunicationTxWrapper.c \
../Middlewares/Robocup/CommunicationHandler/src/fifo.c 

OBJS += \
./Middlewares/Robocup/CommunicationHandler/src/CommunicationRxWrapper.o \
./Middlewares/Robocup/CommunicationHandler/src/CommunicationTxWrapper.o \
./Middlewares/Robocup/CommunicationHandler/src/fifo.o 

C_DEPS += \
./Middlewares/Robocup/CommunicationHandler/src/CommunicationRxWrapper.d \
./Middlewares/Robocup/CommunicationHandler/src/CommunicationTxWrapper.d \
./Middlewares/Robocup/CommunicationHandler/src/fifo.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Robocup/CommunicationHandler/src/CommunicationRxWrapper.o: ../Middlewares/Robocup/CommunicationHandler/src/CommunicationRxWrapper.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/UART/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/CommunicationHandler/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/RemoteControl/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedProvider/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Robocup/CommunicationHandler/src/CommunicationRxWrapper.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Robocup/CommunicationHandler/src/CommunicationTxWrapper.o: ../Middlewares/Robocup/CommunicationHandler/src/CommunicationTxWrapper.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/UART/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/CommunicationHandler/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/RemoteControl/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedProvider/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Robocup/CommunicationHandler/src/CommunicationTxWrapper.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Robocup/CommunicationHandler/src/fifo.o: ../Middlewares/Robocup/CommunicationHandler/src/fifo.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Drivers/Robocup/UART/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/CommunicationHandler/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/RemoteControl/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup3/Middlewares/Robocup/WheelSpeedProvider/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Robocup/CommunicationHandler/src/fifo.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

