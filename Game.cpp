#include "Game.h"


Game::Game()
{

}

void Game::initializeGame()
{ 
    //human init
    human.initializeShip("battleship",'B',4,1);
    human.initializeShip("cruiser",'C',3,2);
    human.initializeShip("destroyer",'D',2,3);
    human.initializeShip("submarine",'S',1,4);
    human.map.initializeMap();

    //ai init
    ai.initializeShip("battleship",'B',4,1);
    ai.initializeShip("cruiser",'C',3,2);
    ai.initializeShip("destroyer",'D',2,3);
    ai.initializeShip("submarine",'S',1,4);
    ai.map.initializeMap();
    ai.placeShips();

    //automatic or manual placement of ships
    int input;
    std::cout << "Do you want to place your ships manually, or let the game do it for you?\nDon't worry, the computer won't remember where he placed your ships ;)\n";
    std::cout << "1. Manual\n";
    std::cout << "2. Automatic (Works fine 98% of the time)\n";
    std::cin >> input;
    if (input == 1) { human.placeShips(true); }
    else { human.placeShips(false); }

    //starts the gameloop
    gameLoop();

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

void Game::damageShip(bool bDidDamage, bool isPlayer, char yPos, int xPos)
{
    int ypos = yPos-97;
    //if true do damage
    if (bDidDamage)
    {
        // if it's the player that shot
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
                        ai.bHitLastRound = true;
                        ai.bKillLastRound = false;
                        //if the ships health is 0, mark it as dead
                        if (ship->healthLeft == 0)
                        {
                            ship->bisDead = true;
                            ai.bKillLastRound = true;
                            ai.bHitLastRound = false;
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
    bool bIsShooting;
    /************************   START OF GAMELOOP   ************************/
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
        std::cout << std::endl;
        std::cout << "AI have " << ai.getTotalShipsLeft() << " ships left.\n";
//        for (auto ship : ai.v_Ships)
//        {
//            if (!ship->bisDead)
//            {
//                std::cout << "Ship name: " << ship->name << ", health left: "  << ship->healthLeft << std::endl;
//            }
//        }
        //prints AI map
        std::cout << "\t\tAI map\n\n";
        ai.map.printMap(1);

        //human shoots first
        bIsShooting = true;
        while (bIsShooting)
        {
            //sets the coordinates you want to shoot
            human.fireShot();
            //places the shot in the map
            ai.map.placeShotInMap(human.getYPos(), human.getXPos());
            //if the spot is already been hit you can try again
            if (!ai.map.bIsHit)
            {
                bIsShooting = true;
                std::cout << "Already been fired at.\n";
            }
            //if the spot havent been hit already
            else
            {
                //if the spot was a ship, damage it
                if (ai.map.bIsHitShip)
                {
                    damageShip(ai.map.bIsHitShip, 1, human.getYPos(),human.getXPos());
                }
                //breaks you out of the loop
                bIsShooting = false;
            }
        }
        //if human is out of ships, break the loop (game is over)
        if (human.getTotalShipsLeft() == 0)
        {
            break;
        }
        //ai turn to shoot
        bIsShooting = true;
        while (bIsShooting)
        {
            //sets the coordinates the ai wants to hit
            ai.smartShot();
            //places the shot in the map
            if (!human.map.placeShotInMap(ai.getYPos(), ai.getXPos()))
            {
                ai.shotsSinceLastHit++;
            }
            else
            {
                ai.shotsSinceLastHit = 0;
            }
            //if the spot is already been hit, the ai tries again
            if (!human.map.bIsHit)
            {
                bIsShooting = true;
            }
            else
            {
                bIsShooting = false;
            }
        }
        //if the spot was a ship, damage it
        if (human.map.bIsHitShip)
        {
            damageShip(human.map.bIsHitShip, 0, ai.getYPos(),ai.getXPos());
            ai.lastHitXPos = ai.xPos;
            ai.lastHitYPos = ai.yPos;
        }
        //if the spot was a miss
        else
        {
            if (ai.bHitLastRound)
            {
                if (ai.bShotHorizontalPositive)
                {
                    ai.bShotHorizontalPositive = false;
                }
                else if (!ai.bShotHorizontalPositive)
                {
                    ai.bShotVerticalPositive = true;
                }
                else if (ai.bShotVerticalPositive)
                {
                    ai.bShotVerticalPositive = false;
                }
            }
        }
        //breaks out of the loop
        bIsShooting = false;

        //if ai is out of ships, break the loop (game is over)
        if (ai.getTotalShipsLeft() == 0)
        {
            break;
        }
    }
    /************************   END OF GAMELOOP   ************************/

    //check to see who won
    if (human.getTotalShipsLeft() == 0)
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
}
