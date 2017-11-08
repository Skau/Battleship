#ifndef APPLAYER_H
#define APPLAYER_H
#include "Player.h"

class AiPlayer : public Player
{
public:
    AiPlayer();

    void placeShips();
};

#endif // APPLAYER_H
