#ifndef GAME_H
#define GAME_H
#include "AiPlayer.h"
#include "HumanPlayer.h"

class Game
{
public:
    Game();

    AiPlayer ai;
    HumanPlayer human;

};

#endif // GAME_H
