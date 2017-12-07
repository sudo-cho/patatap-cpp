#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include <assert.h>

#include "game.hpp"

Game::Game () {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  window = SDL_CreateWindow("patatap c++", 400, 200, 640, 640,
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

  std::cout << glGetString(GL_VERSION) << std::endl;
}

Game::~Game () {
  SDL_GL_DeleteContext(this->glcontext);
	SDL_Quit();
}
