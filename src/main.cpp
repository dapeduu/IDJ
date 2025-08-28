#include <SDL.h>

int main(int argc, char** argv) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;
  
  SDL_Window* win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (!win) { SDL_Quit(); return 1; }
  SDL_Event e;
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) running = false;
    }
    SDL_Delay(16);
  }
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}