#include <exception>
#include <string>

namespace err {
class Audio : public std::exception {
private:
    std::string errorMessage;

public:
    explicit Audio(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

class Image : public std::exception {
private:
    std::string errorMessage;

public:
    explicit Image(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

}