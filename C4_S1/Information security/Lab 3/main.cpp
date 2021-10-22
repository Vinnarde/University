#include <codecvt>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cwctype>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <random>
#include <chrono>

const auto locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
constexpr size_t alphabetSize = 36;
constexpr size_t size{6};

static constexpr auto alphabet_s = [] {
    std::array<wchar_t, alphabetSize> a{};
    for (size_t i = 0; i < alphabetSize - 3; ++i)
        a[i] = L'а' + i;

    a[33] = L' ';
    a[34] = L'.';
    a[35] = L',';
    return a;
}();

std::unordered_set<wchar_t> alphabet;

struct PolibiusSquare {
    std::array<wchar_t, alphabetSize> m_alphabet = alphabet_s;
    int32_t m_nRows, m_nColumns;

    PolibiusSquare(const int32_t nRows, const int32_t nColumns) :
            m_nRows(nRows), m_nColumns(nColumns) {};

    std::wstring encrypt(const std::wstring &message) {
        std::wstring result{};

        for (wchar_t e: message) {
            int index = findCharacter(e);
            result += m_alphabet[mod((index + m_nColumns), m_alphabet.size())];
        }
        return result;
    }

    std::wstring decrypt(const std::wstring &message) {
        std::wstring result{};

        for (wchar_t e: message) {
            int32_t index = findCharacter(e);
            result += m_alphabet[mod((index - m_nColumns), m_alphabet.size())];
        }
        return result;
    }

    // Map that stores frequency of characters in text; {ch, character_count / number_of_characters};
    std::unordered_map<wchar_t, double> m_frequencyTable;
private:
    int findCharacter(wchar_t ch) {
        int index = -1;
        for (int i = 0; i < m_alphabet.size(); ++i) {
            if (ch == m_alphabet[i]) {
                index = i;
                break;
            }
        }
        return index;
    }

    static int32_t mod(int32_t k, int32_t n) {
        return ((k %= n) < 0) ? k + n : k;
    }
};


double calculateW(const std::unordered_map<wchar_t, double> &table_1,
                  const std::unordered_map<wchar_t, double> &table_2) {
    double W{0.0};
    for (auto &item: table_1) {
        double val = item.second - table_2.at(item.first);
        val *= val;
        W += val;
    }
    return W;
}

void printAlphabet() {
    std::wcout << L"Alphabet = [";
    for (wchar_t it: alphabet)
        std::wcout << "'" << it << L"',";
    std::wcout << L"]\n\n";
}

bool notInAlphabet(wchar_t ch) {
    bool result = alphabet.find(ch) == alphabet.end();
    return result;
}

void removeNonAlphabetCharacters(std::wstring &resultString) {
    resultString.erase(std::remove_if(resultString.begin(), resultString.end(), notInAlphabet), resultString.end());
    std::size_t doubleSpace = resultString.find(L"  ");
    while (doubleSpace != std::string::npos) {
        resultString.erase(doubleSpace, 1);
        doubleSpace = resultString.find(L"  ");
    }
}

void calculateFrequency(std::unordered_map<wchar_t, double> &frequencyTable, const std::wstring &msg) {
    for (auto e: alphabet)
        frequencyTable[e] = 0.0;

    for (wchar_t c: msg) {
        frequencyTable[c]++;
    }

    const size_t numOfCharacters = msg.length();
    for (auto &item: frequencyTable) {
        item.second /= numOfCharacters;
    }
}

void printFrequencyTable(const std::unordered_map<wchar_t, double> &frequencyTable) {
    for (auto item: frequencyTable)
        std::wcout << item.first << '\t' << item.second << '\n';
}

int main(int argc, char *argv[]) {

    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    try {

        // receiving polibius square
        PolibiusSquare polibius(36, 1   );
        std::wifstream inputText(L"../input.txt");
        inputText.imbue(locale);
        std::wifstream inputPolibius(L"../polibius.txt");
        inputPolibius.imbue(locale);

        if (inputPolibius.is_open()) {
            for (std::size_t i = 0; i < alphabetSize; ++i) {
                inputPolibius >> std::noskipws >> polibius.m_alphabet[i];
                alphabet.insert(polibius.m_alphabet[i]);
            }
        } else
            throw std::runtime_error("Couldn't open polibius.txt file!\n");

        // receiving source text
        std::wstring buffer;
        if (inputText.is_open()) {
            std::getline(inputText, buffer, L'\0');
        } else {
            throw std::runtime_error("Couldn't open input.txt file!\n");
        }

        std::wcout.imbue(locale);
        std::wcout << L"Reading text...\nSource text:\n" << buffer << L"\n\n";

        // transform source text to lowercase and remove any characters that are not in alphabet
        std::transform(buffer.begin(), buffer.end(), buffer.begin(), std::towlower);
        removeNonAlphabetCharacters(buffer);
        std::wcout << L"Truncated text:\n" << buffer << "\n\n";

        calculateFrequency(polibius.m_frequencyTable, buffer);

        std::wcout << L"Truncated text length: " << buffer.length() << '\n';
        printFrequencyTable(polibius.m_frequencyTable);

        std::wstring encryptedText = polibius.encrypt(buffer);

        std::wcout << L"Encrypted text:\n" << encryptedText << L"\n\n";


        // decrypt process
        typedef std::pair<int, int> intPair;
        std::vector<intPair> combinations = {{1,  36},
                                             {2,  18},
                                             {3,  12},
                                             {4,  9},
                                             {6,  6},
                                             {9,  4},
                                             {12, 3},
                                             {18, 2},
                                             {36, 1}};


        double W = std::numeric_limits<double>::max();

        int row = -1, column = -1;
        std::wstring decryptedMessage;
        for (auto pair: combinations) {
            PolibiusSquare test(pair.first, pair.second);
            test.m_alphabet = polibius.m_alphabet;

//            constexpr std::size_t numberOfAttempts = 1000;
//            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

//            for (std::size_t i = 0; i < numberOfAttempts; ++i) {
//                std::shuffle(test.m_alphabet.begin(), test.m_alphabet.end(), std::default_random_engine(seed));

            std::wstring decryptedText = test.decrypt(encryptedText);
            calculateFrequency(test.m_frequencyTable, decryptedText);

            double temp_W = calculateW(polibius.m_frequencyTable, test.m_frequencyTable);

            if (temp_W < W) {
                W = temp_W;
                row = pair.first;
                column = pair.second;
                decryptedMessage = decryptedText;
            }

//            }
        }

        std::wcout << L"Decrypted message: " << decryptedMessage << L"\nW = " << W <<
                   L"\nnumber of rows = " << row << L"\nnumber of columns = " << column << '\n';

        std::wofstream output("../output.txt");
        output.imbue(locale);

        if (output.is_open())
        {
            output << encryptedText << '\n';
        }

    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
