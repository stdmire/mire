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
            BaseObject("label"),
            _text(text) {
        int width, height;
        TTF_SizeText(font.GetFont(), _text.c_str(), &width, &height);
        rect.setWidth(width);
        rect.setHeight(height);
        sdlrect = SDL_Rect{
            int(rect.pos.x), int(rect.pos.y), rect.getWidth(), rect.getHeight()
        };
    }

    void setText(const std::string &text) {
        _text = text;
    }

    void Render(const core::Renderer &renderer) override {
        // log::out("meki");
        SDL_Surface *surf = TTF_RenderText_Blended(font.GetFont(), _text.c_str(), { 255, 255, 255, 255 });
        if (!surf) {
            log::info("ERROR TTF_RenderText_Blended");
            log::err(SDL_GetError());
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surf);
        if (!texture) {
            log::info("ERROR SDL_CreateTextureFromSurface");
            log::err(SDL_GetError());
        }
        SDL_RenderCopy(renderer.getRenderer(), texture, NULL, &sdlrect);
        SDL_FreeSurface(surf);
    };

    void SetPosition(const core::Vector2 &pos) {
        rect.pos = pos;
        sdlrect = {
            int(rect.pos.x),
            int(rect.pos.y),
            rect.getWidth(),
            rect.getHeight(),
        };
    }

    void Move(const core::Vector2 &dir) {
        rect.pos = rect.pos + dir;
        sdlrect = {
            int(rect.pos.x),
            int(rect.pos.y),
            rect.getWidth(),
            rect.getHeight(),
        };
    }

    core::Font font;
    core::Color color;

private:
    std::string _text;
    SDL_Rect sdlrect;

    void setRect() {
        sdlrect = SDL_Rect{
            int(rect.pos.x), int(rect.pos.y), rect.getWidth(), rect.getHeight()
        };
    }
}; // namespace ui

} // namespace ui