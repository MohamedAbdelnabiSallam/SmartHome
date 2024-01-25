################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../EEPROM_program.c \
../Global_Interrupt_program.c \
../LCD.c \
../MTWI_program.c \
../Mymain.c \
../SPI.c \
../TIM1.c \
../USART.c 

OBJS += \
./DIO.o \
./EEPROM_program.o \
./Global_Interrupt_program.o \
./LCD.o \
./MTWI_program.o \
./Mymain.o \
./SPI.o \
./TIM1.o \
./USART.o 

C_DEPS += \
./DIO.d \
./EEPROM_program.d \
./Global_Interrupt_program.d \
./LCD.d \
./MTWI_program.d \
./Mymain.d \
./SPI.d \
./TIM1.d \
./USART.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


