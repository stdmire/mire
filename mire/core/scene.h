#pragma once
#include "control.h"
#include "layer.h"
#include "object.h"
#include <SDL.h>

namespace core {
class Scene {
    friend class Game;

public:
    Scene(const char *name);
    Scene() = default;
    ~Scene() = default;

    void PushObject(std::shared_ptr<BaseObject> obj);
    std::shared_ptr<BaseObject> GetObject(std::string name);

protected:
    virtual void OnUpdate() {};
    virtual void OnEventUpdate(SDL_Event event) {};
    virtual void OnKeyPressed(Key){};
    virtual void OnKeyReleased(Key){};

private:
    std::string _name;
    std::vector<Layer> _layers;
    std::vector<std::shared_ptr<BaseObject>> _objects;

    void Render(std::shared_ptr<SDL_Renderer> w);
};
} // namespace core