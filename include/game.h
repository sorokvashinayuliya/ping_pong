#pragma once
#include <memory>
#include "ball.h"
#include "paddle.h"
#include "gamestate.h"
#include "constants.h"

class MenuState;
class PlayingState;
class GameOverState;

class Game {
private:
    std::unique_ptr<GameState> currentState;
    Ball ball;
    FirstPaddle first;
    SecondPaddle second;
    ThirdPaddle third;
    FourthPaddle fourth;
public:
    Game();
    void Run();

    Ball& GetBall();
    FirstPaddle& GetFirst() { return first; }
    SecondPaddle& GetSecond() { return second; }
    ThirdPaddle& GetThird() {return third; }
    FourthPaddle& GetFourth() {return fourth; }
};