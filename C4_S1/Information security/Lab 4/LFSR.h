//
// Created by Pepega on 01.10.2021.
//

#ifndef LAB_4_LFSR_H
#define LAB_4_LFSR_H

#include <vector>
#include <string>
#include <cstddef>
#include <bitset>


class LFSR {
public:
    LFSR(std::size_t bitSize, const std::string &seed, const std::vector<int> &taps);

    bool step();

    uint64_t period() const;

private:
    std::size_t m_size;
    uint_fast64_t m_seed;
    uint_fast64_t m_tap_mask;
};


#endif //LAB_4_LFSR_H
