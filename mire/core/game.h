#pragma once
#include "renderer.h"
#include "scene.h"
#include "window.h"

#include <SDL.h>

namespace core {
inline double deltatime = 0;
class Game {
public:
    Game();
    ~Game();
    void Run();
    std::unique_ptr<Scene> _currentScene;

    bool isRunning = false;
    Window _window;
    Renderer renderer;

    void initialize() {
        renderer = Renderer(_window);
    }
};

} // namespace core