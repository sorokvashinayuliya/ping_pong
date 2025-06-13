#pragma once
#include "gamestate.h"
#include "game.h"
#include "gameoverstate.h"

class PlayingState : public GameState {
private:
    Game& game;
    int playerScore = 0;
    int cpuScore = 0;
    bool paused = false;

public:
    PlayingState(Game& game) : game(game) {}

    void Update() override;
    void Draw() override;
    std::unique_ptr<GameState> GetNextState() override;
};