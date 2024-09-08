#include "font.h"
#include "log.h"
#include "utils.h"

namespace core {
auto FontDeleter = [](TTF_Font *font) {
    if (font) {
        TTF_CloseFont(font);
    }
};

Font::Font(const std::string &filePath, int fontSize) :
        _filePath(filePath), _fontSize(fontSize), _font(nullptr, FontDeleter) {
    _fullfilepath = core::GetFullPath(_filePath.c_str());
    if (!LoadFont()) {
        log::out("Failed to load font: ", _fullfilepath, " with size: ", _fontSize);
    }
}

Font::Font() :
        _filePath(DEFAULT_FONT_PATH), _fontSize(DEFAULT_FONT_SIZE), _font(nullptr, FontDeleter) {
    _fullfilepath = core::GetFullPath(_filePath.c_str());
    if (!LoadFont()) {
        log::out("Failed to load font: ", _fullfilepath, " with size: ", _fontSize, "full path:", _fullfilepath);
    }
}

Font::~Font() {
}

TTF_Font *Font::GetFont() const {
    return _font.get();
}

void Font::SetFontSize(int fontSize) {
    _fontSize = fontSize;
    _font.reset();
    LoadFont();
}

bool Font::LoadFont() {
    _font.reset(TTF_OpenFont(_fullfilepath.c_str(), _fontSize));
    if (_font == nullptr) {
        log::out(TTF_GetError());
    }
    return _font != nullptr;
}
} // namespace core