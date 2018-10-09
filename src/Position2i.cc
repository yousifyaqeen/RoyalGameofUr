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
#include "Position2i.h"

  Position2i::Position2i(){
    x=0;
    y=0;
  }
  Position2i::Position2i(int posx,int posy){
    x=posx;
    y=posy;
  }

  std::array<int, 2> Position2i::getPosition(){
    std::array<int, 2> tmp{this->x,this->y};
    return  tmp;
  }
  int Position2i::getPositionX(){

    return x;
  }
  int Position2i::getPositionY(){
    return y;
  }
  void Position2i::setPosition(int posx,int posy){
    this->x=posx;
    this->y=posy;
  }
  void Position2i::setPosition(Position2i position){
    this->x=position.getPositionX();
    this->y=position.getPositionY();
  }
/*  static float distance(Position2i pos1,Position2i pos2){

  }
  static float distance(Position2i pos1){

  }
  float distance(){

  }*/
