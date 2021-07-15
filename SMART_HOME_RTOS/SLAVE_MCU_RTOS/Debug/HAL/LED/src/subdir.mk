################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LED/src/Led.c 

OBJS += \
./HAL/LED/src/Led.o 

C_DEPS += \
./HAL/LED/src/Led.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LED/src/%.o: ../HAL/LED/src/%.c HAL/LED/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\HAL\LCD" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\HAL\LED\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\LIB" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\DIO\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\SPI\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\UART\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\OS\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


