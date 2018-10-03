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
