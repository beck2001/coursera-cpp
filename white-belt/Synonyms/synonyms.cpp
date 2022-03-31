#include <iostream>
#include <map>
#include <set>
#include <string>

void add(std::map<std::string, std::set<std::string>> &syn, const std::string &word1, const std::string &word2);
void count(const std::map<std::string, std::set<std::string>> &syn, const std::string &word);
void check(const std::map<std::string, std::set<std::string>> &syn, const std::string &word1, const std::string &word2);

int main() {
    uint16_t q;
    std::cin >> q;
    std::map<std::string, std::set<std::string>> syn;
    while (q--) {
        std::string operation;
        std::cin >> operation;
        if (operation == "ADD") {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            add(syn, word1, word2);
        }
        else if (operation == "COUNT") {
            std::string word;
            std::cin >> word;
            count(syn, word);
        }
        else if (operation == "CHECK") {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            check(syn, word1, word2);
        }
        else {
            std::cout << "INVALID OPERATION" << std::endl;
        }
    }
    return 0;
}

void add(std::map<std::string, std::set<std::string>> &syn, const std::string &word1, const std::string &word2) {
    syn[word1].insert(word2);
    syn[word2].insert(word1);
}

void count(const std::map<std::string, std::set<std::string>> &syn, const std::string &word) {
    if (syn.find(word) == syn.end()) {
        std::cout << 0 << std::endl;
    }
    else {
        std::cout << syn.at(word).size() << std::endl;
    }
}

void check(const std::map<std::string, std::set<std::string>> &syn, const std::string &word1, const std::string &word2) {

    if (syn.find(word1) == syn.end()) {
        std::cout << "NO" << std::endl;
        return;
    }

    if (syn.at(word1).find(word2) != syn.at(word1).end()) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}
