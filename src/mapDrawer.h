#ifndef MAPDRAWER_H_
#define MAPDRAWER_H_

typedef struct Map {
    int map[8][8];
    int blockSize;
    int mapScale;
} Map;

void DrawMap(Map map);
#endif