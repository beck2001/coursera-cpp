#include <iostream>
#include <string>

void ensure_equal(const std::string& left, const std::string& right);

int main() {
    try {
        ensure_equal("C++ White", "C++ White");
        ensure_equal("C++ White", "C++ Yellow");
    }
    catch (std::runtime_error& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}

void ensure_equal(const std::string& left, const std::string& right) {
    if (left != right) {
        throw std::runtime_error(left + " != " + right);
    }
}
