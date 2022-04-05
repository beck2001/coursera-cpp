#include <iostream>

class Incognizable {
private:
    int64_t a, b;

public:
    Incognizable() = default;

    Incognizable(int64_t num) {
        a = num;
        b = num;
    }

    Incognizable(int64_t a, int64_t b) {
        this->a = a;
        this->b = b;
    }
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
