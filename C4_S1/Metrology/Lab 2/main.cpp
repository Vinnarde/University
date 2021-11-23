#include <iostream>
#include <string>


int main() {
    std::cout << "Enter natural x: " << '\n';
    int x{};
    std::cin >> x;
    std::cout << "Enter natural K:" << '\n';
    int k{};
    std::cin >> k;
    std::string temp = std::to_string(x);
    if (k > temp.size()) {
        std::cout << "k must be <= number of digits in x!\n";
        return 0;
    } else
        std::cout << "First " << k << " digit of " << x << " is " << temp.substr(0, k);
    return 0;
}