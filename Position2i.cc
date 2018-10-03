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
