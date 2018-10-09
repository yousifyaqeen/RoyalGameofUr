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
#include "Position2i.h"
#include <gf/Shapes.h>
#include <gf/RenderWindow.h>

#ifndef TILE_H
#define TILE_H
class Tile{
private:

  int id; //each tile has it's own id
  float width; // tile wodth
  float height;// tile height
  float x;//in the window (not used)
  float y;//in the window (not used)

  gf::Vector2f m_position; // position in the window
  gf::Color4f m_color; //tile color (RectangleShape color)
  float m_outlineThickness;
  gf::Color4f m_outlineColor;
  Position2i pos;//on matrix (not used)
  int capacity; //not used
  gf::Texture *m_texture; // the tile texture needs to be initialised
  gf::Color4f m_shadowColor;
  gf::Vector2f m_shadowSize;
  gf::Vector2f  m_shadowPosition;
  bool m_drawshadow;

public:
  //gf related functions
  //similar to gf::RectangleShape
  void         render(gf::RenderTarget& target);
  void         setPosition(gf::Vector2f pos);
  void         setColor(gf::Color4f color);
  void         setSize(gf::Vector2f size);
  void         setTexture(gf::Texture& texture);
  void         setOutlineThickness(float thickness);
  void         setOutlineColor(gf::Color4f color);
  void         setShadowPosition(gf::Vector2f shadowPosition);
  void         setShadowSize(gf::Vector2f shadowSize);
  void         setShadowColor(gf::Color4f shadowColor);
  gf::Vector2f getPosition();
  // is the shadow set to be drawn ?
  bool         getShadow();
  //draw the shadow
  void         drawShadow();
  //set then draw the shadow
  void         drawShadow(gf::Vector2f shadowPosition,gf::Vector2f shadowSize,gf::Color4f shadowColor);
  //don't draw the shadow
  void         unDrawShadow();

//--------------------------------
//initialising the tile
//most of functions here are redundent and not used
  Tile();
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
};
#endif
