#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game.h"

int main(){
// inirtialising to mt holes.
hole board[26][26];
reset(&board);\

char task[50];
printf("~|| TRIXT ||~\n~>player1 choose ur color[R/B]\n");
printf("~> ");
fgets(task,sizeof(task),stdin);
task[strcspn(task,"\n")]=0;
player *p1=malloc(sizeof(player));
player* p2= malloc(sizeof(player));
if (strcmp(task, "b") == 0 || strcmp(task, "B") == 0){
  
    p1->clr=2;
}
else if (strcmp(task,"r") == 0 || strcmp(task, "R") == 0){ 
    p1->clr=1;
}
else {
    p1->clr=1;
    printf("ur color is Red\n");
}
// assigning colors to players
if (p1->clr==1)p2->clr=2;
else if (p1->clr==2)p2->clr=1;

printf(" help - to view the commands\n");
printf(" exit - to exit the game\n");
printf(" resign - want to give up?\n");
printf(" pegin - to place the peg :: format- pegin row col\n");


// prev and curr for track the current player and the previous player
player* curr=p1;
player* prev=p2;

// interface keeps running till a player resigns or exit the game
while(1){
    if (prev==p2)curr=p1;
    if (prev==p1)curr=p2;
    printf("~>");
    fgets(task,sizeof(task),stdin);
    task[strcspn(task,"\n")]=0;
    char *cmd=strtok(task," ");
    
    if (strcmp(cmd,"pegin")==0 ){
        
        char *row= strtok(NULL," ");
        char *col = strtok(NULL," ");
        if ( row==NULL || col == NULL )
        {
            printf("!!! not a valid hole :)\n");
        }
        else{
            int r=atoi(row),c = atoi(col);
            updmove(&board,curr->clr,r,c);
            printf("\n");
            status(&board);
            printf("\n");
        } 
    }

    if (strcmp(cmd,"help")==0 ){
        printf(" exit - to exit the game\n");
        printf(" resign - want to give up?\n");
        printf(" pegin - to place the peg :: format- pegin row col\n");
    }
    
   
    if (strcmp(cmd,"resign")==0 ){
        if(curr->clr==1){
            printf("R resigned!\n");
            status(&board);
            printf(" B won :)\n");
        }
        else if (p1->clr==2){
            printf("B resigned!\n");
            status(&board);
            printf(" R won :)\n");
        }
        printf("~> Do u want to play again?[y/n]\n");
        char u;printf("~>"); scanf("%c",&u);
        if (u=='y' || u=='Y'){
            reset(&board);
            continue;
        }
        else {
            free(p1);
            free(p2);
            break;
        }
        
    } 
    if (strcmp(cmd,"exit")==0 ){
        if(curr->clr==1){
            printf("R resigned!\n");
            printf(" B won :)\n");
        }
        else if (p1->clr==2){
            printf("B resigned!\n");
            printf(" R won :)\n");
        }
        free(p1);
        free(p2);
        //and free all the mallocs
        break; 
    }



    prev=curr;
    
}
}