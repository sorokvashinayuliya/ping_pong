#include "playingstate.h"

void PlayingState::Update() {
    Vector2 mousePos = GetMousePosition();
    Rectangle pauseButtonRect = {
        (float)GetScreenWidth() - MeasureText("||", 30) - 10,
        10,
        (float)MeasureText("||", 30),
        30
    };

    if (CheckCollisionPointRec(mousePos, pauseButtonRect) && 
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        paused = !paused;
    }

    if (!paused) {
        game.GetBall().Update();
        game.GetFirst().Update();
        game.GetSecond().Update();
        game.GetThird().Update();
        game.GetFourth().Update();

        if (game.GetBall().CheckCollision(game.GetFirst().GetRect()) || 
            game.GetBall().CheckCollision(game.GetSecond().GetRect()) ||
            game.GetBall().CheckCollision(game.GetThird().GetRect()) ||
            game.GetBall().CheckCollision(game.GetFourth().GetRect())) {
            game.GetBall().ReverseX();
        }

        if (game.GetBall().GetX() <= 0) {
            playerScore++;
            game.GetBall().Reset();
        } else if (game.GetBall().GetX() >= GetScreenWidth()) {
            cpuScore++;
            game.GetBall().Reset();
        }
    }
}

void PlayingState::Draw() {
    BeginDrawing();
    ClearBackground(MY_DARK_BLUE);

    
    for (int i = 0; i < GetScreenHeight(); i += 30) {
        DrawRectangle(GetScreenWidth()/2 - 2, i, 4, 20, Color{255, 255, 255, 100});
    }

    game.GetBall().Draw();
    game.GetFirst().Draw();
    game.GetSecond().Draw();
    game.GetThird().Draw();
    game.GetFourth().Draw();

    DrawText(TextFormat("%i", cpuScore), SCREEN_WIDTH/4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", playerScore), 3*SCREEN_WIDTH/4 - 20, 20, 80, WHITE);

    const char pauseButton[] = "||";
    Rectangle pauseButtonRect = {
        (float)GetScreenWidth() - MeasureText(pauseButton, 50) - 10,
        10,
        (float)MeasureText(pauseButton, 50),
        30
    };
    
    Color buttonColor = WHITE;
    if (CheckCollisionPointRec(GetMousePosition(), pauseButtonRect)) {
        buttonColor = YELLOW;
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            buttonColor = GRAY;
        }
    }
    
    DrawText(pauseButton, pauseButtonRect.x, pauseButtonRect.y, 30, buttonColor);

    if (paused) {
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Color{0, 0, 0, 180});
        DrawText("PAUSED", SCREEN_WIDTH/2 - MeasureText("PAUSED", 50)/2, SCREEN_HEIGHT/2 - 50, 50, WHITE);
    }

    EndDrawing();
}

std::unique_ptr<GameState> PlayingState::GetNextState() {
    if (playerScore >= WIN_SCORE || cpuScore >= WIN_SCORE) {
        return std::make_unique<GameOverState>(game, playerScore, cpuScore);
    }
    return nullptr;
}