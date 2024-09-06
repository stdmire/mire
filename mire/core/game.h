#pragma once
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
    std::unique_ptr<Window> _window;

    bool isRunning = false;
};

} // namespace core