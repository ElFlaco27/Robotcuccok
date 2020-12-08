################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Robocup/WheelSpeedProvider/src/WheelSpeedProvider.c 

OBJS += \
./Middlewares/Robocup/WheelSpeedProvider/src/WheelSpeedProvider.o 

C_DEPS += \
./Middlewares/Robocup/WheelSpeedProvider/src/WheelSpeedProvider.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Robocup/WheelSpeedProvider/src/WheelSpeedProvider.o: ../Middlewares/Robocup/WheelSpeedProvider/src/WheelSpeedProvider.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Middlewares/Robocup/RemoteControl/Inc -I../Drivers/Robocup/Timer/Inc -I../Middlewares/Robocup/MotorController/Inc -I../Middlewares/Robocup/WheelSpeedProvider/Inc -I../Middlewares/Robocup/WheelSpeedCalculation/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Robocup/WheelSpeedProvider/src/WheelSpeedProvider.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

