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

void BaseObject::Translate(const Vector3 &offset) {
    _position += offset;
}

// Setter methods
void BaseObject::setPosition(const Vector3 &position) {
    _position = position;
}

void BaseObject::setRotation(const Vector3 &rotation) {
    _rotation = rotation;
}

void BaseObject::setScale(const Vector3 &scale) {
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
} // namespace core