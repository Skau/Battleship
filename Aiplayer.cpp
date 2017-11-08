#include "AiPlayer.h"

AiPlayer::AiPlayer()
{

}

void AiPlayer::placeShips()
{
    for (auto ship : v_Ships)
    {
        while (!ship->bisPlaced)
        {
            int min = 1;
            int max = 2;
            int randomNumber = min + rand() % (( max - min ) + 1);
            bool direction = randomNumber;

            setYPos();
            setXPos();

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
            }
        }
    }
}

void AiPlayer::fireShot()
{
    setYPos();
    setXPos();

    std::cout << "\n\nAI shoots at " << getYPos() << getXPos() << ".\n";
}

void AiPlayer::setYPos()
{
    int min = 0;
    int max = 9;

    yPos = min + rand() % (( max - min ) + 1);
    yPos = yPos+97;
}

void AiPlayer::setXPos()
{
    int min = 0;
    int max = 9;

    xPos = min + rand() % (( max - min ) + 1);
}


