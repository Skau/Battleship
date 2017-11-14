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

    //SMARTAI variables
    bool bKillLastRound;
    bool bHitLastRound;
    bool bShotHorizontalPositive;
    bool bShotVerticalPositive;
    char lastYPos;
    int lastXPos;

private:
    //functions
    void setYPos();
    void setXPos();

    //variables
    std::string name = "Computer";
    int min = 0;
    int max = 9;

};

#endif // APPLAYER_H
