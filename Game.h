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
    void placeShips();
    void fireShot();
    void gameLoop();


private:
    int currentPlayer = 0;
    int inputX;
    char inputY;
};

#endif // GAME_H
