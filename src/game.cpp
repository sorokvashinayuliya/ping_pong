#include "game.h"
#include "menustate.h"

Game::Game() 
    : ball(3*SCREEN_WIDTH/4, SCREEN_HEIGHT/2, BALL_RADIUS, BALL_SPEED),
      first(SCREEN_WIDTH - PADDLE_WIDTH - 200, SCREEN_HEIGHT/4 - PADDLE_HEIGHT/2),
      second(200, SCREEN_HEIGHT/4 - PADDLE_HEIGHT/2),
      third(10, 3*SCREEN_HEIGHT/4 - PADDLE_HEIGHT/2),
      fourth(SCREEN_WIDTH - PADDLE_WIDTH - 10,3 * SCREEN_HEIGHT/4 - PADDLE_HEIGHT/2) 
{
    currentState = std::make_unique<MenuState>(*this);
}

void Game::Run() {
    while (!WindowShouldClose()) {
        currentState->Update();
        
        auto nextState = currentState->GetNextState();
        if (nextState) {
            currentState = std::move(nextState);
        }

        currentState->Draw();
    }
}

Ball& Game::GetBall() { return ball; }

