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
    char symbol;
    int size;
    int numberPerPlayer;
    int healthLeft;
    bool bisPlaced;
    bool bisDead;
    std::vector<int> v_xPos;
    std::vector<int> v_yPos;

};

#endif // SHIP_H
