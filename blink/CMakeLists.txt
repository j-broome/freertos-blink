cmake_minimum_required(VERSION 3.13)

# Set project data
set(PROJECT_NAME "FREERTOS_PICO")

# Set app name(s) and version(s)
set(APP_NAME "BLINK")
set(APP_VERSION_NUMBER "0.0.0")

# Set env variable 'PICO_SDK_PATH' to the local Pico SDK
# Comment out the set() if you have a global copy of the
# SDK set and $PICO_SDK_PATH defined in your $PATH
set(ENV{PICO_SDK_PATH} "C:/pico/freertos-blink/pico-sdk")

# Pull in SDK (must be before project)
include(C:/pico/freertos-blink/pico-sdk/external/pico_sdk_import.cmake)

# Set env variable 'FREERTOS_KERNEL_PATH' to the local FreeRTOS Directory
# Comment out the set() if you have a global copy of the
# RTOS set and $FREERTOS_KERNEL_PATH defined in your $PATH
set(ENV{FREERTOS_KERNEL_PATH} "C:/pico/freertos-blink/FreeRTOS-Kernel")

# Pull in FreeRTOS
include(C:/pico/freertos-blink/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(blink main.c)

target_include_directories(blink PRIVATE ${CMAKE_CURRENT_LIST_DIR})
 
# pull in common dependencies
target_link_libraries(blink pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)

# create map/bin/hex/uf2 file
pico_add_extra_outputs(blink)

