#pragma once
#include "color.h"
#include "renderer.h"
#include "vector.h"
#include <SDL.h>
#include <SDL_image.h>

namespace core {
class BaseObject {
public:
    virtual ~BaseObject() = 0;

    bool getVisibility() const;
    std::string getLayer() const;
    std::string getName() const;
    std::string getId() const;
    std::vector<std::string> getTags() const;
    Vector2 getRotation() const;
    Vector2 getScale() const;

    void setVisibility(bool isvisible);
    void setRotation(const Vector2 &rotation);
    void setScale(const Vector2 &scale);
    void setName(const std::string &name);
    void setId(const std::string &id);
    void setTags(const std::vector<std::string> &tags);
    void setLayer(const std::string &layer);

    virtual void OnClick() {};
    virtual void OnClickReleased() {};

    Rect rect;

protected:
    BaseObject(const char *name);
    bool operator==(const BaseObject &other) const {
        return this->_name == other._name;
    }

    friend class Scene;
    virtual void Render(const Renderer &renderer) {};
    virtual void OnInit(const Renderer &renderer) {};

private:
    Vector2 _rotation;
    Vector2 _scale;
    std::string _name;
    std::string _id;
    std::vector<std::string> _tags;
    std::string _layer;
    bool _isVisible = true;
};

class Object2D : public BaseObject {
public:
    Object2D() :
            BaseObject("Object2d") {
        syncrect();
    }

    void Render(const Renderer &r) override {
        SDL_SetRenderDrawColor(r.getRenderer(), color.getR(), color.getG(), color.getG(), color.getA());
        SDL_RenderFillRect(r.getRenderer(), &sdlrect);
    }

    void setRect(const Rect &r) {
        rect = r;
        syncrect();
    }

    void SetPosition(const Vector2 &pos) {
        rect.pos = pos;
        syncrect();
    }

    Color color;

private:
    void syncrect() {
        sdlrect.x = rect.pos.x;
        sdlrect.y = rect.pos.y;
        sdlrect.w = rect.getWidth();
        sdlrect.h = rect.getHeight();
    }

    SDL_Rect sdlrect;
};

} // namespace core
