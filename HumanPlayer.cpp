#include "HumanPlayer.h"

void HumanPlayer::placeShips(bool bIsManualPlacement, int rows, int columns)
{
    //manual placement of ships
    if (bIsManualPlacement)
    {
        int input;
        bool direction;
        bool bisChoosing;
        map.printMap(1,rows,columns);
        //loops through all ships
        for (auto ship : v_Ships)
        {
            //works exactly like the automatic placement, only that here i am using input values instead of random values
            while (!ship->bisPlaced)
            {
                if (map.bIsPlacementGood==false){std::cout << "Space occupied\n";}
                std::cout << "Where do you want to place your " << ship->name << "? (Size of ship: " << ship->size << ")\n";
                std::cout << "Total number of this ship to place: " << ship->numberPerPlayer << ".\nExample of placement: B3\n";
                bisChoosing = true;
                while (bisChoosing)
                {
                    std::cin >> yPos >> xPos;
                    int ypos = yPos-97;
                    if (ypos < 0 || ypos > 9)
                    {
                        std::cout << "Wrong input, try again.\n";
                    }
                    else if (xPos < 0 || xPos > 9)
                    {
                        std::cout << "Wrong input, try again.\n";
                    }
                    else
                    {
                        bisChoosing = false;
                    }
                }

                if (ship->size > 1)
                {
                    std::cout << "1. Horizontal or 2. Vertical?: \n";
                    std::cin >> input;
                }
                if (input == 1){direction = true;}else{direction = false;}
                map.placeShipInMap(yPos,xPos,ship->symbol,direction,ship->size);
                if (map.bIsPlacementGood==true)
                {
                    int ypos = yPos-97;
                    for (int i = 0; i < ship->size; i++)
                    {
                        if (direction)
                        {
                            ship->v_yPos.push_back(ypos+i);
                            ship->v_xPos.push_back(xPos);
                        }
                        else
                        {
                            ship->v_xPos.push_back(xPos+i);
                            ship->v_yPos.push_back(ypos);
                        }
                    }
                    ship->bisPlaced = true;
                    system("cls");
                    map.printMap(1,rows,columns);
                }
            }
        }
    }
    //automatic placement of ships works exactly like the manual version, only with random numbers (this is the exact same code used for AiPlayer)
    else
    {
        bool direction;
        int randomNumber;
        for (auto ship : v_Ships)
        {
            if (!ship->bisPlaced)
            {
                do
                {
                    max = 1;
                    randomNumber = min + rand() % (( max - min ) + 1);
                    direction = randomNumber;
                    setYPos();
                    setXPos();
                    map.placeShipInMap(yPos,xPos,ship->symbol,direction,ship->size);
                } while (!map.bIsPlacementGood);
                int ypos = yPos-97;
                for (int i = 0; i < ship->size; i++)
                {
                    if (direction)
                    {
                        ship->v_xPos.push_back(xPos);
                        ship->v_yPos.push_back(ypos+i);
                    }
                    else
                    {
                        ship->v_xPos.push_back(xPos+i);
                        ship->v_yPos.push_back(ypos);
                    }

                }
                ship->bisPlaced = true;
            }
        }
    }
}

//sets the coordinates to fire at
void HumanPlayer::fireShot()
{
    bool bIsChoosing = true;
    int ypos;
    std::cout << "Where do you want to shoot? Example:B3\n";
    while (bIsChoosing)
    {

        std::cin >> yPos >> xPos;
        ypos = yPos-97;
        if ((ypos < 0 || ypos > 9) && (xPos < 0 || xPos > 9) )
        {
            std::cout << "Number too high / too low! Between A and J and 0 and 9 please.\n";
        }
        else
        {
            bIsChoosing = false;
        }
    }
}

void HumanPlayer::setYPos()
{
    int min = 0;
    int max = 9;

    yPos = min + rand() % (( max - min ) + 1);
    yPos = yPos+97;
}

void HumanPlayer::setXPos()
{
    int min = 0;
    int max = 9;

    xPos = min + rand() % (( max - min ) + 1);
}
