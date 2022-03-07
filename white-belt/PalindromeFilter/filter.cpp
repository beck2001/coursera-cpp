#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(const std::string &str);
void print_vector(const std::vector<std::string> &v);
std::vector<std::string> palindrome_filter(const std::vector<std::string> &words, int min_length);

int main() {
    int min_length, number_of_words;
    std::cin >> number_of_words >> min_length;
    std::vector<std::string> words(number_of_words);

    for (auto &w : words) {
        std::cin >> w;
    }

    const std::vector<std::string> result = palindrome_filter(words, min_length);
    print_vector(result);

    return 0;
}

bool is_palindrome(const std::string &str) {
    for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

void print_vector(const std::vector<std::string> &v) {
    for (const auto &i : v) {
        std::cout << i << " ";
    }
}

std::vector<std::string> palindrome_filter(const std::vector<std::string> &words, int min_length) {
    std::vector<std::string> result;
    for (const auto &word : words) {
        if (is_palindrome(word) && word.size() >= min_length) {
            result.push_back(word);
        }
    }
    return result;
}
