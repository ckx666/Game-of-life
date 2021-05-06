#include "LifeGame.h"

int getRoundLive(int map[ROWS][COLS],int i,int j){
    int num = 0;
    if(i>0&&j>0&&map[i-1][j-1])num++;//up
    if(i>0&&map[i-1][j])num++;
    if(i>0&&j<COLS-1&&map[i-1][j+1])num++;
    if(j>0&&map[i][j-1])num++;
    if(j<COLS-1&&map[i][j+1])num++;
    if(i<ROWS-1&&j>0&&map[i+1][j-1])num++;
    if(i<ROWS-1&&map[i+1][j])num++;
    if(i<ROWS-1&&j<COLS-1&&map[i+1][j+1])num++;
    return num;
}
void lifeweek1(int map[ROWS][COLS]){//finite
    int num;//store live cells around
    int temp[ROWS][COLS];// record
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            temp[i][j] = 0;
        }
    }
    while (1) {

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
//get map cells how many live
                num = getRoundLive(map, i, j);
                if (3 == num) {
                    temp[i][j] = 1;
                } else if (num == 2) {
                    temp[i][j] = map[i][j];
                } else {
                    temp[i][j] = 0;
                }
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
                        return;
                    }
                }
            }
        }
        memcpy(map, temp, sizeof(int) * ROWS * COLS);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawRect(j, i, map[i][j]);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
//            saveWorld(map);
                        return;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
//            saveWorld(map);
                return;
            }
        }
        SDL_Delay(delaytime);
    }
}
void lifeweek(int map[ROWS][COLS]){//step
    int num;//store live cells around
    int temp[ROWS][COLS];// record
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            temp[i][j] = 0;
        }
    }
    for (int k = 0; k < atoi(step); ++k) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                //get map cells how many live
                num = getRoundLive(map, i, j);
                if (3 == num) {
                    temp[i][j] = 1;
                } else if (num == 2) {
                    temp[i][j] = map[i][j];
                } else {
                    temp[i][j] = 0;
                }
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
                        return;
                    }
                }
            }
        }
        memcpy(map, temp, sizeof(int) * ROWS * COLS);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawRect(j, i, map[i][j]);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
//                        saveWorld(map);
                        return;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
//                saveWorld(map);
                return;
            }
        }
        SDL_Delay(delaytime);
    }
    while (1) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawRect(j, i, map[i][j]);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
//                                saveWorld(map);
                        return;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
//                        saveWorld(map);
                return;
            }
        }
    }
//        } else {
//            printf("invalid step\n");
//        }
//    }
}
