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
 *   Declares functions that read and write to a configuration file.         *
 *                                                                           *
 *   It is here that mod-makers can modify macros to apply acceptable        *
 *   settings for their users. One such important setting specifies the      *
 *   number of custom resolutions available, including the first two         *
 *   standard resolutions.                                                   *
 *                                                                           *
 *****************************************************************************/

#pragma once

#ifndef D2HDCONFIG_H
#define D2HDCONFIG_H

#include "../D2Config.h"
#include "D2HDColor.h"

namespace D2HD {
class D2HDConfig {
public:
    static constexpr int MINIMUM_WIDTH = 640;
    static constexpr int MINIMUM_HEIGHT = 480;
    static constexpr int MAXIMUM_WIDTH = 1068;
    static constexpr int MAXIMUM_HEIGHT = 600;
    static constexpr unsigned int DEFAULT_COLOR_HEX = 0xFFFFFFFF;
    static const D2HD::D2HDColor DEFAULT_COLOR;

    static constexpr bool DEFAULT_ENABLE_800_CONTROL_PANEL = true;
    static constexpr bool DEFAULT_ENABLE_D2MR_BACKGROUND_RIBBON = true;
    static constexpr bool DEFAULT_ENABLE_D2MR_PANEL_BORDER_STYLE = false;
    static constexpr bool DEFAULT_FLIP_D2MR_CONTROL_PANEL = true;
};

extern "C"  void __stdcall getConfigResolution(int* mode);
extern "C"  void __stdcall getConfigResolutionInterception(int* mode);
extern "C"  void __stdcall setConfigResolution(int mode);
extern "C"  void __stdcall setConfigResolutionInterception(int mode);
}

#endif
