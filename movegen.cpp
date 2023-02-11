﻿// This file is part of ChaosClock.
// Copyright (C) 2023 The ChaosClock developers (see AUTHORS file)
//
// ChaosClock is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// ChaosClock is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "movegen.h"
#include "position.h"

ExtMove *generate(Position &pos, ExtMove *moveList)
{
    ExtMove *cur = moveList;

    pos = pos; // TODO: For suppress build warning
    
    for (int m = -1; m < 12; ++m) {
        // TODO: Filter bad moves
        *cur++ = (Move)m;
    }

    return cur;
}
