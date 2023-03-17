import Wordle;
#include <iostream>
#include <vector>

int main()
{
    WordList wordListGetter;
    Ui ui;
    Wordle game;

    wordListGetter.loadFromFile("wordList.txt");
    std::vector<Word> wordList = wordListGetter.getWords();
    Wordle dupa(wordList);
    std::cout<<dupa.isGuessCorrect("sisuaik");
    std::cout<<dupa.isGuessCorrect("penis");
    std::cout<<dupa.isGuessCorrect("dupka");


    std::cout << std::endl;
    std::cout << std::endl;

    while (game.getIsGameOver() == false) {


       std::cout << "\033[33mHello World!\033[0m" << std::endl;
       std::cout << "\033[32mHello World!\033[0m" << std::endl;
       
       Word word = game.generateWordToGuess(wordList);
       game.displayCorrectLetters(wordList[0]);
       ui.readGuess();

       std::cout << word << std::endl;

    }


}
