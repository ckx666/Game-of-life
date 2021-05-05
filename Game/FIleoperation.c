#include "LifeGame.h"

int loadWorld(int ROWS, int COLS, int map1[ROWS][COLS]){

    int m;
    int n;
    FILE *fp1= fopen("oldWorld.txt","r");
    if(fp1 ==NULL){
        printf("not such file!");
        return 1;
    }
    fscanf(fp1,"%d\t",&m);
    fscanf(fp1,"%d\t",&m);
    fscanf(fp1,"%d\n",&n);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            map1[i][j] = 0;
        }
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            fscanf(fp1,"%d",&map1[i][j]);
        }
    }
    fclose(fp1);

    return 0;
}
int saveWorld(int map[ROWS][COLS]){

    char c='\n';
    FILE *fp= fopen("oldWorld.txt","w");
    if(fp ==NULL){
        printf("Cannot open!");
        return 1;
    }
    fprintf(fp,"%d\t",ROWS);
    fprintf(fp,"%d\t",COLS);
    fprintf(fp,"%d\n",SPACE);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            fprintf(fp,"%d\t",map[i][j]);
        }
        fprintf(fp,"%c",c);
    }

    fclose(fp);
    printf("succeed");
}