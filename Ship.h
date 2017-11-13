#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <vector>
class Ship
{
public:
    Ship();
    ~Ship();
    //variables
    std::string name;
    int healthLeft;
    int size;
    int numberPerPlayer;
    char symbol;
    bool bisPlaced;
    bool bisDead;
    std::vector<int> v_xPos;
    std::vector<int> v_yPos;

};

#endif // SHIP_H
