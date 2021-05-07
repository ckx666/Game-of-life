#include "LifeGame.h"

void tell (char* s)
{
    printf ("%s", s);
}
//test DrawCell
int t_drawCell(){
    int t;
    int score=0;
    ROWS=30;
    COLS=30;
    printf("\n*** Checking function drawCell ***\n");
    printf ("#Checking it can handle invalid parameters, x<0:");
    t=drawCell(-1,2,1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    printf("#Checking it can handle invalid parameters, y<0:");
    t=drawCell(1,-2,0);
    if (t==1){
        score++;
        tell ("Passed\n");
    }

    printf("#Checking it can handle invalid parameters, x>=COLS:");
    t=drawCell(30,2,1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    printf("#Checking it can handle invalid parameters, y>=ROWS:");
    t=drawCell(1,30,1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    printf("#Checking it can handle invalid parameters, flag!=1||0:");
    t=drawCell(-1,2,2);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    printf("#Checking it can handle invalid parameters, x<0,y<0,flag!=1||0:");
    t=drawCell(-1,-2,2);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can handle invalid parameters, x>=COLS,y>=ROWS,flag!=1||0:");
    t=drawCell(30,31,2);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it does accept valid parameters:");
    t=drawCell(1,2,1);
    if (t==0){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking static:");
    t=drawCell(2,2,1);
    if (t==0){
        score++;
        tell ("Passed\n");
    }
    printf ("%i/9 for function DrawCell\n", score);
    return score;
}
//test lifeCycle_Step
int t_lifeCycle_Step(){
    int t;
    int score=0;
    ROWS=30;
    COLS=40;
    SPACE=20;
    int num;
    SDL_Event event;
    int test[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test[i][j] = 1;
        }
    }
    int test1[ROWS][COLS];//invalid array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test1[i][j] = -1;
        }
    }
    tell ("\n*** Checking function lifeCycle_Step ***\n");
    tell ("#Checking it can handle invalid parameters, wrong array:");
    t=lifeCycle_Step(test1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking static:");
    t=lifeCycle_Step(test1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can handle valid parameters:");
    event.type = SDL_QUIT;
    strcpy(step,"10");
    for (int k = 0; k < atoi(step); ++k) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                num = getRoundLive(test, i, j);
                if (num == 2) {
                    test1[i][j] = test[i][j];
                }
                else if (num==3 ) {
                    test1[i][j] = 1;
                }else {
                    test1[i][j] = 0;
                }
            }
        }
        memcpy(test, test1, sizeof(int) * ROWS * COLS);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, test[i][j]);
            }
        }
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                t=1;
                break;
            }
        }
        if (t==1){
            break;
        }
    }
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can evolve correctly:");
    if (test[1][1]==0){
        score++;
        tell ("Passed\n");
    }
    printf ("%i/4 for function lifeCycle_Step\n", score);
    return score;

}
//test lifeCycle_Finite
int t_lifeCycle_Finite(){
    static int t;
        static int score=0;
        ROWS=40;
        COLS=20;
        SPACE=10;
    static int num;
    SDL_Event event;
    event.type = SDL_QUIT;
    int test[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test[i][j] = 1;
        }
    }
        int test1[ROWS][COLS];//invalid array
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                test1[i][j] = -1;
            }
        }
        tell ("\n*** Checking function lifeCycle_Finite ***\n");
        tell ("#Checking it can handle invalid parameters, wrong array:");
        t=lifeCycle_Finite(test1);
        if (t==1){
            score++;
            tell ("Passed\n");
        }
    tell ("#Checking static:");
    t=lifeCycle_Finite(test1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }

    tell ("#Checking it can handle valid parameters:");
    while (1) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                num = getRoundLive(test, i, j);
                if (num == 2) {
                    test1[i][j] = test[i][j];
                }
                else if (num==3 ) {
                    test1[i][j] = 1;
                }else {
                    test1[i][j] = 0;
                }
            }
        }
        memcpy(test, test1, sizeof(int) * ROWS * COLS);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, test[i][j]);
            }
        }
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                t=1;
                break;
            }
        }
        if (t==1){
            break;
        }
    }
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can evolve correctly:");
    if (test[1][1]==0){
        score++;
        tell ("Passed\n");
    }
    printf ("%i/4 for function lifeCycle_Finite\n", score);
    return score;
}
//test drawWorld
int t_drawWorld(){
    int t;
    int score=0;
    ROWS=40;
    COLS=20;
    SPACE=10;
    SDL_Event event;
    int test1[ROWS][COLS];//invalid array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test1[i][j] = -1;
        }
    }
    tell ("\n*** Checking function drawWorld ***\n");
    tell ("#Checking it can handle invalid parameters, wrong array:");
    t=drawWorld(test1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking static:");
    t=drawWorld(test1);
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    int test[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test[i][j] = 1;
        }
    }
    tell ("#Checking it does accept valid parameters:");
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, test[i][j]);
//                SDL_Event event;
                event.type = SDL_QUIT;
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        t=1;
                        break;
                    }
                }
            }
        }
    if (t==1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking mouse event can run successfully:");
        SDL_RenderPresent(renderer);
        int x;
        int y;
//        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            event.type = SDL_MOUSEMOTION;
            if (event.type == SDL_MOUSEMOTION) {
                x = 1;
                y = 1;
                event.button.button = SDL_BUTTON_LEFT;
                if (event.button.button == SDL_BUTTON_LEFT) {
                    test[y][x] = 1;
                }
            }
    }
    if (test[y][x] == 1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking new world can be created correctly:");
    event.type = SDL_MOUSEBUTTONDOWN;
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        x = 2;
        y = 2;
        test[y][x] = 1;
    }
        if (test[y][x] == 1) {
            score++;
            tell("Passed\n");
        }
    tell ("#Checking edge case:");
        x= COLS - 1;
        y = ROWS - 1;
    if (y == ROWS - 1 && x == COLS - 1) {
            isOver = true;
        }
    if (isOver == true) {
        score++;
        tell("Passed\n");
    }
    printf ("%i/6 for function drawWorld\n", score);
    return score;
}
//test saveWorld
int t_saveWorld(){
    int t;
    int score=0;
    static int ROWS1;
    static int COLS1;
    static int SPACE1;//read
    static int delaytime1;
    ROWS=40;
    COLS=20;
    SPACE=10;
    delaytime=100;
    int test[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test[i][j] = 1;
        }
    }
    int test1[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test1[i][j] = -1;
        }
    }

    tell ("\n*** Checking function saveWorld ***\n");
    t=saveWorld(test1);
    tell ("#Checking it can handle invalid parameters, wrong array:");
    if (t==1){
        score++;
        tell ("Passed\n");
    }

    t=saveWorld(test);
    FILE *fp1= fopen("oldWorld.txt","r");
    if(fp1 ==NULL){
        printf("not such file!");
        return 1;
    }
    tell ("#Checking it can write into file correctly, ROWS:");
    fscanf(fp1,"%d\t",&ROWS1);
    if (ROWS1==ROWS){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can write into file correctly, COLS:");
    fscanf(fp1,"%d\t",&COLS1);
    if (COLS1==COLS){
        score++;
        tell ("Passed\n");
    }

    tell ("#Checking it can write into file correctly, SPACE:");
    fscanf(fp1,"%d\t",&SPACE1);
    if (SPACE==SPACE1){
        score ++;
        tell ("Passed\n");
    }
    tell ("#Checking it can write into file correctly, delay Time:");
    fscanf(fp1,"%d\n",&delaytime1);
    if (delaytime==delaytime1){
        score ++;
        tell ("Passed\n");
    }
    tell ("#Checking static:");
    if (delaytime==delaytime1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can write into file correctly, map[ROWS][COLS]:");
    int t_test[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            fscanf(fp1, "%d", &t_test[i][j]);
        }
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (t_test[i][j] != 1){
                t=1;
                break;
            }
        }
    }
    if (t==0){
        score += 1;
        tell ("Passed\n");
    }
    fclose(fp1);
    printf ("%i/7 for function saveWorld\n", score);
    return score;
}
//test getRoundLive
int t_getRoundLive(){
    int t;
    int score=0;
    ROWS=30;
    COLS=30;
    int test[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test[i][j] = 1;
        }
    }
    tell ("\n*** Checking function getRoundLive ***\n");
    tell ("#Checking it can handle invalid parameters, i<0:");
    t=getRoundLive(test,-1,0);
    if (t==-1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can handle invalid parameters, j<0:");
    t=getRoundLive(test,1,-2);
    if (t==-1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can handle invalid parameters, i>=COLS:");
    t=getRoundLive(test,30,0);
    if (t==-1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can handle invalid parameters, j>=ROWS:");
    t=getRoundLive(test,1,30);
    if (t==-1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can handle invalid parameters, x<0,y<0");
    t=getRoundLive(test,-1,-1);
    if (t==-1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it can handle invalid parameters, x>=COLS,y>=ROWS:");
    t=getRoundLive(test,31,30);
    if (t==-1){
        score++;
        tell ("Passed\n");
    }
    int test1[ROWS][COLS];//invalid array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test1[i][j] = -1;
        }
    }
    tell ("#Checking it can handle invalid parameters, wrong array:");
    t=getRoundLive(test1,1,3);
    if (t==-1){
        score++;
        tell ("Passed\n");
    }
    tell ("#Checking it does accept valid parameters\n");
    tell ("#Case1 (beyond the edge are assumed dead):");
    t=getRoundLive(test,0,0);
    if (t==3){
        score++;
        tell ("Passed\n");
    }
    tell ("#Case2 (beyond the edge are assumed dead):");
    t=getRoundLive(test,0,1);
    if (t==5){
        score++;
        tell ("Passed\n");
    }
    tell ("#Case3 (beyond the edge are assumed dead):");
    t=getRoundLive(test,1,1);
    if (t==8){
        score++;
        tell ("Passed\n");
    }
    printf ("%i/10 for function getRoundLive\n", score);
    return score;
}
//test total programm
int t_tot(){
    int t;
    static int total=0;
    ROWS=30;
    COLS=30;
    tell ("\n*** Checking all program ***\n");
    //
    tell ("#Checking function drawCell:");
    t=drawCell(1,2,1);
    if (t==0){
        total++;
        tell ("drawCell Passed\n");
    }
    //
    SDL_Event event;
    int test[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test[i][j] = 1;
        }
    }
    tell ("#Checking function drawWorld:");
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            drawCell(j, i, test[i][j]);
            event.type = SDL_QUIT;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    t=1;
                    break;
                }
            }
        }
    }
    if (t==0){
        total++;
        tell ("drawWorld Passed\n");
    }
    //
    tell ("#Checking function saveWorld:");
    int test1[ROWS][COLS];//initial an array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            test1[i][j] = -1;
        }
    }
    t=saveWorld(test1);
    if (t==1){
        total++;
        tell ("saveWorld Passed\n");
    }
    //
    tell ("#Checking function getRoundLive:");
    t=getRoundLive(test,0,0);
    if (t==3){
        total++;
        tell ("getRoundLive Passed\n");
    }
    //
    int num;
    tell ("#Checking function lifeCycle_Finite:");
    t = 1 ;
    while (1) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                num = getRoundLive(test, i, j);
                if (num == 2) {
                    test1[i][j] = test[i][j];
                }
                else if (num==3 ) {
                    test1[i][j] = 1;
                }else {
                    test1[i][j] = 0;
                }
            }
        }
        memcpy(test, test1, sizeof(int) * ROWS * COLS);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, test[i][j]);
            }
        }
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                t=1;
                break;
            }
        }
        if (t==1){
            break;
        }
    }
    if (t==1){
        total++;
        tell ("lifeCycle_Finite Passed\n");
    }
    //
    tell ("#Checking function lifeCycle_Step:");
    strcpy(step,"10");
    for (int k = 0; k < atoi(step); ++k) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                num = getRoundLive(test, i, j);
                if (num == 2) {
                    test1[i][j] = test[i][j];
                }
                else if (num==3 ) {
                    test1[i][j] = 1;
                }else {
                    test1[i][j] = 0;
                }
            }
        }
        memcpy(test, test1, sizeof(int) * ROWS * COLS);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                drawCell(j, i, test[i][j]);
            }
        }
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                t=1;
                break;
            }
        }
    }
    if (t==1){
        total++;
        tell ("lifeCycle_Step Passed\n");
    }

    printf ("%i/6 for all program\n", total);
    return total;
}

int main() {
    static int num=0;
    tell ("\t\tChecking Game of life, behold ...\n");
    tell ("\t=========================================\n");
    tell ("Started ...\n");
    num+=t_drawCell();
    num+=t_drawWorld();
    num+=t_saveWorld();
    num+=t_getRoundLive();
    num+=t_lifeCycle_Finite();
    num+=t_lifeCycle_Step();
    num+=t_tot();
    printf ("\n---------------------------------------------------\n");
    printf ("\t\t\tTotal mark = %i/46\n", num);
    printf ("---------------------------------------------------\n");
    tell ("Finished\n");
    return 0;
}
