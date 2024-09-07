#pragma once
#include "color.h"
#include "object.h"
#include "rect.h"
#include "scene.h"
#include "window.h"
#include <SDL.h>
#include <string>

namespace core {

class Renderer {
    friend class Game;

public:
    Renderer(const Window &window);
    ~Renderer();

    void clear();
    void present();

    void drawLine(int x1, int y1, int x2, int y2);
    void renderTexture(SDL_Texture *texture, const Rect &rect);
    void renderTexture(SDL_Texture *texture, const Rect &srcRect, const Rect &destRect);
    SDL_Renderer *getRenderer() const;

private:
    std::shared_ptr<SDL_Renderer> _renderer;
    SDL_Renderer *sdlrenderer;

    void checkRendererError() const;
};

} // namespace core
