#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Ship.h"

class Player
{
public:
    Player();

    void initializeShip(std::string nameOfShip, char picture, int shipSize, int number);

    std::vector<Ship*> v_Ships;

private:
    int count = 0;
};

#endif // PLAYER_H
