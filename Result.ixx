module;
#include <string>
#include <iostream>
export module Wordle:result;
import :word;

class Result {
private:
    int m_attempts;
    std::string m_word;

public:
    Result(int attempts, const std::string& word) : m_attempts(attempts), m_word(word) {}

    friend std::ostream& operator<<(std::ostream& os, const Result& result) {
        os << "You guessed the word \"" << result.m_word << "\" in " << result.m_attempts << " attempts!\n";
        return os;
    }
};