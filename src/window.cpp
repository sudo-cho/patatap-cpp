#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>

#include "window.h"

Window::Window (GLuint t_width, GLuint t_height)
  : m_width(t_width), m_height(t_height)
{

}

void Window::init () {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute (SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  // Depth size down to 16 to supports low end GPU
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

  window = SDL_CreateWindow("patatap c++", 400, 200, m_width, m_height,
                            SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

  if (window == NULL) {
    printf("Could not create window: %s\n", SDL_GetError());
  }

  glcontext = SDL_GL_CreateContext(window);

#ifdef __APPLE__
#else

  GLint error;
  if(GLEW_OK != (error = glewInit())) {
    std::cerr << "Impossible d'initialiser Glew" << std::endl;
  }

#endif

  glEnable(GL_DEPTH_TEST);

  std::cout << glGetString(GL_VERSION) << std::endl;
}

Window::~Window () {
  SDL_GL_DeleteContext(glcontext);
  SDL_Quit();
}
