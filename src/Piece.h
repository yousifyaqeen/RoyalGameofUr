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
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Window.h>
#include <gf/ResourceManager.h>

#ifndef PIECE_H
#define PIECE_H
class Piece {
private:

  int id;
  float width;
  float height;
  float x;
  float y;
  bool dead;
  Position2i pos;//on Board
  int pos_1D;//on Board
  gf::Vector2f m_position; // center of the square
  float m_radius;
  gf::Color4f m_color;
  gf::Texture *m_texture;
  gf::Color4f m_shadowColor;
  gf::Vector2f m_shadowSize;
  float m_shadowRadius;
  gf::Vector2f m_shadowPosition;
  bool m_drawshadow;

public:
  bool        Alive();
              Piece();
  size_t      Search(const int *self,size_t size, int value);
  size_t      SearchEnd(const int *self,size_t size, int value);

  void        set(int id,float width,float height,float x,float y,Position2i pos);
/*  void        setPosition(Position2i pos);*/
  gf::Vector2f getPosition();
  void        setId(int id);
  void        Die();
  float       setSize(float height, float width);
  /*void        setPosition(float x,float y);*/
  gf::RectF   getLocalBounds();
  void        setOnBoardPosition(Position2i pos);
  void        setOnBoardPosition(int x,int y);
  void        setOnBoardPosition(int x);
  void        setRadius(float radius);
  void        setPosition(gf::Vector2f position);
  void        setColor(gf::Color4f color);
  Position2i  getOnBoardPosition();
  int         getOnBoardPosition1D();
  float       getPositionX();
  float       getPositionY();
  float       getHeight();
  float       getWidth();
//  void        setTexture(gf::Texture texture);
  int         getId();
  void         setTexture(gf::Texture& texture);

  void        render(gf::RenderTarget& target);
};
#endif
