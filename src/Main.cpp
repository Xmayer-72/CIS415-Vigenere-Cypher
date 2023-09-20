#include <iostream>
#include "Vigenere.h"

std::string get_text(){
    char line[50];
    std::cin.getline(line, 50);

    std::string sline;
    for (auto & c : line) 
        c = std::toupper(c);
    
    return std::string(line);
}

int main(){
    Vigenere v_cypher;

    std::cout << "Select Mode:\n[1] Encrypt\n[2] Decrypt" << std::endl;

    char mode = get_text().front();
    switch (mode)
    {
        case '1':
        {
            std::cout << "Selected [1]\nEnter Key:" << std::endl;
            auto key = get_text();

            std::cout << "Enter Phrase" << std::endl;
            auto text = get_text();

            auto cypher = v_cypher.encrypt(key, text);

            std::cout << "Encrypted Phrase using key " << key << " is:\n" << cypher << std::endl;
            break;
        }
        
        case '2':
        {
            std::cout << "Selected [2]\nEnter Key:" << std::endl;
            auto key = get_text();

            std::cout << "Enter Cypher Text" << std::endl;
            auto text = get_text();

            auto plain = v_cypher.decrypt(key, text);

            std::cout << "Decrypted Phrase using key " << key << " is:\n" << plain << std::endl;
            break;
        }

        default:
            std::cout << "selection not valid, try again" << std::endl;
            break;
    }

    return 0;
}