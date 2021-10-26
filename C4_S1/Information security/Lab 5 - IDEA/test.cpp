//
// Created by Pepega on 26.10.2021.
//

#include "IDEA.h"
#include <boost/random.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace boost::random;

void test() {
    IDEA subject;

    typedef independent_bits_engine<mt19937, 128, uint128_t> keyGenerator_t;
    typedef independent_bits_engine<mt11213b, 64, uint64_t> blockGenerator_t;

    keyGenerator_t keyGen;
    blockGenerator_t blockGen;

    uint128_t counter{};

    for (uint32_t i = 0; i < std::numeric_limits<uint16_t>::max(); ++i) {
        subject.setKey(keyGen());
        for (uint32_t j = 0; j < std::numeric_limits<uint16_t>::max(); ++j) {
            uint64_t sourceBlock = blockGen();
            uint64_t encodedBlock = subject._encode(sourceBlock);
            uint64_t decodedBlock = subject._decode(encodedBlock);

            if (sourceBlock != decodedBlock) {
                std::cout << std::dec;
                std::cout << "Key:\t\t" << subject.getKey() << '\n';
                std::cout << "Source block:\t\t" << sourceBlock << '\n';
                std::cout << "Encrypted block:\t" << encodedBlock << '\n';
                std::cout << "Decrypted block:\t" << decodedBlock << '\n';
                std::cout << "Number of errors:\t" << ++counter << "\n\n";
            }
        }
    }

    std::cout << "All test were complete!\n"
              << "Number of errors: " << counter << '\n';

}