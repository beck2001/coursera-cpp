#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

void print_vector(const std::vector<std::string> &v);

int main() {
    uint16_t n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (auto &s : v) {
        std::cin >> s;
    }
    sort(v.begin(), v.end(), [](const std::string &first, const std::string &second) {
        return lex_compare(begin(first), end(first), begin(second), end(second), [](char left, char right) {
            return tolower(left) < tolower(right);
        })
    });
    print_vector(v);
    return 0;
}

void print_vector(const std::vector<std::string> &v) {
    for (const auto &s : v) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
