cmake_minimum_required(VERSION 3.6)
project(PoBaRoTe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp pokemon.cpp pokemon.h)
add_executable(PoBaRoTe ${SOURCE_FILES} pokemon.cpp pokemon.h)