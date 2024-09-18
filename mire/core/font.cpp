#include "font.h"
#include "log.h"
#include "utils.h"

namespace core {
const auto FontDeleter = [](TTF_Font *font) {
    if (font) {
        TTF_CloseFont(font);
    }
};

Font::Font(const std::string &filePath, int fontSize) :
        file(filePath), _fontSize(fontSize), _font(nullptr, FontDeleter) {
    if (!LoadFont()) {
        log::err("Failed to load font: ", file.FullPath(), " with size: ", _fontSize);
    }
}

Font::Font() :
        file(DEFAULT_FONT_PATH), _fontSize(DEFAULT_FONT_SIZE), _font(nullptr, FontDeleter) {
    if (!LoadFont()) {
        log::err("Failed to load font: ", file.FullPath(), " with size: ", _fontSize);
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
    _font.reset(TTF_OpenFont(file.FullPath().c_str(), _fontSize));
    if (_font == nullptr) {
        log::err(TTF_GetError());
    }
    return _font != nullptr;
}
} // namespace core