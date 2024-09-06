#pragma once

#include "log.h"
#include <SDL.h>

namespace core {

class Window {
    friend class Game;

public:
    Window(unsigned int w, unsigned int h, const char *title) :
            width(w), height(h), title(title) {
        log::info("window created width:", w, "height:", h, "title:", title);
        window.reset(SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
    };

    const unsigned int width, height;
    const std::string title;

private:
    std::shared_ptr<SDL_Window> window;
};

} // namespace core