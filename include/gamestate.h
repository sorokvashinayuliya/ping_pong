#pragma once
#include <memory>

class Game;

class GameState {
public:
    virtual ~GameState() = default;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual std::unique_ptr<GameState> GetNextState() = 0;
};