#pragma once
#include "control.h"
#include "core/renderer.h"
#include "layer.h"
#include "object.h"
#include <SDL.h>

namespace core {
class Scene {
    friend class Renderer;
    friend class Game;

public:
    Scene(const char *name);
    Scene() = default;
    ~Scene() = default;

    void PushObject(std::shared_ptr<BaseObject> obj);
    std::shared_ptr<BaseObject> GetObject(std::string name);

protected:
    virtual void OnStart() {};
    virtual void OnUpdate() {};
    virtual void OnEventUpdate(SDL_Event event) {};
    virtual void OnKeyPressed(Key){};
    virtual void OnKeyReleased(Key){};
    virtual void Initialize(const Renderer &renderer);

private:
    std::string _name;
    std::vector<Layer> _layers;
    std::vector<std::shared_ptr<BaseObject>> _objects;

    void Render(const Renderer &renderer);
    void OnMouseClick(int x, int y) {
        for (auto &object : _objects) {
            if (object->rect.contains(Vector2(x, y))) {
                object->OnClick();
            }
        }
        return;
    }

    void OnMouseClickReleased(int x, int y) {
        for (auto &object : _objects) {
            if (object->rect.contains(Vector2(x, y))) {
                object->OnClickReleased();
            }
        }
        return;
    }
};
} // namespace core