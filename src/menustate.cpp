#include "menustate.h"
#include "constants.h"
#include "C:\Users\79176\kfu_projects\pong\raylib\src\raylib.h"

void MenuState::Draw() {
    BeginDrawing();
    ClearBackground(MY_DARK_BLUE);
    DrawText("INSTRUCTIONS", GetScreenWidth()/2 - MeasureText("INSTRUCTIONS", 40)/2, 50, 40, WHITE);
    
    const char* instructions = 
        "Team 1 Controls:\n"
        "\n"
        "- Player 1: UP/DOWN arrows\n"
        "\n"
        "- Player 2: K/M keys\n\n"
        "\n"
        "Team 2 Controls:\n"
        "\n"
        "- Player 1: A/Z keys\n"
        "\n"
        "- Player 2: F/V keys\n\n"
        "\n"
        "Goal: First team to reach 21 points wins!\n";
        DrawText(instructions, GetScreenWidth()/2 - MeasureText("Team 1 Controls:", 24)/2, 120, 24, WHITE);
        Rectangle startButton = { 
            GetScreenWidth()/2 - 100.0f, 
            450.0f, 
            200.0f, 
            50.0f 
        };
        bool mouseOverButton = CheckCollisionPointRec(GetMousePosition(), startButton);
    
        DrawRectangleRec(startButton, mouseOverButton ? LIGHTGRAY : GRAY);
        DrawText("START", 
                startButton.x + startButton.width/2 - MeasureText("START", 30)/2, 
                startButton.y + startButton.height/2 - 15, // vse chisla nuzhno spryatat` v constexpr 
                30, DARKBLUE);
    
        if (mouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            EndDrawing();
            return;
        }
    
    
    EndDrawing();
}

std::unique_ptr<GameState> MenuState::GetNextState() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        game.GetBall().Reset();
        return std::make_unique<PlayingState>(game);
    }
    return nullptr;
}