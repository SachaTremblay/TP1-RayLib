#include "entrypoint.h"
#include "raylib.h"

#include <time.h>

#define RECT_SIZE 64
#define MAX_COL 14
#define MAX_ROW 14
#define WIN_W MAX_COL * RECT_SIZE
#define WIN_H MAX_ROW * RECT_SIZE
//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
bool zombies[MAX_ROW][MAX_COL] = {0}; 
void raylib_start(void){
    InitWindow(WIN_W,WIN_H,"Game Of Life");
    SetRandomSeed(time(NULL));
    for(int i= 0; i < MAX_ROW;++i){
        for(int z = 0; z < MAX_COL;++z ){
            zombies[i][z] = GetRandomValue(0,1);
        }
    }
    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(BLACK);
        for(int y = 0; y < MAX_ROW;y++){
            for(int x = 0; x < MAX_COL;++x){
                float offset = (y % 2 == 0) * RECT_SIZE;
                if(x % 2 == 0){
                    Rectangle get_rekt = CLITERAL(Rectangle){
                        .x=(float)(x*RECT_SIZE + offset),.y=(float)(y*RECT_SIZE),
                        .width=RECT_SIZE,.height=RECT_SIZE
                    };
                    DrawRectangleLinesEx(
                        get_rekt,
                        4,
                        RED
                    );
                }
                else{
                    Rectangle get_rekt = CLITERAL(Rectangle){
                        .x=(float)(x*RECT_SIZE - offset),.y=(float)(y*RECT_SIZE),
                        .width=RECT_SIZE,.height=RECT_SIZE
                    };
                    DrawRectangleLinesEx(
                        get_rekt,
                        4,
                        BLUE
                    );
                }
                SetRandomSeed(time(NULL));
                for(int i= 0; i < MAX_ROW;++i){
                    for(int z = 0; z < MAX_COL;++z ){
                        zombies[i][z] = GetRandomValue(0,1);
                    }
                }
                if(zombies[y][x]){
                    DrawRectangle(x*RECT_SIZE,y*RECT_SIZE,RECT_SIZE,RECT_SIZE,WHITE);
                }
            }
        }

        EndDrawing();
    }
    CloseWindow();
}