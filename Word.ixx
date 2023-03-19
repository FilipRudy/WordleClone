module;
#include <iostream>
#include <string>
#include <vector>
export module Wordle:word;

export class Word {
private:
    std::string m_word;

public:
    Word() : m_word("") {}
    Word(const std::string& word) : m_word(word) {}

    std::string getWord() const
    {
        return m_word;
    }

    std::vector<int> checkForLetterCorrection(Word wordToGuess, Word guess)
    {
        std::vector<int> lettersPositions;

        for (size_t i = 0; i < wordToGuess.length(); i++)
        {
            lettersPositions.push_back(0);
        }

        for (size_t i = 0; i < wordToGuess.length(); i++)
        {
            if (wordToGuess[i] == guess[i])
            {
                lettersPositions[i] = 2;
            }
            else
            {
                for (size_t j = 0; j < wordToGuess.length(); j++)
                {
                    if (guess[i] == wordToGuess[j] && wordToGuess[j] != 2)
                    {
                        lettersPositions[j] = 1;
                    }
                }
            }
        }
        return lettersPositions;
    }


    size_t length() const {
        return m_word.length();
    }

    friend std::ostream& operator<<(std::ostream& os, const Word& word) {
        os << word.m_word;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Word& word) {
        std::string input;
        if (is >> input) {
            word = Word(input);
        }
        return is;
    }

    char& operator[](size_t index) {
        return m_word[index];
    }

    

};

bool operator==(const Word& lhs, const Word& rhs) {
        return lhs.getWord() == rhs.getWord();
    }