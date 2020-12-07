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

#ifndef AGE_ENGINE_H
#define AGE_ENGINE_H

#include <cstdint>
#include <string>

#include <SDL2/SDL.h>

namespace AGE {
class Engine {
private:
  SDL_Window *m_win;
  SDL_Renderer *m_ren;

protected:
  int m_width;
  int m_height;
  const std::string m_org;
  const std::string m_name;

public:
  Engine(const char *org, const char *name, int width = 640, int height = 480);
  ~Engine();

  Engine(const Engine &) = delete;
  Engine &operator=(const Engine &) = delete;

  int start(std::uint32_t flags = SDL_WINDOW_ALLOW_HIGHDPI);

  // Get the path to the directory where preferences can be stored
  std::string getPrefPath(const char *file = "");
};
} // namespace AGE

#endif
