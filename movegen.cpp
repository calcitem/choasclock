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

    int pc = NO_PIECE;

    for (int i = 0; i < 12; i++) {
        pc = pos.board[i];

        if (pc > 0 && pc != i && pc != pos.lastMove) {
            int newLocation = (i + pc) % 12;

            if (!pos.isFixed(newLocation)) {
                *cur++ = (Move)pc;
            }
        }
    }

    if (pos.sideToMove == ODD) {
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

    // Pass only when no move to do
    if (cur == moveList) {
        *cur++ = MOVE_PASS;
    }

    return cur;
}
