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

    double Apply(double source_value) const {
        if (operation == '-') {
            return source_value - value;
        }
        else {
            return source_value + value;
        }
    }

    void Invert() {
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
    std::vector<FunctionPart> parts;

public:
    void Invert() {
        for (auto &f_part : parts) {
            f_part.Invert();
        }
        std::reverse(parts.begin(), parts.end());
    }

    void AddPart(char operation, double value) {
        parts.push_back(FunctionPart(operation, value));
    }

    double Apply(double value) const {
        for (const auto &f_part : parts) {
            value = f_part.Apply(value);
        }
        return value;
    }
};

Function MakeWeightFunction(const Image &image, const Params &params) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params &params, const Image &image) {
    Function function = MakeWeightFunction(image, params);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params, const Image &image, double weight) {
    Function function = MakeWeightFunction(image, params);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    // 36 (weight) quality = 10
    double weight = ComputeImageWeight(params, image);
    double quality = ComputeQualityByWeight(params, image, weight);
    std::cout << "weight: " << weight << std::endl << "quality: " << quality << std::endl;
    return 0;
}
