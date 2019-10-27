cmake_minimum_required(VERSION 3.2)
project(mpags_day_2_stupoole)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(. MPAGSCipher)

add_executable(mpags-cipher
        mpags-cipher.cpp
        MPAGSCipher/transformChar.h
        MPAGSCipher/transformChar.cpp
        MPAGSCipher/processCommandLine.h
        MPAGSCipher/processCommandLine.cpp)

target_compile_features(mpags-cipher PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)
