#include "ball.h"

Ball::Ball(float x, float y, int radius, int speed) 
    : x(x), y(y), radius(radius), speed_x(speed), speed_y(speed) {}

void Ball::Draw() const {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Update() {
    x += speed_x;
    y += speed_y;
    
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
    }
}

void Ball::Reset() {
    x = 3*GetScreenWidth() / 4;
    y = GetScreenHeight() / 2;
    int speed_choices[2] = { -1, 1 };
    speed_x = BALL_SPEED * speed_choices[GetRandomValue(0, 1)];
    speed_y = BALL_SPEED * speed_choices[GetRandomValue(0, 1)];
}

bool Ball::CheckCollision(const Rectangle& rect) const {
    return CheckCollisionCircleRec(Vector2{x, y}, radius, rect);
}

void Ball::ReverseX() { speed_x *= -1; }

float Ball::GetX() const { return x; }
float Ball::GetY() const { return y; }
int Ball::GetRadius() const { return radius; }
int Ball::GetSpeedX() const { return speed_x; }