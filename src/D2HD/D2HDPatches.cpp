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
 * This file incorporates work covered by the following copyright and        *
 * permission notice:                                                        *
 *                                                                           *
 *   ==========================================================              *
 *   D2Ex2                                                                   *
 *   https://github.com/lolet/D2Ex2                                          *
 *   ==========================================================              *
 *   Copyright (c) 2011-2014 Bartosz Jankowski                               *
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
 *   ==========================================================              *
 *                                                                           *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *   Defines functions that are intended to replace instruction code in      *
 *   the Diablo II game process.                                             *
 *                                                                           *
 *   These functions cannot be called without a proper corresponding         *
 *   interception function.                                                  *
 *                                                                           *
 *****************************************************************************/
#include "D2HDPatches.h"

#include "../SDHD.h"

#include "../../../../src/d2dx/D2DXConfigurator.h"

namespace d2dx
{
    ID2DXConfigurator* GetConfiguratorInternal();
}

void __stdcall D2HD::getModeParams(int mode, int* width, int* height) {
    switch (mode)
    {
    case 0:
        *width = 640;
        *height = 480;
        break;
    case 1:
    case 2:
        *width = 800;
        *height = 600;
        break;
    default:
        d2dx::GetConfiguratorInternal()->GetSuggestedCustomResolution(width, height);
        break;
    }
}

void D2HD::repositionPanels() {
    *D2CLIENT_PanelOffsetX = (*D2CLIENT_WindowWidth / 2) - 320;
    *D2CLIENT_PanelOffsetY = (*D2CLIENT_WindowHeight - 480) / -2;
}

void __stdcall D2HD::getPatchedResolutionMode(int* resolutionMode) {
    *resolutionMode = (*D2CLIENT_WindowWidth >= 800) ? 2 : 0;
}

void __stdcall D2HD::resizeGameLogicResolution(int mode) {
    D2HD::getModeParams(mode, D2CLIENT_WindowWidth, D2CLIENT_WindowHeight);
    *D2CLIENT_InventoryArrangeMode = mode;
}

void __stdcall D2HD::getGameWindowWidth(int* width) {
    *width = *D2GFX_WindowWidth;
}

void __stdcall D2HD::getGameWindowHeight(int* height) {
    *height = *D2GFX_WindowHeight;
}

void __stdcall D2HD::setResolutionMode(int* gameResolution,
                                       int configResolution) {
    if (configResolution == 1) {
        *gameResolution = 2;
    } else {
        *gameResolution = configResolution;
    }
}

enum class VideoOptionsProperty
{
    Unknown,
    Resolution,
    LightingQuality,
    BlendedShadows,
    Perspective
};

void __stdcall D2HD::setResolutionModeFromMenu(int* mode) {
    static auto gameVersion = D2Version::getGameVersion();

    if (!mode) {
        return;
    }

    VideoOptionsProperty videoOptionsProperty = VideoOptionsProperty::Unknown;
    if (gameVersion == GameVersion::VERSION_112) {
        switch ((uintptr_t)mode) {
        case 0x6fb9cbc4: videoOptionsProperty = VideoOptionsProperty::Resolution; break;
        case 0x6fb9d114: videoOptionsProperty = VideoOptionsProperty::LightingQuality; break;
        case 0x6fb9d664: videoOptionsProperty = VideoOptionsProperty::BlendedShadows; break;
        case 0x6fb9dbb4: videoOptionsProperty = VideoOptionsProperty::Perspective; break;
        }
    } 
    else if (gameVersion == GameVersion::VERSION_113c) {
        switch ((uintptr_t)mode) {
        case 0x6fb9abdc: videoOptionsProperty = VideoOptionsProperty::Resolution; break;
        case 0x6fb9b12c: videoOptionsProperty = VideoOptionsProperty::LightingQuality; break;
        case 0x6fb9b67c: videoOptionsProperty = VideoOptionsProperty::BlendedShadows; break;
        case 0x6fb9bbcc: videoOptionsProperty = VideoOptionsProperty::Perspective; break;
        }
    }
    else if (gameVersion == GameVersion::VERSION_113d) {
        switch ((uintptr_t)mode) {
        case 0x6fb94f44: videoOptionsProperty = VideoOptionsProperty::Resolution; break;
        case 0x6fb95494: videoOptionsProperty = VideoOptionsProperty::LightingQuality; break;
        case 0x6fb959e4: videoOptionsProperty = VideoOptionsProperty::BlendedShadows; break;
        case 0x6fb95f34: videoOptionsProperty = VideoOptionsProperty::Perspective; break;
        }
    }

    switch (videoOptionsProperty) {
    case VideoOptionsProperty::Resolution:
        if (*mode > 2) {
            *mode = 0;
        }
        *mode = (1 << *mode) - 1;
        break;
    case VideoOptionsProperty::LightingQuality:
        *mode = *mode % 3;
        break;
    case VideoOptionsProperty::BlendedShadows:
    case VideoOptionsProperty::Perspective:
        *mode = *mode % 2;
        break;
    }
}

void __stdcall D2HD::isMouseOverStatsButton(bool *isMouseOver) {
    const int leftSide = (*D2CLIENT_WindowWidth / 2) - 193;
    const int rightSide = leftSide + 32;
    const int topSide = *D2CLIENT_WindowHeight - 41;
    const int bottomSide = topSide + 32;

    const int mousePositionX = *D2CLIENT_MousePositionX;
    const int mousePositionY = *D2CLIENT_MousePositionY;

    *isMouseOver = ((mousePositionX >= leftSide && mousePositionX <= rightSide)
                    && (mousePositionY >= topSide && mousePositionY <= bottomSide));
}

void __stdcall D2HD::isMouseOverSkillButton(bool *isMouseOver) {
    const int leftSide = (*D2CLIENT_WindowWidth / 2) + 164;
    const int rightSide = leftSide + 32;
    const int topSide = *D2CLIENT_WindowHeight - 41;
    const int bottomSide = topSide + 32;

    const int mousePositionX = *D2CLIENT_MousePositionX;
    const int mousePositionY = *D2CLIENT_MousePositionY;

    *isMouseOver = ((mousePositionX >= leftSide && mousePositionX <= rightSide)
                    && (mousePositionY >= topSide && mousePositionY <= bottomSide));
}

void __stdcall D2HD::setGDIForegroundRenderWidth(int mode) {
    int discarded = 0;
    D2HD::getModeParams(mode, D2GDI_ForegroundRenderWidth, &discarded);
}

void __stdcall D2HD::setDirectDrawRenderResolution(int mode, int* width, int* height) {
    D2HD::getModeParams(mode, width, D2DDRAW_WindowHeight);
    *height = *D2DDRAW_WindowHeight;
}

void __stdcall D2HD::setDirect3DRenderResolution(int mode) {
    D2HD::getModeParams(mode, D2DIRECT3D_WindowWidth, D2DIRECT3D_WindowHeight);
}

void __stdcall D2HD::setGlideRenderResolution(int newGameResolutionMode,
        int* glideResolutionMode) {
    D2HD::getModeParams(newGameResolutionMode, D2GLIDE_WindowWidth,
                        D2GLIDE_WindowHeight);

    switch (newGameResolutionMode) {
    case 0:
        *glideResolutionMode = 7;
        break;

    case 1:
        *glideResolutionMode = 8;
        break;

    default:
        *glideResolutionMode = (newGameResolutionMode - 2) + 8;
        break;
    }

    // Apply special case for /r/Diablo2Resurgence
    if (D2Version::getGlide3xVersion() == Glide3xVersion::RESURGENCE
            && *D2GLIDE_WindowWidth == 1068 && *D2GLIDE_WindowHeight == 600) {
        *glideResolutionMode = 0xFF;
    }

    d2dx::GetConfiguratorInternal()->SetCustomResolution(*D2GLIDE_WindowWidth, *D2GLIDE_WindowHeight);

    *D2GLIDE_SpritesInited = (newGameResolutionMode != 1);
}

void __stdcall D2HD::setupGlideWindowSize(int newGlideResolutionMode) {
    const int resolutionMode = (newGlideResolutionMode == 7) ? 0 : ((
                                   newGlideResolutionMode - 8) + 2);
    D2HD::getModeParams(resolutionMode, *GLIDE3X_WindowWidthPtr, *GLIDE3X_WindowHeightPtr);
}
