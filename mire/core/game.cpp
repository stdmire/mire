#include "core/game.h"
#include "core/log.h"
#include "core/scene.h"
#include "game.h"

namespace core {
Game::Game() :
        _window(800, 600, "MIRE Example"), renderer(_window) {
    log::info("Initializing game");
    initialize();
}

Game::~Game() {
    isRunning = false;
    SDL_Quit();
}
void Game::Run() {
    isRunning = true;

    log::info("running engine");

    _currentScene->Initialize(renderer);

    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                isRunning = false;

            _currentScene->OnEventUpdate(event);

            if (event.type == SDL_KEYDOWN) {
                _currentScene->OnKeyPressed((Key)event.key.keysym.sym);
            }

            if (event.type == SDL_KEYUP) {
                _currentScene->OnKeyReleased((Key)event.key.keysym.sym);
            }
        }
        SDL_SetRenderDrawColor(renderer.getRenderer(), 0, 0, 0, 255);
        renderer.clear();

        _currentScene->OnUpdate();

        _currentScene->Render(renderer);
        renderer.present();
        SDL_Delay(16);
    }
}
} // namespace core
