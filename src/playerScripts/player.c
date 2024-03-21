#include"player.h"
#include"raymath.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define SPEEDMAX 200.0f
#define ACCELERATION 5.0f
#define DECCELERATION 2.0f

void InitPlayer(int screenWidth, int screenHeight, Player *player )
{
    player->position.x = (float)screenWidth / 2;
    player->position.y = (float)screenHeight / 2;
}

// void UpdatePlayerMovement(Player *player, float maxSpeed, float accValue, float decValue)
// {
//     player->position.x += GetFrameTime() * player->speed.x;

//     if (IsKeyDown(KEY_LEFT)) 
//     {        
//         player->speed.x -= accValue;
//         player->speed.x = MAX(player->speed.x, -maxSpeed);
//     }
//     else if (IsKeyDown(KEY_RIGHT))
//     {
//         player->speed.x  += accValue;
//         player->speed.x = MIN(player->speed.x, maxSpeed);
//     }
//     else
//     {
//         if(player->speed.x > 0)
//         {
//             player->speed.x -= decValue;
//             player->speed.x = MAX(0, player->speed.x);
//         }
//         else
//         {
//             player->speed.x += decValue;
//             player->speed.x = MIN(0, player->speed.x);
//         }
//     }

//     player->position.y += GetFrameTime() * player->speed.y;

//     if (IsKeyDown(KEY_UP)) 
//     {        
//         player->speed.y -= accValue;
//         player->speed.y = MAX(player->speed.y, -maxSpeed);
//     }
//     else if (IsKeyDown(KEY_DOWN))
//     {
//         player->speed.y  += accValue;
//         player->speed.y = MIN(player->speed.y, maxSpeed);
//     }
//     else
//     {
//         if(player->speed.y > 0)
//         {
//             player->speed.y -= decValue;
//             player->speed.y = MAX(0, player->speed.y);
//         }
//         else
//         {
//             player->speed.y += decValue;
//             player->speed.y = MIN(0, player->speed.y);
//         }
//     }

    // if (IsKeyDown(KEY_UP)) player->position.y -= 3;
    // if (IsKeyDown(KEY_DOWN)) player->position.y += 3;
// }

void handlePlayerCollision(int screenWidth, int screenHeight, Player *player)
{
    if(player->position.x + player->radius >= screenWidth) player->position.x = screenWidth-player->radius;
    if(player->position.x - player->radius <= 0) player->position.x = 0+player->radius;
    if(player->position.y + player->radius >= screenHeight) player->position.y = screenHeight-player->radius;
    if(player->position.y - player->radius <= 0) player->position.y = 0+player->radius;
}

void UpdatePlayerMovement(Player *player, float maxSpeed, float accValue, float decValue)
{
    

    if (IsKeyDown(KEY_LEFT)) 
    {        
        player->angle += 0.1;
        if(player->angle > 2*PI) player->angle = 0;

    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        player->angle -= 0.1;
        if(player->angle < 0) player->angle = 2*PI;
    }

    

    if (IsKeyDown(KEY_UP)) 
    {   
        player->speed.x += accValue*cos(player->angle);
        player->speed.y -= accValue*sin(player->angle);

        if((player->angle <= PI/2 && player->angle >= 0) ||(player->angle >= 3*PI/2 && player->angle <= 2*PI))
            player->speed.x = MIN(player->speed.x, maxSpeed);
        else
            player->speed.x = MAX(player->speed.x, -maxSpeed);

        if(player->angle >= 0 && player->angle <= PI)
            player->speed.y = MAX(player->speed.y, -maxSpeed);
        else
            player->speed.y = MIN(player->speed.y, maxSpeed);

    }
    else if (IsKeyDown(KEY_DOWN))
    {
        player->speed.y  += accValue*sin(player->angle);
        player->speed.x  -= accValue*cos(player->angle);

        if((player->angle <= PI/2 && player->angle >= 0) ||(player->angle >= 3*PI/2 && player->angle <= 2*PI))
            player->speed.x = MAX(player->speed.x, -maxSpeed);
        else
            player->speed.x = MIN(player->speed.x, maxSpeed);

        if(player->angle >= 0 && player->angle <= PI)
            player->speed.y = MIN(player->speed.y, maxSpeed);
        else
            player->speed.y = MAX(player->speed.y, -maxSpeed);
    }
    else
    {
        if(player->speed.y > 0)
        {
            player->speed.y -= decValue;
            player->speed.y = MAX(0, player->speed.y);
        }
        else
        {
            player->speed.y += decValue;
            player->speed.y = MIN(0, player->speed.y);
        }
        
        if(player->speed.x > 0)
        {
            player->speed.x -= decValue;
            player->speed.x = MAX(0, player->speed.x);
        }
        else
        {
            player->speed.x += decValue;
            player->speed.x = MIN(0, player->speed.x);
        }
    }
    player->position.x += GetFrameTime() * player->speed.x;
    player->position.y += GetFrameTime() * player->speed.y;
}

void raycastFromPlayer(Player *player)
{
    int mapX = (int)player->position.x;
    int mapY = (int)player->position.y;
    double sideDistX;
    double sideDistY;

}