#pragma once

#include "object.h"
#include <SDL_image.h>

namespace core {
class Sprite : public BaseObject {
public:
    Sprite() :
            BaseObject("sprite") {
        rect.pos.x = 200;
        rect.pos.x = 100;

        fullpath = "/Users/amarps/Code/mire/assets/bird.png";
    }

    void OnInit(const Renderer &r) override {
        texture = IMG_LoadTexture(r.getRenderer(), fullpath.c_str());
        SDL_QueryTexture(texture, nullptr, nullptr, &textWidth, &textHeight);
    }

    void Render(const core::Renderer &r) override {
        auto sdlrect = rect.toSDLRect();
        SDL_RenderCopy(r.getRenderer(), texture, nullptr, &sdlrect);
    }

    Vector2 TextureSize() {
        return Vector2(textWidth, textHeight);
    }

private:
    int textWidth;
    int textHeight;
    std::string filepath;
    std::string fullpath;
    SDL_Texture *texture;
};
} // namespace core
