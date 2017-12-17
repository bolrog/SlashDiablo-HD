/****************************************************************************
*                                                                           *
*   D2HDStructs.h                                                           *
*   Copyright (C) 2017 Mir Drualga                                          *
*                                                                           *
*   D2Ex: Copyright (c) 2011-2014 Bartosz Jankowski                         *
*                                                                           *
*   Licensed under the Apache License, Version 2.0 (the "License");         *
*   you may not use this file except in compliance with the License.        *
*   You may obtain a copy of the License at                                 *
*                                                                           *
*   http://www.apache.org/licenses/LICENSE-2.0                              *
*                                                                           *
*   Unless required by applicable law or agreed to in writing, software     *
*   distributed under the License is distributed on an "AS IS" BASIS,       *
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
*   See the License for the specific language governing permissions and     *
*   limitations under the License.                                          *
*                                                                           *
*---------------------------------------------------------------------------*
*                                                                           *
*   Declares custom structs that are used by this mod.                      *
*                                                                           *
*****************************************************************************/

#pragma once

#ifndef D2HDSTRUCTS_H
#define D2HDSTRUCTS_H

#include <Windows.h>
#include <string>

namespace Color {
    struct RGBFormat {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char tint;
    };

    DWORD FormatRGBtoBGR(RGBFormat* format);
    DWORD FormatRGBtoBGR(DWORD color);
    DWORD FormatRGBtoBGR(std::string color);
}

#endif
