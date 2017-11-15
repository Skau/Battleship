#include "AiPlayer.h"

AiPlayer::AiPlayer()
{

}

void AiPlayer::placeShips()
{
    bool direction;

    for (auto ship : v_Ships)
    {
        if (!ship->bisPlaced)
        {
            do
            {
                max = 1;
                int randomNumber = min + rand() % (( max - min ) + 1);
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

void AiPlayer::fireShot()
{
    setYPos();
    setXPos();

    std::cout << "\n\nAI shoots at " << getYPos() << getXPos() << ".\n";
}

void AiPlayer::smartShot()
{
    bool bIsChoosing = true;

    while (bIsChoosing)
    {
        if (bKillLastRound)
        {
            setYPos();
            setXPos();
            bIsChoosing = false;
        }
        else if (bHitLastRound)
        {
            if (shotsSinceLastHit == 0)
            {
                yPos = lastHitYPos+1;
                xPos = lastHitXPos;
                int ypos = yPos-97;
                if ((ypos > -1 && ypos < 10) && (xPos > -1 && xPos < 10))
                {
                    bIsChoosing = false;
                    bShotHorizontalPositive = false;
                }
                else
                {
                    shotsSinceLastHit++;
                }
            }
            else if (shotsSinceLastHit == 1)
            {
                yPos = lastHitYPos-1;
                xPos = lastHitXPos;
                int ypos = yPos-97;

                if ((ypos > -1 && ypos < 10) && (xPos > -1 && xPos < 10))
                {
                    bIsChoosing = false;
                    bShotVerticalPositive = true;
                }
                else
                {
                    shotsSinceLastHit++;
                }
            }
            else if (shotsSinceLastHit == 2)
            {
                yPos = lastHitYPos;
                xPos = lastHitXPos+1;
                int ypos = yPos-97;
                if ((ypos > -1 && ypos < 10) && (xPos > -1 && xPos < 10))
                {
                    bIsChoosing = false;
                }
                else
                {
                    shotsSinceLastHit++;
                }
            }
            else if (shotsSinceLastHit == 3)
            {
                yPos = lastHitYPos;
                xPos = lastHitXPos-1;
                int ypos = yPos-97;
                if ((ypos > -1 && ypos < 10) && (xPos > -1 && xPos < 10))
                {
                    bIsChoosing = false;
                }
                else
                {
                    setYPos();
                    setXPos();
                    bShotHorizontalPositive = true;
                    bIsChoosing = false;
                }
            }
            else
            {
                setYPos();
                setXPos();
                bShotHorizontalPositive = true;
                bIsChoosing = false;
            }
        }
        else
        {
            setXPos();
            setYPos();
            bIsChoosing = false;
        }
    }
    std::cout << "\n\nAI shoots at " << getYPos() << getXPos() << ".\n";
}

void AiPlayer::setYPos()
{
    max = 9;
    yPos = min + rand() % (( max - min ) + 1);
    yPos = yPos+97;
}

void AiPlayer::setXPos()
{
    max = 9;
    xPos = min + rand() % (( max - min ) + 1);
}


