/*
 * the royal game of ur - A student indie game
 * Copyright (C) 2018-2019 to al kes ishaq yousif
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <array>
#include "Position2i.h"
#include "Piece.h"
#ifndef PLAYER_H
#define PLAYER_H
class Player{

private:
   int id;
   std::array<Piece, 8> pieces;
   std::array<bool, 8> hand;
   int score;
public:
    Player();
    Position2i  getPosition(int index);
    void        killpiece(int index);
    int         countAlive();
    void        setPosition(int index, int x ,int y);
    bool        pieceAlive(int index);
    bool        tileAlive(int index);
    void        increaseScore();
    int         getScore();
};
#endif
