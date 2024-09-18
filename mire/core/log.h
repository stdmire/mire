#pragma once
#include <iostream>
#include <json.hpp>
#include <sstream>

namespace log {
template <typename T>
void out(T &&arg) {
    std::cout << arg << std::endl;
}

template <typename T, typename... Args>
void out(T &&arg, Args &&...restArgs) {
    std::cout << arg << " ";
    out(std::forward<Args>(restArgs)...);
}

inline void info(const char *message) {
    nlohmann::json j;
    j["message"] = message;
    out(j);
}

template <typename... Args>
void info(Args... args) {
    std::ostringstream oss;
    auto add_to_stream = [&](const auto &arg) {
        if constexpr (sizeof...(args) > 0) {
            oss << arg << " ";
        } else {
            oss << arg;
        }
    };

    (add_to_stream(args), ...);

    std::string result = oss.str();

    if (!result.empty()) {
        result.erase(result.size() - 1);
    }

    nlohmann::json j;
    j["message"] = result;
    out(j);
}

inline void err(const char *message) {
    nlohmann::json j;
    j["ERROR"] = message;
    out(j);
}

template <typename... Args>
void err(Args... args) {
    std::ostringstream oss;
    auto add_to_stream = [&](const auto &arg) {
        if constexpr (sizeof...(args) > 0) {
            oss << arg << " ";
        } else {
            oss << arg;
        }
    };

    (add_to_stream(args), ...);

    std::string result = oss.str();

    if (!result.empty()) {
        result.erase(result.size() - 1);
    }

    nlohmann::json j;
    j["ERROR"] = result;
    out(j);
}

} // namespace log