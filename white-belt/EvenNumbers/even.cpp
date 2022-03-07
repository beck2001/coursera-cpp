#include <iostream>

int main() {
    uint16_t a, b;
    std::cin >> a >> b;
    for (uint16_t i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            std::cout << i << " ";
        }
    }
    return 0;
}
