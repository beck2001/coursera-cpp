#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::istream input("input.txt");
  if (input) {
      std::string line;
      getline(input, line);
      std::cout << line << std::endl;
  }
  else {
      std::cout << "error, while creating input stream" << std::endl;
  }
  return 0;
}
