//
// Created by Pepega on 25.10.2021.
//

#ifndef LAB_5___IDEA_IDEA_H
#define LAB_5___IDEA_IDEA_H

#include <boost/multiprecision/cpp_int.hpp>
#include <array>

using namespace boost::multiprecision;

class IDEA {

private:
    uint128_t mainKey;
    uint32_t keys[52];

    void makeKeys();

    std::string readBlock(FILE *input);

    static uint16_t inverseKey(uint16_t key) ;
    static uint16_t extendedGcd(uint32_t a, uint32_t b);

public:
    void debug();
    std::string encode(const std::string& text);
    std::string decode(const std::string& text);

    void setKey(uint128_t key);
    uint128_t getKey() const;
    uint64_t _encode(uint64_t block);
    uint64_t _decode(uint64_t block);

};


#endif //LAB_5___IDEA_IDEA_H
