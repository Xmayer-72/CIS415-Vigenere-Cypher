#pragma once

#include <string>

class Vigenere
{
private:
    std::string expand_key(int size, std::string key){
        for (int i = 0; ; i++)
        {
            if (size == i)
                i = 0;
            if (key.size() == size)
                break;
            key.push_back(key[i]);
        }
        return key;
    }
public:
    std::string encrypt(const std::string key, const std::string plain_text){
        std::string cipher_text;
    
        auto full_key = expand_key(plain_text.size(), key);

        for (int i = 0; i < plain_text.size(); i++)
        {
            // converting in range 0-25
            char x = (plain_text[i] + full_key[i]) %26;
    
            // convert into alphabets(ASCII)
            x += 'A';
    
            cipher_text.push_back(x);
        }

        return cipher_text;
    }

    std::string dencrypt(const std::string key, const std::string cypher_text){

    }
};