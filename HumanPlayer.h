#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer();

    void placeShips();
};

#endif // HUMANPLAYER_H
