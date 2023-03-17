module;
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <string>
export module Wordle:wordList;
import :word;

export class WordList {
private:
    std::vector<Word> m_words;

public:
    WordList() {}

    bool loadFromFile(const std::string& filename) {
        std::filesystem::path filePath(filename);
        if (!std::filesystem::exists(filePath)) {
            std::cerr << "Error: could not open file \"" << filename << "\"." << std::endl;
            return false;
        }

        std::ifstream file(filePath);
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
