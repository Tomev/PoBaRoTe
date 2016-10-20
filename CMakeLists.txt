cmake_minimum_required(VERSION 3.6)
project(PoBaRoTe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static -static-libgcc -static-libstdc++ -o")

set(SOURCE_FILES main.cpp)

include_directories(PoBaRoTe)

add_subdirectory(PoBaRoTe)
add_subdirectory(PoBaRoTe_Tests)

add_executable(PoBaRoTe ${SOURCE_FILES})