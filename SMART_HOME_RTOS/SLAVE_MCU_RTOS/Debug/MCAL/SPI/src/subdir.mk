################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SPI/src/SPI.c 

OBJS += \
./MCAL/SPI/src/SPI.o 

C_DEPS += \
./MCAL/SPI/src/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SPI/src/%.o: ../MCAL/SPI/src/%.c MCAL/SPI/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\HAL\LCD" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\HAL\LED\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\LIB" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\DIO\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\SPI\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\UART\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\OS\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


