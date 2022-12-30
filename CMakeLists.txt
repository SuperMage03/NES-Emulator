cmake_minimum_required(VERSION 3.23)
project(NES_Emulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH  ${PROJECT_SOURCE_DIR}/SDL2)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(NES_Emulator main.cpp BUS.cpp BUS.h CPU.cpp CPU.h MEMORY.cpp MEMORY.h)
target_link_libraries(NES_Emulator ${SDL2_LIBRARIES})

