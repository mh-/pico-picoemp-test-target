# What CMake to start at
cmake_minimum_required(VERSION 3.12)
 
# Include the subsidiary .cmake file to get the SDK
include(pico_sdk_import.cmake)
 
# Set the name and version of the project
project(pico-picoemp-test-target VERSION 1.0.0)
 
# Link the Project to a source file (step 4.6)
add_executable(pico-picoemp-test-target source.c)
 
# Link the Project to an extra library (pico_stdlib)
target_link_libraries(pico-picoemp-test-target pico_stdlib)
 
# Initalise the SDK
pico_sdk_init()
 
# enable usb output, disable uart output
pico_enable_stdio_usb(pico-picoemp-test-target 1)
pico_enable_stdio_uart(pico-picoemp-test-target 0)
 
# Enable extra outputs (SWD?)
pico_add_extra_outputs(pico-picoemp-test-target)
