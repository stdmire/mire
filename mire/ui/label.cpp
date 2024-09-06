#include "label.h"
#include "core/font.h"
#include <SDL_ttf.h>

Label::Label(const std::string &text, const SDL_Color &color, int x, int y, std::shared_ptr<core::Font> font) :
        text_(text), color_(color), x_(x), y_(y), font_(font), texture_(nullptr) {
    rect_.x = x_;
    rect_.y = y_;
}

Label::~Label() {
    if (texture_) {
        SDL_DestroyTexture(texture_);
    }
}

void Label::Render(SDL_Renderer *renderer) {
    if (texture_ == nullptr) {
        CreateTexture(renderer);
    }
    SDL_RenderCopy(renderer, texture_, nullptr, &rect_);
}

void Label::SetText(const std::string &text) {
    if (text_ != text) {
        text_ = text;
        if (texture_) {
            SDL_DestroyTexture(texture_);
            texture_ = nullptr;
        }
    }
}

void Label::SetPosition(int x, int y) {
    x_ = x;
    y_ = y;
    rect_.x = x_;
    rect_.y = y_;
}

void Label::CreateTexture(SDL_Renderer *renderer) {
    if (font_ && font_->GetFont()) {
        SDL_Surface *surface = TTF_RenderText_Blended(font_->GetFont(), text_.c_str(), color_);
        if (surface) {
            texture_ = SDL_CreateTextureFromSurface(renderer, surface);
            rect_.w = surface->w;
            rect_.h = surface->h;
            SDL_FreeSurface(surface);
        }
    }
}
