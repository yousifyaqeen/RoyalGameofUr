#include <set>
#include <vector>
#include <array>

#ifndef POSITION2I_H
#define POSITION2I_H
class Position2i{
private:
  int x;
  int y;
public:
Position2i();
Position2i(int posx,int posy);
std::array<int, 2> getPosition();
int getPositionX();
int getPositionY();
void setPosition(int posx,int posy);
void setPosition(Position2i pos);
};
#endif
