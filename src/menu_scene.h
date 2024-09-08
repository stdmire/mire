#pragma once

#include "core/scene.h"
#include "ui/label.h"
#include <SDL.h>
#include <memory>

class MenuScene : public core::Scene {
public:
    MenuScene() :
            Scene("Menu") {
        auto label = std::make_shared<ui::Label>("my label");

        PushObject(label);
    }
    ~MenuScene() {

    };

    void OnUpdate() override;
    void OnKeyPressed(core::Key) override;
    void OnKeyReleased(core::Key) override;
    void OnEventUpdate(SDL_Event event) override;

    int speedX = 0;
    int speedY = 0;
};