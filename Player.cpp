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
        v_Ships.at(count)->name = nameOfShip;
        v_Ships.at(count)->symbol = picture;
        v_Ships.at(count)->size = shipSize;
        v_Ships.at(count)->numberPerPlayer = number;
        count++;
    }
}

