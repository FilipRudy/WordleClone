#pragma once
#include <string>
#include <iostream>
#include "Result.h"


class UI {
public:
    static char readGuess() {
        std::cout << "Enter a guess: ";
        char guess;
        std::cin >> guess;
        std::cout << "\n";
        return guess;
    }

    static void displayGuess(const std::string& guess) {
        std::cout << "Your guess: " << guess << "\n";
    }

    static void displayResult(const Result& result) {
        std::cout << result << "\n";
    }

    static void displayIncorrectGuess() {
        std::cout << "Incorrect guess. Please try again.\n\n";
    }

    static void displayGameOver() {
        std::cout << "Game over. Better luck next time!\n";
    }

    static void displayGameStart() {
        std::cout << "Welcome to Wordle!\n";
    }

    static void displayWordLength(size_t length) {
        std::cout << "The word to guess is " << length << " letters long.\n\n";
    }

    static void displayWordSoFar(const std::string& wordSoFar) {
        std::cout << "Word so far: " << wordSoFar << "\n";
    }
};