################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../calculator.c \
../dcMotor.c \
../externalInterrupts.c \
../icu.c \
../keypad.c \
../lcd.c \
../led.c \
../main.c \
../pushButton.c \
../pwm.c \
../uart.c 

OBJS += \
./adc.o \
./calculator.o \
./dcMotor.o \
./externalInterrupts.o \
./icu.o \
./keypad.o \
./lcd.o \
./led.o \
./main.o \
./pushButton.o \
./pwm.o \
./uart.o 

C_DEPS += \
./adc.d \
./calculator.d \
./dcMotor.d \
./externalInterrupts.d \
./icu.d \
./keypad.d \
./lcd.d \
./led.d \
./main.d \
./pushButton.d \
./pwm.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


