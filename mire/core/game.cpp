#include "core/game.h"
#include "core/log.h"
#include "core/scene.h"
#include "game.h"

namespace core {
Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        log::out("SDL could not initialize! SDL_Error: ", SDL_GetError());
    }

    _window = std::make_unique<Window>(800, 600, "MIRE Example");
}

Game::~Game() {
    isRunning = false;
}
void Game::Run() {
    isRunning = true;
    std::shared_ptr<SDL_Renderer> renderer(SDL_CreateRenderer(_window->window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
    if (!renderer) {
        log::out("Renderer could not be created! SDL_Error: ", SDL_GetError());
    }

    log::info("running engine");

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

        _currentScene->OnUpdate();

        SDL_RenderClear(renderer.get());
        _currentScene->Render(renderer);
        SDL_RenderPresent(renderer.get());
    }
}
} // namespace core
