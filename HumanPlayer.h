#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer();

    //functions
    void placeShips(bool bIsManualPlacement);
    void fireShot();

private:

    //these two functions are only used to get random numbers for the automatic placement of ships
    void setYPos();
    void setXPos();

    //variables
    std::string name = "Human";

};

#endif // HUMANPLAYER_H
