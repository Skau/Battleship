#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <vector>
class Ship
{
public:
    Ship();
    std::string name;
    char symbol;
    bool bisHuman;
    bool bisHorizontal;
    bool bisPlaced;
    bool bisDead;
    int healthLeft;
    int size;
    int numberPerPlayer;

    std::vector<int> v_xPos;
    std::vector<int> v_yPos;

};

#endif // SHIP_H
