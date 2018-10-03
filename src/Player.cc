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
