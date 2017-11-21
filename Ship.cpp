#include "Ship.h"
//initializer list for the ships, just to set some default values (these are overriden pretty quickly anyway)
Ship::Ship()
    : name(" "), symbol(' '), size(0), numberPerPlayer(0), healthLeft(0), bisPlaced(false), bisDead(false)
{
}
//clear the positions when the ship is deleted
Ship::~Ship()
{
    v_xPos.clear();
    v_yPos.clear();
}

