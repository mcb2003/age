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

#include <iostream>

#include <SDL2/SDL.h>

#include "engine.h"

int main(int, char **) {
  try {
    AGE::Engine engine{"Blind Computing", "Test Program"};
    SDL_Log("Pref path: %s", engine.getPrefPath().c_str());
    return engine.start();
  } catch (const char *err) {
    // SDL initialisation error
    // The SDL_Log* functions don't require SDL to be initialised to work
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialise engine: %s",
                 err);
    return 1;
  }
}
