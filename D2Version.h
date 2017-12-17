/****************************************************************************
*                                                                           *
*   D2Version.h                                                             *
*   Copyright (C) 2017 Mir Drualga                                          *
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
*   This file is used to declare the functions and Diablo II versions that  *
*   are to be detected from Game.exe.                                       *
*                                                                           *
*****************************************************************************/

#pragma once

#ifndef _D2VERSION_H
#define _D2VERSION_H

#include <string>

enum VersionID {
    INVALID = -1,
    VERSION_113c = 0,
    VERSION_113d
};

namespace D2Version {
    extern VersionID versionID;
    VersionID GetGameVersionID();
    void Init();
    std::string GetGameVersionString();
};

#endif
