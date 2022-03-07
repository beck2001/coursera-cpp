#include <iostream>

int gcd(int a, int b);

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << gcd(x, y);
    return 0;
}

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}
