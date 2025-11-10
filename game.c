#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game.h"
void reset(hole (*board)[24][24]){
    for (int i = 0; i < 24; i++){
        for (int j = 0; j < 24; j++){
            (*board)[i][j].role=0;
        }
    }
}

void updmove(hole (*board)[24][24],int player,int row ,int col){// pass argument as &board
    if (row >23 || col > 23 || row <0 || col <0){
        printf("!!! not a valid hole :)\n");
    }

    else (*board)[row][col].role = player;
    
    return ;
}   

void status(hole (*board)[24][24]){

    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 24; j++){
            if ((*board)[i][j].role==0)printf("_ ");
            else if ((*board)[i][j].role==1)printf("R ");
            else if ((*board)[i][j].role==2)printf("B ");    
        }
        printf("\n");
    }

}


