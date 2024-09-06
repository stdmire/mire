#include "font.h"
#include "log.h"

namespace core {
// Custom deleter for unique_ptr to call TTF_CloseFont
auto FontDeleter = [](TTF_Font *font) {
    if (font) {
        TTF_CloseFont(font);
    }
};

Font::Font(const std::string &filePath, int fontSize) :
        _filePath(filePath), _fontSize(fontSize), _font(nullptr, FontDeleter) {
    if (!LoadFont()) {
        log::out("Failed to load font: ", _filePath, " with size: ", _fontSize);
    }
}

Font::~Font() {
    // No need for manual deletion, unique_ptr will handle it
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
    _font.reset(TTF_OpenFont(_filePath.c_str(), _fontSize));
    return _font != nullptr;
}
} // namespace core