#include <iostream>
#include <string>
#include <algorithm>

class ReversibleString {
private:
    std::string m_string;

public:
    ReversibleString() = default;

    explicit ReversibleString(const std::string &string) {
        m_string = string;
    }

    void reverse() {
        std::reverse(m_string.begin(), m_string.end());
    }

    std::string to_string() const {
        return m_string;
    }
};

int main() {
    ReversibleString s("live");
    s.reverse();
    std::cout << s.to_string() << std::endl;

    s.reverse();
    const ReversibleString &s_ref = s;
    std::string tmp = s_ref.to_string();
    std::cout << tmp << std::endl;

    ReversibleString empty;
    std::cout << "\"" << empty.to_string() << "\"" << std::endl;
    return 0;
}
