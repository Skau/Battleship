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

    while (bPlayAgain)
    {
        game.gameLoop();
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
