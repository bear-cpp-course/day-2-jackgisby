# basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# create interface library for catch
add_library(Catch INTERFACE)
target_include_directories(Catch
        INTERFACE ${CMAKE_CURRENT_LIST_DIR}
        )

# catch test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch)

add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar Catch MPAGSCipher)
add_test(NAME test-transformChar COMMAND testTransformChar)