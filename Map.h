#ifndef MAP_H
#define MAP_H
#include <iostream>

class Map
{
public:
    Map();


    struct mapElements
    {
        char element;
        bool bIsShip;
        bool bIsPlayer;
        bool bHasBeenShotAt;
    };

    void placeShipInMap(char yPos, int xPos, char element, bool direction, int size, bool player);
    void placeShotInMap(char yPos, int xPos);
    void printMap();

    mapElements mapArea[10][10];
    bool bIsPlacementGood = true;




private:
    char defaultSpace = ' ';
    char hit = 'H';
    char miss = 'M';



};

#endif // MAP_H
