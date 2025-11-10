#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game.h"

int main(){
// inirtialising to mt holes.
hole board[26][26];
reset(&board);

char task[50];
printf("~|| TRIXT ||~\n~> choose ur color[R/B]\n");
printf("~> ");
fgets(task,sizeof(task),stdin);
task[strcspn(task,"\n")]=0;
player *p=malloc(sizeof(player));

if (strcmp(task, "b") == 0 || strcmp(task, "B") == 0){
  
    p->clr=2;
}
else if (strcmp(task,"r") == 0 || strcmp(task, "R") == 0){ 
    p->clr=1;
}
else {
    p->clr=1;
    printf("ur color is Red\n");
}


while(1){
    printf("~>");
    fgets(task,sizeof(task),stdin);
    task[strcspn(task,"\n")]=0;
    char *cmd=strtok(task," ");
    
    if (strcmp(cmd,"help")==0 ){
        printf(" status - displays the current state of board\n");
        printf(" exit - to exit the game\n");
        printf(" resign - if u want to give up\n");
        printf(" pegin - to place the peg :: format- pegin row col\n");
    }
    
    if (strcmp(cmd,"status")==0 ){
        status(&board);
    }
    if (strcmp(cmd,"exit")==0 ){
        printf(" u lose to me\n");
        free(p);
        //and free all the mallocs
        break; 
    }

    if (strcmp(cmd,"resign")==0 ){
        printf(" you resigned!\n");
        status(&board);
        printf(" I win :)\n");
        printf("~>");reset(&board);
        
    }

    if (strcmp(cmd,"pegin")==0 ){
        char *row=strtok(NULL," ");
        char *col = strtok(NULL," ");
        if ( row==NULL || col == NULL )
        {
            printf("!!! not a valid hole :)\n");
            continue;
        }
        int r=atoi(row),c = atoi(col);
        updmove(&board,p->clr,r,c);
    }
}
}