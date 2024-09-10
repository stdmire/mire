#pragma once

#include "log.h"
#include <SDL.h>
#include <memory.h>
struct SDL_Window_Deleter {
    void operator()(SDL_Window *window) const {
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
};

namespace core {
class Window {
    friend class Game;
    friend class Renderer;

public:
    Window(unsigned int w, unsigned int h, const char *title) :
            width(w), height(h), title(title) {
        log::info("window created width:", w, "height:", h, "title:", title);
        window.reset(SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN));
    };

    unsigned int width, height;
    std::string title;

private:
    std::unique_ptr<SDL_Window, SDL_Window_Deleter> window;
};
} // namespace core