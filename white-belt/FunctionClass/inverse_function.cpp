#include <iostream>
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

    double Apply(double source_value) const {
        if (operation == '-') {
            return source_value - value;
        }
        else {
            return source_value + value;
        }
    }

    void Inverse() {
        if (operation == '-') {
            operation = '+';
        }
        else {
            operation = '-';
        }
    }
};

class Function {
private:
    std::vector<FunctionParts> parts;

public:
    void Inverse() {
        for (auto &f_part : parts) {
            part.Inverse();
        }
    }

    void AddPart(const FunctionPart &function_part) {
        parts.push_back(function_part);
    }

    double Apply(double value) const {
        for (const auto &f_part : parts) {
            value = f_part.Apply(value);
        }
        return value;
    }
};

int main() {
    return 0;
}
