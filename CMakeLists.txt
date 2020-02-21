cmake_minimum_required(VERSION 3.2)  # CMake version check
project(MPAGSCipher VERSION 0.1.0)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)  # Enable c++14 standard

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(SOURCE_FILES mpags-cipher.cpp)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -pedantic -Wshadow") # include error messages
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(mpags-cipher
        mpags-cipher.cpp
        MPAGSCipher/TransformChar.cpp MPAGSCipher/TransformChar.hpp
        MPAGSCipher/ProcessCommandLine.cpp MPAGSCipher/ProcessCommandLine.hpp
        MPAGSCipher/runCaesarCipher.cpp MPAGSCipher/runCaesarCipher.hpp)

target_include_directories(mpags-cipher
        PRIVATE MPAGSCipher
        )
