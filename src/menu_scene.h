#pragma once

#include "core/scene.h"
#include <SDL.h>

class MenuScene : public core::Scene {
public:
    MenuScene();
    ~MenuScene() {};

    void OnUpdate() override;
    void OnKeyPressed(core::Key) override;
    void OnKeyReleased(core::Key) override;
    void OnEventUpdate(SDL_Event event) override;

    int speedX = 0;
    int speedY = 0;
};