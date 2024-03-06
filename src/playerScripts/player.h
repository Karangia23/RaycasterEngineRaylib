#ifndef PLAYER_H_
#define PLAYER_H_

#include <raylib.h>

typedef struct Player {
    Vector2 position;
    Vector2 speed;
    float radius;
} Player;

void InitPlayer(int screenWidth, int screenHeight, Player *player);
void UpdatePlayerMovement(Player *player, float maxSpeed, float accValue, float decValue);
void handlePlayerCollision(int screenWidth, int screenHeight, Player *player);

#endif