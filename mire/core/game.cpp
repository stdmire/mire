#include "core/game.h"
#include "core/log.h"
#include "core/scene.h"
#include "game.h"

namespace core {
Game::Game() :
        _window(1920, 1080, "MIRE Example"), renderer(_window) {
    SDL_SetWindowResizable(_window.window.get(), SDL_TRUE);
    IMG_Init(IMG_INIT_PNG);
    SDL_MaximizeWindow(_window.window.get());

    log::info("Initializing game");
    if (TTF_Init() != 0) {
        log::out("TTF_Init");
        SDL_Quit();
    }
}

Game::~Game() {
    isRunning = false;
    SDL_Quit();
}
void Game::Run() {
    isRunning = true;

    log::info("running engine");

    SDL_EventState(SDL_TEXTINPUT, SDL_DISABLE);

    while (isRunning) {
        EventLoop();
        RenderScene();
    }
}
} // namespace core
