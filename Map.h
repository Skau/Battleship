#ifndef MAP_H
#define MAP_H
#include <iostream>

class Map
{
public:
    Map();

    //functions
    void initializeMap();
    bool placeShotInMap(char yPos, int xPos);
    void printMap(bool printShips);
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


    const int ROWS = 10;
    const int COLUMNS = 10;

    char defaultSpace = ' ';
    char hit = 'H';
    char miss = 'M';

    bool bIsHitDefault;
    bool bIsHitAlready;

};

#endif // MAP_H
