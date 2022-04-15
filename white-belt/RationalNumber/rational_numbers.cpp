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
        this->numerator = 0;
        this->denominator = 1;
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

Rational operator+(const Rational& lhs, const Rational& rhs) {
    if (lhs.get_denominator() == rhs.get_denominator()) {
        return {lhs.get_numerator() + rhs.get_numerator(), lhs.get_denominator()};
    }
    int common_denominator = lhs.get_denominator() * rhs.get_denominator();
    return {lhs.get_numerator() * rhs.get_denominator() + rhs.get_numerator() * lhs.get_denominator(), common_denominator};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    if (lhs.get_denominator() == rhs.get_denominator()) {
        return {lhs.get_numerator() - rhs.get_numerator(), lhs.get_denominator()};
    }
    int common_denominator = lhs.get_denominator() * rhs.get_denominator();
    return {lhs.get_numerator() * rhs.get_denominator() - rhs.get_numerator() * lhs.get_denominator(), common_denominator};
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.get_numerator() == rhs.get_numerator() && lhs.get_denominator() == rhs.get_denominator();
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return lhs.get_numerator() != rhs.get_numerator() || lhs.get_denominator() != rhs.get_denominator();
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.get_numerator() * rhs.get_numerator(), lhs.get_denominator() * rhs.get_denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return {lhs.get_numerator() * rhs.get_denominator(), lhs.get_denominator() * rhs.get_numerator()};
}

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
    {
        const Rational r(4, -6);
        if (r.get_numerator() != -2 || r.get_denominator() != 3) {
            std::cout << "Rational(4, -6) != -2/3" << std::endl;
            return 3;
        }
    }
    {
        const Rational r(0, 15);
        if (r.get_numerator() != 0 || r.get_denominator() != 1) {
            std::cout << "Rational(0, 15) != 0/1" << std::endl;
            return 4;
        }
    }
    {
        const Rational r;
        if (r.get_numerator() != 0 || r.get_denominator() != 1) {
            std::cout << "Rational() != 0/1" << std::endl;
            return 5;
        }
    }
    {
        const Rational r1(4, 6);
        const Rational r2(2, 3);
        if (r1 != r2) {
            std::cout << "4/6 != 2/3" << std::endl;
            return 6;
        }
    }
    {
        const Rational r1(4, 6);
        const Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            std::cout << "4/6 != 2/3" << std::endl;
            return 6;
        }
    }
    {
        const Rational r1(2, 3);
        const Rational r2(4, 3);
        const Rational res = r1 + r2;
        bool equal = res == Rational(2, 1);
        if (!equal) {
            std::cout << "2/3 + 4/3 != 2" << std::endl;
            return 7;
        }
    }
    {
        const Rational r1(5, 7);
        const Rational r2(2, 9);
        const Rational res = r1 - r2;
        bool equal = res == Rational(31, 63);
        if (!equal) {
            std::cout << "5/7 - 2/9 != 31/63" << std::endl;
            return 8;
        }
    }
    {
        const Rational r1(2, 3);
        const Rational r2(4, 3);
        const Rational res = r1 * r2;
        bool equal = res == Rational(8, 9);
        if (!equal) {
            std::cout << "2/3 * 4/3 != 8/9" << std::endl;
            return 9;
        }
    }
    {
        const Rational r1(5, 4);
        const Rational r2(15, 8);
        const Rational res = r1 / r2;
        bool equal = res == Rational(2, 3);
        if (!equal) {
            std::cout << "5/4 / 15/8 != 2/3" << std::endl;
            return 10;
        }
    }
    
    std::cout << "OK" << std::endl;
    return 0;
}
