//
// Created by l on 5/3/21.
//

#ifndef GAME_LIFEGAME_H
#define GAME_LIFEGAME_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>
#include <stdbool.h>


//SIZE OF MAP
int ROWS;
int COLS;
int SPACE;
char step[100000];
SDL_Renderer * renderer;
SDL_Window * window;
bool isOver;
int delaytime;

//draw allmap
extern int drawWorld(int map[ROWS][COLS]);
//draw a rect
extern int drawCell(int x,int y,int flag);
//lifeweek
extern int lifeCycle_Step(int map[ROWS][COLS]);
extern int lifeCycle_Finite(int map[ROWS][COLS]);
//get live number
extern int getRoundLive(int map[ROWS][COLS],int i,int j);
//saveoldworld
extern int saveWorld(int map[ROWS][COLS]);


#endif //GAME_LIFEGAME_H
