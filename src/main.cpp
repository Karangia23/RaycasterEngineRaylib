#include <raylib.h>
#include <stdio.h>
#include "src\playerScripts\player.c"

int main()
{
    //--------------------- inits--------
    Color darkGreen = {20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    float maxSpeed = 200.0f;
    float acc = 20.0f;
    float decc = 5.0f;

    Player player = {0, 0,0,0,7.0f};

    InitPlayer(screenWidth, screenHeight, &player);
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    //--------------------- inits/--------
    //--------------------- mainLoop--------
    while (!WindowShouldClose())
    {   UpdatePlayerMovement(&player, maxSpeed, acc, decc);
        handlePlayerCollision(screenWidth, screenHeight, &player);
    //---------------------------drawing function 
        BeginDrawing();
        ClearBackground(darkGreen);
        DrawCircle(player.position.x, player.position.y, player.radius, WHITE);
        EndDrawing();
    }
    //--------------------- mainLoop--------
    CloseWindow();
    return 0;
}
