#include <iostream>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <vector>

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

std::ostream& operator<<(std::ostream& stream, const Rational& r) {
    stream << r.get_numerator() << "/" << r.get_denominator();
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    if (lhs.get_denominator() == rhs.get_denominator()) {
        return lhs.get_numerator() < rhs.get_numerator();
    }
    return lhs.get_numerator() * rhs.get_denominator() < rhs.get_numerator() * lhs.get_denominator();
}

std::istream& operator>>(std::istream& stream, Rational& r) {
    if (stream) {
        int num, den;
        char delim;
        stream >> num >> delim >> den;
        if (stream) {
            if (delim == '/') {
                r = Rational(num, den);
            }
            else {
                stream.setstate(std::ios_base::failbit);
            }
        }
    }
    return stream;
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
    {
        std::ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            std::cout << "Rational(-6, 8) should be written as -3/4" << std::endl;
            return 11;
        }
    }
    {
        std::istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            std::cout << "5/7 is incorrectly read as " << r << std::endl;
            return 12;
        }
    }
    {
        std::istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            std::cout << "Read from empty stream works incorrectly" << std::endl;
            return 13;
        }
    }
    {
        std::istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Multiple values are read incorrectly" << std::endl;
            return 14;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Read from emtpy stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
            return 15;
        }
    }
    {
        std::istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            std::cout << "Reading of incorrectly formatted rationals shouldn't change arguments: " << r1 << " " << r2 << " " << r3 << std::endl;
            return 16;
        }
    }
    {
        std::istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            std::cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << std::endl;
            return 17;
        }
    }
    {
        const std::set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            std::cout << "Wrong amount of items in the set" << std::endl;
            return 18;
        }

        std::vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != std::vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            std::cout << "Rationals compare works incorrectly" << std::endl;
            return 19;
        }
    }
    {
        std::map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];
        if (count.size() != 2) {
            std::cout << "Wrong amount of items in the map" << std::endl;
            return 20;
        }
    }
    
    std::cout << "OK" << std::endl;
    return 0;
}
