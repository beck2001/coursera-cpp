#include <iostream>
#include <algorithm>
#include <vector>

void reverse_sequence(std::vector<int>& v);
void print_vector(const std::vector<int>& v);

int main() {
	int size;
	std::cin >> size;
	std::vector<int> v(size);

	for (auto& i : v) {
		std::cin >> i;
	}
	print_vector(v);
	
	reverse_sequence(v);
	print_vector(v);
	return 0;
}

void reverse_sequence(std::vector<int>& v) {
	std::reverse(std::begin(v), std::end(v));
}

void print_vector(const std::vector<int>& v) {
	for (const auto& i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
