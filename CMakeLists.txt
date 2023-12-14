cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(runtime-magic)

option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." NO)
option(CMAKE_BUILD_TYPE "Default build type" "Debug")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/colored_output.cmake)
include(cmake/custom_compile_options.cmake)
include(cmake/apple_framework.cmake)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

if (${FORCE_COLORED_OUTPUT})
  colored_output()
endif ()

message(STATUS "CMAKE_OBJCXX_COMPILER: ${CMAKE_OBJCXX_COMPILER}")

custom_compile_options()

add_subdirectory(modules)
