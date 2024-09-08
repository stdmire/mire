#include "core/game.h"
#include "core/log.h"
#include "core/scene.h"
#include "game.h"

namespace core {
Game::Game() :
        _window(1920, 1080, "MIRE Example"), renderer(_window) {
    SDL_SetWindowResizable(_window.window.get(), SDL_TRUE);
    SDL_MaximizeWindow(_window.window.get());
    SDL_ShowCursor(SDL_ENABLE);

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
    SDL_EventState(SDL_TEXTINPUT, SDL_DISABLE);

    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                isRunning = false;

            _currentScene->OnEventUpdate(event);

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y = 2;
                SDL_GetMouseState(&x, &y);

                _currentScene->OnMouseClick(x, y);
            }

            if (event.type == SDL_MOUSEBUTTONUP) {
                int x, y = 2;
                SDL_GetMouseState(&x, &y);

                _currentScene->OnMouseClickReleased(x, y);
            }

            if (SDL_GetEventState(SDL_TEXTINPUT) == SDL_DISABLE) {
                if (event.type == SDL_KEYDOWN) {
                    _currentScene->OnKeyPressed((Key)event.key.keysym.sym);
                }
            }

            if (event.type == SDL_KEYUP) {
                _currentScene->OnKeyReleased((Key)event.key.keysym.sym);
            }
        }
        SDL_SetRenderDrawColor(renderer.getRenderer(), COLOR_Slate50.getR(), COLOR_Slate50.getG(), COLOR_Slate50.getB(), COLOR_Slate50.getA());
        // log::out(COLOR_Slate50.getR(), COLOR_Slate50.getG(), COLOR_Slate50.getB(), COLOR_Slate50.getA());
        renderer.clear();

        _currentScene->OnUpdate();

        _currentScene->Render(renderer);
        renderer.present();
        SDL_Delay(16);
    }
}
} // namespace core
