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




void reset(hole (*board)[26][26]);
void status(hole (*board)[26][26]);
int updmove(hole (*board)[26][26],int player,int row ,int col);














#endif