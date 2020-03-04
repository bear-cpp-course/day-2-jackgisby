# create interface library for catch
add_library(Catch INTERFACE)
target_include_directories(Catch
        INTERFACE ${CMAKE_CURRENT_LIST_DIR}
        )

# catch test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch)

# function tests
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar Catch MPAGSCipher)
add_test(NAME test-transformChar COMMAND testTransformChar)

add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine Catch MPAGSCipher)
add_test(NAME test-processCommandLine COMMAND testProcessCommandLine)

add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher Catch MPAGSCipher)
add_test(NAME test-caesarCipher COMMAND testCaesarCipher)