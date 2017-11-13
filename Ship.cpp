#include "Ship.h"

Ship::Ship()
{
    name = " ";
    symbol = ' ';
    size = 0;
    numberPerPlayer = 0;
    healthLeft = 0;
    bisPlaced = false;
    bisDead = false;
}

Ship::~Ship()
{
    v_xPos.clear();
    v_yPos.clear();
}

