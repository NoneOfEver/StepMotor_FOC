################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ADC.c \
../User/DMA.c \
../User/MT6816.c \
../User/SPI.c \
../User/ch32v20x_it.c \
../User/hw_elec.c \
../User/main.c \
../User/sin_form.c \
../User/system_ch32v20x.c 

C_DEPS += \
./User/ADC.d \
./User/DMA.d \
./User/MT6816.d \
./User/SPI.d \
./User/ch32v20x_it.d \
./User/hw_elec.d \
./User/main.d \
./User/sin_form.d \
./User/system_ch32v20x.d 

OBJS += \
./User/ADC.o \
./User/DMA.o \
./User/MT6816.o \
./User/SPI.o \
./User/ch32v20x_it.o \
./User/hw_elec.o \
./User/main.o \
./User/sin_form.o \
./User/system_ch32v20x.o 



# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/ADC/ADC_DMA/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/CH32V203EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
