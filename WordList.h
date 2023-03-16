#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Word.h"

class WordList {
private:
    std::vector<Word> m_words;

public:
    WordList() {}

    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: could not open file \"" << filename << "\"." << std::endl;
            return false;
        }

        std::string word;
        while (file >> word) {
            m_words.push_back(word);
        }

        file.close();
        return true;
    }

    std::vector<Word> getWords() const {
        return m_words;
    }
};