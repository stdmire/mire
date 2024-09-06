#include <SDL.h>
#include <iostream>

#include "core/game.h"
#include "core/log.h"
#include "menu_scene.h"
#include <memory>

int main() {
    log::out("Starting the app kontol");
    core::Game app;
    auto menuScene = std::unique_ptr<MenuScene>();
    app._currentScene = std::move(menuScene);

    app.Run();
}

// Konstanta untuk ukuran jendela
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Ukuran paddle
const int PADDLE_WIDTH = 20;
const int PADDLE_HEIGHT = 100;
const int BALL_SIZE = 20;

// Kecepatan paddle dan bola
const int PADDLE_SPEED = 10;
const int BALL_SPEED = 5;

// Struct untuk paddle
struct Paddle {
    int x, y;
    int width, height;
};

// Struct untuk bola
struct Ball {
    int x, y;
    int width, height;
    int velX, velY;
};

// Fungsi untuk menangani input paddle
void handleInput(SDL_Event &event, bool &up, bool &down) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_UP) up = true;
        if (event.key.keysym.sym == SDLK_DOWN) down = true;
    }
    if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_UP) up = false;
        if (event.key.keysym.sym == SDLK_DOWN) down = false;
    }
}

// Fungsi untuk update posisi paddle
void updatePaddle(Paddle &paddle, bool up, bool down) {
    if (up && paddle.y > 0) paddle.y -= PADDLE_SPEED;
    if (down && paddle.y + paddle.height < WINDOW_HEIGHT) paddle.y += PADDLE_SPEED;
}

// Fungsi untuk update posisi bola
void updateBall(Ball &ball, Paddle &leftPaddle, Paddle &rightPaddle) {
    ball.x += ball.velX;
    ball.y += ball.velY;

    // Pantulan di dinding atas dan bawah
    if (ball.y <= 0 || ball.y + ball.height >= WINDOW_HEIGHT) {
        ball.velY = -ball.velY;
    }

    // Pantulan di paddle kiri
    if (ball.x <= leftPaddle.x + leftPaddle.width &&
            ball.y + ball.height >= leftPaddle.y &&
            ball.y <= leftPaddle.y + leftPaddle.height) {
        ball.velX = -ball.velX;
    }

    // Pantulan di paddle kanan
    if (ball.x + ball.width >= rightPaddle.x &&
            ball.y + ball.height >= rightPaddle.y &&
            ball.y <= rightPaddle.y + rightPaddle.height) {
        ball.velX = -ball.velX;
    }

    // Reset bola jika keluar dari layar
    if (ball.x <= 0 || ball.x + ball.width >= WINDOW_WIDTH) {
        ball.x = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
        ball.y = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;
        ball.velX = BALL_SPEED * (ball.velX > 0 ? -1 : 1); // Arah pantulan tetap
        ball.velY = BALL_SPEED;
    }
}

// Fungsi untuk merender paddle dan bola
void render(SDL_Renderer *renderer, Paddle &leftPaddle, Paddle &rightPaddle, Ball &ball) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Paddle kiri
    SDL_Rect leftRect = { leftPaddle.x, leftPaddle.y, leftPaddle.width, leftPaddle.height };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &leftRect);

    // Paddle kanan
    SDL_Rect rightRect = { rightPaddle.x, rightPaddle.y, rightPaddle.width, rightPaddle.height };
    SDL_RenderFillRect(renderer, &rightRect);

    // Bola
    SDL_Rect ballRect = { ball.x, ball.y, ball.width, ball.height };
    SDL_RenderFillRect(renderer, &ballRect);

    SDL_RenderPresent(renderer);
}

int s(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Paddle kiri dan kanan
    Paddle leftPaddle = { 50, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT };
    Paddle rightPaddle = { WINDOW_WIDTH - 50 - PADDLE_WIDTH, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT };

    // Bola
    Ball ball = { WINDOW_WIDTH / 2 - BALL_SIZE / 2, WINDOW_HEIGHT / 2 - BALL_SIZE / 2, BALL_SIZE, BALL_SIZE, BALL_SPEED, BALL_SPEED };

    bool running = true;
    bool leftUp = false, leftDown = false;
    bool rightUp = false, rightDown = false;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            // Input untuk paddle kiri
            handleInput(event, leftUp, leftDown);

            // Input untuk paddle kanan
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_w) rightUp = true;
                if (event.key.keysym.sym == SDLK_s) rightDown = true;
            }
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_w) rightUp = false;
                if (event.key.keysym.sym == SDLK_s) rightDown = false;
            }
        }

        // Update paddle dan bola
        updatePaddle(leftPaddle, leftUp, leftDown);
        updatePaddle(rightPaddle, rightUp, rightDown);
        updateBall(ball, leftPaddle, rightPaddle);

        // Render scene
        render(renderer, leftPaddle, rightPaddle, ball);

        SDL_Delay(16); // Delay untuk membuat FPS sekitar 60
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
