/*****************************************************************************
 *                                                                           *
 * SlashDiablo HD                                                           *
 * Copyright (C) 2017  Mir Drualga                                          *
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
 *   Defines the functions that read and write to a configuration file.      *
 *                                                                           *
 *   This file can be modified to add more configuration options.            *
 *                                                                           *
 *****************************************************************************/

#include "D2HDConfig.h"

#include <windows.h>

#include <regex>
#include <sstream>
#include <string>

#include "../SDHD.h"
#include "D2HDColor.h"

const D2HD::D2HDColor D2HD::D2HDConfig::DEFAULT_COLOR(255, 255, 255, 255);

void __stdcall D2HD::getConfigResolution(int* mode) {
    *mode = 3;
}

void __stdcall D2HD::setConfigResolution(int mode) {
}
