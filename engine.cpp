/*
    age - A simple, fast Audio Game Engine
    Copyright (C) 2020  Michael Connor Buchan

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Author: Michael Connor Buchan <mikey@blindcomputing.org>
   */

/* SPDXLicenseIdentifier: LGPL-3-or-later */

#include "engine.h"

namespace AGE {
// Engine constructor
Engine::Engine(const char *title, int width, int height, std::uint32_t flags)
    : m_win{nullptr} {
  // Initialise SDL subsystems
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    throw SDL_GetError();

  // Create a window
  if (!(m_win = SDL_CreateWindow(title, 0, 0, width, height, flags)))
    throw SDL_GetError();
}

Engine::~Engine() {
  SDL_DestroyWindow(m_win);
  SDL_Quit();
}
} // namespace AGE
