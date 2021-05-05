#include "LifeGame.h"
void drawRect(int x,int y,int flag){
    if (flag){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_Rect r1 = {x*SPACE,y*SPACE,SPACE,SPACE};
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(renderer,&r1);
    }
    else{
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_Rect r0 = {x*SPACE,y*SPACE,SPACE,SPACE};
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(renderer,&r0);
    }
    //line color
    SDL_SetRenderDrawColor(renderer,96,96,96,255);
    SDL_RenderDrawLine(renderer, x*SPACE, y*SPACE, x*SPACE+SPACE, y*SPACE);//ver
    SDL_RenderDrawLine(renderer, x*SPACE, y*SPACE, x*SPACE, y*SPACE+SPACE);//leftdown
    SDL_RenderDrawLine(renderer, x*SPACE+SPACE, y*SPACE, x*SPACE+SPACE, y*SPACE+SPACE);//rightdown
    SDL_RenderDrawLine(renderer, x*SPACE+SPACE, y*SPACE+SPACE, x*SPACE, y*SPACE+SPACE);//hori
}
void drawMap(int map[ROWS][COLS]){
    while(1){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawRect(j,i,map[i][j]);
                SDL_Event event;
                while(SDL_PollEvent(&event)){
                    if (event.type==SDL_QUIT){
                        return;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        int x;
        int y;
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            //printf("event type, %d\n",event.type);(event.type==)SDL_MOUSEBUTTONDOWN
            if (event.type==SDL_MOUSEMOTION) {

                x=event.motion.x/SPACE;
                y=event.motion.y/SPACE;
                map[y][x] = 1;

                if(y==ROWS-1&&x==COLS-1){
                    isSetover=true;
                    return;
                }
            }
            if (event.type==SDL_QUIT){
                return;
            }
        }
        SDL_Delay(10);
        if(isSetover) {
            break;
        }
    }
}