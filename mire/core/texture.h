#pragma once

#include "object.h"
#include "renderer.h"
#include <SDL.h>
#include <memory>

auto TextureDeleter = [](SDL_Texture *texture) {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
};

auto SurfaceDeleter = [](SDL_Surface *surface) {
    if (surface) {
        SDL_FreeSurface(surface);
    }
};

namespace core {
class Texture : public BaseObject {
public:
    Texture() :
            surface(nullptr, SurfaceDeleter),
            texture(nullptr, TextureDeleter),
            BaseObject("texture") {
    }

    ~Texture() {
    }

private:
    std::unique_ptr<SDL_Texture, void (*)(SDL_Texture *)> texture;
    std::unique_ptr<SDL_Surface, void (*)(SDL_Surface *)> surface;
    int height;
};
} // namespace core