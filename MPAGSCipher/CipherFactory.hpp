#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

// Standard Library
#include <memory>

// Project files
#include "Cipher.hpp"
#include "CipherType.hpp"

std::unique_ptr<Cipher> cipherFactory(CipherType& type, std::string& key);

#endif //MPAGSCIPHER_CIPHERFACTORY_HPP
