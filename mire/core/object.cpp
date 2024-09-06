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

    log::info("object with name", _name);
}

void BaseObject::Translate(const Vector3 &offset) {
    _position += offset;
}

} // namespace core