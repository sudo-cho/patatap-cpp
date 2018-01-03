#pragma once

#include <patatap/shapes/quad.hpp>
#include <patatap/shapes/square.hpp>
#include <patatap/simon.hpp>

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <string>

#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

namespace patatap {
  class Game {
  public:
    Game(int tPosX, int tPosY, int tSizeX, int tSizeY, int tNbShapes);
    ~Game();

    bool Init();
    bool LoadSounds();
    void CreateShapes();
    void Render(double delta);
    void HandleEvents(const SDL_Event &event);
    static double GetDelta();

    bool loop = true;
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Mix_Chunk *sounds[6];

    std::vector<Shape *> shapes;
    int posX, posY, sizeX, sizeY, nbShapes;

    // change value to adjust simon's says steps
    Simon *simon = new Simon(6);
  };
}
