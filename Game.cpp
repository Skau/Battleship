#include "Game.h"


Game::Game()
{
    initializeGame();
}

void Game::initializeGame()
{
    placeShips();
}

void Game::placeShips()
{
    int input;
    bool direction;
    bool isPlayer = true;
    bool bisChoosing = true;

    for (auto ship : human.v_Ships)
    {
        bisChoosing = true;
        input = 0;
        while (bisChoosing)
        {
            system("cls");
            map.printMap();
            if (map.bIsPlacementGood==false){std::cout << "Space occupied\n";}
            std::cout << "Where do you want to place your " << ship->name << "? (Size of ship: " << ship->size << ")\n";
            std::cout << "Total number of this ship to place: " << ship->numberPerPlayer << ".\nExample of placement: B3\n";
            std::cin >> inputY >> inputX;
            if (ship->size > 1)
            {
                std::cout << "1. Horizontal or 2. Vertical?: \n";
                std::cin >> input;
            }
            if (input == 1 && input == 0){direction = true;}else{direction = false;}
            map.placeShipInMap(inputY,inputX,ship->symbol,direction,ship->size,isPlayer);
            if (map.bIsPlacementGood==true)
            {
                bisChoosing=false;
                if (input == 1)
                {
                    ship->startXPos=inputX;
                    ship->endXPos=inputX+ship->size;
                }
                else
                {
                    ship->startYPos=inputY;
                    ship->endYPos=inputY+ship->size;
                }
            }
            else
            {
                bisChoosing=true;
            }
        }
    }
}

void Game::fireShot()
{
    std::cout << "Where do you want to shoot? Example:B3\n";
    std::cin >> inputY >> inputX;
    map.placeShotInMap(inputY,inputX);
}

void Game::gameLoop()
{
    bool bisChoosing = true;

    while (bisChoosing)
    {
        fireShot();
        system("cls");
        map.printMap();
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
