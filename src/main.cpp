#include <GL/glew.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "game.hpp"
#include "shapes/defaultShape.hpp"

using namespace std;

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
  Game game;

  glEnable(GL_DEPTH_TEST);

  DefaultShape newShape;

  bool _continue = true;
  while(_continue){

    SDL_Event e;
    while(SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT) {
        _continue = false;
      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    newShape.drawShape();

    SDL_Delay(1000/60);
    SDL_GL_SwapWindow(game.window);
  }

  return 0;
}
