//
// Created by Pepega on 25.10.2021.
//

#include "IDEA.h"
#include <bitset>
#include <utility>

//std::string toBinary(uint128_t val) {
//    std::string result;
//    while (val > 0) {
//        result += (val & 1) ? '1' : '0';
//        val >>= 1;
//    }
//    return result;
//}
//
//std::string toBinary(const std::string &str) {
//    std::string result{};
//    for (auto e: str) {
//        result += std::bitset<8>(e).to_string();
//    }
//    return result;
//}

void IDEA::makeKeys() {
//    mainKey = std::numeric_limits<uint128_t>::max();
    uint128_t tempKey = mainKey;
    uint128_t temp = tempKey;
    for (int i = 0; i < 52; ++i) {
        if (i != 0 && i % 8 == 0) {
            // cycle shift 25 bits to left
            tempKey = (tempKey << 25 | tempKey >> (128 - 25));
            std::cout << "Temp key = " << tempKey << '\n';
            temp = tempKey;
        }
        // first 16 bits of temp(128-bit)
        keys[i] = ((temp >> (128 - 16)) & 0xffff).convert_to<uint16_t>();
        temp <<= 16; // shift to next key
    }

}

void IDEA::debug() {
    makeKeys();

    for (int i = 0; i < 52; ++i) {
        std::cout << "k" << i / 6 + 1 << i % 6 + 1 << " = " << keys[i] << '\n';
    }
}


std::string IDEA::encode(const std::string &text) {

    std::string temp{}; //= toBinary(text);
    uint64_t block = _encode(std::bitset<64>(temp).to_ullong());
    std::string result{};

    for (int i = 7; i >= 0; --i) {
        result += static_cast<char>((block >> (8 * i)) & 0xff);
    }

    return result;
//    return std::bitset<64>(_encode(std::stoull(text))).to_string();
}

std::string IDEA::decode(const std::string &text) {
    std::string temp{};// = toBinary(text);
    uint64_t block = _decode(std::bitset<64>(temp).to_ullong());
    std::string result{};

    for (int i = 7; i >= 0; --i) {
        result += static_cast<char>((block >> (8 * i)) & 8);
    }

    return result;
}

uint64_t IDEA::_encode(uint64_t block) {
    uint64_t result{};

    std::clog << "Key: " << mainKey << '\n';
    std::clog << "Source block: " << block;
    uint32_t parts[4];
    for (int i = 3; i >= 0; --i) {
        parts[i] = block & 0xffff;
        block >>= 16;
    }
<<<<<<< Updated upstream
    std::cout << "\nEncode keys: \n";
=======

    std::clog << "\nEncode keys: \n";
>>>>>>> Stashed changes

    for (int round = 0; round < 8; ++round) {

        // 0x10001 = 2^16 + 1, 0x10000 = 2^16

        uint16_t k[6];
        k[0] = keys[round * 6];
        k[1] = keys[round * 6 + 1];
        k[2] = keys[round * 6 + 2];
        k[3] = keys[round * 6 + 3];
        k[4] = keys[round * 6 + 4];
        k[5] = keys[round * 6 + 5];

        for (auto item: k)
            std::cout << std::setw(4) << std::setfill('0')  << std::hex << item << ' ';

        // steps 1 - 4
        parts[0] = (parts[0] * keys[round * 6]) % 0x10001;
        parts[1] = (parts[1] + keys[round * 6 + 1]) % 0x10000;
        parts[2] = (parts[2] + keys[round * 6 + 2]) % 0x10000;
        parts[3] = (parts[3] * keys[round * 6 + 3]) % 0x10001;

        // steps 5 - 6
        uint32_t temp1 = parts[0] ^ parts[2];
        uint32_t temp2 = parts[1] ^ parts[3];

        // steps 7 - 8
        temp1 = (temp1 * keys[round * 6 + 4]) % 0x10001;
        temp2 = (temp2 + temp1) % 0x10000;

        // step 9 - 10
        temp2 = (temp2 * keys[round * 6 + 5]) % 0x10001;
        temp1 = (temp1 + temp2) % 0x10000;

        // steps 11 - 14
        parts[0] ^= temp2;
        parts[2] ^= temp2;
        parts[1] ^= temp1;
        parts[3] ^= temp1;

        if (round != 7) {
            std::swap(parts[1], parts[2]);
        }

        std::cout << "\t|\t";
        for (auto item: parts)
            std::cout << std::hex << std::setw(4) << std::setfill('0') << item << ' ';
        std::cout << '\n';


    }
    parts[0] = (parts[0] * keys[48]) % 0x10001;
    parts[1] = (parts[1] + keys[48 + 1]) % 0x10000;
    parts[2] = (parts[2] + keys[48 + 2]) % 0x10000;
    parts[3] = (parts[3] * keys[48 + 3]) % 0x10001;


    for (int i = 0; i < 4; ++i) {
        std::cout << std::setw(4) << std::setfill('0') << std::hex << keys[48 + i] << ' ';
    }

<<<<<<< Updated upstream
    std::cout << "\t\t|\t";
=======
    std::clog << "\t\t\t|\t";
>>>>>>> Stashed changes
    for (int i = 0; i < 4; ++i) {
        result += parts[i];
        std::cout << std::hex << std::setw(4) << std::setfill('0') << parts[i] << ' ';
        if (i != 3)
            result <<= 16;
    }


<<<<<<< Updated upstream
    std::cout << "\nEncode keys end!\n\n";
=======
    std::clog << "\nEncode keys end!\n";
    std::clog << "Encoded block: " << result << "\n\n";
>>>>>>> Stashed changes

    return result;
}

uint64_t IDEA::_decode(uint64_t block) {
    uint64_t result{};

    uint32_t parts[4];
    for (int i = 3; i >= 0; --i) {
        parts[i] = block & 0xffff;
        block >>= 16;
    }

    std::cout << "\nDecode keys: \n";

    for (int round = 0; round < 8; ++round) {
        // 0x10001 = 2^16 + 1, 0x10000 = 2^16
        uint16_t k[6];
        k[0] = inverseKey(keys[6 * (8 - round)]);
        if (round == 0) {
            k[1] = 65536 - keys[6 * (8 - round) + 1];
            k[2] = 65536 - keys[6 * (8 - round) + 2];
        } else {
            k[1] = 65536 - keys[6 * (8 - round) + 2];
            k[2] = 65536 - keys[6 * (8 - round) + 1];
        }
        k[3] = inverseKey(keys[6 * (8 - round) + 3]);
        k[4] = keys[6 * (8 - round) - 2];
        k[5] = keys[6 * (8 - round) - 1];

        for (auto item: k)
            std::cout << std::setw(4) << std::setfill('0') << std::hex << item << ' ';

        // steps 1 - 4
        parts[0] = (parts[0] * k[0]) % 0x10001;
        parts[1] = (parts[1] + k[1]) % 0x10000;
        parts[2] = (parts[2] + k[2]) % 0x10000;
        parts[3] = (parts[3] * k[3]) % 0x10001;

        // steps 5 - 6
        uint32_t temp1 = parts[0] ^ parts[2];
        uint32_t temp2 = parts[1] ^ parts[3];

        // steps 7 - 8
        temp1 = (temp1 * k[4]) % 0x10001;
        temp2 = (temp2 + temp1) % 0x10000;

        // step 9 - 10
        temp2 = (temp2 * k[5]) % 0x10001;
        temp1 = (temp1 + temp2) % 0x10000;

        // steps 11 - 14
        parts[0] ^= temp2;
        parts[2] ^= temp2;
        parts[1] ^= temp1;
        parts[3] ^= temp1;

        if (round != 7) {
            std::swap(parts[1], parts[2]);
        }

        std::cout << "\t|\t";
        for (auto item: parts)
            std::cout << std::hex << std::setw(4) << std::setfill('0') << item << ' ';
        std::cout << '\n';
    }
    uint16_t k[4];
    k[0] = inverseKey(keys[0]);
    k[1] = 65536 - keys[1];
    k[2] = 65536 - keys[2];
    k[3] = inverseKey(keys[3]);

    for (auto item: k)
        std::cout << std::hex << std::setw(4) << std::setfill('0') << item << ' ';

    parts[0] = (parts[0] * k[0]) % 0x10001;
    parts[1] = (parts[1] + k[1]) % 0x10000;
    parts[2] = (parts[2] + k[2]) % 0x10000;
    parts[3] = (parts[3] * k[3]) % 0x10001;

<<<<<<< Updated upstream
    std::cout << "\t\t|\t";
=======
    std::clog << "\t\t\t|\t";
>>>>>>> Stashed changes
    for (int i = 0; i < 4; ++i) {
        result += parts[i];
        std::cout << std::hex << std::setw(4) << std::setfill('0') << parts[i] << ' ';
        if (i != 3)
            result <<= 16;
    }
<<<<<<< Updated upstream
    std::cout << "\nDecode keys end!\n\n";
=======
    std::clog << "\nDecode keys end!\n";
    std::clog << "Decoded block: " << result << "\n\n";
>>>>>>> Stashed changes
    return result;
}

uint16_t IDEA::inverseKey(uint16_t key) {
    return extendedGcd(0x10001, key);
}

uint16_t IDEA::extendedGcd(uint32_t a, uint32_t b) {
//    uint16_t x = 0, lastX = 1, y = 1, lastY = 0, temp, quotient;
//    while (b != 0) {
//        temp = b;
//        quotient = a / b;
//        b = a % b;
//        a = temp;
//        temp = x;
//        x = lastX - quotient * x;
//        lastX = temp;
//        temp = y;
//        y = lastY - quotient * y;
//        lastY = temp;
//    }
//    return lastY;

//    uint32_t s{0}, old_s{1}, t{1}, old_t{0}, r{b}, old_r{a};
//
//    while (r != 0) {
//        uint32_t quotient = old_r / r;
//        uint32_t temp = r;
//        r = old_r - quotient * r;
//        old_r = temp;
//        temp = s;
//        s = old_s - quotient * s;
//        old_s = temp;
//        temp = t;
//        t = old_t - quotient * t;
//        old_t = temp;
//    }
//    return old_t;

    //a*x + b*y = 1
    //std::cout << " a = " << a << " b = " << b;
    int buf = a;
    //std::cout << " buf = " << buf;
    int q, r, x, x1, x2, y, y1, y2;
    x2 = 1, x1 = 0, y2 = 0, y1 = 1;
    while (b > 0) {
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;//
        //std::cout << " a= " << a << " b= " << b << " q= " << q << " x= " << x << " y= " << y << " r= " << r << " x2= " << x2 << " y2= " << y2 << std::endl;
    }
    //std::cout << "  y2 = " << y2;
    if (y2 < 0) {
        //std::cout << "  y2%buf = " << y2%buf << " y2%buf + buf = " << y2%buf + buf;
        y2 = y2 % buf + buf;
    }
    //std::cout << "  return y2 = " << y2%buf << "\n";
    return y2 % buf;//
}


void IDEA::setKey(uint128_t key) {
    mainKey = std::move(key);
    makeKeys();
}

uint128_t IDEA::getKey() const {
    return mainKey;
}

