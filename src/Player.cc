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
#include "Player.h"

  Player::Player(){
    for(int i=0;i<8;i++){
      this->hand.at(i)=true;
      this->pieces[i].setOnBoardPosition(0,0);
      this->score =0;
    }
  }

  Position2i Player::getPosition(int index){
    if(index<pieces.size())
    return pieces[index].getOnBoardPosition();
  }
  void Player::setPosition(int index, int x ,int y){
    pieces[index].setOnBoardPosition(x,y);
  }

  void Player::killpiece(int index){
    hand.at(index)=false;
  }
  int Player::countAlive(){
    int count=0;
    for(int i=0;i<8;i++){
      if(this->hand[i] = true)
        count++;
    }
    return count;
  }
  bool Player::pieceAlive(int index){
    return hand.at(index);
  }

  void Player::increaseScore(){
    score+=1;
  }

  int Player::getScore(){
    return score;
  }
