#include "Piece.h"



 void Piece::render(gf::RenderTarget& target) {
   gf::CircleShape shape;
   shape.setPosition(m_position);
   shape.setRadius(m_radius);
   shape.setTexture(*m_texture);
   if(m_drawshadow){
     gf::CircleShape shadow;
     shadow.setPosition(m_shadowPosition);
     shadow.setRadius(m_shadowRadius+2);
     shadow.setColor(m_shadowColor);
     target.draw(shadow);
 }
   target.draw(shape);

 }

gf::RectF Piece::getLocalBounds(){
  gf::CircleShape shape;
  shape.setPosition(m_position);
  shape.setRadius(m_radius);
  return shape.getLocalBounds();

}

void Piece::set(int id,float width,float height,float x,float y,Position2i pos){
  this->id=id;
  this->width=width;
  this->height=height;
  this->x=x;
  this->y=y;
  this->pos=pos;
}

/*void  setTexture(gf::Texture texture){
  m_texture=texture;
}*/
Piece::Piece():m_texture(nullptr){
  gf::Vector2f tmp({0.f,0.f});
  this->id=0;
  this->width=0;
  this->height=0;
  this->x=0;
  this->y=0;
  this->m_position = tmp;
  this->m_radius = 0.f;
  pos_1D=1;
  dead=false;
  m_shadowColor = gf::Color::Black;

}
size_t Piece::Search(const int *self,size_t size, int value) {
  for(int i=0 ;i<size;++i){
    if(self[i] == value){
      return i;
    }
  }
  return 0;

}
size_t Piece::SearchEnd(const int *self,size_t size, int value) {
  for(int i=size-1 ;i>=0;--i){
    if(self[i] == value){
      return i;
    }
  }
  return 0;

}

/*void       Piece::setPosition(float x,float y){this->x=x; this->y=y;}
void         Piece::setPosition(Position2i pos){this->x=pos.getPositionX(); this->y=pos.getPositionY();}*/
float        Piece::setSize(float height, float width){this->height=height; this->width=width;}
void         Piece::setId(int id){this->id=id;}
void         Piece::Die(){dead=true;}
bool         Piece::Alive(){return dead;}
void         Piece::setTexture(gf::Texture& texture){m_texture=&texture;};
void         Piece::setOnBoardPosition(Position2i pos){this->pos=pos;}
void         Piece::setOnBoardPosition(int x,int y){this->pos.setPosition(x,y);}
void         Piece::setOnBoardPosition(int x){this->pos_1D=x;}
float        Piece::getPositionX(){return x;}
float        Piece::getPositionY(){return y;}
float        Piece::getHeight(){return height;}
gf::Vector2f Piece::getPosition(){return m_position;}
float        Piece::getWidth(){return width;}
int          Piece::getId(){return id;}
Position2i   Piece::getOnBoardPosition(){return pos;}
int          Piece::getOnBoardPosition1D(){return pos_1D;}
void         Piece::setRadius(float radius){m_radius = radius;};
void         Piece::setPosition(gf::Vector2f position){m_position=position;};
void         Piece::setColor(gf::Color4f color){m_color=color;};
