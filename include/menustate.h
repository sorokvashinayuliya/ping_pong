#pragma once
#include "gamestate.h"
#include "game.h"
#include "playingstate.h"

class MenuState : public GameState {
private:
    Game& game;
    
public:
    MenuState(Game& game) : game(game) {}

    void Update() override {}
    void Draw() override;
    std::unique_ptr<GameState> GetNextState() override;
};