#include "core/core.h"
#include <SDL.h>
#include <SDL_mixer.h>

auto MusicDeleter = [](Mix_Music *music) {
    if (music) {
        Mix_FreeMusic(music);
    }
};

namespace audio {
class Music {
public:
    Music() :
            music(nullptr, MusicDeleter) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        }
    }

    ~Music() {
        Mix_CloseAudio();
    }

    bool loadBGM(const std::string &path) {
        music.reset(Mix_LoadMUS(path.c_str()));
        if (music == nullptr) {
            log::err("Failed to load BGM! SDL_mixer Error: ", Mix_GetError());
            return false;
        }
        return true;
    }

    void play(int loops = -1) {
        if (music != nullptr) {
            if (Mix_PlayMusic(music.get(), loops) == -1) {
                log::err("Failed to load BGM! SDL_mixer Error: ", Mix_GetError());
            }
        }
    }

    void pause() {
        if (Mix_PlayingMusic() == 1) {
            Mix_PauseMusic();
        }
    }

    void resume() {
        if (Mix_PausedMusic() == 1) {
            Mix_ResumeMusic();
        }
    }

    void stop() {
        Mix_HaltMusic();
    }

private:
    std::unique_ptr<Mix_Music, void (*)(Mix_Music *)> music;
};
} // namespace audio