module;
#include <fstream>
#include <vector>
#include <ranges>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <windows.h>
export module Wordle:game;
import :wordList;
import :word;
import :ui;

export class Wordle {
private:
    std::vector<Word> m_words;
    Word solution;
    bool isGameOver;
    bool isGameWon;

public:
    Wordle() {
        isGameOver = false;
        isGameWon = false;
        srand(time(nullptr));
    }

    Wordle(std::vector<Word> m_words) {

        isGameOver = false;
        srand(time(nullptr));
        solution = m_words[rand() % m_words.size()];
    }

    bool getIsGameOver() {
        return isGameOver;
    }

    bool getIsGameWon() {
        return isGameWon;
    }

    Word generateWordToGuess(std::vector<Word> wordList) {
        // Inicjalizacja generatora liczb pseudolosowych
        std::random_device rd;
        std::mt19937 gen(rd());

        // Sprawdzenie, czy lista s³ów nie jest pusta
        if (wordList.empty()) {
            throw std::invalid_argument("Word list is empty");
        }

        // Losowanie indeksu s³owa
        std::uniform_int_distribution<> dis(0, wordList.size() - 1);
        int index = dis(gen);

        return wordList[index];
    }

    bool isWordInList(std::vector<Word> words, Word word)
    {
        std::cout << words.size();
        return std::find(words.begin(), words.end(), word) != words.end();
    }

    void startGame(Word wordToGuess, Ui& ui, std::vector<Word> m_words, Word solution) {
        Word guess;
        do {
            guess = ui.readGuess(m_words);
            if (guess == solution)
            {
                isGameWon = true;
                break;
            }
            ui.displayWordLength(guess, wordToGuess);
        } while (ui.getAttemptNumber() < 6);
        isGameOver = true;
    }

};