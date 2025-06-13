#include "paddle.h"
#include "ball.h"
#include "C:\Users\79176\kfu_projects\pong\raylib\src\raylib.h"

void Paddle::LimitMovement() {
    y = (y < 0) ? 0 : (y > GetScreenHeight() - height) ? GetScreenHeight() - height : y;
}

Paddle::Paddle(float x, float y, float width, float height, int speed)
    : x(x), y(y), width(width), height(height), speed(speed) {}

void Paddle::Draw() const {
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8f, 0, WHITE);
}

Rectangle Paddle::GetRect() const {
    return Rectangle{x, y, width, height};
}

float Paddle::GetY() const { return y; }
float Paddle::GetHeight() const { return height; }

FirstPaddle::FirstPaddle(float x, float y) 
    : Paddle(x, y, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED) {}

void FirstPaddle::Update() {
    if (IsKeyDown(KEY_UP)) y -= speed;
    if (IsKeyDown(KEY_DOWN)) y += speed;
    LimitMovement();
}

SecondPaddle::SecondPaddle(float x, float y) 
    : Paddle(x, y, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED) {}

void SecondPaddle::Update() {
    if (IsKeyDown(KEY_A)) y -= speed;
    if (IsKeyDown(KEY_Z)) y += speed;
    LimitMovement();
}

ThirdPaddle::ThirdPaddle(float x, float y)
    : Paddle(x, y, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED) {}

void ThirdPaddle::Update() {
    if (IsKeyDown(KEY_F)) y -= speed;
    if (IsKeyDown(KEY_V)) y += speed;
    LimitMovement();
}

FourthPaddle::FourthPaddle(float x, float y)
    : Paddle(x, y, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED) {}

void FourthPaddle::Update() {
    if (IsKeyDown(KEY_K)) y -= speed;
    if (IsKeyDown(KEY_M)) y += speed;
    LimitMovement();
}