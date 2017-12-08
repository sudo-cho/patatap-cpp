#ifndef WINDOW_H
#define WINDOW_H

#ifdef __APPLE__
#include <OpenGL/glext.h>
#else
#include <GL/glew.h>
#endif

#include <SDL2/SDL.h>

class Window{
 public:
  SDL_Window *window;
  SDL_GLContext glcontext;
  GLuint m_width, m_height;

  Window(GLuint t_width, GLuint t_height);
  ~Window();

  void init();
};

#endif
