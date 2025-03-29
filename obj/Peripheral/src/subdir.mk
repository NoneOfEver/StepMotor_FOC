################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_adc.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_bkp.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_can.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_crc.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_dbgmcu.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_dma.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_exti.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_flash.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_gpio.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_i2c.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_iwdg.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_misc.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_opa.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_pwr.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_rcc.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_rtc.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_spi.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_tim.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_usart.c \
c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_wwdg.c 

C_DEPS += \
./Peripheral/src/ch32v20x_adc.d \
./Peripheral/src/ch32v20x_bkp.d \
./Peripheral/src/ch32v20x_can.d \
./Peripheral/src/ch32v20x_crc.d \
./Peripheral/src/ch32v20x_dbgmcu.d \
./Peripheral/src/ch32v20x_dma.d \
./Peripheral/src/ch32v20x_exti.d \
./Peripheral/src/ch32v20x_flash.d \
./Peripheral/src/ch32v20x_gpio.d \
./Peripheral/src/ch32v20x_i2c.d \
./Peripheral/src/ch32v20x_iwdg.d \
./Peripheral/src/ch32v20x_misc.d \
./Peripheral/src/ch32v20x_opa.d \
./Peripheral/src/ch32v20x_pwr.d \
./Peripheral/src/ch32v20x_rcc.d \
./Peripheral/src/ch32v20x_rtc.d \
./Peripheral/src/ch32v20x_spi.d \
./Peripheral/src/ch32v20x_tim.d \
./Peripheral/src/ch32v20x_usart.d \
./Peripheral/src/ch32v20x_wwdg.d 

OBJS += \
./Peripheral/src/ch32v20x_adc.o \
./Peripheral/src/ch32v20x_bkp.o \
./Peripheral/src/ch32v20x_can.o \
./Peripheral/src/ch32v20x_crc.o \
./Peripheral/src/ch32v20x_dbgmcu.o \
./Peripheral/src/ch32v20x_dma.o \
./Peripheral/src/ch32v20x_exti.o \
./Peripheral/src/ch32v20x_flash.o \
./Peripheral/src/ch32v20x_gpio.o \
./Peripheral/src/ch32v20x_i2c.o \
./Peripheral/src/ch32v20x_iwdg.o \
./Peripheral/src/ch32v20x_misc.o \
./Peripheral/src/ch32v20x_opa.o \
./Peripheral/src/ch32v20x_pwr.o \
./Peripheral/src/ch32v20x_rcc.o \
./Peripheral/src/ch32v20x_rtc.o \
./Peripheral/src/ch32v20x_spi.o \
./Peripheral/src/ch32v20x_tim.o \
./Peripheral/src/ch32v20x_usart.o \
./Peripheral/src/ch32v20x_wwdg.o 



# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32v20x_adc.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_adc.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_bkp.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_bkp.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_can.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_can.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_crc.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_crc.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_dbgmcu.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_dbgmcu.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_dma.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_dma.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_exti.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_exti.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_flash.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_flash.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_gpio.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_gpio.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_i2c.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_i2c.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_iwdg.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_iwdg.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_misc.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_misc.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_opa.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_opa.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_pwr.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_pwr.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_rcc.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_rcc.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_rtc.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_rtc.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_spi.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_spi.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_tim.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_tim.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_usart.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_usart.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v20x_wwdg.o: c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/src/ch32v20x_wwdg.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

