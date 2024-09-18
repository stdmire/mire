#pragma once
#include "baseobject.h"
#include "color.h"
#include "physic.h"
#include "renderer.h"
#include "vector.h"
#include <SDL.h>
#include <SDL_image.h>

namespace core {

class Object2D : public BaseObject {
public:
    Object2D() :
            BaseObject("Object2d"), body(this) {
        syncrect();
    }

    void Render(const Renderer &r) override {
        SDL_SetRenderDrawColor(r.getRenderer(), color.getR(), color.getG(), color.getG(), color.getA());
        SDL_RenderFillRect(r.getRenderer(), &sdlrect);
    }

    void setRect(const Rect &r) {
        rect = r;
        syncrect();
    }

    void SetPosition(const Vector2 &pos) {
        rect.pos = pos;
        syncrect();
    }
    Color color;

private:
    void syncrect() {
        sdlrect.x = rect.pos.x;
        sdlrect.y = rect.pos.y;
        sdlrect.w = rect.getWidth();
        sdlrect.h = rect.getHeight();
    }

    SDL_Rect sdlrect;
    Body body;
};

} // namespace core
