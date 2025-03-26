#ifndef LOGIC_H
#define LOGIC_H
#include "types.h"

//This file contains the function definitions

short int roll();                   //roll the dize
char Colours(short int i);          //colours of player
short int movepiece(short int piece_location, short int player_approach, short int Dice_value);// piece movement throught the board (not from base)
void function();                    //initialeze players and their pieces and other events;          

#endif
