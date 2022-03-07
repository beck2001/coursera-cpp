#include <iostream>

void update_if_greater(int x, int &y);

int main() {
    int a, b;
    std::cin >> a >> b;
    update_if_greater(a, b);
    std::cout << a << " " << b;
    return 0;
}

void update_if_greater(int x, int &y) {
    if (x > y) {
        y = x;
    }
}
