#include "core/game.h"
#include "SDL_stdinc.h"
#include "core/log.h"
#include "core/scene.h"
#include "game.h"
#include <SDL.h>
namespace core {
Game::Game() :
        _window(1920, 1080, "MIRE Example"), renderer(_window) {
    SDL_SetWindowResizable(_window.window.get(), SDL_FALSE);
    IMG_Init(IMG_INIT_PNG);
    SDL_MaximizeWindow(_window.window.get());
    SDL_RenderSetLogicalSize(renderer.getRenderer(), 1920, 1080);

    log::info("Initializing game");
    if (TTF_Init() != 0) {
        log::err("TTF_Init");
        SDL_Quit();
    }
}

Game::~Game() {
    isRunning = false;
    SDL_Quit();
}
void Game::Run() {
    isRunning = true;

    log::info("running game");

    SDL_EventState(SDL_TEXTINPUT, SDL_DISABLE);

    while (isRunning) {
        EventLoop();
        RenderScene();
    }
}

} // namespace core
