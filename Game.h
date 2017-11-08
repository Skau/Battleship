#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "AiPlayer.h"
#include "HumanPlayer.h"
#include "Map.h"
class Game
{
public:
    Game();

    AiPlayer ai;
    HumanPlayer human;

    void initializeGame();
    void damageShip(bool bDidDamage, bool isPlayer, char yPos, int xPos);
    void gameLoop();


private:
    int currentPlayer = 0;
    int inputX;
    char inputY;
    bool bIsShooting;
};

#endif // GAME_H
