#pragma once
#include "core/baseobject.h"
#include "core/log.h"
#include "vector.h"
#include <string>
#include <vector>

namespace core {

inline std::vector<BaseObject *> reserverdObjects;

class Body {
public:
    Body(BaseObject *o) {
        reserverdObjects.push_back(o);
    }

    core::Vector2 velocity;
    float gravity = 6 * 0.016;
    int mass = 10;

    void Update(BaseObject *curObj) {
        isFall = true;
        for (auto &o : reserverdObjects) {
            if (o == curObj) {
                continue;
            }

            if (o->rect.intersects(curObj->rect)) {
                velocity.y = 0;
                isFall = false;
            }
        }

        if (isFall) {
            velocity.y += gravity;
            curObj->rect.pos.y += velocity.y;
        }
        log::out(velocity);
    }

private:
    bool isFall = false;
};

} // namespace core