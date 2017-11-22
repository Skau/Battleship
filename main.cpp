#include <iostream>
#include <ctime>
#include "Game.h"
#include "Map.h"

bool playAgain();

int main()
{
    //declaring variables
    srand(time(0));
    bool bPlayAgain = true;
    //instantiating the game object
    Game game;

    std::cout << "Welcome to Battleships!\n\n";
    //the main loop
    while (bPlayAgain)
    {
        game.initializeGame();
        bPlayAgain = playAgain();
    }
    return 0;
}
//function to ask if you want to play again
bool playAgain()
{
    std::string input;

    std::cout << "Do you want to play again? (y/n)\n";
    std::cin >> input;

    if (input == "y" || input == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }

}


//CURRENT ISSUES IN DESCENDING ORDER OF IMPORTANCE (AKA FIX TOP ONE FIRST):
/*
 * Game seems to crash when you want to play again. Either it's something not being reset re-init and/or it's something not being initialized correctly on re-init. I have yet to figure out what it is.
 * This bug happens everytime you answer yes to play again. It annoys me. It crashes because the game tries to access an index of some vector or array that's out of range, but I am certain all my containers are reset on new game.
 * Troubleshooting does not solve anything. I even tried debugging in VS2017. No luck.
 *
 * Once in a while a ship that gets hit does not lose health. It always affects all the elements after the initial placement element. Aka never square 1 of a ship(the placement square), but 2nd, 3rd and 4th.
 * The consequenses of this bug is that you will never be able to finish the game, as the game only ends when either all your ships or all AI's ships are marked dead. Not figured out what it is, as I cannot force it to happen.
 *
 * My patented (not) "SMART AI(tm)" system is implemented, but could be more optimized. I will still keep it in the game, as the buggy "SMART AI (tm)" system is still more fun than a fully randomized AI (aka just shoots wherever it wants regardless of ship locations).
 *
 * Game still sometimes hangs at the start. I know it's the do while loop when placing ships that for some reason once in a while never breaks. Not sure what the cause is, as I cannot force the bug to happen.
*/

