#include <patatap/game.hpp>

#ifdef _WIN32
#include <windows.h>
int CALLBACK WinMain(
                     _In_ HINSTANCE hInstance,
                     _In_ HINSTANCE hPrevInstance,
                     _In_ LPSTR     lpCmdLine,
                     _In_ int       nCmdShow
                     )
#else
  int main (int argc, char* args[])
#endif
{
  patatap::Game patatap(0, 0, 1280, 720, 6);

  while (patatap.loop) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      patatap.HandleEvents(event);
    }

    patatap.Render(patatap::Game::GetDelta());
  }
  return 0;
}
