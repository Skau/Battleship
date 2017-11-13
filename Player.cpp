#include <string>
#include "Player.h"


Player::Player()
{

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
        v_Ships.at(count)->healthLeft = shipSize;
        v_Ships.at(count)->bisPlaced = false;
        v_Ships.at(count)->bisDead = false;
        v_Ships.at(count)->v_xPos.reserve(shipSize);
        v_Ships.at(count)->v_xPos.reserve(shipSize);

        count++;
    }

    totalShips = v_Ships.size();
}

char Player::getYPos()
{
    return yPos;
}

int Player::getXPos()
{
    return xPos;
}

int Player::getTotalShipsLeft()
{
    return totalShips;
}

void Player::setTotalShipsLeft()
{
    count = 0;
    for (auto ship : v_Ships)
    {
        if (!ship->bisDead)
        {
            count++;
        }
    }
    totalShips = count;
}

