#include "engine.h"

namespace AGE {
Engine::Engine() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw SDL_GetError();
  }
}

Engine::~Engine() { SDL_Quit(); }
} // namespace AGE
