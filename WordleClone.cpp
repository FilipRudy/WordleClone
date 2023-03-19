import Wordle;
#include <iostream>
#include <vector>

int main()
{
    WordList wordListGetter;
    Ui ui(0);
    Wordle game;

    wordListGetter.loadFromFile("wordList.txt");
    std::vector<Word> wordList = wordListGetter.getWords();

    while (game.getIsGameOver() == false) {
       Word wordToGuess = game.generateWordToGuess(wordList);
       ui.displayGameStart();
       ui.displayWordLength(wordToGuess);
       game.startGame(wordToGuess, ui, wordList, wordToGuess);
    }


}
