#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <bits/stdc++.h>
#include "Player.h"

using namespace std;

class Game
{
    public:
        Player players[2];
        Puzzle puzzle;
        Roue roue;
        string mode;
        int Current_Player;

        Game();
        void choix();
        void resoudre();
        int buyVoyelle();
        void consonne();

};

#endif // GAME_H_INCLUDED
