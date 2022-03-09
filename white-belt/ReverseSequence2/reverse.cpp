#include <iostream>
#include <vector>

std::vector<int> reversed(const std::vector<int> &v);

void print_vector(const std::vector<int> &v);

int main() {
    int v_size;
    std::cin >> v_size;
    std::vector<int> v(v_size);

    for (auto &i: v) {
        std::cin >> i;
    }
    std::vector<int> result = reversed(v);
    print_vector(result);
    return 0;
}

std::vector<int> reversed(const std::vector<int> &v) {
    std::vector<int> reversed_vector;
    for (size_t i = v.size(); i-- > 0;) {
        reversed_vector.push_back(v[i]);
    }
    return reversed_vector;
}

void print_vector(const std::vector<int> &v) {
    for (const auto &i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
