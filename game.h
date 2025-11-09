#ifndef GAME_H
#define GAME_H

typedef struct hole {
    int role;
    int pos_con[8][2];
    int nof_con;
} hole;

typedef struct move {
    int row,col;
    int plr;
    struct move* prev;
    struct move* next;
} move;

typedef struct player {
    int clr;
    struct player* head;
} player;





void status(hole (*board)[24][24]);
void updmove(hole (*board)[24][24],int player,int row ,int col);














#endif