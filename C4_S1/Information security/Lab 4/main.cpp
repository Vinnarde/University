#include <iostream>
#include "LFSR.h"
#include <fstream>
#include <string>

std::string convertToBinary(const std::string &source) {
    std::string result;
    result.reserve(source.size() * 8);
    for (auto item: source) {
        result += std::bitset<8>(item).to_string();
    }
    return result;
}

std::string convertToASCII(const std::string &source) {
    std::string result;
    result.reserve(source.size() / 8);
    for (std::size_t i = 0; i < source.size(); i += 8) {
        result += static_cast<char> (std::bitset<8>(source.substr(i, 8)).to_ulong());
    }
    return result;
}

std::string binaryStringXOR(const std::string &first, const std::string &second) {
    std::string result;
    if (first.size() != second.size())
        throw std::invalid_argument("binaryStringXOR: string lengths are different!");

    for (std::size_t i = 0; i < first.size(); ++i)
        result += (first[i] == second[i]) ? '0' : '1';

    return result;
}

int main() {
//    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::ifstream inputText("../input.txt");
    std::string sourceText;
    // read full text of input.txt file
    std::getline(inputText, sourceText, '\0');
    std::string binaryText = convertToBinary(sourceText);

    LFSR first_stage(7, "1000001", std::vector<int>{6, 5});
    LFSR second_stage(19, "1000110", std::vector<int>{18, 17, 16, 13});

    std::string key;
    key.reserve(binaryText.size());
    for (std::size_t i = 0; i < binaryText.size(); ++i) {
        if (first_stage.step()) {
        } else {
            second_stage.step();
        }
        key.push_back(second_stage.step() ? '1' : '0');

    }
    std::string cipher = binaryStringXOR(binaryText, key);

    std::string binaryDecryptedText = binaryStringXOR(cipher, key);
    std::string decryptedText = convertToASCII(binaryDecryptedText);

    std::ofstream outputText("../output.txt");
    std::ofstream outputKey("../key.txt");

//    std::cout << "Encrypted Text " << convertToASCII(cipher) << '\n';

    outputText << cipher << '\n';
    outputKey << key << '\n';

    std::cout << "Original text: " << sourceText << '\n';
    std::cout << "Original text(binary): " << binaryText << '\n';


    std::cout << "Key: " << key << '\n';
    std::cout << "Cipher text: " << cipher << '\n';
    std::cout << "Decrypted text: " << decryptedText << '\n';

//    std::cout << first_stage.period() << '\n';
//    std::cout << second_stage.period() << '\n';


    return 0;
}
