#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Ship.h"

class Player
{
public:
    Player();

    void printStuff();

protected:
    Ship battleship; //size 4, 1 per player
    Ship cruiser;    // size 3, 2 per player
    Ship destroyer;  //size 2, 3 per player
    Ship submarine; //size 1, 4 per player
};

#endif // PLAYER_H
