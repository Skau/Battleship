#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{

}

void HumanPlayer::placeShips()
{
    int input;
    bool direction;
    bool bisChoosing;
    map.printMap(1);
    for (auto ship : v_Ships)
    {
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
                ship->bisHorizontal = direction;
                ship->bisPlaced = true;
                system("cls");
                map.printMap(1);
            }
        }
    }
    //         *********** FOR TESTING PURPOSES ***********
    //    for (auto ship : v_Ships)
    //    {
    //        while (!ship->bisPlaced)
    //        {
    //            int min = 1;
    //            int max = 2;
    //            int randomNumber = min + rand() % (( max - min ) + 1);
    //            bool direction = randomNumber;

    //            setYPos();
    //            setXPos();

    //            map.placeShipInMap(yPos,xPos,ship->symbol,direction,ship->size);
    //            if (map.bIsPlacementGood==true)
    //            {
    //                int ypos = yPos-97;
    //                for (int i = 0; i < ship->size; i++)
    //                {
    //                    if (direction)
    //                    {
    //                       ship->v_yPos.push_back(ypos+i);
    //                       ship->v_xPos.push_back(xPos);
    //                    }
    //                    else
    //                    {
    //                        ship->v_xPos.push_back(xPos+i);
    //                        ship->v_yPos.push_back(ypos);
    //                    }
    //                }
    //                ship->bisHorizontal = direction;
    //                ship->bisPlaced = true;
    //            }
    //        }
    //    }
}

//sets the coordinates to fire at
void HumanPlayer::fireShot()
{
    std::cout << "Where do you want to shoot? Example:B3\n";
    std::cin >> yPos >> xPos;
}

void HumanPlayer::setYPos()
{
    int min = 0;
    int max = 10;

    yPos = min + rand() % (( max - min ) + 1);
    yPos = yPos+97;
}

void HumanPlayer::setXPos()
{
    int min = 0;
    int max = 10;

    xPos = min + rand() % (( max - min ) + 1);
}
