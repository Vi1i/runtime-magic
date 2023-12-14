cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(rtfm-dbus VERSION 0.1.0 LANGUAGES CXX)

find_package(dbus)

configure_file(include/rtfm/core/ipc/meta/dbus_version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/rtfm/core/ipc/meta/dbus_version.h @ONLY)

add_library(rtfm-dbus SHARED
  src/core/ipc/macos_notification_center.mm
)

target_compile_features(rtfm-dbus PUBLIC cxx_std_20)
set_target_properties(rtfm-dbus PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(rtfm-dbus PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(rtfm-dbus
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

message(STATUS "APPLE_FRAMEWORKS_FOUND: ${APPLE_FRAMEWORKS_FOUND}")
message(STATUS "dbus_FOUND: ${dbus_FOUND}")


target_link_libraries(rtfm-dbus
  PRIVATE
)