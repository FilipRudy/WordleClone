#include <string>

class Word {
private:
    std::string m_word;

public:
    Word() : m_word("") {}
    Word(const std::string& word) : m_word(word) {}

    bool containsLetter(char letter) const {
        return m_word.find(letter) != std::string::npos;
    }

    bool isCorrect(const std::string& guess) const {
        if (guess.length() != m_word.length()) {
            return false;
        }

        for (size_t i = 0; i < m_word.length(); i++) {
            if (guess[i] != m_word[i]) {
                return false;
            }
        }

        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const Word& word) {
        os << word.m_word;
        return os;
    }
};