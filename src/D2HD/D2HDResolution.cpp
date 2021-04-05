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
 *   Defines a class that stores resolutions and the list of resolutions     *
 *   intended for the game.                                                  *
 *                                                                           *
 *****************************************************************************/

#include "D2HDResolution.h"

#include "../SDHD.h"

D2HD::D2HDResolution::D2HDResolution(const int width,
                                     const int height) : width(width), height(height) {
}

int D2HD::D2HDResolution::getWidth() const {
    return D2HD::D2HDResolution::width;
}

int D2HD::D2HDResolution::getHeight() const {
    return D2HD::D2HDResolution::height;
}

int D2HD::D2HDResolution::getResolutionCount() {
    return 4;
}
