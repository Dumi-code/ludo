#include "types.h"
#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This file have the main function to execute the program and call the function defined in logic.c

int main()
{
        printf("There are 4  players(Red,Green,Yellow,Blue)   \n\n");
        printf("The Red player has   (04)  pieces named R1 R2 R3 R4\n");
        printf("The Green player has (04)  pieces named G1 G2 G3 G4\n");
        printf("The Yellow player has (04) pieces named Y1 Y2 Y3 Y4\n");
        printf("The Blue player has  (04)  pieces named B1 B2 B3 B4\n\n");

        function();
        return 0;
}
