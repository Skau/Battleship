#ifndef MAP_H
#define MAP_H
#include <iostream>

class Map
{
public:
    Map();

    //functions
    void initializeMap(int rows, int columns);
    bool placeShotInMap(char yPos, int xPos);
    void printMap(bool printShips, int rows, int columns);
    void placeShipInMap(char yPos, int xPos, char element, bool direction, int size);

    //variables
    bool bIsPlacementGood = true;
    bool bIsHit;
    bool bIsHitShip;

private:

    //variables
    struct mapElements
    {
        char element;
        bool bIsShip;
        bool bHasBeenShotAt;
    }; mapElements mapArea[10][10];

    char defaultSpace = ' ';
    char hit = 'H';
    char miss = 'M';

    bool bIsHitDefault;
    bool bIsHitAlready;

};

#endif // MAP_H
