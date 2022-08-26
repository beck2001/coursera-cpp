#include <iostream>

double add(double, double);
double multiply(double, double);
double subtract(double, double);
double calculate(double, double, double (*fun_ptr)(double, double));

int main() {
  double (*pf[3])(double, double) = {add, multiply, subtract};
  for (int i = 0; i < 3; ++i) {
    std::cout << "#" << (i + 1) << ". Enter x and y: ";
    double x, y;
    std::cin >> x >> y;
    std::cout << calculate(x, y, pf[i]) << std::endl;
  }
  return 0;
}

double add(double x, double y) {
  return x + y;
}

double multiply(double x, double y) {
  return x * y;
}

double subtract(double x, double y) {
  return x - y;
}

double calculate(double x, double y, double (*fun_ptr)(double, double)) {
  return fun_ptr(x, y);
}
