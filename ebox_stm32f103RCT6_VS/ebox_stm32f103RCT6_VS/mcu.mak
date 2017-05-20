#This file is generated by VisualGDB.
#It contains GCC settings automatically derived from the board support package (BSP).
#DO NOT EDIT MANUALLY. THE FILE WILL BE OVERWRITTEN. 
#Use VisualGDB Project Properties dialog or modify Makefile or per-configuration .mak files instead.

#VisualGDB provides BSP_ROOT and TOOLCHAIN_ROOT via environment when running Make. The line below will only be active if GNU Make is started manually.
BSP_ROOT ?= C:/SysGCC/arm-eabi
EFP_BASE ?= $(LOCALAPPDATA)/VisualGDB/EmbeddedEFPs
TESTFW_BASE ?= $(LOCALAPPDATA)/VisualGDB/TestFrameworks
TOOLCHAIN_ROOT ?= C:/SysGCC/arm-eabi
#Embedded toolchain
CC := $(TOOLCHAIN_ROOT)/bin/arm-eabi-gcc.exe
CXX := $(TOOLCHAIN_ROOT)/bin/arm-eabi-g++.exe
LD := $(CXX)
AR := $(TOOLCHAIN_ROOT)/bin/arm-eabi-ar.exe
OBJCOPY := $(TOOLCHAIN_ROOT)/bin/arm-eabi-objcopy.exe

#Additional flags
PREPROCESSOR_MACROS += __UVISION_VERSION="514" STM32F10X_MD
INCLUDE_DIRS += mcu/stm32f10x/libraries/CMSIS/CM3/CoreSupport mcu/stm32f10x/libraries/STM32F10x_StdPeriph_Driver/inc mcu/stm32f10x/libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x mcu/stm32f10x/ebox mcu/stm32f10x/ebox/core mcu/stm32f10x/ebox/Peripherals common/util common/edriver common/network common/fat common/edriver/WiFi user common/cJSON common/edriver/SFUD/sfud/inc common/edriver/SFUD/ebox common/bigiot common/usb_device_stack/USBDevice common/usb_device_stack/USBHID common/gui common/FreeModbus/modbus/ascii common/FreeModbus/modbus/include common/FreeModbus/modbus/rtu common/FreeModbus/modbus/tcp common/FreeModbus/port Project/stm32f10x/mdk/RTE C:/Keil_v5/ARM/PACK/Keil/STM32F1xx_DFP/1.0.5/Device/Include C:/Keil_v5/ARM/CMSIS/Include os/FreeRTOS/Source/include os/FreeRTOS/Source/portable/RVDS/ARM_CM3 common/edriver/MPU9250/eMPL common/edriver/MPU9250
LIBRARY_DIRS += 
LIBRARY_NAMES += 
ADDITIONAL_LINKER_INPUTS += 
MACOS_FRAMEWORKS += 
LINUX_PACKAGES += 

CFLAGS += 
CXXFLAGS += 
ASFLAGS += 
LDFLAGS += 
COMMONFLAGS += 
LINKER_SCRIPT := 

