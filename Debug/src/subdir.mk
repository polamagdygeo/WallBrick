################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ball.cpp \
../src/Bar.cpp \
../src/Barrier.cpp \
../src/Brick.cpp \
../src/Circle.cpp \
../src/Controller.cpp \
../src/Frame.cpp \
../src/FrameSide.cpp \
../src/Object.cpp \
../src/Session.cpp \
../src/View.cpp \
../src/main.cpp 

OBJS += \
./src/Ball.o \
./src/Bar.o \
./src/Barrier.o \
./src/Brick.o \
./src/Circle.o \
./src/Controller.o \
./src/Frame.o \
./src/FrameSide.o \
./src/Object.o \
./src/Session.o \
./src/View.o \
./src/main.o 

CPP_DEPS += \
./src/Ball.d \
./src/Bar.d \
./src/Barrier.d \
./src/Brick.d \
./src/Circle.d \
./src/Controller.d \
./src/Frame.d \
./src/FrameSide.d \
./src/Object.d \
./src/Session.d \
./src/View.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/pola/SDL2-2.0.10/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


