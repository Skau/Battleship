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
        bool bHasBeenShotAt;
    };

    void initializeMap();
    void placeShipInMap(char yPos, int xPos, char element, bool direction, int size);
    bool placeShotInMap(char yPos, int xPos);
    void printMap(bool printShips);

    mapElements mapArea[10][10];

    bool bIsPlacementGood = true;

private:
    char defaultSpace = ' ';
    char hit = 'H';
    char miss = 'M';



};

#endif // MAP_H
