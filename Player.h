#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Ship.h"
#include "map.h"

class Player
{
public:
    Player();

    Map map;

    //Functions
    void initializeShip(std::string nameOfShip, char picture, int shipSize, int number);
    char getYPos();
    int getXPos();
    int getTotalShipsLeft();
    void setTotalShipsLeft();

    //variables
    std::vector<Ship*> v_Ships;
    int xPos;
    char yPos;

protected:

    //variables
    int count = 0;
    int totalShips;

};

#endif // PLAYER_H
