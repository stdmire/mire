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
        auto isSceneEmpty = false;
        auto sceneName = scene->_name;
        if (scenes.empty()) {
            isSceneEmpty = true;
        }
        scene->Initialize(renderer);
        scenes[scene->_name] = std::move(scene);
        SetCurrentScene(sceneName);
    }

    void SetCurrentScene(const std::string &name) {
        _currentSceneName = name;

        auto it = scenes.find(_currentSceneName);
        m_currentScene = it->second.get();
        m_currentScene->Initialize(renderer);
    }

    void EventLoop() {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }

            m_currentScene->OnEventUpdate(event);

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = 0;
                int y = 0;
                SDL_GetMouseState(&x, &y);

                m_currentScene->OnMouseClick(x, y);
            }

            if (event.type == SDL_MOUSEBUTTONUP) {
                int x = 0;
                int y = 0;
                SDL_GetMouseState(&x, &y);

                m_currentScene->OnMouseClickReleased(x, y);
            }

            if (SDL_GetEventState(SDL_TEXTINPUT) == SDL_DISABLE) {
                if (event.type == SDL_KEYDOWN) {
                    m_currentScene->OnKeyPressed((Key)event.key.keysym.sym);
                }
            }

            if (event.type == SDL_KEYUP) {
                m_currentScene->OnKeyReleased((Key)event.key.keysym.sym);
            }
        }
    }

    void RenderScene() {
        SDL_SetRenderDrawColor(renderer.getRenderer(), COLOR_Slate50.getR(), COLOR_Slate50.getG(), COLOR_Slate50.getB(), COLOR_Slate50.getA());
        renderer.clear();

        m_currentScene->OnUpdate();

        m_currentScene->Render(renderer);
        renderer.present();
        SDL_Delay(16);
    }

    void StopGame() {
        isRunning = false;
    }

private:
    Scene *m_currentScene;
    std::string _currentSceneName;
    std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
    SDL_Event event;
};

} // namespace core