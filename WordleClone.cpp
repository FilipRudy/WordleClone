import Wordle;
#include <iostream>
#include <vector>

int main()
{
    WordList wordListGetter;
    Ui ui(0);
    Wordle game;
    int attemptNumber = 0;

    wordListGetter.loadFromFile("wordList.txt");
    std::vector<Word> wordList = wordListGetter.getWords();

    while (game.getIsGameOver() == false) {
       Word wordToGuess = game.generateWordToGuess(wordList);
       ui.displayGameStart();
       ui.displayWordLength(wordToGuess);
      // std::cout << "\033[33mHello World!\033[0m" << std::endl;
       //std::cout << "\033[32mHello World!\033[0m" << std::endl;
       
       //game.displayCorrectLetters(wordList[0]);
       game.startGame(wordToGuess, ui);


    }


}
