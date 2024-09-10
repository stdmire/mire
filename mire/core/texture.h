#pragma once

#include "SDL_image.h"
#include "core/color.h"
#include "core/file.h"
#include "core/font.h"
#include "err/err.h"
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
class TextureBase : public BaseObject {
public:
    TextureBase() :
            width(0),
            height(0),
            surface(nullptr, SurfaceDeleter),
            texture(nullptr, TextureDeleter),
            BaseObject("texture") {
    }

    TextureBase(const std::string &path) :
            surface(nullptr, SurfaceDeleter),
            texture(nullptr, TextureDeleter),
            file(path),
            BaseObject("texture") {}

protected:
    std::unique_ptr<SDL_Texture, void (*)(SDL_Texture *)> texture;
    std::unique_ptr<SDL_Surface, void (*)(SDL_Surface *)> surface;
    Color color;
    int height, width;
    File file;
};

class FontTexture : public TextureBase {
public:
    FontTexture() {}
    FontTexture(const std::string &path) :
            TextureBase(path) {
    }
};

} // namespace core