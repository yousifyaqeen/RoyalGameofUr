/*
 * the royal game of ur - A student indie game
 * Copyright (C) 2018-2019 to al kes ishaq yousif
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
  this->m_shadowPosition=gf::Vector2f(x,y);
  this->m_shadowSize=gf::Vector2f(width+m_outlineThickness,height+m_outlineThickness);
  this->m_shadowColor=gf::Color::Black;
  this->m_drawshadow = false;

}
Tile::Tile():m_texture(nullptr){
  Position2i tmp(0,0);

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
  this->m_shadowSize=gf::Vector2f(width+m_outlineThickness,height+m_outlineThickness);
  this->m_shadowPosition=gf::Vector2f(0,0);
  this->m_shadowColor=gf::Color::Black;
  this->m_drawshadow = false;

}

void Tile::render(gf::RenderTarget& target)  {
  gf::RectangleShape  shape;
  shape.setSize(gf::Vector2f{ width, height });
  shape.setPosition(m_position);
  shape.setColor(m_color);
  shape.setOutlineColor(m_outlineColor);
  shape.setOutlineThickness(m_outlineThickness);
  shape.setTexture(*m_texture);

  if(this->m_drawshadow){
    gf::RectangleShape  shadow;
    shadow.setSize(m_shadowSize);
    shadow.setPosition(m_shadowPosition);
    shadow.setColor(m_shadowColor);

    target.draw(shadow);
  }
  target.draw(shape);

}
void Tile::drawShadow(){
                this->m_drawshadow=true;
              };

void Tile::drawShadow(gf::Vector2f shadowPosition,gf::Vector2f shadowSize,gf::Color4f shadowColor){
              this->m_shadowPosition=shadowPosition;
              this->m_shadowSize=shadowSize;
              this->m_shadowColor=shadowColor;
              this->m_drawshadow=true;
             };
void         Tile::unDrawShadow(){this->m_drawshadow = false;};
bool         Tile::getShadow(){return this->m_drawshadow;};
void         Tile::setShadowSize(gf::Vector2f shadowSize){this->m_shadowSize=shadowSize;};
void         Tile::setShadowPosition(gf::Vector2f shadowPosition){this->m_shadowPosition=shadowPosition;};
void         Tile::setShadowColor(gf::Color4f shadowColor){this->m_shadowColor=shadowColor;};



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
