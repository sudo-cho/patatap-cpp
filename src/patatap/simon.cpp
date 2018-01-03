#include <patatap/simon.hpp>

namespace patatap {
  Simon::Simon (int tNbSteps)
    : nbSteps(tNbSteps)
  {
    this->initNumbers();
  }

  void Simon::initNumbers () {
    srand (time(NULL));

    for (int i = 0; i < nbSteps; ++i) {
      numbers[i] = rand() % 6 + 1;
    }
  }

  SDL_Event Simon::getKeyCode (int number) {
    SDL_Event sdlevent;
    sdlevent.type = SDL_KEYDOWN;

    switch (number) {
    case 1:
      sdlevent.key.keysym.sym = SDLK_s;
      break;
    case 2:
      sdlevent.key.keysym.sym = SDLK_d;
      break;
    case 3:
      sdlevent.key.keysym.sym = SDLK_f;
      break;
    case 4:
      sdlevent.key.keysym.sym = SDLK_g;
      break;
    case 5:
      sdlevent.key.keysym.sym = SDLK_h;
      break;
    case 6:
      sdlevent.key.keysym.sym = SDLK_j;
      break;
    }

    return sdlevent;
  }

  void Simon::initSequence () {
    if (curStep < nbSteps) {
      switch (curStep) {
      case 0:
        currentKey[0] = getKeyCode(numbers[0]);
        SDL_PushEvent(&currentKey[0]);
        SDL_PushEvent(&currentKey[0]);
        break;
      case 1:
        for(int i = 0; i < 2; i++) {
          currentKey[i] = getKeyCode(numbers[i]);
          SDL_PushEvent(&currentKey[i]);
        }
        break;
      case 2:
        for(int i = 0; i < 3; i++) {
          currentKey[i] = getKeyCode(numbers[i]);
          SDL_PushEvent(&currentKey[i]);
        }
        break;
      case 3:
        for(int i = 0; i < 4; i++) {
          currentKey[i] = getKeyCode(numbers[i]);
          SDL_PushEvent(&currentKey[i]);
        }
        break;
      case 4:
        for(int i = 0; i < 5; i++) {
          currentKey[i] = getKeyCode(numbers[i]);
          SDL_PushEvent(&currentKey[i]);
        }
        break;
      case 5:
        for(int i = 0; i < 6; i++) {
          currentKey[i] = getKeyCode(numbers[i]);
          SDL_PushEvent(&currentKey[i]);
        }
        break;
      }
    }
  }

  void Simon::CheckSequence (SDL_Event keyCodePressed) {
    if(status) {
      if (keyCodePressed.key.keysym.sym == currentKey[0].key.keysym.sym) {
        curStep++;
      }
      else {
        curStep = 0;
      }
    }
  }

  void Simon::toggleStatus () {
    status = true;
  }
}
