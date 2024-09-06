#pragma once
#include "vector.h"
#include <SDL.h>

namespace core {

class BaseObject {
public:
    Vector3 _position;
    Vector3 _rotation;
    Vector3 _scale;
    std::string _name;
    std::string _id;
    std::vector<std::string> _tags;
    std::string _layer;

    virtual void Translate(const Vector3 &offset);

protected:
    BaseObject(const char *name);
    bool operator==(const BaseObject &other) const {
        return this->_name == other._name;
    }

    friend class Scene;
    virtual void Render(std::shared_ptr<SDL_Renderer> window) {};
};

} // namespace core
