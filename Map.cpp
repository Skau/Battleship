#include "Map.h"
#include <iostream>

Map::Map()
{

}

void Map::initializeMap()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            mapArea[i][j].element = defaultSpace;
            mapArea[i][j].bHasBeenShotAt = false;
            mapArea[i][j].bIsShip = false;
        }
    }
}

void Map::placeShipInMap(char yPos, int xPos, char element, bool direction, int size)
{
    int ypos = yPos-97;
    int count = 0;

    //true = horizontal
    if (direction)
    {
        for (int i = 0; i < size; i++)
        {
            if ((!mapArea[xPos][ypos+i].bIsShip) && (mapArea[xPos][ypos+i].element == defaultSpace))
            {
                if (ypos+i < 11)
                {
                    count++;
                }
            }
        }
        if (count == size)
        {
            for (int i = 0; i < size; i++)
            {
                mapArea[xPos][ypos+i].element = element;
                mapArea[xPos][ypos+i].bIsShip = true;
            }
            bIsPlacementGood = true;
        }
        else
        {
            count = 0;
            for (int i = 0; i < size; i++)
            {
                if ((!mapArea[xPos][ypos-i].bIsShip) && (mapArea[xPos][ypos-i].element == defaultSpace))
                {
                    count++;
                }
            }
            if (count == size)
            {
                for (int i = 0; i < size; i++)
                {
                    mapArea[xPos][ypos-i].element = element;
                    mapArea[xPos][ypos-i].bIsShip = true;
                }
                bIsPlacementGood = true;
            }
            else
            {
                bIsPlacementGood = false;
            }
        }
    }
    else
    {
        count = 0;
        for (int i = 0; i < size; i++)
        {
            if ((!mapArea[xPos+i][ypos].bIsShip) && (mapArea[xPos+i][ypos].element == defaultSpace))
            {
                {
                    count++;
                }
            }
            if (count == size)
            {
                for (int i = 0; i < size; i++)
                {
                    mapArea[xPos+i][ypos].element = element;
                    mapArea[xPos+i][ypos].bIsShip = true;
                }
                bIsPlacementGood = true;
            }
            else
            {
                count = 0;
                for (int i = 0; i < size; i++)
                {
                    if ((!mapArea[xPos-i][ypos].bIsShip) && (mapArea[xPos-i][ypos].element == defaultSpace))
                    {

                        count++;

                    }
                }
                if (count == size)
                {
                    for (int i = 0; i < size; i++)
                    {
                        mapArea[xPos-i][ypos].element = element;
                        mapArea[xPos-i][ypos].bIsShip = true;
                    }
                    bIsPlacementGood = true;
                }
                else
                {
                    bIsPlacementGood = false;
                }
            }
        }
    }
}

bool Map::placeShotInMap(char yPos, int xPos)
{
    int ypos = yPos-97;
    //if the coordinates haven't been hit before
    if (!mapArea[xPos][ypos].bHasBeenShotAt)
    {
        //if theres a ship there
        if (mapArea[xPos][ypos].bIsShip)
        {
            //mark spot as a hit and return true
            mapArea[xPos][ypos].element = hit;
            mapArea[xPos][ypos].bHasBeenShotAt = true;
            return true;
        }
        else
        {
            //mark spot as a miss and return false
            mapArea[xPos][ypos].element = miss;
            mapArea[xPos][ypos].bHasBeenShotAt = true;
            return false;
        }
    }
    else
    {
        //return false if it's already hit
        std::cout << "Already been fired at.\n";
        return false;
    }
}

void Map::printMap(bool printShips)
{
    std::cout << "     A   B   C   D   E   F   G   H   I   J" << std::endl;
    std::cout << "   +---------------------------------------+" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << " " << i << " | ";
        for (int j = 0; j < 10; j++)
        {
            if (printShips)
            {
                std::cout << mapArea[i][j].element << " | ";
            }
            else
                if (mapArea[i][j].element == hit || mapArea[i][j].element == miss )
                {
                    std::cout << mapArea[i][j].element << " | ";
                }
                else
                {
                    std::cout << ' ' << " | ";
                }
        }
        std::cout << "\n   +---------------------------------------+" << std::endl;
    }

}



