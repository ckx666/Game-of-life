#include "LifeGame.h"

extern int getRoundLive(int map[ROWS][COLS],int i,int j){
    if(i<0||j<0||i>=COLS||j>=ROWS){
        return -1;
    }
    for (int x = 0; x < ROWS; ++x) {
        for (int y = 0; y < COLS; ++y) {
            if (map[x][y] != 1&&map[x][y] != 0){
                return -1;
            }
        }
    }
    static int num = 0;
    if(i>0&&j>0&&map[i-1][j-1])num++;//up left
    if(i>0&&map[i-1][j])num++;
    if(i>0&&j<COLS-1&&map[i-1][j+1])num++;
    if(j>0&&map[i][j-1])num++;
    if(j<COLS-1&&map[i][j+1])num++;
    if(i<ROWS-1&&j>0&&map[i+1][j-1])num++;
    if(i<ROWS-1&&map[i+1][j])num++;
    if(i<ROWS-1&&j<COLS-1&&map[i+1][j+1])num++;
    return num;
}

extern int lifeCycle_Finite(int map[ROWS][COLS]) {//finite choice
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (map[i][j] != 1&&map[i][j] != 0){
                return 1;
            }
        }
    }
    static int num;//store live cells around
    int temp[ROWS][COLS];// record
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            temp[i][j] = 0;
        }
    }
    while (1) {

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
//get map cells how many live principle
                num = getRoundLive(map, i, j);
                if (num == 2) {
                    temp[i][j] = map[i][j];
                }
                else if (num==3 ) {
                    temp[i][j] = 1;
                }else {
                    temp[i][j] = 0;
                }
            }
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                //printf("event type, %d\n",event.type);
                if (event.type == SDL_QUIT) {
                    return 0;
                }
            }
        }

        memcpy(map, temp, sizeof(int) * ROWS * COLS);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, map[i][j]);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
//            saveWorld(map);
                        return 0;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
//            saveWorld(map);
                return 0;
            }
        }
        SDL_Delay(delaytime);
    }
}
int lifeCycle_Step(int map[ROWS][COLS]){//step choice
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (map[i][j] != 1&&map[i][j] != 0){
                return 1;
            }
        }
    }
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
                //get map cells how many live principle
                num = getRoundLive(map, i, j);
                if (num == 2) {
                    temp[i][j] = map[i][j];
                }
                else if (3 == num) {
                    temp[i][j] = 1;
                }else {
                    temp[i][j] = 0;
                }
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
                        return 0;
                    }
                }
            }
        }
        memcpy(map, temp, sizeof(int) * ROWS * COLS);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, map[i][j]);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
                        return 0;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 0;
            }
        }
        SDL_Delay(delaytime);
    }
    while (1) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, map[i][j]);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
                        return 0;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 0;
            }
        }
    }
}