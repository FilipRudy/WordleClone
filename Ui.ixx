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
import :wordList;


export class Ui {
private:
    size_t attemptNumber;
    std::vector<char> usedLetters;

public:
    Ui(size_t m_attemptNumber) : attemptNumber(m_attemptNumber), usedLetters(28, ' ') {}


    static Word readGuess(std::vector<Word> m_words) {
        std::cout << "Enter a 5-letter word without numbers or special characters: ";
        Word guess;
        WordList wordList;
        std::regex pattern("[a-zA-Z]{5}");
        std::cin >> guess;
        if(!wordList.ifWordExist(guess, m_words))
        {   
            if (!std::regex_match(guess.getWord(), pattern))
            {
                std::cout << "\nError: Please enter a 5-letter word without numbers or special characters.\n";
                return readGuess(m_words);  // Call the function recursively to ask for another word
            }
            std::cout << "\nError: The word you input doesn't exist\n";
            return readGuess(m_words);  // Call the function recursively to ask for another word
        }
        // Check if the input matches the regular expression pattern
        
        if (!std::regex_match(guess.getWord(), pattern)) {
            
            std::cout << "\nError: Please enter a 5-letter word without numbers or special characters.\n";
            return readGuess(m_words);  // Call the function recursively to ask for another word
        }

        std::cout << "\n";
        return guess;
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

    char displayHighscores()
    {

        std::cout << "Would you like to see all records?" << std::endl;
        std::cout << "0 - don't display records" << std::endl;
        std::cout << "1 - display records" << std::endl;
        char input = readUserInput();

        std::cout << std::endl;
        return input;
    }

    char displaySaveHighscore()
    {
        
        std::cout << "Would you like to save your record?" << std::endl;
        std::cout << "0 - don't save the record" << std::endl;
        std::cout << "1 - save the record" << std::endl;
        char input = readUserInput();
        
        std::cout << std::endl;
        return input;
    }

    char readUserInput()
    {
        char input;
        std::cin >> input;
        if (input != '0' && input != '1')
        {
            std::cout << "Please input one of the correct numbers" << std::endl;
            std::cout << "0 - don't save the record" << std::endl;
            std::cout << "1 - save the record" << std::endl;
            readUserInput();
        }
        return input;
    }

    void displayWordLength(Word word, Word wordToGuess) {
        ++attemptNumber;
        if (attemptNumber != 6)
        {
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
                std::cout << "and this is your attempt number " << attemptNumber + 1 << std::endl;
                std::cout << "so far you used letters: ";
                displayUsedLetters();
        }
        
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