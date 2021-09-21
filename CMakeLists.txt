cmake_minimum_required(VERSION 3.5)

project(testable-singleton LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(testable-singleton
        pincode.cpp pincode.h
        settingssingleton.cpp settingssingleton.h
        main.cpp)
