#pragma once
#include "renderer.h"
#include "scene.h"
#include "window.h"

#include <SDL.h>
#include <SDL_ttf.h>
namespace core {
inline double deltatime = 0;
class Game {
public:
    Game();
    ~Game();
    void Run();

    bool isRunning = false;
    Window _window;
    Renderer renderer;

    void AddScene(std::unique_ptr<Scene> scene) {
        if (scenes.empty()) {
            _currentScene = scene->_name;
        }
        scenes[scene->_name] = std::move(scene);
    }

    Scene *CurrentScene() const {
        auto it = scenes.find(_currentScene);
        return it->second.get();
    }

    void SetCurrentScene(const std::string &name) {
        _currentScene = name;
    }

private:
    std::string _currentScene;
    std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
};

} // namespace core