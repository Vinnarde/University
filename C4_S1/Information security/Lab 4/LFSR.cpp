//
// Created by Pepega on 01.10.2021.
//

#include "LFSR.h"
#include <stdexcept>
#include <iostream>

bool LFSR::step() {
    bool feedback = m_seed & 0x1;

    m_seed >>= 1;
    if (feedback)
        m_seed ^= m_tap_mask;

    return feedback;
}

LFSR::LFSR(std::size_t bitSize, const std::string &seed, const std::vector<int> &taps) {
    m_size = bitSize;

    if (bitSize < seed.size())
        throw std::invalid_argument("LFSR constructor: bitSize < seed.size().");

    m_seed = std::bitset<64>(seed).to_ullong();
    if (m_seed == 0)
        throw std::invalid_argument("LFSR constructor: seed == 0.");

    std::bitset<64> tempMask(0ull);

    for (auto e: taps)
        tempMask.flip(e);

    m_tap_mask = tempMask.to_ullong();

    // debug
    //std::clog << std::bitset<64>(m_tap_mask).to_string() << '\n';
}

uint64_t LFSR::period() const {
    uint64_t start = m_seed;
    uint64_t period = 0;

    do {
        bool bit = start & 1;
        start >>= 1;
        if (bit)
            start ^= m_tap_mask;

        ++period;
    } while (start != m_seed);

    return period;
}

