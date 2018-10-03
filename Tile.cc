#include "Tile.h"

    void Tile::set(int id,float width,float height,float x,float y,Position2i pos,int capacity){
    this->id=id;
    this->width=width;
    this->height=height;
    this->x=x;
    this->y=y;
    this->capacity=capacity;
    this->pos=pos;
  }
  Tile::Tile(){
    Position2i tmp(0,0);
    this->id=0;
    this->width=0;
    this->height=0;
    this->x=0;
    this->y=0;
    this->capacity=0;
    this->pos =tmp;

  }
  float        Tile::getPositionX(){return x;}
  float        Tile::getPositionY(){return y;}
  float        Tile::getHeight(){return height;}
  float        Tile::getWidth(){return width;}
  int          Tile::getId(){return id;}
  int          Tile::getCapacity(){return capacity;}
  Position2i   Tile::getOnBoardPosition(){return pos;}
  int          Tile::getOnBoardPositionX(){return pos.getPositionX();}
  int          Tile::getOnBoardPositionY(){return pos.getPositionY();}
  void         Tile::setOnBoardPosition(Position2i pos){this->x = pos.getPositionX(); this->y = pos.getPositionY();}
  void         Tile::setOnBoardPosition(int x,int y){this->x=x; this->y = y;}
