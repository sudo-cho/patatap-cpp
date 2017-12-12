#include <GL/glew.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#else
#include <GL/gl.h>
#endif

#include <iostream>
#include <SDL2/SDL.h>
#include <string>

#include "game.h"
#include "window.h"
#include "helpers/resource_manager.h"

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
  Window win(640, 480);
  Game patatap;

  patatap.init(win);

  bool _continue = true;
  while(_continue){

    SDL_Event e;
    while(SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT) {
        _continue = false;
      }

      switch(e.type) {
      case SDL_KEYDOWN:
        std::cout << "keydown pressed" << std::endl;
        break;
      }
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    patatap.render();

    SDL_Delay(1000/60);
    SDL_GL_SwapWindow(win.window);
  }

  ResourceManager::Clear();

  return 0;
}
