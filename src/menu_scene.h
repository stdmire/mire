#pragma once

#include "core/control.h"
#include "core/scene.h"
#include "ui/label.h"
#include <SDL.h>
#include <memory>

class MenuScene : public core::Scene {
public:
    MenuScene() :
            Scene("Menu") {
        label = std::make_shared<ui::Label>("Start Game");

        PushObject(label);
    }
    ~MenuScene() {

    };

    void OnUpdate() override {
        label->Move(dir);
    }
    void OnKeyPressed(core::Key k) override {
        int speed = 10;
        if (k == core::K_w) {
            dir.y = -speed;
        }
        if (k == core::K_a) {
            dir.x = -speed;
        }
        if (k == core::K_s) {
            dir.y = speed;
        }
        if (k == core::K_d) {
            dir.x = speed;
        }
    }
    void OnKeyReleased(core::Key k) override {
        if (k == core::K_w || k == core::K_s) {
            dir.y = 0;
            label->Move(dir);
        }

        if (k == core::K_a || k == core::K_d) {
            dir.x = 0;
            label->Move(dir);
        }
    }
    void OnEventUpdate(SDL_Event event) override;

    int speedX = 0;
    int speedY = 0;

    std::shared_ptr<ui::Label> label;
    core::Vector2 dir;
};