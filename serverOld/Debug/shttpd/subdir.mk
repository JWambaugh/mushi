################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../shttpd/auth.c \
../shttpd/cgi.c \
../shttpd/compat_rtems.c \
../shttpd/compat_unix.c \
../shttpd/compat_win32.c \
../shttpd/compat_wince.c \
../shttpd/io_cgi.c \
../shttpd/io_dir.c \
../shttpd/io_emb.c \
../shttpd/io_file.c \
../shttpd/io_socket.c \
../shttpd/io_ssi.c \
../shttpd/io_ssl.c \
../shttpd/log.c \
../shttpd/md5.c \
../shttpd/shttpd.c \
../shttpd/standalone.c \
../shttpd/string.c 

O_SRCS += \
../shttpd/auth.o \
../shttpd/cgi.o \
../shttpd/compat_unix.o \
../shttpd/io_cgi.o \
../shttpd/io_dir.o \
../shttpd/io_emb.o \
../shttpd/io_file.o \
../shttpd/io_socket.o \
../shttpd/io_ssi.o \
../shttpd/io_ssl.o \
../shttpd/log.o \
../shttpd/md5.o \
../shttpd/shttpd.o \
../shttpd/string.o 

OBJS += \
./shttpd/auth.o \
./shttpd/cgi.o \
./shttpd/compat_rtems.o \
./shttpd/compat_unix.o \
./shttpd/compat_win32.o \
./shttpd/compat_wince.o \
./shttpd/io_cgi.o \
./shttpd/io_dir.o \
./shttpd/io_emb.o \
./shttpd/io_file.o \
./shttpd/io_socket.o \
./shttpd/io_ssi.o \
./shttpd/io_ssl.o \
./shttpd/log.o \
./shttpd/md5.o \
./shttpd/shttpd.o \
./shttpd/standalone.o \
./shttpd/string.o 

C_DEPS += \
./shttpd/auth.d \
./shttpd/cgi.d \
./shttpd/compat_rtems.d \
./shttpd/compat_unix.d \
./shttpd/compat_win32.d \
./shttpd/compat_wince.d \
./shttpd/io_cgi.d \
./shttpd/io_dir.d \
./shttpd/io_emb.d \
./shttpd/io_file.d \
./shttpd/io_socket.d \
./shttpd/io_ssi.d \
./shttpd/io_ssl.d \
./shttpd/log.d \
./shttpd/md5.d \
./shttpd/shttpd.d \
./shttpd/standalone.d \
./shttpd/string.d 


# Each subdirectory must supply rules for building sources it contributes
shttpd/%.o: ../shttpd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


