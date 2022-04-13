#include <iostream>
#include <cmath>

class Rational {
private:
    int numerator;
    int denominator;
    int gcd(int a, int b) const {
        a = abs(a), b = abs(b);
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

public:
    int get_numerator() const {
        return numerator;
    }

    int get_denominator() const {
        return denominator;
    }

    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator < 0 && denominator < 0 || numerator >= 0 && denominator < 0) {
            this->numerator = -numerator / gcd(numerator, denominator);
            this->denominator = -denominator / gcd(numerator, denominator);
        }
        else if (numerator == 0) {
            this->numerator = numerator;
            this->denominator = 1;
        }
        else {
            this->numerator = numerator / gcd(numerator, denominator);
            this->denominator = denominator / gcd(numerator, denominator);
        }
    }

};

int main() {
    {
        const Rational r(3, 10);
        if (r.get_numerator() != 3 || r.get_denominator() != 10) {
            std::cout << "Rational(3, 10) != 3/10" << std::endl;
            return 1;
        }
    }
    {
        const Rational r(8, 12);
        if (r.get_numerator() != 2 || r.get_denominator() != 3) {
            std::cout << "Rational(8, 12) != 2/3" << std::endl;
            return 2;
        }
    }
    {
        const Rational r(-4, 6);
        if (r.get_numerator() != -2 || r.get_denominator() != 3) {
            std::cout << "Rational(-4, 6) != -2/3" << std::endl;
            return 3;
        }
    }
    std::cout << "OK" << std::endl;
    return 0;
}
