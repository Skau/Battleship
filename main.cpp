#include <iostream>
#include <ctime>
#include "Game.h"
#include "Map.h"

bool playAgain();

int main()
{
    srand(time(0));
    bool bPlayAgain = true;
    Game game;

    std::cout << "Welcome to Battleships!\n\n";
    while (bPlayAgain)
    {
        game.initializeGame();
        bPlayAgain = playAgain();
    }

    return 0;
}

bool playAgain()
{
    std::string input;

    std::cout << "Do you want to play again? (y/n)\n";
    std::cin >> input;

    if (input == "y" || input == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }

}


//CURRENT ISSUES IN DESCENDING ORDER OF IMPORTANCE (AKA FIX TOP ONE FIRST):
/*
 * Game seems to crash when you want to play again. Either it's something not being reset re-init and/or it's something not being initialized correctly on re-init.
 * Once in a while a ship that gets hit does not lose health. It always affects all the elements after the initial placement element. Aka never square 1 of a ship(placement square), but 2,3 and 4.
 * Need to implement Smart AI (that doesn't just shoot randomly). If AI gets a hit, he should shoot close to the place he hit next round.
*/
