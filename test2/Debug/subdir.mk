################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DCMOTOR_program.c \
../DIO_program.c \
../EXTI_program.c \
../GIE_program.c \
../TIMER0_programe.c \
../TIMER1_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./DCMOTOR_program.o \
./DIO_program.o \
./EXTI_program.o \
./GIE_program.o \
./TIMER0_programe.o \
./TIMER1_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./DCMOTOR_program.d \
./DIO_program.d \
./EXTI_program.d \
./GIE_program.d \
./TIMER0_programe.d \
./TIMER1_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


