#include "Board.h"

Board::Board(){

}



Position2i Board::calculatePositionOnBoard(int id){
  int current=0;
  Position2i vec(100,100);
  for(int i=0;i<3;i++){
    for(int j=0;j<8;j++){
      if(current==id){
        vec.setPosition(i,j);
        return vec;
      }
      current++;
    }
  }
  return vec;
}
