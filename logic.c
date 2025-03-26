#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "logic.h"
#include "types.h"

//This file implement the game logic , including function to handle the gameplay

short int roll()
{
        return  rand()%6 + 1;      //roll the dice;
}
char Colours(short int i)
{
        switch(i)
        {
                case 0:
                    printf("Yellow");
                    break;
                case 1:
                    printf("Green ");
                    break;
                case 2:
                    printf("Blue  ");
                    break;
                case 3:
                    printf("Red   ");
                    break;
        }
}

short int movepiece(short int piece_location,short int player_approach, short int Dice_value)        //move piece and get moved location of piece
{
        short int e;
         if((piece_location >= 53) || ((piece_location + Dice_value >= player_approach) && (piece_location <= player_approach)))
         {
                         for(e=1;e<=Dice_value;e++)
                         {
                                if(piece_location + e == player_approach)
                                {
                                        piece_location = 53;
                                }
                                else if(piece_location >= 53  &&  piece_location < 59)
                                {
                                        piece_location=piece_location+1;
                                }
                         }
                         return piece_location;
         }
         else if(piece_location <= 52)
         {
                     piece_location= (piece_location + Dice_value) % 52;
                     return piece_location;
	 }
}
void function()
{
        short int i,j,k,max,max_value,r,approach;
        struct Player players[4];
        char colours[4]={'Y','G','B','R'};
        short int ap[4]={52,13,26,39};
        srand(time(NULL));

        for(i=0;i<4;i++)
        {
           players[i].colour=colours[i];
           players[i].start_location= i*13 + 2 ;
           players[i].approach=ap[i];

            for(j=0;j<4;j++)
            {
                    players[i].pieces[j].number= j + 1;
                    players[i].pieces[j].location=-1;
            }
        }
    rollAgain:

        for(i=0;i<4;i++)
        {
                players[i].r=roll();
                printf("%c   rolls  %hd\n",Colours(i),players[i].r);
        }
        printf("\n");
        max_value=players[0].r;                  //find a player rolled max dice value
        max=0;

        for(j=1;j<4;j++)
        {
                if(players[j].r>max_value)
                {
                     max_value=players[j].r;
                     max=j;
                }
        }
        for(k=max+1;k<=4;k++)
        {
                if(players[k].r==players[max].r)
                {
                    goto rollAgain;
                }
        }
        printf("%c   player has the highest roll and will begin the game  \n",Colours(max));

        short int     R,tos,pisame,pig,pih,pib,pi_same_cell,pigs[4],pibs[4],piboard[4],board,pre_location,winners,won[3];  //R : Dize value
        short int     g,t,kk,a,b,bb,m,mmm,f,ff,ww,vv,s,x,y,w,v,lpl,lp,klpl;   //board : pieces in the board ( moving )
        short int     safe[4]={2,15,28,41};                                        //pib : pieces in the base,         pih : pieces in the  home,      pig : pieces can move
        winners=0;
        i=max;
	j=0;
	g=0;


 while(winners<3)
 {
        printf("\n==============  Round  %hd =================================\n\n",++g);
        i=i%4;

   for(kk=0;kk<4;kk++)
   {
     for(t=0;t<3;t++)
     {
         R=roll();
         pig=0;
         pih=0;
         pib=0;
         board=0;

       for(m=0;m<4;m++)
       {
              if(players[i].pieces[m].location>-1 &&  players[i].pieces[m].location<59)
              {
                   piboard[board]=m;
                   ++board;

                      pisame=0;

                      for(mmm=0;mmm<4;mmm++)
                      {
                         if(mmm!=m)//check player can move any piece
                         {
                            if(movepiece(players[i].pieces[m].location,players[i].approach,R)==players[i].pieces[mmm].location
                               &&  players[i].pieces[mmm].location<59 || players[i].pieces[m].location+R>59 )
                            {
                                    ++pisame;
                            }
                         }
                      }
                     if(pisame==0)
                     {
                           pigs[pig]=m;
                           ++pig;
                     }

              }
              else if(players[i].pieces[m].location==-1)                // check number of pieces in the Base for current player
              {
                      pibs[pib]=m;
                      pib=pib+1;
              }
              else if(players[i].pieces[m].location==59)               // check number of pieces in the Home  for current player
              {
                      pih=pih+1;
              }
       }
        if(pih==4)
      {
         t=3;
      }
      else{
       printf("%c player rolled   %hd\n",Colours(i),R);
       if(R!=6 && pig==0)
       {
                 t=3;

       }
     else
     {
         if(pig>0)
         {
                 j=pigs[rand()%pig];
         }

         tos=rand()%2;
         //printf("%c player rolled   %hd\n",Colours(i),R);
         pre_location=players[i].pieces[j].location;

        if(pib>0 && R==6 && ((board==0 &&  players[i].pieces[j].location==-1) || (board>0 && tos==0)||(pig==0)))//a new piece move
        {
             for(ff=0;ff<=3;ff++)
             {
                    f=pibs[ff];

                    if(players[i].pieces[f].location==-1)
                    {
                             players[i].pieces[f].location=players[i].start_location;
                             ++board;
                             --pib;
                             printf("%c  moves   piece  %c%hd",Colours(i),players[i].colour,f+1);
                             printf(" Base to the starting point X [L%hd]\n",players[i].pieces[f].location);
                             printf("%c player now has %hd/4 on pieces on the board and %hd/4 pieces on the base\n",Colours(i),board,pib);
                             ff=4;
                    }
             }
	}
	  else if(pig>0 && (((R!=6 || (R==6 && tos==1)) && (players[i].pieces[j].location!=-1)) || board==4 || pib==0))//pieces move
        {

              if((players[i].pieces[j].location     >= 53)  ||
                ((players[i].pieces[j].location + R >= players[i].approach)  && (players[i].pieces[j].location     <= players[i].approach)))
              {
                   if(players[i].pieces[j].location+R>=players[i].approach)// pieces move throught the  home straight untill reach the Home
                    {
                         pre_location=players[i].pieces[j].location;

                         players[i].pieces[j].location=movepiece(players[i].pieces[j].location,players[i].approach,R);

                        printf("%c moves   piece  %c%hd   from location L%hd to ",Colours(i),players[i].colour,j+1,pre_location%53);

                         if(R!=6 && players[i].pieces[j].location!=59)
                         {
                                t=3;
                         }
			 if(players[i].pieces[j].location!=59)
			 {
                                printf("L%hd by %hd units\n",players[i].pieces[j].location-53,R);
			 }
			
                         if(players[i].pieces[j].location==59)
                         {
                                printf(" Home by %hd units",R);
                                ++pih;
                                --board;

                                if(pih==4)
                                {
					printf("\n");
                                        printf("%c  win\n",Colours(i));
                                        t=3;

                                        players[i].finished=59;

                                        won[winners]=i;
                                        ++winners;

                                        if(winners==3)                                      // game over when   winners == 3
                                        {
                                                winners=3;
                                                players[i].finished=59;
                                                for(winners=0;winners<3;winners++)
                                                {
                                                  if(winners==0)
                                                  {
                                                        printf("\nFirst place  : ");

                                                  }
                                                  else if(winners==1)
                                                  {
                                                          printf("Second place : ");
                                                  }
                                                  else if(winners==2)
                                                  {
							   printf("Third place  : ");
                                                  }
                                                  printf(" %c\n",Colours(won[winners]));
                                                }
                                                for(i=0;i<4;i++)
                                                {
                                                         if(players[i].finished!=59)
                                                         {
                                                             printf("Forth place  : ");
                                                             printf(" %c\n\n",Colours(i));
                                                         }
                                                }

                                                kk=4;
                                                printf("Game over !!! \n");
                                        }
                                }
                         }
                    }
              }
              else if(players[i].pieces[j].location <= 52)//pieces move 50 cells untill reach the approach cell
              {                                                                                                //and captures opposing player's piece
                     pre_location=players[i].pieces[j].location;
                     players[i].pieces[j].location = (players[i].pieces[j].location + R) % 52;
                    // players[i].pieces[j].location=movepiece(players[i].pieces[j].location,players[i].approach,R);
                     printf("%c moves   piece  %c%hd   from Location L%hd to L%hd by %hd units ",Colours(i),players[i].colour,j+1,pre_location,players[i].pieces[j].location,R);

                     a=i;
                     b=j;
                     pi_same_cell=0;

                     for(s=0;s<=3;s++)  //check pices in safe cells
                     {
                            if((players[a].pieces[b].location + R ) % 52==safe[s])
                            {
                                  s=4;
                                  x=4;
                            }
                     }
                     for(x=0;x<=3;x++)   //capturing prosess
                     {
                            if(a!=x)
                            {
                                 for(y=0;y<=3;y++)
                                 {
                                    if(a!=x && players[a].pieces[b].location==players[x].pieces[y].location)
                                    {
                                         ++pi_same_cell;

                                         if(pi_same_cell>1)
                                         {
                                               x=3;

                                         }
                                         else if(pi_same_cell==1)
                                         {
                                               w=x;
                                               v=y;
                                         }
                                    }
                                 }
                                 if(pi_same_cell==1)
                                 {
                                         ww=w;
                                         vv=v;
                                 }
                            }
                     }
                     if(pi_same_cell==1)  //captured piece return to the base
                     {
                                 players[ww].pieces[vv].location=-1;
                                 printf(", captures %c%hd, and return it to the base\n",players[ww].colour,vv+1);
                                 printf("%cplayer now has %hd/4 on the board and %hd/4 pieces on the base",Colours(i),board,pib);
                     }

                     if(R!=6)
                     {
                                 t=3;
                     }
                     printf("\n");
              }
              else if(R!=6 && pig==0)
              {
                      t=3;
              }
        }
        else if(R!=6 && pig==0 && players[i].pieces[j].location==-1)
        {
                t=3;
        }

       }
      }

     }

     i=(i+1)%4;
   }
        lpl=max;
       for(klpl=0; klpl<4;klpl++) //print locations of pieces
        {
             printf("\n==================================\n");
             printf("Location of pieces  ");
             printf("%c\n",Colours(lpl));
             printf("==================================\n");

             for(lp=0;lp<4;lp++)
             {
                    if(players[lpl].pieces[lp].location==-1)
                    {
                            printf("Piece %c%hd  - >  Base\n",players[lpl].colour,lp+1);
                    }

                    else if(players[lpl].pieces[lp].location==59)
                    {
                            printf("Piece %c%hd  - >  Home\n",players[lpl].colour,lp+1);
                    }

                    else if(players[lpl].pieces[lp].location>=53)
                    {
                            printf("Piece %c%hd  - >  ",players[lpl].colour,lp+1); 
			    printf("%c homepath L%hd\n",Colours(lpl),players[lpl].pieces[lp].location-53);
                    }
                    else if(players[lpl].pieces[lp].location<=52)
                    {
                            printf("Piece %c%hd  - >  L%hd\n",players[lpl].colour,lp+1,players[lpl].pieces[lp].location);
                    }
             }
             lpl=(lpl+1)%4;
        }
 }
}
