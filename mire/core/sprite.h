#pragma once

#include "core/log.h"
#include "core/rect.h"
#include "object.h"
#include "texture.h"
#include <SDL_image.h>

namespace core {
class Sprite : public BaseObject {
public:
    Sprite() :
            BaseObject("sprite") {
    }

    Sprite(const std::string &path) :
            BaseObject("sprite"),
            texture(path) {
    }

    void OnInit(const Renderer &r) override {
        LoadImage();
        texture.UpdateTexture(r);
        rect.setWidth(texture.GetWidth());
        rect.setHeight(texture.GetHeight());
    }

    void Render(const core::Renderer &r) override {
        if (isTextureUpdated) {
            texture.UpdateTexture(r);
            isTextureUpdated = false;
        }
        auto sdlrect = rect.toSDLRect();
        SDL_RenderCopy(r.getRenderer(), texture.GetTexture(), nullptr, &sdlrect);
    }

    Vector2 TextureSize() {
        return Vector2(textWidth, textHeight);
    }

private:
    void LoadImage() {
        texture.UpdateSurface();
        isTextureUpdated = true;
    }

    bool isTextureUpdated = false;
    int textWidth;
    int textHeight;
    TextureImage texture;
};
} // namespace core
