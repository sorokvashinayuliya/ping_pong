#pragma once
#include "C:\Users\79176\kfu_projects\pong\raylib\src\raylib.h"

class Paddle {
protected:
    float x, y;
    float width, height;
    int speed;

    void LimitMovement();

public:
    Paddle(float x, float y, float width, float height, int speed);
    virtual void Update() = 0;
    void Draw() const;
    Rectangle GetRect() const;
    float GetY() const;
    float GetHeight() const;
};

class FirstPaddle : public Paddle {
public:
    FirstPaddle(float x, float y);
    void Update() override;
};

class SecondPaddle : public Paddle {
public:
    SecondPaddle(float x, float y);  
    void Update() override;
};

class ThirdPaddle : public Paddle {
public:
    ThirdPaddle(float x, float y);  
    void Update() override;
};

class FourthPaddle : public Paddle {
public:
    FourthPaddle(float x, float y);  
    void Update() override;
};