#include "core/scene.h"
#include "core/game.h"
#include "core/log.h"
#include "core/object.h"

#include "scene.h"
#include <iostream>

namespace core {
void Scene::PushObject(std::shared_ptr<BaseObject> obj) {
    log::info("pushed", obj->_name, "to", _name, "scene");

    _objects.push_back(obj);
}

void Scene::Render(const Renderer &w) {
    for (auto &layer : _layers) {
        for (auto &object : _objects) {
            if (object->_layer == layer.Name) {
                if (object->_isVisible) {
                    // log::info("drawing object", object->_name, "at layer: ", object->_layer);
                    object->Render(w);
                }
            }
        }
    }
    return;
}

void Scene::Initialize(const Renderer &renderer) {
    for (auto &object : _objects) {
        log::info("initializing", object->_name);
        object->OnInit(renderer);
    }

    return;
}

std::shared_ptr<BaseObject> Scene::GetObject(std::string name) {
    for (auto &obj : _objects) {
        if (obj->_name == name) {
            log::info("getting object: ", obj->_name.c_str());
            return obj;
        }
    }

    throw;
}

Scene::Scene(const char *name) :
        _name(name) {
    log::info(name, "scene created");
    _layers.push_back(Layer{ "Default", 0 });
}

} // namespace core