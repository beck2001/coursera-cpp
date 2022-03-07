#include <iostream>

int main() {
    uint32_t a, b;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << "Impossible";
    }
    else {
        std::cout << a / b;
    }
    return 0;
}
