#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Matrix {
    std::vector<int> mMatrix;
    std::size_t nRows{}, nCols{};

    void fillRandom();

    void task();

    void printMatrix();
};

void Matrix::fillRandom() {

    std::random_device randomDevice;
    std::mt19937 mersenneEngine{randomDevice()};  // Generates random integers
    std::uniform_int_distribution<int> dist{-10, 10};

    auto gen = [&dist, &mersenneEngine]() {
        return dist(mersenneEngine);
    };

    mMatrix.resize(nRows * nCols);
    std::generate(mMatrix.begin(), mMatrix.end(), gen);
}

void Matrix::printMatrix() {
    for (std::size_t row = 0; row < nRows; ++row) {
        for (std::size_t col = 0; col < nCols; ++col) {
            std::cout << std::fixed << std::setw(4) <<mMatrix[row * nCols + col] << ' ';
        }
        std::cout << '\n';
    }
}

void Matrix::task() {
    for (int i = 0; i < std::min(nCols, nRows); ++i) {
        mMatrix[i * nCols + i] = i;
    }
}

int main() {
    Matrix m;
    std::cout << "Enter M:";
    std::cin >> m.nRows;
    std::cout << "Enter N:";
    std::cin >> m.nCols;

    m.fillRandom();
    m.printMatrix();

    m.task();
    std::cout << "After changes:\n";
    m.printMatrix();
    return 0;
}
