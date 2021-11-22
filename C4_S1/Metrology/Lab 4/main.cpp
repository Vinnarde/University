#include <iostream>

bool sumEqualTo(int number, const int target) {
    int sum{0};
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum == target;
}

int main() {
    int a{}, b{}, s{};
    do {
        std::cout << "Enter A: ";
        std::cin >> a;
        std::cout << "Enter B: ";
        std::cin >> b;
    } while (a > b);
    std::cout << "Enter S: ";
    std::cin >> s;

    bool flag{false};
    for (int i = a; i <= b; ++i) {
        if (sumEqualTo(i, s)) {
            std::cout << i << '\n';
            flag = true;
        }

    }

    if (!flag) {
        std::cout << "There are no required numbers!\n";
    }

    return 0;
}