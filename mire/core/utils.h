#pragma once

#include "log.h"

namespace core {
inline std::string GetFullPath(const char *path) {
#ifdef ROOT_DIR
#define STR(str) #str
#define STRING(str) STR(str)
    auto fullpath = std::string(STRING(ROOT_DIR)) + std::string(path);
    return fullpath;
#endif
    return path;
}
} // namespace core
