#include <iostream>

double find_percentage(double value, double percentage);

int main() {
    double n, a, b, x, y, result;
    std::cin >> n >> a >> b >> x >> y;
    double first_discount = n, second_discount = n;

    if (n > a) {
        first_discount = n - find_percentage(n, x);
    }

    if (n > b) {
        second_discount = n - find_percentage(n, y);
    }

    result = first_discount < second_discount ? first_discount : second_discount;
    std::cout << result;
    return 0;
}

double find_percentage(double value, double percentage) {
    return value * percentage / 100;
}
