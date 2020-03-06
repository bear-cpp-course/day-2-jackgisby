cmake_minimum_required(VERSION 3.2)  # CMake version check
project(MPAGSCipher VERSION 0.3.0)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)  # Enable c++14 standard

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(SOURCE_FILES mpags-cipher.cpp)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -pedantic -Wshadow") # include error messages
set(CMAKE_CXX_EXTENSIONS OFF)

#documentation
add_subdirectory(Documentation)

# testing
enable_testing()
add_subdirectory(Testing)

# Add executable target with source files listed in SOURCE_FILES variable
add_subdirectory(MPAGSCipher)
add_executable(mpags-cipher mpags-cipher.cpp)
target_link_libraries(mpags-cipher PRIVATE MPAGSCipher)
