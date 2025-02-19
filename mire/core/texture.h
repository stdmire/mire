#pragma once

#include "SDL_events.h"
#include "SDL_render.h"
#include "baseobject.h"
#include "core/color.h"
#include "core/file.h"
#include "core/font.h"
#include "core/log.h"
#include "core/vector.h"
#include "err/err.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <memory>
#include <tuple>

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
            BaseObject("texture") {
    }

    SDL_Surface *GetSurface() {
        return surface.get();
    }

    SDL_Texture *GetTexture() {
        return texture.get();
    }

protected:
    std::unique_ptr<SDL_Texture, void (*)(SDL_Texture *)> texture;
    std::unique_ptr<SDL_Surface, void (*)(SDL_Surface *)> surface;
    Color color;
    int height, width;
    File file;
};

class TextureFont : public TextureBase {
public:
    TextureFont() {}
    TextureFont(const std::string &path) :
            TextureBase(path) {
    }

    void UpdateSurface(const Font &f, Color c, std::string text) {
        surface.reset(TTF_RenderText_Blended(
                f.GetFont(), text.c_str(),
                {
                        (unsigned char)c.getR(),
                        (unsigned char)c.getG(),
                        (unsigned char)c.getB(),
                        (unsigned char)c.getA(),
                }));
        if (surface == nullptr) {
            log::info("ERROR TTF_RenderText_Blended");
            throw err::SDL(SDL_GetError());
        }
    }

    void UpdateTexture(const core::Renderer &renderer) {
        texture.reset(SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.get()));
        if (texture == nullptr) {
            log::info("ERROR SDL_CreateTextureFromSurface");
            throw err::SDL(SDL_GetError());
        }
    }
};

class TextureImage : public TextureBase {
public:
    TextureImage() {}
    TextureImage(const std::string &path) :
            TextureBase(path) {}

    void UpdateSurface() {
        surface.reset(IMG_Load(file.FullPath().c_str()));
        if (surface == nullptr) {
            log::info("ERROR SDL_CreateTextureFromSurface");
            throw err::SDL(IMG_GetError());
        }
    }

    void UpdateTexture(const core::Renderer &renderer) {
        texture.reset(SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.get()));
        if (texture == nullptr) {
            log::info("ERROR SDL_CreateTextureFromSurface");
            throw err::SDL(SDL_GetError());
        }

        SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height);
    }

    int GetWidth() {
        return width;
    }

    int GetHeight() {
        return height;
    }
};

} // namespace core