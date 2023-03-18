module;
#include <fstream>
#include <vector>
#include <ctime>
#include <regex>
#include <cstdlib>
#include <iostream>
export module Wordle:ui;
import :result;
import :word;


export class Ui {
private:
    size_t attemptNumber;
    
    std::vector<char> usedLetters;

public:
    Ui(size_t m_attemptNumber) : attemptNumber(m_attemptNumber), usedLetters(28, ' ') {}


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

    static void displayGameOver(Word lastGuess, Word wordToGuess) {
        if (lastGuess == wordToGuess)
        {
            std::cout << "\nGame over. You won!\n";
        }
        else
        {
            std::cout << "\nGame over. The word to guess was: " << wordToGuess<< " Better luck next time!\n";
        }
        
    }

    static void displayGameStart() {
        std::cout << "Welcome to Wordle!\n";
    }

    size_t getAttemptNumber()
    {
        return attemptNumber;
    }

    void getUsedLetters(Word word)
    {
        bool canAddLetter = true;

        for (size_t i = 0; i < word.length(); i++)
        {
            for (size_t j = 0; j < usedLetters.size(); j++)
            {
                if (word[i] == usedLetters[j])
                {
                    canAddLetter = false;
                }
            }

            if (canAddLetter)
            {
                usedLetters.push_back(word[i]);
                canAddLetter = true;
            }
            else
            {
                canAddLetter = true;
            }
            
        }

    }

    void displayUsedLetters()
    {
        for (size_t i = 0; i < usedLetters.size(); i++)
        {
            if (usedLetters[i] != ' ')
            {
                std::cout << usedLetters[i] << " ";
            }
            
        }

        std::cout<< std::endl;
    }

    void displayWordLength(Word word, Word wordToGuess) {
        ++attemptNumber;
        getUsedLetters(word);
        std::vector<int> letterCorrection = word.checkForLetterCorrection(word, wordToGuess);
        std::cout << "The word to guess is: ";

        for (int i = 0; i < wordToGuess.length(); i++)
        {
            if (letterCorrection[i] == 2)
            {
                std::cout << "\033[32m" << word[i] << "\033[0m ";
            }
            else if (letterCorrection[i] == 1)
            {
                std::cout << "\033[33m" << word[i] << "\033[0m ";
            }
            else
            {
                std::cout << "_ ";
            }
        }
        std::cout << "and this is your attempt number " << attemptNumber << std::endl;
        std::cout << "so far you used letters: ";
        displayUsedLetters();
    }

    void displayWordLength(Word wordToGuess) {
        std::cout << "Today's word to guess is: ";

        for (int i = 0; i < wordToGuess.length(); i++)
        {
            std::cout << "_ ";
        }
        std::cout << "(" << wordToGuess.length() << ") letters long, please input your guess below\n";
    }
};