#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> unique_strings;
    uint16_t n;
    std::cin >> n;
    while (n--) {
        std::string given_string;
        std::cin >> given_string;
        unique_strings.insert(given_string);
    }
    std::cout << unique_strings.size() << std::endl;
    return 0;
}
