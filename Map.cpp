#include "Map.h"
#include <iostream>

Map::Map()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {

            mapArea[i][j] = ' ';
        }

    }
}

void Map::setInMap(char yPos, int xPos, char element)
{
    int ypos;
    if (yPos == 'a'){ypos = 0;}
    if (yPos == 'b'){ypos = 1;}
    if (yPos == 'c'){ypos = 2;}
    if (yPos == 'd'){ypos = 3;}
    if (yPos == 'e'){ypos = 4;}
    if (yPos == 'f'){ypos = 5;}
    if (yPos == 'g'){ypos = 6;}
    if (yPos == 'h'){ypos = 7;}
    if (yPos == 'i'){ypos = 8;}
    if (yPos == 'j'){ypos = 9;}

    mapArea[xPos][ypos] = element;
}

void Map::printMap()
{
    std::cout << "     A   B   C   D   E   F   G   H   I   J" << std::endl;
    std::cout << "   +---------------------------------------+" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << " " << i << " | ";
        for (int j = 0; j < 10; j++)
        {
            std::cout << mapArea[i][j] << " | ";
        }
        std::cout << "\n   +---------------------------------------+" << std::endl;
    }

}



