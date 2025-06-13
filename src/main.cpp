#include "game.h"
#include <string> 
#include "../tests/manual_tests.h"

int main(int argc, char* argv[]) { 
    if (argc > 1 && std::string(argv[1]) == "--test") {
        RunAllTests();
        return 0;
    }

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong Game");
    SetTargetFPS(60);

    Game game;
    game.Run();

    CloseWindow();
    return 0;
}