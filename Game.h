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

    //functions
    void initializeGame();

private:

    //functions
    void gameLoop();
    void damageShip(bool bDidDamage, bool isPlayer, char yPos, int xPos);


    //variables
    int inputX;
    char inputY;

};

#endif // GAME_H
