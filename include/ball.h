#pragma once
#include "C:\Users\79176\kfu_projects\pong\raylib\src\raylib.h"
#include "constants.h"

class Ball {
private:
    float x, y;
    int speed_x, speed_y;
    int radius;

public:
    Ball(float x, float y, int radius, int speed);
    void Draw() const;
    void Update();
    void Reset();
    bool CheckCollision(const Rectangle& rect) const;
    void ReverseX();
    float GetX() const;
    float GetY() const;
    int GetRadius() const;
    int GetSpeedX() const;
};