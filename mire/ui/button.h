#pragma once

#include "core/core.h"
#include "label.h"

namespace ui {
class Button : public core::BaseObject {
public:
    Button(std::string text) :
            BaseObject("Button"), label(text) {
        rect = label.rect;
        background.rect = label.rect;
    }

    void Render(const core::Renderer &renderer) override {
        background.Render(renderer);
        label.Render(renderer);
    };

    void SetPosition(const core::Vector2 &pos) {
        label.SetPosition(pos);
        background.SetPosition(pos);
        rect = background.rect;
    }

    void SetOnClick(std::function<void()> fn) {
        onClickCallback = fn;
    }

    void SetOnClickReleased(std::function<void()> fn) {
        onClickReleasedCallback = fn;
    }

    void OnClick() override {
        onClickCallback();
    }

    void OnClickReleased() override {
        onClickReleasedCallback();
    }

    std::function<void()> onClickCallback = []() {
        log::out("Clicked");
    };
    std::function<void()> onClickReleasedCallback = []() {
        log::out("Click Released");
    };
    bool isFocus = false;
    Label label;
    core::Object2D background;
};
} // namespace ui