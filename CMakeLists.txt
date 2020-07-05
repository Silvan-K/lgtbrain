cmake_minimum_required(VERSION 3.17)

# Set the project name
project(lgtdisplay)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

# Require user to supply subarussm path
set(SUBARUSSM_INSTALL_DIR "" CACHE FILEPATH "Path to subarussm")
set(SUBARUSSM_INCLUDE_DIR ${SUBARUSSM_INSTALL_DIR}/include/subarussm/)
set(SUBARUSSM_LIB_DIR ${SUBARUSSM_INSTALL_DIR}/lib/subarussm/)

if(NOT EXISTS ${SUBARUSSM_INCLUDE_DIR}/ECUPort.hh)
  message(SEND_ERROR "Can't find ECUPort.hh in ${SUBARUSSM_INCLUDE_DIR}")
endif()

include_directories(${SUBARUSSM_INCLUDE_DIR})
link_directories(${SUBARUSSM_LIB_DIR})

# Build output paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# Add src subdirectory
add_subdirectory(src)
