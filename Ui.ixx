module;
#include <fstream>
#include <vector>
#include <ctime>
#include <regex>
#include <cstdlib>
#include <iostream>
export module Wordle:ui;
import :result;


export class Ui {
public:
    static Word readGuess() {
        std::cout << "Enter a 5-letter word without numbers or special characters: ";
        Word guess;
        std::cin >> guess;

        // Check if the input matches the regular expression pattern
        std::regex pattern("[a-zA-Z]{5}");
        if (!std::regex_match(guess.getWord(), pattern)) {
            
            std::cout << "\nError: Please enter a 5-letter word without numbers or special characters.\n";
            return readGuess();  // Call the function recursively to ask for another word
        }

        std::cout << "\n";
        return guess;
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
        std::cout << "The word to guess is ";
        for (int i = 0; i < length; i++)
        {
            std::cout << "_ ";
        }
        std::cout << "(" << length << ") letters long\n";
    }

    static void displayWordSoFar(const std::string& wordSoFar) {
        std::cout << "Word so far: " << wordSoFar << "\n";
    }
};