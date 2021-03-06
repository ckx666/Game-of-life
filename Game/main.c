#include "LifeGame.h"

int main() {
    static int end=0;
    static int i;
    static int new = 0;
    static char choice[10];
    static char ROWS2[100];
    static char COLS2[100];
    static char SPACE2[100];
    static char delaytime2[100];
    while(1) {
        printf("\nWelcome to Game of Life\n");
        printf("Please choose an option\n");
        printf("1) Create and run a new world\n");
        printf("2) Load and run an old world\n");
        printf("3) Leave\n");
        printf(" Option: ");
        static char option[100];
        scanf("%s", option);

        //1 start
        if (atoi(option) == 1) {
            if (new == 2) {
                printf("You have already created a new world\n");
            }
            else {

                while (1){
                    printf("\nPlease enter height of the new world: ");//rows
                    scanf("%s", ROWS2);
                    if (atoi(ROWS2)==0){
                        printf("invalid height. Please enter again");
                    } else if (atoi(ROWS2)<20){
                        printf("Too small. Please enter again");
                    }else if (atoi(ROWS2)>100){
                        printf("Too big. Please enter again");
                    } else{
                        ROWS=atoi(ROWS2);
                        break;
                    }
                }
                while (1){
                    printf("Please enter width of the new world: ");//cols
                    scanf("%s", COLS2);
                    if (atoi(COLS2)==0){
                        printf("invalid height. Please enter again");
                    } else if (atoi(COLS2)<20){
                        printf("Too small. Please enter again");
                    }else if (atoi(COLS2)>100){
                        printf("Too big. Please enter again");
                    } else{
                        COLS=atoi(COLS2);
                        break;
                    }
                }
                while (1){
                    printf("Please enter size of each cell: ");//size
                    scanf("%s", SPACE2);
                    if (atoi(SPACE2)==0){
                        printf("invalid height. Please enter again\n");
                    } else if (atoi(SPACE2)<1){
                        printf("Too small. Please enter again\n");
                    }else if (atoi(SPACE2)>50){
                        printf("Too big. Please enter again\n");
                    } else{
                        SPACE=atoi(SPACE2);
                        break;
                    }
                }
                while (1){
                    printf("Please enter delay time of each tep: ");//DELAY TIME
                    scanf("%s", delaytime2);
                    if (atoi(delaytime2)==0){
                        printf("invalid height. Please enter again\n");
                    } else if (atoi(delaytime2)<10){
                        printf("Too small. Please enter again\n");
                    }else if (atoi(delaytime2)>1000){
                        printf("Too big. Please enter again\n");
                    } else{
                        delaytime=atoi(delaytime2);
                        break;
                    }
                }



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
                while (1) {

                    printf("Do you want to set steps to evolve [yes/no]:\n ");//step
                    scanf("%s", choice);
                    if (strcmp(choice, "yes") == 0) {

                        while (1) {
                            printf("Please enter steps you want to evolve:\n ");//step
                            scanf("%s", step);
                            if (atoi(step) > 0) {
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
                                new = 1;
                                printf("You have successfully created a new world!\n");
                                end=2;
                                break;
                            } else {
                                printf("invalid step\n");
                            }
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
                        new = 1;
                        printf("You have successfully created a new world!\n");
                        end=2;
                    } else {
                        printf("Invalid option!\n ");
                    }
                    if (end==2){
                        break;
                    }

                }
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

                //initial array start
                int **temparr1 = NULL; //????????????????????????????????????int
                temparr1 = (int **) malloc(
                        sizeof(int *) * ROWS); //arr??????????????????????????????????????????????????????????????????int???????????????????????????????????????????????????????????????row???
                for (i = 0; i < ROWS; i++) //?????????????????????
                {
                    temparr1[i] = (int *) malloc(sizeof(int) * COLS); //????????????col???
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
                while (1) {

                    printf("Do you want to set steps to evolve [yes/no]:\n ");//step
                    scanf("%s", choice);
                    if (strcmp(choice, "yes") == 0) {

                        while (1) {
                            printf("Please enter steps you want to evolve:\n ");//step
                            scanf("%s", step);
                            if (atoi(step) > 0) {
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
                                new = 1;
                                printf("You have successfully run an old world!\n");
                                end=2;
                                break;
                            } else {
                                printf("invalid step\n");
                            }
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
                        new = 1;
                        printf("You have successfully run an old world!\n");
                        end=2;
                    } else {
                        printf("Invalid option!\n ");
                    }
                    if (end==2){
                        break;
                    }

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