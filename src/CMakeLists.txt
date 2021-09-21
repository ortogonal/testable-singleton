cmake_minimum_required(VERSION 3.5)

project(testable-singleton LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(testable-singleton
        isettings.h
        pincode.cpp pincode.h
        settingsimpl.cpp settingsimpl.h
        settingssingleton.cpp settingssingleton.h
        main.cpp)
