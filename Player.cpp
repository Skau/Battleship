#include <string>
#include "Player.h"

//used for both ai and human to initialize the ships
void Player::initializeShip(std::string nameOfShip, char picture, int shipSize, int number)
{
    //loops as many times as the total number of that ship is to be added
    for (int i = 0; i < number; i++)
    {
        //adds a new ship with the specified variables
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
//returns the y pos
char Player::getYPos()
{
    return yPos;
}
//returns the x pos
int Player::getXPos()
{
    return xPos;
}
//returns total number of ships left
int Player::getTotalShipsLeft()
{
    return totalShips;
}
//sets this everytime a ship dies
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

