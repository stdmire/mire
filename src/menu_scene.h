#pragma once

#include "mire.h"

class MenuScene : public core::Scene {
public:
    MenuScene() :
            Scene("Menu") {
        label = std::make_shared<ui::Label>("Start Game");
        input = std::make_shared<ui::Input>("myinput");
        btn = std::make_shared<ui::Button>("btn");

        btn->SetPosition(core::Vector2(100, 100));
        btn->background.color = core::Color();

        btn->SetOnClick([&]() {
            label->SetPosition(core::Vector2(200, 200));
        });

        btn->SetOnClickReleased([&]() {
            label->SetPosition(core::Vector2(300, 100));
        });

        auto sprite = std::make_shared<core::Sprite>();
        sprite->rect.pos.x = 300;
        sprite->rect.pos.y = 300;

        PushObject(sprite);
        PushObject(btn);
        PushObject(label);
        PushObject(input);
    }
    MenuScene(const MenuScene &) = default;
    MenuScene(MenuScene &&) = delete;
    auto operator=(const MenuScene &) -> MenuScene & = default;
    auto operator=(MenuScene &&) -> MenuScene & = delete;
    MenuScene(std::shared_ptr<ui::Label> label, std::shared_ptr<ui::Input> input, std::shared_ptr<ui::Button> btn, core::Vector2 dir) :
            label(std::move(label)), input(std::move(input)), btn(std::move(btn)), dir(dir) {}
    virtual ~MenuScene() {

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

        if (k == core::K_l) {
            label->setText("change text");
        }
        if (k == core::K_p) {
            label->setText("not changed");
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
    void OnEventUpdate(SDL_Event event) override {
        input->OnTypeHandler(event);
    }

    int speedX = 0;
    int speedY = 0;

    std::shared_ptr<ui::Label> label;
    std::shared_ptr<ui::Input> input;
    std::shared_ptr<ui::Button> btn;
    core::Vector2 dir;
};