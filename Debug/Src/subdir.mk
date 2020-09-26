################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Common_Data.c \
../Src/Initialize_System.c \
../Src/main.c \
../Src/stm32l4xx_hal_msp.c \
../Src/stm32l4xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32l4xx.c 

OBJS += \
./Src/Common_Data.o \
./Src/Initialize_System.o \
./Src/main.o \
./Src/stm32l4xx_hal_msp.o \
./Src/stm32l4xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32l4xx.o 

C_DEPS += \
./Src/Common_Data.d \
./Src/Initialize_System.d \
./Src/main.d \
./Src/stm32l4xx_hal_msp.d \
./Src/stm32l4xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Common_Data.o: ../Src/Common_Data.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Common_Data.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/Initialize_System.o: ../Src/Initialize_System.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Initialize_System.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32l4xx_hal_msp.o: ../Src/stm32l4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32l4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32l4xx_it.o: ../Src/stm32l4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32l4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/system_stm32l4xx.o: ../Src/system_stm32l4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L476xx -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/MotorController/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/WheelSpeedCalculation/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Drivers/Robocup/Timer/Inc" -I"/Users/dimagic/STM32CubeIDE/workspace_1.0.2/robocup/Middlewares/Robocup/RemoteControl/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/system_stm32l4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
