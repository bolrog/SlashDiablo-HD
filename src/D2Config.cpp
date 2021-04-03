/*****************************************************************************
 *                                                                           *
 * SlashDiablo HD                                                            *
 * Copyright (C) 2017  Mir Drualga                                           *
 *                                                                           *
 *  This program is free software: you can redistribute it and/or modify     *
 *  it under the terms of the GNU Affero General Public License as published *
 *  by the Free Software Foundation, either version 3 of the License, or     *
 *  (at your option) any later version.                                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU Affero General Public License for more details.                      *
 *                                                                           *
 *  You should have received a copy of the GNU Affero General Public License *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                           *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *   Defines the configuration functions that stores settings and acts as    *
 *   the parent class for derivative mods that also need to have a settings  *
 *   file.                                                                   *
 *                                                                           *
 *****************************************************************************/

#include "D2Config.h"

#include <cstdlib>
#include <regex>
#include <windows.h>
#include <ios>
#include <iostream>
#include <sstream>
#include <string_view>

D2Config::D2Config() : D2Config(DEFAULT_CONFIG_PATH) {
}

D2Config::D2Config(const std::wstring& configPath) : configPath(configPath) {
}
