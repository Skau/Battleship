#include "AiPlayer.h"

//automatic placement of ships
void AiPlayer::placeShips()
{
    bool direction;
    int randomNumber;
    //loops through all ships in the vector, and places them
    for (auto ship : v_Ships)
    {
        //when it actually hits a ship that's been placed, go out of the loop
        if (!ship->bisPlaced)
        {
            //do while loop, used because the placement can be off.
            //it loops untl the placement is valid
            do
            {
                //sets random direction, getting either a 1 or a 0
                max = 1;
                randomNumber = min + rand() % (( max - min ) + 1);
                direction = randomNumber;
                //gets random x and y pos.
                setYPos();
                setXPos();
                //tries placing a ship using the x, y and direction (also using some of the ships stats)
                map.placeShipInMap(yPos,xPos,ship->symbol,direction,ship->size);
            } while (!map.bIsPlacementGood);
            //converting the char to an int to add into the ships placement vectors, so the ship knows where it is
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
//just sets x and y, then broadcasts the attempt
void AiPlayer::fireShot()
{
    setYPos();
    setXPos();

    std::cout << "\n\nAI shoots at " << getYPos() << getXPos() << ".\n";
}
//here i tried to implement a smartshot, but it is quiet complicated and not very well done (in my opinion).
//it works 90% of the time. it was still a pretty fun project to try, i learned a lot.
//SMART AI(tm)
void AiPlayer::smartShot()
{
    bool bIsChoosing = true;
//loops until the shot is legit
    while (bIsChoosing)
    {
        //if it actually killed something last round, it randomizes the variables (this is kinda overpowered, because the AI actually knows when it's done with a ship)
        //it was the only way I could think of.
        if (bKillLastRound)
        {
            setYPos();
            setXPos();
            bIsChoosing = false;
        }
        //if it hit in the last couple of rounds
        else if (bHitLastRound)
        {
            //shoots a specific direction relative to the last hit depending on how many rounds since the last hit
            //could have used a switch for this, but because of all the code i felt it was cleaner like this (probably wrong)
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
//sets y pos to a random letter by converting a random int to a char by adding 97
void AiPlayer::setYPos()
{
    max = 9;
    yPos = min + rand() % (( max - min ) + 1);
    yPos = yPos+97;
}
//sets a x pos
void AiPlayer::setXPos()
{
    max = 9;
    xPos = min + rand() % (( max - min ) + 1);
}


