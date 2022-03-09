#include <iostream>
#include <string>
#include <vector>

void move_strings(std::vector<std::string> &lhs, std::vector<std::string> &rhs);
void print_vector(const std::vector<std::string> &v);

int main() {
    int size1, size2;
    std::cin >> size1 >> size2;
    std::vector<std::string> v1(size1);
    std::vector<std::string> v2(size2);

    for (auto &w : v1) {
        std::cin >> w;
    }
    for (auto &w : v2) {
        std::cin >> w;
    }

    move_strings(v1, v2);
    print_vector(v1);
    print_vector(v2);
    return 0;
}

void move_strings(std::vector<std::string> &lhs, std::vector<std::string> &rhs) {
    rhs.insert(std::end(rhs), std::begin(lhs), std::end(lhs));
    lhs.clear();
}

void print_vector(const std::vector<std::string> &v) {
    for (const auto &i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
