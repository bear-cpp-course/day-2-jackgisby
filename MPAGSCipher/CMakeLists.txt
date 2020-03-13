add_library(MPAGSCipher STATIC
        TransformChar.cpp TransformChar.hpp
        ProcessCommandLine.cpp ProcessCommandLine.hpp
        CaesarCipher.cpp CaesarCipher.hpp CipherMode.hpp
        PlayfairCipher.cpp PlayfairCipher.hpp
        VigenereCipher.cpp VigenereCipher.hpp Cipher.hpp CipherType.hpp CipherFactory.cpp CipherFactory.hpp)

target_include_directories(MPAGSCipher
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}
        )

target_compile_features(MPAGSCipher
        PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization
        )