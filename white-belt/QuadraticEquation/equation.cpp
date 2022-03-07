#include <cmath>
#include <iostream>

double discriminant(double a, double b, double c);
void solve_quadratic_equation(double a, double b, double c);

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    solve_quadratic_equation(a, b, c);
    return 0;
}

double discriminant(double a, double b, double c) {
    return pow(b, 2) - 4 * a * c;
}

void solve_quadratic_equation(double a, double b, double c) {
    if (a == 0) {
        std::cout << -c / b;
        return;
    }

    double d = discriminant(a, b, c);
    if (d > 0) {
        double first_root = (-b + sqrt(d)) / (2 * a);
        double second_root = (-b - sqrt(d)) / (2 * a);
        std::cout << first_root << " " << second_root;
    }
    else if (d == 0) {
        std::cout << -b / (2 * a);
    }
    else {
        std::cout << "no real roots";
    }
}
