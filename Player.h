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
    void fireShot();
    char getYPos();
    int getXPos();

    //Variables
    std::vector<Ship*> v_Ships;
    int totalShips;

protected:
    int xPos;
    char yPos;

private:
    int count = 0;


};

#endif // PLAYER_H
