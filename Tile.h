#include "Position2i.h"
#include <gf/Shapes.h>
#include <gf/RenderWindow.h>

#ifndef TILE_H
#define TILE_H
class Tile{
private:

  int id;
  float width;
  float height;
  float x;//in the window
  float y;//in the window
  gf::Vector2f m_position;
  gf::Color4f m_color;
  float m_outlineThickness;
  gf::Color4f m_outlineColor;
  Position2i pos;//on matrix
  int capacity;
  gf::Texture *m_texture;

public:
  void         render(gf::RenderTarget& target);
  Tile();
  void setPosition(gf::Vector2f pos);
  gf::Vector2f getPosition();
  void         setTexture(gf::Texture& texture);
  void         setColor(gf::Color4f color);
  void         setOutlineColor(gf::Color4f color);
  void         setOutlineThickness(float thickness);
  void         set(int id,float width,float height,float x,float y,Position2i pos,int capacity);
  float        getPositionX();
  float        getPositionY();
  void         setPosition(float x,float y);
  float        getHeight();
  float        getWidth();
  int          getId();
  int          getCapacity();
  void         setCapacity(int capacity);
  Position2i   getOnBoardPosition();
  int          getOnBoardPositionX();
  int          getOnBoardPositionY();
  void         setOnBoardPosition(Position2i pos);
  void         setOnBoardPosition(int x,int y);
  void         setSize(gf::Vector2f size);
};
#endif
