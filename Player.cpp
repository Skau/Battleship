#include <string>
#include "Player.h"


Player::Player()
{
    initializeShip("battleship",'B',4,1);
    initializeShip("cruiser",'C',3,2);
    initializeShip("destroyer",'D',2,3);
    initializeShip("submarine",'S',1,4);
}

void Player::initializeShip(std::string nameOfShip, char picture, int shipSize, int number)
{
    for (int i = 0; i < number; i++)
    {
        v_Ships.push_back(new Ship);
        if (i > 0)
        {
            std::string l = std::to_string(i+1);
            v_Ships.at(count)->name = nameOfShip+l;
        }
        else
        {
            v_Ships.at(count)->name = nameOfShip;
        }

        v_Ships.at(count)->symbol = picture;
        v_Ships.at(count)->size = shipSize;
        v_Ships.at(count)->numberPerPlayer = number;
        count++;
    }

    totalShips = v_Ships.size();
}

void Player::fireShot()
{
    std::cout << "Where do you want to shoot? Example:B3\n";
    std::cin >> yPos >> xPos;
}

char Player::getYPos()
{
    return yPos;
}

int Player::getXPos()
{
    return xPos;
}

