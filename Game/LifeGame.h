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
void drawWorld(int map[ROWS][COLS]);
//draw a rect
void drawCell(int x,int y,int flag);
//lifeweek
void lifeCycle_Step(int map[ROWS][COLS]);
void lifeCycle_Finite(int map[ROWS][COLS]);
//get live number
int getRoundLive(int map[ROWS][COLS],int i,int j);
//saveoldworld
int saveWorld(int map[ROWS][COLS]);



#endif //GAME_LIFEGAME_H
