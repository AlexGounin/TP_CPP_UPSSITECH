################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Entree.cpp \
../src/TP_agenda.cpp \
../src/Tableau.cpp 

OBJS += \
./src/Entree.o \
./src/TP_agenda.o \
./src/Tableau.o 

CPP_DEPS += \
./src/Entree.d \
./src/TP_agenda.d \
./src/Tableau.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


