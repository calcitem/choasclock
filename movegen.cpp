// This file is part of ChaosClock.
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

    // TODO: performance

    for (int i = 0; i < 12; i++) {
        if (pos.board[i] != -1 && i != pos.board[i]) {
            *cur++ = (Move)(pos.board[i]);
        }
    }

    if (pos.sideToMove == WHITE) {
        for (int i = 0; i < pos.inHand.size(); i++) {
            if (pos.inHand[i] % 2 == 1) {
                *cur++ = (Move)pos.inHand[i];
            }
        }
    } else {
        for (int i = 0; i < pos.inHand.size(); i++) {
            if (pos.inHand[i] % 2 == 0) {
                *cur++ = (Move)pos.inHand[i];
            }
        }
    }

    *cur++ = MOVE_PASS;

    return cur;
}
