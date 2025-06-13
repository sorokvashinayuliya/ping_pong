#pragma once
#include "gamestate.h"
#include "game.h"
#include "playingstate.h"
#include <string>

class GameOverState : public GameState {
private:
    Game& game;
    int playerScore;
    int cpuScore;

public:
    GameOverState(Game& game, int playerScore, int cpuScore) 
        : game(game), playerScore(playerScore), cpuScore(cpuScore) {}

    void Update() override;
    void Draw() override;
    std::unique_ptr<GameState> GetNextState() override;
};