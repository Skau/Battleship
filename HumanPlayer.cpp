#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{

}

void HumanPlayer::placeShips()
{
    int input;
    bool direction;
    bool isPlayer = true;
    bool bisChoosing = true;

    for (auto ship : v_Ships)
    {
        bisChoosing = true;
        input = 0;
        while (bisChoosing)
        {
            if (map.bIsPlacementGood==false){std::cout << "Space occupied\n";}
            std::cout << "Where do you want to place your " << ship->name << "? (Size of ship: " << ship->size << ")\n";
            std::cout << "Total number of this ship to place: " << ship->numberPerPlayer << ".\nExample of placement: B3\n";
            std::cin >> yPos >> xPos;
            if (ship->size > 1)
            {
                std::cout << "1. Horizontal or 2. Vertical?: \n";
                std::cin >> input;
            }
            if (input == 1){direction = true;}else{direction = false;}
            map.placeShipInMap(yPos,xPos,ship->symbol,direction,ship->size,isPlayer);
            if (map.bIsPlacementGood==true)
            {
                bisChoosing=false;
                if (input == 1)
                {
                    ship->startXPos=xPos;
                    ship->endXPos=xPos+ship->size;
                }
                else
                {
                    ship->startYPos=yPos;
                    ship->endYPos=yPos+ship->size;
                }
                system("cls");
                map.printMap();
            }
            else
            {
                bisChoosing = true;
            }
        }
    }
}
