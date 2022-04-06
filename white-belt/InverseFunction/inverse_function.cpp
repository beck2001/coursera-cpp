#include <iostream>
#include <algorithm>
#include <vector>

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
private:
    char operation;
    double value;

public:
    FunctionPart(char operation, double value) {
        this->operation = operation;
        this->value = value;
    }

    void invert() {
        if (operation == '-') {
            operation = '+';
        }
        else {
            operation = '-';
        }
    }

    double apply(double source_value) const {
        if (operation == '-') {
            return source_value - value;
        }
        else {
            return source_value + value;
        }
    }
};

class Function {
private:
    std::vector<FunctionPart> parts;

public:
    void add_part(char operation, double value) {
        parts.push_back(FunctionPart(operation, value));
    }

    void invert() {
        for (auto &f_part : parts) {
            f_part.invert();
        }
        std::reverse(parts.begin(), parts.end());
    }

    double apply(double value) const {
        for (const auto &f_part : parts) {
            value = f_part.apply(value);
        }
        return value;
    }
};

int main() {
    return 0;
}
