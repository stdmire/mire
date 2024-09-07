#pragma once
#include <SDL_ttf.h>
#include <memory>
#include <string>

inline const std::string DEFAULT_FONT_PATH = "assets/handjet.ttf";
inline const int DEFAULT_FONT_SIZE = 24;

namespace core {
class Font {
public:
    Font(const std::string &filePath, int fontSize);
    Font();
    ~Font();

    TTF_Font *GetFont() const;
    void SetFontSize(int fontSize);

private:
    std::string _filePath;
    std::string _fullfilepath;
    int _fontSize;
    std::unique_ptr<TTF_Font, void (*)(TTF_Font *)> _font;

    bool LoadFont();
};
} // namespace core