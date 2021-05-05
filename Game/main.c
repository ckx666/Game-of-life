#include "LifeGame.h"





char getstep(){
    char st[15];
    printf("input string:\n");
    fgets(st,15,stdin); /*stdin  键盘输入*/
    fputs(st,stdout);   /*stdout 标准输出*/
}

int main() {
    int end=0;
    int i;
    while(1){
        printf("\nWelcome to Game of Life\n");
        printf("Please choose an option\n");
        printf("1) Create a new world\n");
        printf("2) Run the new world\n");
        printf("3) Run an old world\n");
        printf("4) Leave\n");
        printf(" Option: ");
        char option[100];
        scanf("%s", option);
        if (atoi(option)==1) {
            printf("\nPlease enter height of the new world: ");//rows
            scanf("%d", &ROWS);
            printf("Please enter width of the new world: ");//cols
            scanf("%d", &COLS);
            printf("Please enter size of each cell: ");//size
            scanf("%d", &SPACE);
            printf("Please enter steps you want to evolve:\n ");//size
            scanf("%s", step);
            int ** temparr=NULL; //下面假设存储的数据类型为int
            temparr = (int **) malloc(sizeof(int *) * ROWS); //arr在这里可以看出成数组，数组的每个成员都是指向int类型的指针，这样每个指针指向的代表一行，共row行
            for (i = 0; i < ROWS; i++) //为每行申请空间
            {
                temparr[i] = (int *) malloc(sizeof(int) * COLS); //每一行有col列
            }
            int map[ROWS][COLS];//0 die 1 live
            for (int m = 0; m < ROWS; ++m) {
                for (int n = 0; n < COLS; ++n) {
                    map[m][n] = 0;
                }
            }
            if (strlen(step) == 0){
                if (SDL_Init(SDL_INIT_VIDEO)) {
                    SDL_Log("Can not init video, %s", SDL_GetError());
                    return 1;//init
                }
                window = SDL_CreateWindow("Game of life",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          COLS * SPACE, ROWS * SPACE,
                                          SDL_WINDOW_SHOWN);
                if (window == NULL) {
                    SDL_Log("Can not create window, %s", SDL_GetError());
                    return 2;//window
                }
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                if (renderer == NULL) {
                    SDL_Log("Can not create renderer,%s", SDL_GetError());
                }
                drawMap(map);
                lifeweek1(map);
                saveWorld(map);
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
            }else if (atoi(step) != 0){
                if (SDL_Init(SDL_INIT_VIDEO)) {
                    SDL_Log("Can not init video, %s", SDL_GetError());
                    return 1;//init
                }
                window = SDL_CreateWindow("Game of life",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          COLS * SPACE, ROWS * SPACE,
                                          SDL_WINDOW_SHOWN);
                if (window == NULL) {
                    SDL_Log("Can not create window, %s", SDL_GetError());
                    return 2;//window
                }
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                if (renderer == NULL) {
                    SDL_Log("Can not create renderer,%s", SDL_GetError());
                }
                drawMap(map);
                lifeweek(map);
                saveWorld(map);
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
            }else{
                printf("invalid step\n");
            }
        }
        else if (atoi(option)==2) {
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
                }
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
            else if(atoi(option)==4){

                printf("Thank you for playing the game!\n");
                printf("Goodbye!");
                end = 1;} else{

                printf("Sorry, the option you entered was invalid, please try again.\n");
                break;
        }
        if (end == 1)
            break;
    }

    return 0;

}