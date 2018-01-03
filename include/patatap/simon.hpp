#pragma once

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <SDL2/SDL.h>

namespace patatap {
  class Simon {
  public:
    // max steps are 6
    Simon(int tNbSteps);
    ~Simon();

    void initNumbers();
    SDL_Event getKeyCode(int number);
    void initSequence();
    void CheckSequence(SDL_Event keyCodePressed);
    void toggleStatus();
  private:
    int nbSteps;
    int curStep{0};
    int numbers[6];
    bool status = false;
    SDL_Event currentKey[6];
  };
}
