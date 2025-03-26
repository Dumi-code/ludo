#ifndef TYPES_H
#define TYPES_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "logic.h"

//This file contain data structeres

struct Piece
{
        short int  number;          //number of the piece
        short int location;         // current location of the piece
};
struct Player
{
        struct Piece pieces[4];     //Array of pieces for the player
        char colour;                //Player's color
        short int start_location;   //starting location of the player
        short int approach;         //Approach (entering cell of the  home straight)
        short int finished;         //indicates if the player has finished
        short int r;                //dice value of player (untill start the game)
};
struct ludoGame
{
        struct Player players[4];   //All players in the game
};                                                                                      


#endif

