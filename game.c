#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game.h"
void reset(hole (*board)[26][26]){
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            (*board)[i][j].role=0;
        }
    }
}

void updmove(hole (*board)[26][26],int player,int row ,int col){// pass argument as &board
    if (row >24 || col > 24 || row <1 || col <1){
        printf("!!! not a valid hole :)\n");
    }

    else (*board)[row][col].role = player;
    
    return ;
}   

void status(hole (*board)[26][26]){

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++){
            if((i==0 && j==0) || (i==0 && j==25) || (i==25 && j==0)||(i==25 && j==25))
                printf("+ ");
            else if(i==0 )printf("- ");
            else if(j==0)printf("| ");
            else if(i==25 )printf("- ");
            else if(j==25)printf("| ");
            else if(i>0 && i<25 &&j>0 && j<25){
                if ((*board)[i][j].role==0)printf(". ");
                else if ((*board)[i][j].role==1)printf("R ");
                else if ((*board)[i][j].role==2)printf("B ");  
            }
              
        }
        printf("\n");
    }

}


