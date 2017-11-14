#ifndef APPLAYER_H
#define APPLAYER_H
#include "Player.h"

class AiPlayer : public Player
{
public:
    AiPlayer();

    //functions
    void placeShips();
    void fireShot();
    void smartShot();
    void setYPos();
    void setXPos();

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

    //variables
    std::string name = "Computer";
    int min = 0;
    int max = 9;

};

#endif // APPLAYER_H
