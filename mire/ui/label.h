#pragma once

#include "SDL_rect.h"
#include "core/core.h" // IWYU pragma: keep
#include "core/texture.h"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

namespace ui {

class Label : public core::BaseObject {
public:
    Label(std::string text) :
            BaseObject("label"),
            _text(text) {
        TTF_SizeText(font.GetFont(), _text.c_str(), &width, &height);
        rect.setWidth(width);
        rect.setHeight(height);
        UpdateTexture();
    }

    void setText(const std::string &text) {
        _text = text;
        TTF_SizeText(font.GetFont(), _text.c_str(), &width, &height);
        rect.setWidth(width);
        rect.setHeight(height);
        UpdateTexture();
    }

    const std::string &getText() {
        return _text;
    }

    void Render(const core::Renderer &renderer) override {
        if (textureupdated) {
            texture.UpdateTexture(renderer);
            textureupdated = false;
        }
        sdlrect = rect.toSDLRect();
        SDL_RenderCopy(renderer.getRenderer(), texture.GetTexture(), NULL, &sdlrect);
    };

    void SetPosition(const core::Vector2 &pos) {
        rect.pos = pos;
    }

    void Move(const core::Vector2 &dir) {
        rect.pos = rect.pos + dir;
    }

    core::Font font;
    core::Color color;

private:
    void UpdateTexture() {
        texture.UpdateSurface(font, color, _text);
        textureupdated = true;
    }
    std::string _text;
    int width, height;
    core::FontTexture texture;
    bool textureupdated = false;
    SDL_Rect sdlrect;
};

} // namespace ui