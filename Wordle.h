#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "wordlist.h"

class Wordle {
private:
    std::vector<Word> m_words;
    Word m_solution;

public:
    Wordle(std::vector<Word> m_words) {


        srand(time(nullptr));
        m_solution = m_words[rand() % m_words.size()];
    }

    bool isGuessCorrect(const std::string& guess) const {
        return m_solution.isCorrect(guess);
    }
};
