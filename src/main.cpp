#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <string>
#include <glimac/common.hpp>

#include "game.hpp"
#include "draw.hpp"

using namespace std;
using namespace glimac;

#ifdef _WIN32
#include <windows.h>
int CALLBACK WinMain(
                     _In_ HINSTANCE hInstance,
                     _In_ HINSTANCE hPrevInstance,
                     _In_ LPSTR     lpCmdLine,
                     _In_ int       nCmdShow
                     )
#else
  int main(int argc, char *argv[])
#endif
{
  // initialization
  Game game;

  glEnable(GL_DEPTH_TEST);

  Program program;

  GLuint locationMVPMatrix = 0, locationMVMatrix = 0, locationNormalMatrix = 0;

  game.initProgram(&program, &locationMVPMatrix, &locationMVMatrix, &locationNormalMatrix);

  DefaultShape newShape;

  bool _continue = true;
  while(_continue){
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT) {
        _continue = false; // Leave the loop after this iteration
      }
    }

    /* game draw objects*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    newShape.drawShape();

    SDL_Delay(1000/60);
    SDL_GL_SwapWindow(game.window);
  }

  delete game;
  return 0;
}
