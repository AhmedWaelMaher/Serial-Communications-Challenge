################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio.c \
../Dio_config.c \
../LCD.c \
../Service.c \
../Timer.c \
../Timer_config.c \
../app.c \
../comm_manager_config.c \
../communication_manager.c \
../spi.c \
../switch.c \
../uart.c 

OBJS += \
./Dio.o \
./Dio_config.o \
./LCD.o \
./Service.o \
./Timer.o \
./Timer_config.o \
./app.o \
./comm_manager_config.o \
./communication_manager.o \
./spi.o \
./switch.o \
./uart.o 

C_DEPS += \
./Dio.d \
./Dio_config.d \
./LCD.d \
./Service.d \
./Timer.d \
./Timer_config.d \
./app.d \
./comm_manager_config.d \
./communication_manager.d \
./spi.d \
./switch.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


