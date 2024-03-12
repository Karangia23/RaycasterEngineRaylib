#include <raylib.h>
#include <stdio.h>
#include "./playerScripts/player.c"
#include "raycast.c"
#include "mapDrawer.c"
#include <math.h>
#include <raymath.h>

int main()
{
    //--------------------- inits--------
    Color darkGreen = {20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    float maxSpeed = 200.0f;
    float acc = 20.0f;
    float decc = 5.0f;

    Map map = {
        {
            {0,0,0,0,0,0,0,0},
            {0,1,0,0,0,0,0,0},
            {0,1,0,0,0,0,0,0},
            {0,1,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,1,0,1,0,0,1},
            {0,0,0,0,0,0,1,1},
        },
        10,
        5
    };

    Player player = {0, 0,0,0,7.0f, 0.0f};

    InitPlayer(screenWidth, screenHeight, &player);
    InitWindow(screenWidth, screenHeight, "Raycaster!");
    SetTargetFPS(60);
    //--------------------- inits/--------
    //--------------------- mainLoop--------
    while (!WindowShouldClose())
    {   UpdatePlayerMovement(&player, maxSpeed, acc, decc);
        handlePlayerCollision(screenWidth, screenHeight, &player);
    //---------------------------drawing function 
        BeginDrawing();
        ClearBackground(darkGreen);
        DrawMap(map);
        DrawCircle(player.position.x, player.position.y, player.radius, WHITE);
        EndDrawing();
    }
    //--------------------- mainLoop--------
    CloseWindow();
    return 0;
}
