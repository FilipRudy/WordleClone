module;
#include <string>
#include <iostream>
export module Wordle:result;
import :word;

export class Result {
private:
    int m_attempts;
    Word m_word;
    bool m_isGameWon;

public:
    Result(int attempts, const Word& word, bool isGameWon) : m_attempts(attempts), m_word(word), m_isGameWon(isGameWon) {}

    friend std::ostream& operator<<(std::ostream& os, const Result& result) {
        if (result.m_isGameWon) {
            os << "Congratulations, you won! You guessed the word \"" << result.m_word << "\" in " << result.m_attempts << " attempts.\n";
        }
        else {
            os << "Sorry, you lost. The word was \"" << result.m_word << "\". Better luck next time!\n";
        }
        return os;
    }
};