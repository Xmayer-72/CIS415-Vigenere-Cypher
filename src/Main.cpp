#include <iostream>
#include "Vigenere.h"

std::string get_text(){
    char line[25];
    std::cin.getline(line, 25);

    for (auto & c : line) c = toupper(c);
    
    return std::string(line);
}

int main(){
    Vigenere v_cypher;

    std::cout << "Select Mode:\n[1] Encrypt\n[2] Decrypt\n[3] Run Tests" << std::endl;

    char mode = get_text().front();

    switch (mode)
    {
        case '1':
            {
            std::cout << "select #1\nEnter Key:" << std::endl;
            auto key = get_text();

            std::cout << "Enter Phrase" << std::endl;
            auto text = get_text();

            auto cypher = v_cypher.encrypt(key, text);

            std::cout << "Encrypted Phrase using key " << key << " is:\n" << cypher << std::endl;
            break;
            }
        case '2':
            {
            std::cout << "select #2" << std::endl;
            break;
            }
        case '3':
            {
            std::cout << "select #3" << std::endl;
            //auto cypherText = v_cypher.encrypt("test", "This is a test of the encryption system");
            break;
            }
        default:
            std::cout << "selection not valid, try again" << std::endl;
            break;
    }

    return 0;
}