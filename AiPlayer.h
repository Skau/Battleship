#ifndef APPLAYER_H
#define APPLAYER_H
#include "Player.h"

class AiPlayer : public Player
{
public:
    AiPlayer(){}
    //functions
    void placeShips();
    void smartShot();

    //SMARTAI variables
    bool bKillLastRound = false;
    bool bHitLastRound = false;
    bool bShotHorizontalPositive = true;
    bool bShotVerticalPositive = false;
    char lastHitYPos = ' ';
    char lastYPos = ' ';
    int lastHitXPos = 0;
    int lastXPos = 0;
    int shotsSinceLastHit = 0;

private:
    void fireShot();
    void setYPos();
    void setXPos();

};

#endif // APPLAYER_H
