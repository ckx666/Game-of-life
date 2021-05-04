//
// Created by l on 5/3/21.
//

#ifndef GAME_LIFEGAME_H
#define GAME_LIFEGAME_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>
#include <stdbool.h>
#define ROWS 20
#define COLS 20
#define SPACE 30

//SIZE OF MAP
//int ROWS=0;
//int COLS=0;
//int SPACE=0;
char step[100000];
SDL_Renderer * renderer;
SDL_Window * window;
bool isSetover = false;


//draw allmap
void drawMap(int map[ROWS][COLS]);
//draw a rect
void drawRect(int x,int y,int flag);
//lifeweek
void lifeweek(int map[ROWS][COLS]);
//get live number
int getRoundLive(int map[ROWS][COLS],int i,int j);
//saveoldworld
int saveWorld(int map[ROWS][COLS]);
//readoldworld
int loadWorld(int map[ROWS][COLS]);
//creatnewworld
int createNewWorld();

#endif //GAME_LIFEGAME_H
