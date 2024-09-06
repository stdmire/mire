#pragma once
#include <SDL_ttf.h>
#include <memory>
#include <string>

namespace core {
class Font {
public:
    Font(const std::string &filePath, int fontSize);
    ~Font();

    TTF_Font *GetFont() const;
    void SetFontSize(int fontSize);

private:
    std::string _filePath;
    int _fontSize;
    std::unique_ptr<TTF_Font, void (*)(TTF_Font *)> _font;

    bool LoadFont();
};
} // namespace core