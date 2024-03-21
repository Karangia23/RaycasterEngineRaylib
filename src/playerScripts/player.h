#ifndef PLAYER_H_
#define PLAYER_H_

#include <raylib.h>

//Player struct for 2D map traversal
typedef struct Player {
    Vector2 position;
    Vector2 speed;
    float radius;
    float angle;
    int fieldOfView;
} Player;

//Initialize player character in the middle of the screen
void InitPlayer(int screenWidth, int screenHeight, Player *player);
//Update player movment durning update call
void UpdatePlayerMovement(Player *player, float maxSpeed, float accValue, float decValue);
//Handle player collisions with screen boundaries
void handlePlayerCollision(int screenWidth, int screenHeight, Player *player);

#endif