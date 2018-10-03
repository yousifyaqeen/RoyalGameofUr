#include "Position2i.h"
#ifndef TILE_H
#define TILE_H
class Tile{
private:

  int id;
  float width;
  float height;
  float x;//in the window
  float y;//in the window
  Position2i pos;//on matrix
  int capacity;
public:
  Tile();
  void        set(int id,float width,float height,float x,float y,Position2i pos,int capacity);
  float       getPositionX();
  float       getPositionY();
  void        setPosition(float x,float y);
  float       getHeight();
  float       getWidth();
  int         getId();
  int         getCapacity();
  void        setCapacity(int capacity);
  Position2i  getOnBoardPosition();
  int         getOnBoardPositionX();
  int         getOnBoardPositionY();
  void        setOnBoardPosition(Position2i pos);
  void        setOnBoardPosition(int x,int y);
};
#endif
