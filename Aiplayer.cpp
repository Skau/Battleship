#include "AiPlayer.h"

AiPlayer::AiPlayer()
{

}

void AiPlayer::placeShips()
{
    for (auto ship : v_Ships)
    {
        if (!ship->bisPlaced)
        {
            min = 0;
            max = 1;
            int randomNumber = min + rand() % (( max - min ) + 1);
            bool direction = randomNumber;
            do
            {
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
        else { break; }
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
    min = 0;
    max = 9;
    yPos = min + rand() % (( max - min ) + 1);
    yPos = yPos+97;
}

void AiPlayer::setXPos()
{
    min = 0;
    max = 9;
    xPos = min + rand() % (( max - min ) + 1);
}


