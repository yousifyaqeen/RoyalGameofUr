#include "Position2i.h"
#ifndef BOARD_H
#define BOARD_H
class Board{
  public:
    Board();
    static Position2i tilePosition(int id);
    Position2i getPosition(int id);
    Position2i setPosition(int id,int i, int j);
    Position2i calculatePositionOnBoard(int id);
  private:
    Position2i Player1Position [8];
    int p1PathCapacity[14]={1,1,1,1,1,1,4,1,1,4,1,1,1,1};
    Position2i Player2Position [8];
    int p2PathCapacity[14]={1,1,1,1,1,1,4,1,1,4,1,1,1,1};
  };
  #endif
