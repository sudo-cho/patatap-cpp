#pragma once

#include <SDL2/SDL.h>

class Game {

public:
  SDL_Window *window;
  SDL_GLContext glcontext;

  Game();
  ~Game();
};
