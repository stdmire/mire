#pragma once

#include "core/color.h"
#include "core/font.h"
#include "core/log.h"
#include "core/object.h"
#include "core/texture.h"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

namespace ui {

class Label : public core::BaseObject {
public:
    Label(std::string text) :
            BaseObject("label") {
    }

    void setText(const std::string &text) {
        _text = text;
    }

    void Render(const core::Renderer &renderer) override {
        // log::out("meki");
        SDL_Surface *surf = TTF_RenderText_Blended(font.GetFont(), _text.c_str(), { 255, 255, 255, 255 });
        if (!surf) {
            // log::info("ERROR TTF_RenderText_Blended");
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surf);
        SDL_SetRenderTarget(renderer.getRenderer(), texture);
        SDL_FreeSurface(surf);
    };

    core::Font font;
    core::Color color;

private:
    std::string _text;
};

} // namespace ui