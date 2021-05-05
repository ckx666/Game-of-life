//
// Created by l on 5/3/21.
//

#ifndef GAME_LIFEGAME_H
#define GAME_LIFEGAME_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>
#include <stdbool.h>
//#define ROWS 50
//#define COLS 100
//#define SPACE 10

//SIZE OF MAP
int ROWS;
int COLS;
int SPACE;
char step[100000];
SDL_Renderer * renderer;
SDL_Window * window;
bool isSetover;

char getstep();
//draw allmap
void drawMap(int map[ROWS][COLS]);
//draw a rect
void drawRect(int x,int y,int flag);
//lifeweek
void lifeweek(int map[ROWS][COLS]);
void lifeweek1(int map[ROWS][COLS]);
//get live number
int getRoundLive(int map[ROWS][COLS],int i,int j);
//saveoldworld
int saveWorld(int map[ROWS][COLS]);
//readoldworld
int loadWorld(int ROWS, int COLS,int map1[ROWS][COLS]);


#endif //GAME_LIFEGAME_H
