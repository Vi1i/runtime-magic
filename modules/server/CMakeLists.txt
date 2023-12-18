cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(rtfm-server VERSION 0.0.1 LANGUAGES CXX)

configure_file(include/rtfm/server/meta/version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/rtfm/server/meta/version.h @ONLY)

add_executable(rtfm-server
  src/server.cpp
)

target_compile_features(rtfm-server PUBLIC cxx_std_20)
set_target_properties(rtfm-server PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(rtfm-server
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

target_link_libraries(rtfm-server
  PRIVATE
    rtfm-core
)