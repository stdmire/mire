#include "menu_scene.h"

int main() {
    log::info("Starting the app");
    core::Game app;
    auto menuScene = std::make_unique<MenuScene>();
    app.AddScene(std::move(menuScene));

    app.Run();
}
