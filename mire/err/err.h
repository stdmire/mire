#include <exception>
#include <stdexcept>
#include <string>

namespace err {
class Audio : public std::exception {
private:
    std::string errorMessage;

public:
    explicit Audio(const std::string &message) :
            errorMessage(message) {}

    const char *what() const noexcept override {
        return errorMessage.c_str();
    }
};

class Image : public std::exception {
private:
    std::string errorMessage;

public:
    explicit Image(const std::string &message) :
            errorMessage(message) {}

    const char *what() const noexcept override {
        return errorMessage.c_str();
    }
};

class SDL : public std::exception {
private:
    std::string errorMessage;

public:
    explicit SDL(const std::string &message) :
            errorMessage(message) {}

    const char *what() const noexcept override {
        return errorMessage.c_str();
    }
};

class InvalidFileType : public std::invalid_argument {
public:
    InvalidFileType() :
            std::invalid_argument("Invalid File Type") {};
};

} // namespace err