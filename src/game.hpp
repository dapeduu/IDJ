#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL 
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

class Game {
  public:
    ~Game();
    void run();
    SDL_Renderer* getRenderer();
    Game& getInstance();
  private:
    Game();
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // GAME_H