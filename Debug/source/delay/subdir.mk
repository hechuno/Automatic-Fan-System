################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/delay/delay.c 

C_DEPS += \
./source/delay/delay.d 

OBJS += \
./source/delay/delay.o 


# Each subdirectory must supply rules for building sources it contributes
source/delay/%.o: ../source/delay/%.c source/delay/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL27Z64VLH4 -DCPU_MKL27Z64VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSERIAL_PORT_TYPE_UART=1 -I"C:\Users\Allo\Documents\MCUXpressoIDE_11.8.0_1165\workspace\TP3.3\BMP280+afficheur 7 segments (1).zip_expanded\BMP280+afficheur 7 segments\utilities" -I"C:\Users\Allo\Documents\MCUXpressoIDE_11.8.0_1165\workspace\TP3.3\BMP280+afficheur 7 segments (1).zip_expanded\BMP280+afficheur 7 segments\component\serial_manager" -I"C:\Users\Allo\Documents\MCUXpressoIDE_11.8.0_1165\workspace\TP3.3\BMP280+afficheur 7 segments (1).zip_expanded\BMP280+afficheur 7 segments\drivers" -I"C:\Users\Allo\Documents\MCUXpressoIDE_11.8.0_1165\workspace\TP3.3\BMP280+afficheur 7 segments (1).zip_expanded\BMP280+afficheur 7 segments\component\uart" -I"C:\Users\Allo\Documents\MCUXpressoIDE_11.8.0_1165\workspace\TP3.3\BMP280+afficheur 7 segments (1).zip_expanded\BMP280+afficheur 7 segments\CMSIS" -I"C:\Users\Allo\Documents\MCUXpressoIDE_11.8.0_1165\workspace\TP3.3\BMP280+afficheur 7 segments (1).zip_expanded\BMP280+afficheur 7 segments\component\lists" -I"C:\Users\Allo\Documents\MCUXpressoIDE_11.8.0_1165\workspace\TP3.3\BMP280+afficheur 7 segments (1).zip_expanded\BMP280+afficheur 7 segments\device" -I../board -I../source -I../ -I../drivers -I../device -I../CMSIS -I../component/uart -I../component/serial_manager -I../component/lists -I../utilities -I../board/boards -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source-2f-delay

clean-source-2f-delay:
	-$(RM) ./source/delay/delay.d ./source/delay/delay.o

.PHONY: clean-source-2f-delay

