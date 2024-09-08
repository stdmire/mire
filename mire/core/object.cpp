#include "core/object.h"
#include "core/log.h"
#include "object.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#define STR(str) #str
#define STRING(str) STR(str)

namespace core {
BaseObject::BaseObject(const char *name) {
    _name = name;
    using namespace std::chrono;
    auto msSinceEpoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    _id = _name + "-" + std::to_string(msSinceEpoch.count());
    _layer = "Default";

    log::info("object", _name, "created successfully");
}

BaseObject::~BaseObject() {
    log::info("object", _name, "deleted successfully");
}

void BaseObject::setVisibility(bool isvisible) {
    _isVisible = isvisible;
}

void BaseObject::setRotation(const Vector2 &rotation) {
    _rotation = rotation;
}

void BaseObject::setScale(const Vector2 &scale) {
    _scale = scale;
}

void BaseObject::setName(const std::string &name) {
    _name = name;
}

void BaseObject::setId(const std::string &id) {
    _id = id;
}

void BaseObject::setTags(const std::vector<std::string> &tags) {
    _tags = tags;
}

void BaseObject::setLayer(const std::string &layer) {
    _layer = layer;
}

Vector2 BaseObject::getRotation() const {
    return _rotation;
}

Vector2 BaseObject::getScale() const {
    return _scale;
}

std::string BaseObject::getName() const {
    return _name;
}

std::string BaseObject::getId() const {
    return _id;
}

std::vector<std::string> BaseObject::getTags() const {
    return _tags;
}

bool BaseObject::getVisibility() const {
    return _isVisible;
}

std::string BaseObject::getLayer() const {
    return _layer;
}

} // namespace core