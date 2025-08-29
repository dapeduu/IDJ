#include "game.hpp"
#include "SDL_mixer.h"

Game& Game::getInstance(){
    if(!instance){
        instance = new Game();
    }

    return *instance;
}

SDL_Renderer* Game::getRenderer(){
    return renderer;
}

void Game::run() {
    // Apos o State
}

Game::Game(){
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return;
    };
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
        printf("IMG_Init failed: %s\n", SDL_GetError());
        return;
    };
    if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
        printf("Mix_Init failed: %s\n", SDL_GetError());
        return;
    };

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
        printf("Mix_OpenAudio failed: %s\n", SDL_GetError());
        return;
    };
    
    window = SDL_CreateWindow("Joguim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Init state
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}