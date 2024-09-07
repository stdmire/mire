#pragma once

#include "core/color.h"
#include "core/font.h"
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

    core::Texture texture;
    core::Font font;
    core::Color color;
};

} // namespace ui