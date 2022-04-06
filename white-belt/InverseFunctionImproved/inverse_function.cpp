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
        else if (operation == '+') {
            operation = '-';
        }
        else if (operation == '*') {
            operation = '/';
        }
        else {
            operation = '*';
        }
    }

    double apply(double source_value) const {
        if (operation == '-') {
            return source_value - value;
        }
        else if (operation == '+') {
            return source_value + value;
        }
        else if (operation == '*') {
            return source_value * value;
        }
        else {
            // it is guaranteed that division by zero is avoided
            return source_value / value;
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

Function MakeWeightFunction(const Image &image, const Params &params) {
    Function function;
    function.add_part('*', params.a);
    function.add_part('-', image.freshness * params.b);
    function.add_part('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Image &image, const Params &params) {
    Function function = MakeWeightFunction(image, params);
    return function.apply(image.quality);
}

double ComputeQualityByWeight(const Image &image, const Params &params, double weight) {
    Function function = MakeWeightFunction(image, params);
    function.invert();
    return function.apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    std::cout << ComputeImageWeight(image, params) << std::endl;
    std::cout << ComputeQualityByWeight(image, params, 52) << std::endl;
    return 0;
}
