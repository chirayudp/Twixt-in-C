#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "game.h"

int main(){
hole board[24][24];

for (int i = 0; i < 24; i++)
{
    for (int j = 0; j < 24; j++){
        (board)[i][j].role==0;
    }
}
char cmd[20];
int st=1;
while(st){
    fgets(cmd,sizeof(cmd),stdin);
    cmd[strcspn(cmd,"\n")]=0;
    if (strcmp(cmd,"status")==0 ){
        status();
    }

}
}
