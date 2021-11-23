#include <iostream>
#include "IDEA.h"
#include <fstream>

#include <bitset>

void test();

std::string toBinary(const std::string &str) {
    std::string result{};
    for (auto e: str) {
        result += std::bitset<8>(e).to_string();
    }
    return result;
}

int main() {
    IDEA idea;
//    idea.debug();
//    std::string encodedText = idea.encode("12345678");
//    std::string decodedText = idea.decode(encodedText);

    uint64_t block = std::bitset<64>("0011010000000110000101010100111100010001000000010101111000110010").to_ullong();
//    idea.setKey(uint128_t("325707035209054072129538414474792315481"));
//    uint64_t block = 9573735755748060456ull;

    idea.setKey(uint128_t("5192455318486707404433266433261576"));
    block = 4295098371;

    uint64_t eBlock = idea._encode(block);
    uint64_t dBlock = idea._decode(eBlock);

    std::cout << std::dec;
    std::cout << "Source block:\t\t" << block << '\n';
    std::cout << "Encrypted block:\t" << eBlock << '\n';
    std::cout << "Decrypted block:\t" << dBlock << '\n';
    std::cout << "source == decrypted:\t" << std::boolalpha << (block == dBlock);


//    test();

    return 0;
}
