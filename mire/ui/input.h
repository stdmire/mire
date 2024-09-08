#pragma once

#include "core/core.h"
#include "label.h"

namespace ui {
class Input : public core::BaseObject {
public:
    Input(std::string text) :
            BaseObject("input"), label(text), placeholder("placeholder") {
        rect = label.rect;
        placeholder.rect = label.rect;
        background.rect = label.rect;
    }

    void Render(const core::Renderer &renderer) override {
        background.Render(renderer);
        if (label.getText().length() > 0 || isFocus) {
            label.Render(renderer);
        } else {
            placeholder.Render(renderer);
        }
    };

    void OnClick() override {
        SDL_StartTextInput();
        isFocus = true;
    }

    void OnTypeHandler(SDL_Event e) {
        if (e.type == SDL_TEXTINPUT && isFocus) {
            label.setText(label.getText() + e.text.text);
        }

        // Event untuk deteksi backspace
        else if (e.type == SDL_KEYDOWN && isFocus) {
            if (e.key.keysym.sym == SDLK_BACKSPACE && label.getText().length() > 0) {
                auto ltext = label.getText();
                ltext.pop_back();
                label.setText(ltext);
            }
            if (e.key.keysym.sym == SDLK_RETURN) {
                SDL_StopTextInput();
                isFocus = false;
            }
        }

        rect = label.rect;
        placeholder.rect = label.rect;
        background.setRect(rect);
    }

    bool isFocus = false;
    Label label;
    Label placeholder;
    core::Object2D background;
};
} // namespace ui