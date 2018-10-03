#include "Tile.h"

    void Tile::set(int id,float width,float height,float x,float y,Position2i pos,int capacity){
    this->id=id;
    this->width=width;
    this->height=height;
    this->x=x;
    this->y=y;
    this->capacity=capacity;
    this->pos=pos;
    this->m_position=gf::Vector2f(x,y);
  }
  Tile::Tile():m_texture(nullptr){
    Position2i tmp(0,0);
    gf::Vector2u tmp2(10,10);
    this->id=0;
    this->width=0;
    this->height=0;
    this->x=0;
    this->y=0;
    this->capacity=0;
    this->pos =tmp;
    this->m_color=gf::Color::White;
    this->m_outlineThickness=4;
    this->m_outlineColor = gf::Color::Blue;

  }

   void Tile::render(gf::RenderTarget& target)  {
    gf::RectangleShape  shape;
    shape.setSize(gf::Vector2f{ width, height });
    shape.setPosition(m_position);
    shape.setColor(m_color);
    shape.setOutlineColor(m_outlineColor);
    shape.setOutlineThickness(m_outlineThickness);

    shape.setTexture(*m_texture);

    target.draw(shape);

  }
  void         Tile::setColor(gf::Color4f color){m_color=color;};
  void         Tile::setOutlineColor(gf::Color4f color){m_outlineColor = color;};
  void         Tile::setOutlineThickness(float thickness){m_outlineThickness=thickness;};
 void          Tile::setTexture(gf::Texture& texture){m_texture=&texture;};
 void          Tile::setPosition(gf::Vector2f pos){ m_position=pos;}
void           Tile::setSize(gf::Vector2f size){width = size.x;height = size.y;};
gf::Vector2f   Tile::getPosition(){return m_position;}
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
