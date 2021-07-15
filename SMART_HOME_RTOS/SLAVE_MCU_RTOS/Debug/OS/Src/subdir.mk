################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/Src/croutine.c \
../OS/Src/heap_4.c \
../OS/Src/list.c \
../OS/Src/port.c \
../OS/Src/queue.c \
../OS/Src/tasks.c \
../OS/Src/timers.c 

OBJS += \
./OS/Src/croutine.o \
./OS/Src/heap_4.o \
./OS/Src/list.o \
./OS/Src/port.o \
./OS/Src/queue.o \
./OS/Src/tasks.o \
./OS/Src/timers.o 

C_DEPS += \
./OS/Src/croutine.d \
./OS/Src/heap_4.d \
./OS/Src/list.d \
./OS/Src/port.d \
./OS/Src/queue.d \
./OS/Src/tasks.d \
./OS/Src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
OS/Src/%.o: ../OS/Src/%.c OS/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\HAL\LCD" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\HAL\LED\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\LIB" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\DIO\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\SPI\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\MCAL\UART\inc" -I"C:\Users\EslamFayad\AMIT_L11WORK\SMART_HOME_RTOS\SLAVE_MCU_RTOS\OS\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


