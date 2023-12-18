cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(rtfm-core VERSION 0.1.0 LANGUAGES CXX)

configure_file(include/rtfm/core/meta/version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/rtfm/core/meta/version.h @ONLY)

add_library(rtfm-core SHARED
  src/core.cc
  src/parser/sem_ver_parser.cc
  src/info/sem_ver.cc
)

target_compile_features(rtfm-core PUBLIC cxx_std_20)
set_target_properties(rtfm-core PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(rtfm-core
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

message(STATUS "APPLE_FRAMEWORKS_FOUND: ${APPLE_FRAMEWORKS_FOUND}")
message(STATUS "dbus_FOUND: ${dbus_FOUND}")

target_link_libraries(rtfm-core
  PRIVATE
)