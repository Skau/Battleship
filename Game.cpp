#include "Game.h"


Game::Game()
{

}

void Game::initializeGame()
{ 
    human.initializeShip("battleship",'B',4,1);
    human.initializeShip("cruiser",'C',3,2);
    human.initializeShip("destroyer",'D',2,3);
    human.initializeShip("submarine",'S',1,4);
    human.map.initializeMap();
    human.placeShips();

    ai.initializeShip("battleship",'B',4,1);
    ai.initializeShip("cruiser",'C',3,2);
    ai.initializeShip("destroyer",'D',2,3);
    ai.initializeShip("submarine",'S',1,4);
    ai.map.initializeMap();
    ai.placeShips();
}

void Game::damageShip(bool bDidDamage, bool isPlayer, char yPos, int xPos)
{
    int ypos = yPos-97;
    //if true do damage
    if (bDidDamage)
    {   // if it's the player that shot
        if (isPlayer)
        {
            //iterate through ai ships
            for (auto ship : ai.v_Ships)
            {
                //take the size to iterate through to find the location
                for (int i = 0; i < ship->size; i++)
                {
                    //if the shot location is a part of the ship
                    if (ship->v_xPos.at(i) == xPos && ship->v_yPos.at(i) == ypos)
                    {
                        //remove health
                        ship->healthLeft--;
                        //if the ships health is 0, mark it as dead
                        if (ship->healthLeft == 0)
                        {
                            ship->bisDead = true;
                        }
                        //break the loop because you can only hit one spot per shot
                        break;
                    }
                }
            }
            //sets the new total ships left
            ai.setTotalShipsLeft();
        }
        //if its the AI that shot
        else
        {
            //iterate through human ships
            for (auto ship : human.v_Ships)
            {
                //take the size to iterate through to find the location
                for (int i = 0; i < ship->size; i++)
                {
                    //if the shot location is a part of the ship
                    if (ship->v_xPos[i] == xPos && ship->v_yPos[i] == ypos)
                    {
                        //remove health
                        ship->healthLeft--;
                        //if the ships health is 0, mark it as dead
                        if (ship->healthLeft == 0)
                        {
                            ship->bisDead = true;
                        }
                        //break the loop because you can only hit one spot per shot
                        break;
                    }
                }
            }
            //sets the new total ships left
            human.setTotalShipsLeft();
        }
    }
}

void Game::gameLoop()
{
    bool bisPlaying = true;

    initializeGame();

    while (bisPlaying)
    {
        //prints players map first
        std::cout << "\t\tPlayer map\n\n";
        human.map.printMap(1);
        std::cout << "\nYou have " << human.getTotalShipsLeft() << " ships left.\n";
//        for (auto ship : human.v_Ships)
//        {
//            if (!ship->bisDead)
//            {
//                std::cout << "Ship name: " << ship->name << ", health left: "  << ship->healthLeft << std::endl;
//            }
//        }
        std::cout << "AI have " << ai.getTotalShipsLeft() << " ships left.\n\n";
//        for (auto ship : ai.v_Ships)
//        {
//            if (!ship->bisDead)
//            {
//                std::cout << "Ship name: " << ship->name << ", health left: "  << ship->healthLeft << std::endl;
//            }
//        }
        //prints AI map
        std::cout << "\t\tAI map\n\n";
        ai.map.printMap(0);
        //human shoots first
        human.fireShot();
        //places the element in the map, and damages the enemy ship if it's a hit
        damageShip(ai.map.placeShotInMap(human.getYPos(), human.getXPos()), 1, human.getYPos(),human.getXPos());
        if (human.getTotalShipsLeft() == 0)
        {
            break;
        }
        ai.fireShot();
        damageShip(human.map.placeShotInMap(ai.getYPos(), ai.getXPos()), 0, ai.getYPos(), ai.getXPos());
        if (ai.getTotalShipsLeft() == 0)
        {
            break;
        }
    }

    if (human.getTotalShipsLeft() != 0)
    {
        human.map.printMap(1);
        ai.map.printMap(1);
        std::cout << "You lost!\n";
    }
    else
    {
        human.map.printMap(1);
        ai.map.printMap(1);
        std::cout << "You won!\n";
    }

    for (unsigned int i = 0; i < human.v_Ships.size(); i++)
    {
        delete (human.v_Ships.at(i));
    }
    human.v_Ships.clear();
    for (unsigned int i = 0; i < ai.v_Ships.size(); i++)
    {
        delete (ai.v_Ships.at(i));
    }
    ai.v_Ships.clear();
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
