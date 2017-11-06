#ifndef MAP_H
#define MAP_H
#include <iostream>

class Map
{
public:
    Map();


    void setInMap(char yPos, int xPos, char element);
    void printMap();

    char mapArea[10][10];

private:




};

#endif // MAP_H
