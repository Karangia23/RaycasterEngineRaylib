#include"mapDrawer.h"
#include<raylib.h>
void DrawMap(Map map)
{
    for(int i=0; i<8; i++)
    {
        for(int j= 0; j<8; j++)
        {
            //DrawRectangle(j*map.blockSize, i*map.blockSize,map.blockSize,map.blockSize, BLACK);
            //DrawRectangle(1+j*map.blockSize, 1+i*map.blockSize,map.blockSize-1,map.blockSize-1, WHITE);
            DrawRectangle(j * map.mapScale * map.blockSize, i * map.mapScale * map.blockSize, map.mapScale * map.blockSize, map.mapScale * map.blockSize, BLACK);
            if(map.map[i][j] == 1)
            {
            DrawRectangle(1 + j * map.mapScale * map.blockSize, 1 + i * map.mapScale * map.blockSize, map.mapScale * map.blockSize - 1, map.mapScale * map.blockSize - 1, WHITE);
            }


        }
    }
}