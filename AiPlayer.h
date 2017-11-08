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
    void setYPos();
    void setXPos();

    //variables
    std::string name = "Computer";
};

#endif // APPLAYER_H
