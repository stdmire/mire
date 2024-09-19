#include "core/game.h"
#include "SDL_stdinc.h"
#include "core/log.h"
#include "core/scene.h"
#include "game.h"
#include <SDL.h>
namespace core {
Game::Game() :
        _window(1920, 1080, "MIRE Example"), renderer(_window) {
    Init();
    SetResolution(1980, 1080);
}

Game::Game(int resWidth, int resHeight, int winWidth, int winHeight) :
        _window(winWidth, winHeight, "MIRE Example"), renderer(_window) {
    Init();
    SetResolution(resWidth, resHeight);
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

void Game::SetResolution(int width, int height) const {
    SDL_RenderSetLogicalSize(renderer.getRenderer(), width, height);
}

void Game::Init() {
    SDL_SetWindowResizable(_window.window.get(), SDL_FALSE);
    IMG_Init(IMG_INIT_PNG);
    SDL_MaximizeWindow(_window.window.get());

    log::info("Initializing game");
    if (TTF_Init() != 0) {
        log::err("TTF_Init");
        SDL_Quit();
    }
}
} // namespace core
