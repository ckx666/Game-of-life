#include "LifeGame.h"
int saveWorld(int map[ROWS][COLS]){

    char c='\n';
    FILE *fp= fopen("oldWorld.txt","w");
    if(fp ==NULL){
        printf("Cannot open!");
        return 1;
    }
    fprintf(fp,"%d\t",ROWS);
    fprintf(fp,"%d\t",COLS);
    fprintf(fp,"%d\t",SPACE);
    fprintf(fp,"%d\n",delaytime);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            fprintf(fp,"%d\t",map[i][j]);
        }
        fprintf(fp,"%c",c);
    }

    fclose(fp);
    printf("Save file successfully!\n");
}