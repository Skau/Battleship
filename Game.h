#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "AiPlayer.h"
#include "HumanPlayer.h"
#include "Map.h"
class Game
{
public:
    Game();

    AiPlayer ai;
    HumanPlayer human;
    Map map;

    void initializeGame();
    void gameLoop();

private:

    int inputX;
    char inputY;
    char hit = 'H';
    char miss = 'M';

};

#endif // GAME_H
