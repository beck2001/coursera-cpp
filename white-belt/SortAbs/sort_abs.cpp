#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void print_vector(const std::vector<int32_t> &v);

int main() {
    uint16_t n;
    std::cin >> n;
    std::vector<int32_t> v(n);
    for (auto &number : v) {
        std::cin >> number;
    }
    sort(v.begin(), v.end(), [](int32_t a, int32_t b) { return abs(a) < abs(b); });
    print_vector(v);
    return 0;
}

void print_vector(const std::vector<int32_t> &v) {
    for (const auto &number : v) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}
