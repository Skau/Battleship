#include "Game.h"


Game::Game()
{
    initializeGame();
}

void Game::initializeGame()
{
    system("cls");
    human.map.printMap();
    placeShips();
}

void Game::placeShips()
{

}

void Game::gameLoop()
{
    bool bisChoosing = true;

    while (bisChoosing)
    {
        human.placeShips();
        human.fireShot();
        human.map.placeShotInMap(human.getYPos(), human.getXPos());
        system("cls");
        std::cout << "You have " << human.totalShips << " ships left.\n";
        human.map.printMap();
    }
}




//the game makes the map with default values
//9x9 grid where alle squares are empty
//initializes all variables for both players
//the player places the ships
//loops till the player is done
//the AI places the ships
//loops till the AI is done
//player starts
//enters a combination of a letter and a number (ex: B3)
//checks if its a legit coordinate on the board
//if it is:
//checks to see if it hits a ship
//if it does mark it as a hit
//if not mark it as a miss

//if its not legit, ask player to enter coords again
//when the player is done its the AI turn
//ai shoots on a square
//mark if hit or miss
//loop back to player
//when all spots where a ship is is marked as a hit the game is over
//ask to play again
//loop if so, else quit game
