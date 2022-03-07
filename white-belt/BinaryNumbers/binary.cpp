#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<int> &v);

int main() {
    int n;
    std::cin >> n;
    std::vector<int> in_binary;

    while (n != 0) {
        in_binary.push_back(n % 2);
        n /= 2;
    }

    std::reverse(std::begin(in_binary), std::end(in_binary));
    print_vector(in_binary);
    return 0;
}

void print_vector(const std::vector<int> &v) {
    for (const auto &i : v) {
        std::cout << i;
    }
}
