#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer();
    std::string name = "Human";

    void placeShips();
    void fireShot();

    //testing
    void setYPos();
    void setXPos();
};

#endif // HUMANPLAYER_H
