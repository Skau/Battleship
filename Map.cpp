#include "Map.h"
#include <iostream>

Map::Map()
{

}

void Map::initializeMap(int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
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

bool Map::placeShotInMap(char yPos, int xPos)
{
    int ypos = yPos-97;
    //if the coordinates haven't been hit before
    if (!mapArea[xPos][ypos].bHasBeenShotAt)
    {
        //if theres a ship there
        if (mapArea[xPos][ypos].bIsShip)
        {
            //mark spot as a hit
            mapArea[xPos][ypos].element = hit;
            mapArea[xPos][ypos].bHasBeenShotAt = true;
            bIsHit = true;
            bIsHitShip = true;
            return true;
        }
        else
        {
            //mark spot as a miss
            mapArea[xPos][ypos].element = miss;
            mapArea[xPos][ypos].bHasBeenShotAt = true;
            bIsHit = true;
            bIsHitDefault = true;
            bIsHitShip = false;
            return false;
        }
    }
    else
    {
        //return false if it's already hit
        bIsHit = false;
        bIsHitAlready = true;
        bIsHitDefault = false;
        bIsHitShip = false;
        return false;
    }
}

void Map::printMap(bool printShips, int rows, int columns)
{
    std::cout << "     ";
    for (char i = 'A'; i < rows+65; i++)
    {
        std::cout << i << "   ";
    }
    std::cout << std::endl;
    std::cout << "  +";
    for (int i = 0; i < rows; i++)
    {
        std::cout << "----";
    }
    std::cout << "+\n";

    for (int i = 0; i < rows; i++)
    {
        std::cout << i << " |  ";
        for (int j = 0; j < columns; j++)
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
        std::cout << "\n  +";
        for (int i = 0; i < rows; i++)
        {
            std::cout << "----";
        }
        std::cout << "+\n";
    }
}



