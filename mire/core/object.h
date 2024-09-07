#pragma once
#include "vector.h"
#include <SDL.h>

namespace core {
class BaseObject {
public:
    Vector3 getPosition() const;
    Vector3 getRotation() const;
    Vector3 getScale() const;
    std::string getName() const;
    std::string getId() const;
    std::vector<std::string> getTags() const;
    std::string getLayer() const;

    void setPosition(const Vector3 &position);
    void setRotation(const Vector3 &rotation);
    void setScale(const Vector3 &scale);
    void setName(const std::string &name);
    void setId(const std::string &id);
    void setTags(const std::vector<std::string> &tags);
    void setLayer(const std::string &layer);

    virtual void Translate(const Vector3 &offset);

    ~BaseObject();

protected:
    BaseObject(const char *name);
    bool operator==(const BaseObject &other) const {
        return this->_name == other._name;
    }

    friend class Scene;
    virtual void Render(std::shared_ptr<SDL_Renderer> window) {};

private:
    Vector3 _position;
    Vector3 _rotation;
    Vector3 _scale;
    std::string _name;
    std::string _id;
    std::vector<std::string> _tags;
    std::string _layer;
};

} // namespace core
