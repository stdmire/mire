#pragma once
#include "core/font.h"
#include <SDL.h>
#include <memory>
#include <string>

class Label {
public:
    Label(const std::string &text, const SDL_Color &color, int x, int y, std::shared_ptr<core::Font> font);
    ~Label();

    // Function to render the label
    void Render(SDL_Renderer *renderer);

    // Function to set new text
    void SetText(const std::string &text);

    // Function to set position
    void SetPosition(int x, int y);

private:
    std::string text_;
    SDL_Color color_;
    int x_, y_;

    std::shared_ptr<core::Font> font_; // Use shared pointer for font management
    SDL_Texture *texture_; // Texture to render the text
    SDL_Rect rect_; // Rectangle to hold text dimensions

    // Internal function to create texture from text
    void CreateTexture(SDL_Renderer *renderer);
};
