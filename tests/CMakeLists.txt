cmake_minimum_required(VERSION 3.5)
project(basic_test)

# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
include_directories(../src)

# Add test cpp file
add_executable(testPinCode
    ../src/pincode.cpp ../src/pincode.h
    ../src/settingssingleton.cpp ../src/settingssingleton.h
    testpincode.cpp
)

# Link test executable against gtest & gtest_main
target_link_libraries(testPinCode gtest gtest_main pthread)

add_test(
    NAME testPinCode
    COMMAND testPinCode
)
