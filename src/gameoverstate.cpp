#include "gameoverstate.h"
#include <string>
void GameOverState::Update() {
    if (IsKeyPressed(KEY_ENTER)) {
        game.GetBall().Reset();
    }
}

void GameOverState::Draw() {
    BeginDrawing();
    ClearBackground(MY_DARK_BLUE);

    std::string winnerText = (playerScore > cpuScore) ? "PLAYER WINS!" : "CPU WINS!";
    DrawText(winnerText.c_str(), SCREEN_WIDTH/2 - MeasureText(winnerText.c_str(), 50)/2, 100, 50, WHITE);
    
    DrawText(TextFormat("Final Score: %i - %i", cpuScore, playerScore), 
            SCREEN_WIDTH/2 - MeasureText(TextFormat("Final Score: %i - %i", cpuScore, playerScore), 30)/2, 
            200, 30, WHITE);
    
    DrawText("Press ENTER to play again", SCREEN_WIDTH/2 - MeasureText("Press ENTER to play again", 30)/2, 300, 30, WHITE);

    EndDrawing();
}

std::unique_ptr<GameState> GameOverState::GetNextState() {
    if (IsKeyPressed(KEY_ENTER)) {
        return std::make_unique<PlayingState>(game);
    }
    return nullptr;
}