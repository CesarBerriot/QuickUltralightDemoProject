cmake_minimum_required(VERSION 3.29)
project(QuickUltralightDemoProject C)

set(CMAKE_C_STANDARD 11)

# QuickUltralight integration
file(DOWNLOAD https://raw.githubusercontent.com/CesarBerriot/QuickUltralight/refs/heads/master/QuickUltralight.cmake ${CMAKE_BINARY_DIR}/QuickUltralight/QuickUltralight.cmake)
include(${CMAKE_BINARY_DIR}/QuickUltralight/QuickUltralight.cmake)

# target
add_executable(QuickUltralightDemoProject main.c)
target_compile_options(QuickUltralightDemoProject PRIVATE -ansi -pedantic-errors -std=c11 -Werror -Wall -Wextra -Wno-unused-parameter)
QuickUltralightSetupTarget(QuickUltralightDemoProject)
