#ifndef GAME_H
#define GAME_H

#ifdef __APPLE__
#include <OpenGL/glext.h>
#else
#include <GL/glew.h>
#endif

#include <SDL2/SDL.h>

class Game {
 public:

  Game();
  ~Game();

  void init();

  void processInput(GLfloat dt);
  void update(GLfloat dt);
  void render();
};

#endif
