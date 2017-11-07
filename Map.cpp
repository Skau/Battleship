#include "Map.h"
#include <iostream>

Map::Map()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            mapArea[i][j].element = defaultSpace;
            mapArea[i][j].bHasBeenShotAt = false;
            mapArea[i][j].bIsPlayer = false;
            mapArea[i][j].bIsShip = false;
        }

    }
}

void Map::placeShipInMap(char yPos, int xPos, char element, bool direction, int size, bool player)
{
    bool horizontal = direction;
    bool isPlayer = player;
    int ypos = yPos-97;
    int count = 0;

    if (horizontal == true)
    {
        for (int i = 0; i < size; i++)
        {
            if (mapArea[xPos+i][ypos].element == defaultSpace)
            {
                count++;
            }
        }
        if (count == size)
        {
            for (int i = 0; i < size; i++)
            {
                mapArea[xPos+i][ypos].element = element;
                mapArea[xPos+i][ypos].bIsPlayer = isPlayer;
            }
            bIsPlacementGood = true;
        }
        else
        {
            count = 0;
            for (int i = 0; i < size; i++)
            {
                if (mapArea[xPos-i][ypos].element == defaultSpace)
                {
                    count++;
                }
            }
            if (count == size)
            {
                for (int i = 0; i < size; i++)
                {
                    mapArea[xPos-i][ypos].element = element;
                    mapArea[xPos-i][ypos].bIsPlayer = isPlayer;
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
            if (mapArea[xPos][ypos+i].element == defaultSpace)
            {
                count++;
            }
        }
        if (count == size)
        {
            for (int i = 0; i < size; i++)
            {
                mapArea[xPos][ypos+i].element = element;
                mapArea[xPos][ypos+i].bIsPlayer = isPlayer;
            }
            bIsPlacementGood = true;
        }
        else
        {
            count = 0;
            for (int i = 0; i < size; i++)
            {
                if (mapArea[xPos][ypos-i].element == defaultSpace)
                {
                    count++;
                }
            }
            if (count == size)
            {
                for (int i = 0; i < size; i++)
                {
                    mapArea[xPos][ypos-i].element = element;
                    mapArea[xPos][ypos-i].bIsPlayer = isPlayer;
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

void Map::placeShotInMap(char yPos, int xPos)
{
    int ypos = yPos-97;
    if (mapArea[xPos][ypos].element != defaultSpace)
    {
        if ((mapArea[xPos][ypos].element != hit) && (mapArea[xPos][ypos].element != miss))
        {
            mapArea[xPos][ypos].element = hit;
        }
        else
        {
            std::cout << "Already hit this spot.\n";
        }
    }
    else
    {
        mapArea[xPos][ypos].element = miss;
    }
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
            std::cout << mapArea[i][j].element << " | ";
        }
        std::cout << "\n   +---------------------------------------+" << std::endl;
    }

}



