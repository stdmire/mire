#include "err/err.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>

namespace audio {
class Sound {
public:
    Sound() :
            sound(nullptr) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            throw err::Audio(SDL_GetError());
        }
    }

    ~Sound() {
        cleanUp();
    }

    bool loadSound(const std::string &path) {
        sound = Mix_LoadWAV(path.c_str());
        if (sound == nullptr) {
            throw err::Audio(Mix_GetError());
        }
        return true;
    }

    void play(int loops = 0) {
        if (sound != nullptr) {
            if (Mix_PlayChannel(-1, sound, loops) == -1) {
                throw err::Audio(Mix_GetError());
            }
        }
    }

    void setVolume(int volume) {
        _volume = volume;
        if (sound != nullptr) {
            Mix_VolumeChunk(sound, _volume);
        }
    }

    void cleanUp() {
        if (sound != nullptr) {
            Mix_FreeChunk(sound);
            sound = nullptr;
        }
        Mix_CloseAudio();
        SDL_Quit();
    }

private:
    Mix_Chunk *sound;
    int _volume = 60;
};

} // namespace audio