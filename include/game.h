#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "window.h"

class Game {
 public:

  Game();
  ~Game();

  void init(Window &win);

  void processInput(GLfloat dt);
  void update(GLfloat dt);
  void render();
};

#endif
