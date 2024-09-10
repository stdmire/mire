#pragma once

#include "object.h"
#include <SDL.h>
#include <memory>

const auto TextureDeleter = [](SDL_Texture *texture) {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
};

const auto SurfaceDeleter = [](SDL_Surface *surface) {
    if (surface != nullptr) {
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
    int height, width;
};
} // namespace core