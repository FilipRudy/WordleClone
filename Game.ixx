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
    Word m_solution;
    bool isGameOver;

public:
    Wordle() {
        isGameOver = false;
        srand(time(nullptr));
    }

    Wordle(std::vector<Word> m_words) {

        isGameOver = false;
        srand(time(nullptr));
        m_solution = m_words[rand() % m_words.size()];
    }

    bool getIsGameOver() {
        return isGameOver;
    }

    Word generateWordToGuess(std::vector<Word> wordList) {
        // Inicjalizacja generatora liczb pseudolosowych
        std::random_device rd;
        std::mt19937 gen(rd());

        // Sprawdzenie, czy lista s��w nie jest pusta
        if (wordList.empty()) {
            throw std::invalid_argument("Word list is empty");
        }

        // Losowanie indeksu s�owa
        std::uniform_int_distribution<> dis(0, wordList.size() - 1);
        int index = dis(gen);

        return wordList[index];
    }


    void startGame(Word wordToGuess, Ui ui) {
        Word guess;
        do {
            guess = ui.readGuess();
            ui.displayWordLength(guess, wordToGuess);
        } while (ui.getAttemptNumber() < 6);
        isGameOver = true;
        ui.displayGameOver(guess, wordToGuess);
    }


    static void displayCorrectLetters(const Word& guess) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // ustawienie koloru tekstu na niebieski
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

        // wy�wietlenie napisu w niebieskim kolorze
        std::cout << "To jest niebieski tekst" << std::endl;


        // przywr�cenie domy�lnych kolor�w
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    }


};