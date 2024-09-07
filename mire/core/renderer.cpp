#include "renderer.h"
// #include <SDL_image.h>
#include <iostream>

namespace core {

// Constructor: Creates an SDL_Renderer
Renderer::Renderer(const Window &window) {
    log::info("initialize renderer");
    log::info(window.title);
    _renderer.reset(SDL_CreateRenderer(window.window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
    if (!_renderer) {
        checkRendererError();
    }
    log::info("success renderer");
}

// Destructor: Destroys the SDL_Renderer
Renderer::~Renderer() {
    if (_renderer) {
        SDL_DestroyRenderer(sdlrenderer);
    }
}

// Clear the screen with the current drawing color
void Renderer::clear() {
    SDL_RenderClear(sdlrenderer);
}

// Present the rendered image to the screen
void Renderer::present() {
    SDL_RenderPresent(sdlrenderer);
}

// Draw a line between two points
void Renderer::drawLine(int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(sdlrenderer, x1, y1, x2, y2);
}

// Render a texture to the screen at a specified rectangle
void Renderer::renderTexture(SDL_Texture *texture, const Rect &rect) {
    SDL_Rect sdlRect = rect.toSDLRect();
    SDL_RenderCopy(sdlrenderer, texture, nullptr, &sdlRect);
}

// Render a portion of a texture with scaling
void Renderer::renderTexture(SDL_Texture *texture, const Rect &srcRect, const Rect &destRect) {
    SDL_Rect srcSDLRect = srcRect.toSDLRect();
    SDL_Rect destSDLRect = destRect.toSDLRect();
    SDL_RenderCopy(sdlrenderer, texture, &srcSDLRect, &destSDLRect);
}

// Get the raw SDL_Renderer object
SDL_Renderer *Renderer::getRenderer() const {
    return sdlrenderer;
}

// Check for renderer-related errors
void Renderer::checkRendererError() const {
    std::cerr << "SDL Renderer Error: " << SDL_GetError() << std::endl;
}

} // namespace core
