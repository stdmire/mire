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

    auto currentscene = CurrentScene();
    currentscene->Initialize(renderer);
    SDL_EventState(SDL_TEXTINPUT, SDL_DISABLE);

    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }

            currentscene->OnEventUpdate(event);

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = 0;
                int y = 0;
                SDL_GetMouseState(&x, &y);

                currentscene->OnMouseClick(x, y);
            }

            if (event.type == SDL_MOUSEBUTTONUP) {
                int x = 0;
                int y = 0;
                SDL_GetMouseState(&x, &y);

                currentscene->OnMouseClickReleased(x, y);
            }

            if (SDL_GetEventState(SDL_TEXTINPUT) == SDL_DISABLE) {
                if (event.type == SDL_KEYDOWN) {
                    currentscene->OnKeyPressed((Key)event.key.keysym.sym);
                }
            }

            if (event.type == SDL_KEYUP) {
                currentscene->OnKeyReleased((Key)event.key.keysym.sym);
            }
        }
        SDL_SetRenderDrawColor(renderer.getRenderer(), COLOR_Slate50.getR(), COLOR_Slate50.getG(), COLOR_Slate50.getB(), COLOR_Slate50.getA());
        renderer.clear();

        currentscene->OnUpdate();

        currentscene->Render(renderer);
        renderer.present();
        SDL_Delay(16);
    }
}
} // namespace core
