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

int updmove(hole (*board)[26][26],int player,int row ,int col){// pass argument as &board
    if (row >24 || col > 24 || row <1 || col <1 ||(row==1 && col==1) || (row==1 && col==24) || (row==24 && col==1)||(row==24 && col==24)){
        printf("!!! not a valid hole :)\n");
        return 0;
    }
    if ((*board)[row][col].role != 0)
    {
        printf("!!! sorry hole not available :)\n");
        return 0;
    }
    if(row==1){
        (*board)[0][col].role=player;
    }
    else if(col ==1){
        (*board)[row][0].role=player;
    }
    else if(row == 24){
        (*board)[25][col].role=player;
    }
    else if(col ==24){
        (*board)[row][25].role=player;
    }
    (*board)[row][col].role = player;
    
    return 1;
}   

void status(hole (*board)[26][26]){

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++){
            if((i==1 && j==1) || (i==1 && j==24) || (i==24 && j==1)||(i==24 && j==24))printf("+ ");
            
            else if(i==0 || i==25){
                if((i==0 && j==0) || (i==0 && j==1)|| (i==0 && j==24) ||(i==25 && j==1) ||(i==25 && j==0) ||(i==25 && j==25)||(i==25 && j==24)||(i==0 && j==25))printf("  ");
                else {
                    if ((*board)[i][j].role==0)printf(". ");
                    else if ((*board)[i][j].role==1)printf("R ");
                    else if ((*board)[i][j].role==2)printf("B ");
                }
            }
            else if(j==25 || j==0 ){
                if((i==0 && j==0) || (i==0 && j==25) || (i==24 && j==25)||(i==1 && j==0)  || (i==25 && j==0) || (i==25 && j==25)||(i==25 && j==0) || (i==0 && j==25) ||(i==24 && j==0)||(i==1 && j==25)||(i==0 && j==25))printf("  ");
                else {
                    if ((*board)[i][j].role==0)printf(". ");
                    else if ((*board)[i][j].role==1)printf("R ");
                    else if ((*board)[i][j].role==2)printf("B ");
                }
            }
            else if(i==1 )printf("- ");
            else if(j==1)printf("| ");
            else if(i==24 )printf("- ");
            else if(j==24)printf("| ");
            else if(i>1 && i<24 &&j>1 && j<24){
                if ((*board)[i][j].role==0)printf(". ");
                else if ((*board)[i][j].role==1)printf("R ");
                else if ((*board)[i][j].role==2)printf("B ");  
            }
              
        }
        printf("\n");
    }

}


