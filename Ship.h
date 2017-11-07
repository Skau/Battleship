#ifndef SHIP_H
#define SHIP_H
#include <iostream>

class Ship
{
public:
    Ship();

    std::string name;
    char symbol;
    int healthLeft;
    int size;
    int numberPerPlayer;
    int startXPos, endXPos;
    int startYPos, endYPos;

};

#endif // SHIP_H
