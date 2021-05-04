#include "LifeGame.h"

int loadWorld(int map[ROWS][COLS]){
//    int b[2][3]={1};
    FILE *fp1= fopen("oldWorld.txt","r");
    if(fp1 ==NULL){
        printf("not such file!");
        return 1;
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            fscanf(fp1,"%d",&map[i][j]);
        }
    }
    fclose(fp1);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d\t",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int saveWorld(int map[ROWS][COLS]){
//    int a[2][3]={1,2,3,4,5,6};
    char c='\n';
    FILE *fp= fopen("oldWorld.txt","w");
    if(fp ==NULL){
        printf("Cannot open!");
        return 1;
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            fprintf(fp,"%d\t",map[i][j]);
        }
        fprintf(fp,"%c",c);
    }
    fclose(fp);
    printf("succeed");
}
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
void lifeweek(int map[ROWS][COLS]){
    int num;//store live cells around
    int temp[ROWS][COLS];// record
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            temp[i][j] = 0;
        }
    }
//    int step=1;
    while(1) {
//        for (int k = 0; k < step; ++k) {
        for (int i = 0; i < COLS; ++i) {
            for (int j = 0; j < ROWS; ++j) {
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
        for (int i = 0; i < COLS; ++i) {
            for (int j = 0; j < ROWS; ++j) {
                drawRect(j, i, map[i][j]);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    //printf("event type, %d\n",event.type);
                    if (event.type == SDL_QUIT) {
                        saveWorld(map);
                        return;
                    }
                }
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                saveWorld(map);
                return;
            }
        }
        SDL_Delay(10);
    }
//    }

}
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
                    //printf("event type, %d\n",event.type);
                    if (event.type==SDL_QUIT){
                        return;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);
        int x;
        int y;
        int c=0;
        SDL_Event event;
        SDL_Event event1;
//        while(SDL_PollEvent(&event1)) {
//            //printf("event type, %d\n",event.type);(event.type==SDL_MOUSEMOTION)
//            if (event1.type == SDL_MOUSEBUTTONDOWN) {
//                c = 1;
//                break;
//            }
//            if (event.type==SDL_QUIT){
//                return;
//            }
//
//        }
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
//                SDL_PollEvent(&event);
//                    if (event.type == SDL_MOUSEMOTION) {
//                        map[y][x] = 1;
//                    } else {
//                        map[y][x] = 0;
//                    }
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
int createNewWorld(){
    int map[ROWS][COLS];//0 die 1 live
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            map[j][i] = 0;
        }
    }
    if(SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Can not init video, %s",SDL_GetError());
        return 1;//init
    }
    window = SDL_CreateWindow("hello world",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              COLS*SPACE,ROWS*SPACE,
                              SDL_WINDOW_SHOWN);
    if(window==NULL){
        SDL_Log("Can not create window, %s",SDL_GetError());
        return 2;//window
    }
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (renderer==NULL){
        SDL_Log("Can not create renderer,%s",SDL_GetError());
    }

    drawMap(map);
    saveWorld(map);
//    lifeweek(map);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    loadWorld(map);
}

int main() {
    int end=0;
    int i;
    int ** arr=NULL; //下面假设存储的数据类型为int
    printf("Please enter height of the new world: ");//rows
    scanf("%d",&ROWS);
    printf("Please enter width of the new world: ");//cols
    scanf("%d",&COLS);
    printf("Please enter size of each cell: ");//size
    scanf("%d",&SPACE);
    arr = (int **)malloc(sizeof(int*)*ROWS); //arr在这里可以看出成数组，数组的每个成员都是指向int类型的指针，这样每个指针指向的代表一行，共row行
    for(i=0; i<ROWS; i++) //为每行申请空间
    {
        arr[i]=(int*)malloc(sizeof(int)*COLS); //每一行有col列
    }
//    while(1){
        int map[ROWS][COLS];//0 die 1 live
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                map[i][j] = 0;
            }
        }
//        printf("\nWelcome to Game of Life\n");
//        printf("Please choose an option\n");
//        printf("1) Create a new world\n");
//        printf("2) Run the new world\n");
//        printf("3) Run an old world\n");
//        printf("4) Leave\n");
//        printf(" Option: ");
//        char option[100];
//        scanf("%s", option);
//        switch (atoi(option))
//        {
//            case 1:
                if(SDL_Init(SDL_INIT_VIDEO)){
                    SDL_Log("Can not init video, %s",SDL_GetError());
                    return 1;//init
                }
                window = SDL_CreateWindow("Game of life",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          COLS*SPACE,ROWS*SPACE,
                                          SDL_WINDOW_SHOWN);
                if(window==NULL){
                    SDL_Log("Can not create window, %s",SDL_GetError());
                    return 2;//window
                }
                renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
                if (renderer==NULL){
                    SDL_Log("Can not create renderer,%s",SDL_GetError());
                }
                drawMap(map);
                saveWorld(map);
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
//                break;
//            case 2:
//                if(SDL_Init(SDL_INIT_VIDEO)){
//                    SDL_Log("Can not init video, %s",SDL_GetError());
//                    return 1;//init
//                }
//                window = SDL_CreateWindow("hello world",
//                                          SDL_WINDOWPOS_CENTERED,
//                                          SDL_WINDOWPOS_CENTERED,
//                                          COLS*SPACE,ROWS*SPACE,
//                                          SDL_WINDOW_SHOWN);
//                if(window==NULL){
//                    SDL_Log("Can not create window, %s",SDL_GetError());
//                    return 2;//window
//                }
//                renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
//                if (renderer==NULL){
//                    SDL_Log("Can not create renderer,%s",SDL_GetError());
//                }
//                loadWorld(map);
//                lifeweek(map);
//                SDL_DestroyRenderer(renderer);
//                SDL_DestroyWindow(window);
//                saveWorld(map);
//                break;
//            case 3:
//
//                if(SDL_Init(SDL_INIT_VIDEO)){
//                    SDL_Log("Can not init video, %s",SDL_GetError());
//                    return 1;//init
//                }
//                window = SDL_CreateWindow("hello world",
//                                          SDL_WINDOWPOS_CENTERED,
//                                          SDL_WINDOWPOS_CENTERED,
//                                          COLS*SPACE,ROWS*SPACE,
//                                          SDL_WINDOW_SHOWN);
//                if(window==NULL){
//                    SDL_Log("Can not create window, %s",SDL_GetError());
//                    return 2;//window
//                }
//                renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
//                if (renderer==NULL){
//                    SDL_Log("Can not create renderer,%s",SDL_GetError());
//                }
//                loadWorld(map);
//                lifeweek(map);
//                SDL_DestroyRenderer(renderer);
//                SDL_DestroyWindow(window);
//                saveWorld(map);
//
//                break;
//            case 4:
//                printf("Thank you for playing the game!\n");
//                printf("Goodbye!");
//                end = 1;
//                break;
//            default:
//                printf("Sorry, the option you entered was invalid, please try again.\n");
//                break;
//        }
//        if (end == 1)
//            break;
//    }

    return 0;

}