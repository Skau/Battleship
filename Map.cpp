#include "Map.h"
#include <iostream>

//initalizes an array with blanks
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
//this is the function that both the human and ai uses for placing their ships
//it basically starts by checking if theres a ship there.
//then it iterates through which direction to place the ship by counting
//from the location the user wants to place their ships
//if the ship cannot fit in a specific location, it tries placing it the other way
//it works fine in 95% of scenarios.
//it's not the best solutions
void Map::placeShipInMap(char yPos, int xPos, char element, bool direction, int size)
{
    int ypos = yPos-97;
    int count = 0;

    //used for horizontal placement
    if (direction)
    {
        //loop depends on the ships size
        for (int i = 0; i < size; i++)
        {   //if theres no ship there
            if ((!mapArea[xPos][ypos+i].bIsShip) && (mapArea[xPos][ypos+i].element == defaultSpace))
            {
                //increment the counter
                if (ypos+i < 11)
                {
                    count++;
                }
            }
        }
        //if the count is the same as the ship
        if (count == size)
        {
            //place the ship
            for (int i = 0; i < size; i++)
            {
                mapArea[xPos][ypos+i].element = element;
                mapArea[xPos][ypos+i].bIsShip = true;
            }
            bIsPlacementGood = true;
        }
        //else try another direction
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
            //if it doesnt work, the player or ai has to try again
            else
            {
                bIsPlacementGood = false;
            }
        }
    }
    //used for vertical placement (exact same as above)
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

//prints the map
//i tried my best to use as many loops as possible during printing
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
            //if it's the humans map, print the ships too
            if (printShips)
            {
                std::cout << mapArea[i][j].element << " | ";
            }
            //if it's the computers map, print only the hits and misses
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



