#include <patatap/game.hpp>

using namespace std::chrono;

// SDL_delay replaced by c++11 chrono, timePrev is declared global, it's a bit dirty but it works fine.
auto timePrev = std::chrono::high_resolution_clock::now();

namespace patatap {
  Game::Game (int tPosX, int tPosY, int tSizeX, int tSizeY, int tNbShapes)
    : posX(tPosX), posY(tPosY), sizeX(tSizeX), sizeY(tSizeY), nbShapes(tNbShapes)
  {
    this->Init();
    this->CreateShapes();
    this->LoadSounds();

    try {
      if (nbShapes > 6) {
        throw std::string("you cannot add more than 6 shapes");
      }
      else if (this->nbShapes == 0) {
        throw std::string("you must add a shape");
      }
    }
    catch(std::string const& stringErr) {
      std::cerr << stringErr << std::endl;
      this->nbShapes = 6;
    }
  }

  Game::~Game () {
    for (int i=0; i<6; ++i) {
      Mix_FreeChunk(sounds[i]);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }

  bool Game::Init () {

    if (SDL_Init( SDL_INIT_EVERYTHING ) == -1) {
      std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
      return false;
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
      printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
      return false;
    }

    this->window = SDL_CreateWindow("patatap", this->posX, this->posY, this->sizeX, this->sizeY, 0);

    if (this->window == nullptr) {
      std::cout << "Failed to create window : " << SDL_GetError();
      return false;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, 0);

    if (this->renderer == nullptr) {
      std::cout << "Failed to create renderer : " << SDL_GetError();
      return false;
    }

    SDL_RenderSetLogicalSize(this->renderer, this->sizeX, this->sizeY);
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);


    return true;
  }

  bool Game::LoadSounds () {
    sounds[0] = Mix_LoadWAV("sounds/01.wav");
    sounds[1] = Mix_LoadWAV("sounds/02.wav");
    sounds[2] = Mix_LoadWAV("sounds/03.wav");
    sounds[3] = Mix_LoadWAV("sounds/04.wav");
    sounds[4] = Mix_LoadWAV("sounds/05.wav");
    sounds[5] = Mix_LoadWAV("sounds/06.wav");

    return true;
  }

  void Game::CreateShapes () {
    srand (time(NULL));

    int ranW = 0;
    int ranH = 0;

    const int OFFSET = 50;

    for (int i = 0; i < 6; ++i) {
      int ranX = rand() % (sizeX - 100) + OFFSET;
      int ranY = rand() % (sizeY - 100) + OFFSET;
      int type = rand() % 2 + 1;
      int anim = rand() % 2;

      switch (type) {
      case 1:
        shapes.push_back(new Square(ranX, ranY, ranW, ranH, anim));
        break;
      case 2:
        shapes.push_back(new Quad(ranX, ranY, ranW, anim));
        break;
      }
    }
  }

  void Game::Render (double delta) {
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
      (*it)->InitAnimation(delta);
      SDL_Rect elm = (*it)->GetShape();
      SDL_RenderFillRect(renderer,  const_cast<SDL_Rect*>(&elm));
    }

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderPresent( renderer);
  }

  void Game::HandleEvents (const SDL_Event &event) {
    switch(event.type) {
    case SDL_QUIT:
    case SDL_APP_TERMINATING:
      this->loop = false;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_s:
        Mix_PlayChannel( -1, sounds[0], 0 );
        shapes[0]->ToggleAnimation();
        this->simon->CheckSequence(event);
        break;
      case SDLK_d:
        Mix_PlayChannel( -1, sounds[1], 0 );
        shapes[1]->ToggleAnimation();
        this->simon->CheckSequence(event);
        break;
      case SDLK_f:
        Mix_PlayChannel( -1, sounds[2], 0 );
        shapes[2]->ToggleAnimation();
        this->simon->CheckSequence(event);
        break;
      case SDLK_g:
        Mix_PlayChannel( -1, sounds[3], 0 );
        shapes[3]->ToggleAnimation();
        this->simon->CheckSequence(event);
        break;
      case SDLK_h:
        Mix_PlayChannel( -1, sounds[4], 0 );
        shapes[4]->ToggleAnimation();
        this->simon->CheckSequence(event);
        break;
      case SDLK_j:
        Mix_PlayChannel( -1, sounds[5], 0 );
        shapes[5]->ToggleAnimation();
        this->simon->CheckSequence(event);
        break;
      case SDLK_SPACE:
        this->simon->toggleStatus();
        this->simon->initSequence();
        break;
      }
      break;
    }
  }

  // Returns time since last time this function was called in seconds with nanosecond precision
  double Game::GetDelta () {
    auto timeCurrent = high_resolution_clock::now();
    auto timeDiff = duration_cast< nanoseconds >( timeCurrent - timePrev );

    double delta = timeDiff.count();
    delta /= 1000000000;

    timePrev = timeCurrent;
    return delta;
  }
}
