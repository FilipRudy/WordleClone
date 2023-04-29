import Wordle;
#include <iostream>
#include <vector>

int main()
{
    WordList wordListGetter;
    Scoreboard highscoresGetter("highscoresList.txt");
    Ui ui(0);
    Wordle game;

    wordListGetter.loadFromFile("wordList.txt");
    std::vector<Word> wordList = wordListGetter.getWords();
    Word wordToGuess = game.generateWordToGuess(wordList);

    while (game.getIsGameOver() == false) {
        std::cout << wordToGuess;
       ui.displayGameStart();
       ui.displayWordLength(wordToGuess);
       game.startGame(wordToGuess, ui, wordList, wordToGuess);
       
    }
    Result result(ui.getAttemptNumber() + 1, wordToGuess, game.getIsGameWon());
    
    
    std::cout << result <<std::endl;
    if(game.getIsGameWon())
    highscoresGetter.addRecord(ui.getAttemptNumber() + 1, ui.displaySaveHighscore());
    highscoresGetter.showRecords(ui.displayHighscores());
}
