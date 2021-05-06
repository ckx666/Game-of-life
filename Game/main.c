#include "LifeGame.h"

int main() {
    int end=0;
    int i;
    int new = 0;
    char choice[10];
    while(1) {
        printf("\nWelcome to Game of Life\n");
        printf("Please choose an option\n");
        printf("1) Create and run a new world\n");
        printf("2) Load and run an old world\n");
        printf("3) Leave\n");
        printf(" Option: ");
        char option[100];
        scanf("%s", option);

        //1 start
        if (atoi(option) == 1) {
            if (new == 1) {
                printf("You have already created a new world\n");
            }
            else {


            printf("\nPlease enter height of the new world: ");//rows
            scanf("%d", &ROWS);
            printf("Please enter width of the new world: ");//cols
            scanf("%d", &COLS);
            printf("Please enter size of each cell: ");//size
            scanf("%d", &SPACE);
            printf("Please enter delay time of each tep: ");//size
            scanf("%d", &delaytime);
            printf("Do you want to set steps to evolve [yes/no]:\n ");//step
            scanf("%s", choice);

//initial array start
            int **temparr = NULL;
            temparr = (int **) malloc(sizeof(int *) * ROWS);
            for (i = 0; i < ROWS; i++) {
                temparr[i] = (int *) malloc(sizeof(int) * COLS);
            }
            int map[ROWS][COLS];//0 die 1 live
            for (int m = 0; m < ROWS; ++m) {
                for (int n = 0; n < COLS; ++n) {
                    map[m][n] = 0;
                }
            }
            //initial array end

            if (strcmp(choice, "yes") == 0) {
                printf("Please enter steps you want to evolve:\n ");//step
                scanf("%s", step);
                if (atoi(step) != 0) {
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
                    drawWorld(map);
                    lifeCycle_Step(map);
                    saveWorld(map);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                } else {
                    printf("invalid step\n");
                }

            } else if (strcmp(choice, "no") == 0) {
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
                drawWorld(map);
                lifeCycle_Finite(map);
                saveWorld(map);
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
            } else {
                printf("Invalid option!\n ");
            }
            new = 1;
            printf("You have successfully created a new world!\n");
        }
    }
            //1 end

            //2 start
        else if (atoi(option)==2) {

//get information start
            FILE *fp1 = fopen("oldWorld.txt", "r");
            if (fp1 == NULL) {
                printf("not such file!");
                return 1;
            }

            fscanf(fp1, "%d\t", &ROWS);
            if (ROWS == '\0') {
                printf("There isn't an old world. Please create one first!\n");
                fclose(fp1);
            } else {
                fscanf(fp1, "%d\t", &COLS);
                fscanf(fp1, "%d\t", &SPACE);
                fscanf(fp1, "%d\n", &delaytime);


                printf("Do you want to set steps to evolve [yes/no]:\n ");//step
                scanf("%s", choice);
                //initial array start
                int **temparr1 = NULL; //下面假设存储的数据类型为int
                temparr1 = (int **) malloc(
                        sizeof(int *) * ROWS); //arr在这里可以看出成数组，数组的每个成员都是指向int类型的指针，这样每个指针指向的代表一行，共row行
                for (i = 0; i < ROWS; i++) //为每行申请空间
                {
                    temparr1[i] = (int *) malloc(sizeof(int) * COLS); //每一行有col列
                }
                int map1[ROWS][COLS];//0 die 1 live
                for (i = 0; i < ROWS; ++i) {
                    for (int j = 0; j < COLS; ++j) {
                        map1[i][j] = 0;
                    }
                }
                for (i = 0; i < ROWS; ++i) {
                    for (int j = 0; j < COLS; ++j) {
                        fscanf(fp1, "%d", &map1[i][j]);
                    }
                }
                //initial array end
                fclose(fp1);

                //test print
//                printf("%d\t", ROWS);
//                printf("%d\t", COLS);
//                printf("%d\n", SPACE);
//                for (i = 0; i < ROWS; ++i) {
//                    for (int j = 0; j < COLS; ++j) {
//                        printf("%d\t", map1[i][j]);
//                    }
//                    printf("\n");
//                }

                //test print
                if (strcmp(choice, "yes") == 0) {
                    printf("Please enter steps you want to evolve:\n ");//step
                    scanf("%s", step);
                    if (atoi(step) != 0) {
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
                        lifeCycle_Step(map1);
                        saveWorld(map1);
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                    } else {
                        printf("invalid step\n");
                    }

                } else if (strcmp(choice, "no") == 0) {
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
                    lifeCycle_Finite(map1);
                    saveWorld(map1);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                } else {
                    printf("Invalid option!\n ");
                }
            }
        }
//leave
            else if(atoi(option)==3){

                printf("Thank you for playing the game!\n");
                printf("Goodbye!");
                end = 1;
            }
            else{

                printf("Sorry, the option you entered was invalid, please try again.\n");
        }
        if (end == 1)
            break;
    }

    return 0;

}