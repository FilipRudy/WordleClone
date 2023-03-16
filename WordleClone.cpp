#include <iostream>
#include "Wordle.h"


int main()
{
    WordList dupka;
    
    dupka.loadFromFile("wordList.txt");
    std::vector<Word> siu =  dupka.getWords();
    Wordle dupa(siu);
    std::cout<<dupa.isGuessCorrect("sisuaik");
    std::cout<<dupa.isGuessCorrect("penis");
    std::cout<<dupa.isGuessCorrect("dupka");

    for (const auto& word : siu) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}
