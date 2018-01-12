/*****************************************************************************
 *                                                                           *
 *   D2Stubs.cpp                                                             *
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
 *    Defines the functions that are used to help call functions in          *
 *    Diablo II that do not conform to standard calling conventions.         *
 *                                                                           *
 *****************************************************************************/

#include "D2Stubs.h"

extern "C" {
HANDLE __stdcall loadMPQStub(DWORD OrderFlag, const char* szDllFile, const char* szMpqFile, const char* szName, DWORD _1, BOOL(__stdcall *fnMPQMissing)(), DWORD func);
}

HANDLE loadMPQ(DWORD OrderFlag, const char* szDllFile, const char* szMpqFile, const char* szName, DWORD _1, BOOL(__stdcall *fnMPQMissing)()) {
    return loadMPQStub(OrderFlag, szDllFile, szMpqFile, szName, _1, fnMPQMissing, D2WIN_LoadMpq_I);
}
