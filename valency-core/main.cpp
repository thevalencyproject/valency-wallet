#include <iostream>
#include "cryptography/aes-encryption/AES-Encryption.h"

int main() {
    AESEncryption aes = AESEncryption(128);
    std::vector<unsigned char> key;
    key.push_back('B');
    key.push_back('A');
    key.push_back('N');
    key.push_back('A');
    key.push_back('N');
    key.push_back('A');
    key.push_back('N');
    key.push_back('A');
    key.push_back('N');
    key.push_back('A');
    key.push_back('N');
    key.push_back('A');
    key.push_back('N');
    key.push_back('A');
    key.push_back('N');
    key.push_back('A');
    std::vector<unsigned char> data;
    data.push_back('B');
    data.push_back('A');
    data.push_back('N');
    data.push_back('A');
    data.push_back('N');
    data.push_back('A');
    data.push_back('N');
    data.push_back('A');
    data.push_back('N');
    data.push_back('A');
    data.push_back('N');
    data.push_back('A');
    data.push_back('N');
    data.push_back('A');
    data.push_back('N');
    data.push_back('A');
    std::vector<unsigned char> output;
    output = aes.encrypt(&key, &data);
    
    // Output the output 
    for(int i = 0; i < output.size(); i++) {
        std::cout << std::to_string(output.at(i));
    }

    aes.~AESEncryption();

    return 0;
}