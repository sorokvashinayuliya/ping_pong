#include <iostream>
#include <string>
#include "ball.h"
#include "paddle.h" 
#include "game.h"
#include "manual_tests.h"

void TestBall() {
    std::cout << "=== Testing the ball ===" << std::endl;
    
    Ball ball(100, 100, 10, 5);
    
    if (ball.GetX() != 100 || ball.GetY() != 100) {
        std::cout << "ERROR: incorrect starting position" << std::endl;
    } else {
        std::cout << "SUCCESS: the initial position is correct" << std::endl;
    }

    ball.Update();
    if (ball.GetX() != 105 || ball.GetY() != 105) {
        std::cout << "ERROR: wrong movement" << std::endl;
    } else {
        std::cout << "SUCCESS: The movement is working" << std::endl;
    }
}

void TestPaddle() {
    std::cout << "\n=== Testing the platform ===" << std::endl;
    
    FirstPaddle paddle(50, 100);
    Rectangle rect = paddle.GetRect();

    if (rect.width != PADDLE_WIDTH || rect.height != PADDLE_HEIGHT) {
        std::cout << "ERROR: incorrect platform sizes" << std::endl;
    } else {
        std::cout << "SUCCESS: the dimensions of the platform are correct" << std::endl;
    }
    
    std::cout << "NOTE: The motion test requires manual verification" << std::endl;
}

void TestCollision() {
    std::cout << "\n=== Collision Testing ===" << std::endl;
    
    Ball ball(60, 100, 10, 5);
    FirstPaddle paddle(50, 100);
    
    if (!ball.CheckCollision(paddle.GetRect())) {
        std::cout << "ERROR: No collision detected" << std::endl;
    } else {
        std::cout << "SUCCESS: Collision detected" << std::endl;
    }
}

void RunAllTests() {
    std::cout << "===== RUNNING TESTS =====" << std::endl;
    TestBall();
    TestPaddle();
    TestCollision();
    std::cout << "===== THE TESTS ARE COMPLETED =====" << std::endl;
}