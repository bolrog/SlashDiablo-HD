; /*****************************************************************************
;  *                                                                           *
;  * SlashDiablo HD                                                            *
;  * Copyright (C) 2017  Mir Drualga                                           *
;  *                                                                           *
;  *  This program is free software: you can redistribute it and/or modify     *
;  *  it under the terms of the GNU Affero General Public License as published *
;  *  by the Free Software Foundation, either version 3 of the License, or     *
;  *  (at your option) any later version.                                      *
;  *                                                                           *
;  *  This program is distributed in the hope that it will be useful,          *
;  *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
;  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
;  *  GNU Affero General Public License for more details.                      *
;  *                                                                           *
;  *  You should have received a copy of the GNU Affero General Public License *
;  *  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
;  *                                                                           *
;  *---------------------------------------------------------------------------*
;  *                                                                           *
;  *   The file defines the interception functions used to call the draw       *
;  *   functions safely.                                                       *
;  *                                                                           *
;  *****************************************************************************/
.386
.MODEL FLAT

PUBLIC _determineVideoOptionTextInterception
PUBLIC _drawControlPanel800ForegroundInterception
PUBLIC _drawControlPanelBackgroundInterception
PUBLIC _drawPanelBackgroundInterception

PUBLIC _drawActiveStatsButtonInterception
PUBLIC _drawInactiveStatsButtonInterception
PUBLIC _drawStatsButtonTextInterception

PUBLIC _drawActiveSkillButtonInterception
PUBLIC _drawInactiveSkillButtonInterception
PUBLIC _drawSkillButtonTextInterception

PUBLIC _unloadCellFilesInterception

EXTERN _determineVideoOptionText@16 :PROC
EXTERN _drawControlPanel800Foreground :PROC
EXTERN _drawControlPanelBackground :PROC
EXTERN _drawPanelBackground :PROC
EXTERN _drawActiveStatsButton@0 :PROC
EXTERN _drawInactiveStatsButton@0 :PROC
EXTERN _drawStatsButtonText@0 :PROC
EXTERN _drawActiveSkillButton@0 :PROC
EXTERN _drawInactiveSkillButton@0 :PROC
EXTERN _drawSkillButtonText@0 :PROC
EXTERN _unloadCellFiles@4 :PROC

_TEXT SEGMENT

_determineVideoOptionTextInterception:
    ; Original code
    mov ecx, dword ptr [eax + ecx * 4 + 540h]

    push edx
    sub esp, 4
    lea edx, dword ptr [esp]
    pushad
    push ecx
    push esi
    push eax
    push edx
    call _determineVideoOptionText@16
    popad
    mov ecx, dword ptr [edx]
    add esp, 4
    pop edx
    ret

_drawControlPanel800ForegroundInterception:
    pushad
    call _drawControlPanel800Foreground
    popad
    ret

_drawControlPanelBackgroundInterception:
    pushad
    call _drawControlPanelBackground
    popad

    ;Original code
    mov ecx, 18
    ret

_drawPanelBackgroundInterception:
    pushad
    call _drawPanelBackground
    popad

    ;Original code
    add esp, 128h
    ret

_drawActiveStatsButtonInterception:
    pushad
    call _drawActiveStatsButton@0
    popad
    ret

_drawInactiveStatsButtonInterception:
    pushad
    call _drawInactiveStatsButton@0
    popad
    ret

_drawStatsButtonTextInterception:
    pushad
    call _drawStatsButtonText@0
    popad
    ret

_drawActiveSkillButtonInterception:
    pushad
    call _drawActiveSkillButton@0
    popad
    ret

_drawInactiveSkillButtonInterception:
    pushad
    call _drawInactiveSkillButton@0
    popad
    ret

_drawSkillButtonTextInterception:
    pushad
    call _drawSkillButtonText@0
    popad
    ret

_unloadCellFilesInterception:
    sub esp, 4
    lea esi, dword ptr [esp]
    pushad
    push esi
    call _unloadCellFiles@4
    popad
    mov esi, dword ptr [esi]
    add esp, 4
    ret

_TEXT ENDS

END
