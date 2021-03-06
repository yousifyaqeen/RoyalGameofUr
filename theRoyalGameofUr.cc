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

#include <gf/Event.h>
#include <gf/Font.h>
#include <gf/RenderWindow.h>
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Window.h>
#include <string>
#include <iostream>
#include <gf/Shapes.h>
#include <array>
#include <gf/ResourceManager.h>
#include "src/Position2i.h"
#include "src/Player.h"
#include "src/Tile.h"
#include "src/Random.h"



const static int wWidth = 1020;
const static int wHieght = 600;
const static int numTiles = 8;
const static int Board_Num_Tiles_width=8;
const static int Board_Num_Tiles_height=3;
const static float Board_square_size = 100.0f;
const static float tile_Boarder_width = 4.f;
const static float Board_square_Full_size = Board_square_size+tile_Boarder_width;
const static float totalBoardWidth = ((wWidth/2)-(Board_Num_Tiles_width*(Board_square_Full_size/2)));
const static float totalBoardHeight = ((wHieght/2)-(Board_Num_Tiles_height*(Board_square_Full_size/2)));

int main() {
  //this array is used to display the texture on the tiles
  int BoardArray[24]  = { 4,2,1,2,0,0,4,5,
    6,1,3,4,1,7,2,1,
    4,2,1,2,0,0,4,5};
    //this array defines where each player can player
    //player one can play in 1 and 3
    //player two can play in 2 and 3
    int BoardPlayerArray[24]  = { 1,1,1,1,0,0,1,1,
      3,3,3,3,3,3,3,3,
      2,2,2,2,0,0,2,2};
      //this array defines the path for each player
      //each piece start on 1 and end on 15
      int pathArray[24]  =
      { 4,3,2,1,16,15,14,13,
        5,6,7,8,9,10,11,12,
        4,3,2,1,16,15,14,13};

        bool isEmpty[24]={1,1,1,1,1,1,1,1,
          1,1,1,1,1,1,1,1,
          1,1,1,1,1,1,1,1};
          //there is two tiles that can recive more than one piece and
          //this array save the number of tiles on these two

          int OnTile[2]={0,0};
          //gf matrix is a 2d array , very practical in this case
          //it can takes 1d array and create the 2d array
          gf::Matrix<int, 3, 8> displayMatrix(BoardArray);

          // Create the main window and the renderer
          gf::Window window("the royal game of ur", { wWidth, wHieght});
          gf::RenderWindow renderer(window);

          /*using the resource manager to load textures
          * very well organised and more readable code
          * and all resources are in the same place
          */

          gf::ResourceManager resources;
          resources.addSearchDir("./res");
          gf::Font& font = resources.getFont("asvcodar-lt-bold.ttf");
          gf::Texture& eyest = resources.getTexture("1.png");
          gf::Texture& pointat = resources.getTexture("2.png");
          gf::Texture& pointst = resources.getTexture("3.png");
          gf::Texture& anothert = resources.getTexture("4.png");
          gf::Texture& end4pointst = resources.getTexture("5.png");
          gf::Texture& cantdie = resources.getTexture("6.png");
          gf::Texture& player1 = resources.getTexture("p1.png");
          gf::Texture& player2 = resources.getTexture("p2.png");

          //displaying the title in the center of the window
          gf::Text text("The Royal Game Of UR", font);
          text.setPosition({ (window.getSize().x - text.getLocalBounds().width)/2, text.getLocalBounds().height });
          text.setCharacterSize(30);
          text.setColor(gf::Color::Red);

          //creating the game board
          //see Tile.h for def
          Tile tiles[24];
          //see Position2i.h for def
          Position2i currentOnBoardPos(0,0);
          float currentX;
          float currentY;
          int currentTile        = 0;
          //reading the 2d array and assigning a texture for each tile
          for(int i          = 0;i<3;i++){
            for(int j        = 0;j<8;j++){
              //initialising the current variable with the position on the board;
              currentOnBoardPos.setPosition(i,j);
              //calculating the new position for each tile
              // we put the new tile on the left each time
              currentX = (totalBoardWidth + (Board_square_Full_size * j));
              currentY = (totalBoardHeight + (Board_square_Full_size * i));
              //initialising the tile
              tiles[currentTile].set(currentTile,Board_square_size,Board_square_size,currentX,currentY, currentOnBoardPos,1);
              //drawing the shadow under the board

              //still experimenting with the shadows
              tiles[currentTile].drawShadow();
              tiles[currentTile].setShadowPosition(gf::Vector2f(currentX+15,currentY+15));
              tiles[currentTile].setShadowSize(gf::Vector2f(Board_square_size+15,Board_square_size+15));
              tiles[currentTile].setShadowColor(gf::Color::fromRgba32(130, 82, 1,255));
              switch (displayMatrix.grid[i][j]) {
                case 0:
                //if it's on one of the four empty tiles we want no shadow to
                //be drawn inder the tile
                tiles[currentTile].unDrawShadow();
                tiles[currentTile].setColor(gf::Color::Transparent);
                tiles[currentTile].setOutlineColor(gf::Color::Blue);
                tiles[currentTile].setOutlineThickness(0);
                break;
                case 1:
                tiles[currentTile].setTexture(pointat);
                break;
                case 2:
                tiles[currentTile].setTexture(eyest);
                break;
                case 3:
                tiles[currentTile].setTexture(pointst);
                break;
                case 4:
                tiles[currentTile].setTexture(anothert);
                break;
                case 5:
                tiles[currentTile].setTexture(end4pointst);
                break;
                case 6:
                tiles[currentTile].setTexture(cantdie);
                break;
                case 7:
                tiles[currentTile].setTexture(pointst);
                break;
              }
              currentTile++;

            }
          }
          //initialising the pieces
          //see piece.h for more info
          //each player has 8 pieces
          Piece piece1[numTiles];
          for(int i=0;i<numTiles;i++){
            piece1[i].setRadius(30);
            piece1[i].setPosition({ Board_square_size +(60*i), 30.f });
            piece1[i].setTexture(player1);
          }
          Piece piece2[numTiles];
          for(int i=0;i<numTiles;i++){
            piece2[i].setRadius(30);
            piece2[i].setPosition({Board_square_size +(60*i), wHieght-30.f });
            piece2[i].setTexture(player2);
          }

          gf::Text DiceText("You Got", font);
          DiceText.setPosition({ ((window.getSize().x/4)+(window.getSize().x/2)) - (DiceText.getLocalBounds().width/2), DiceText.getLocalBounds().height });
          DiceText.setCharacterSize(30);
          DiceText.setColor(gf::Color::Red);
          renderer.clear(gf::Color::White);

          // Start the game loop
          bool chose = true;
          bool p1 = true;
          int current = 0;
          int MouseX = 0;
          int MouseY = 0;
          int throwDice=0;
          auto  thrw = true;
          while (window.isOpen()) {
            // Process events
            gf::Event event;
            while (window.pollEvent(event)) {
              if(thrw){
                throwDice = Random::RandomIntBetween(1,5) ;
                DiceText.setString(std::to_string(throwDice));
                //  printf("random %d\n",throwDice );
                thrw = false;
              }
              switch (event.type) {
                case gf::EventType::Closed:
                window.close();
                break;
                case gf::EventType::MouseButtonPressed:
                if(p1){
                  for(int i =0;i<numTiles;i++){
                    if(event.mouseButton.coords.x<piece1[i].getPosition().x+piece1[i].getLocalBounds().width &&event.mouseButton.coords.x>piece1[i].getPosition().x
                    &&event.mouseButton.coords.y<piece1[i].getPosition().y+piece1[i].getLocalBounds().height&&event.mouseButton.coords.y>piece1[i].getPosition().y){
                      if(!piece1[i].Alive()){
                        int newpos =piece1[i].Search(pathArray,24,piece1[i].getOnBoardPosition1D()-1+throwDice);
                        if(isEmpty[newpos]==1){
                          isEmpty[newpos-throwDice]=1;
                          piece1[i].setOnBoardPosition(piece1[i].getOnBoardPosition1D()+throwDice);
                          if(piece1[i].getOnBoardPosition1D()-1==7){
                            OnTile[0]-=1;
                          }
                          if(piece1[i].getOnBoardPosition1D()-1==10){
                            OnTile[1]-=1;
                          }

                          if(piece1[i].getOnBoardPosition1D()-1<15){
                            if(piece1[i].getOnBoardPosition1D()-1==7){
                              OnTile[0]+=1;
                              piece1[i].setPosition(gf::Vector2f(tiles[newpos].getPosition().x + 19 +(5*OnTile[0]),tiles[newpos].getPosition().y + 19 + (5*OnTile[0])));
                              thrw = true;
                              p1=false;

                            }else if(piece1[i].getOnBoardPosition1D()-1==10){
                              OnTile[1]+=1;
                              piece1[i].setPosition(gf::Vector2f(tiles[newpos].getPosition().x + 19+(5*OnTile[1]),tiles[newpos].getPosition().y + 19 + (5*OnTile[1])));
                              thrw = true;
                              p1=false;
                            }else{
                              printf("here \n"   );
                              piece1[i].setPosition(gf::Vector2f(tiles[newpos].getPosition().x + 19,tiles[newpos].getPosition().y + 19));
                              thrw = true;
                              p1=false;
                              printf("%d newpos \n",newpos   );
                              isEmpty[newpos]=0;
                            }


                          }else{
                            piece1[i].setPosition(gf::Vector2f(tiles[5].getPosition().x + 19,tiles[5].getPosition().y + 19));
                            thrw = true;
                            p1=false;
                            piece1[i].Die();
                          }
                        }
                      }

                      break;
                    }
                  }
                }else{
                  for(int i =0;i<numTiles;i++){
                    if(event.mouseButton.coords.x<piece2[i].getPosition().x+piece2[i].getLocalBounds().width &&event.mouseButton.coords.x>piece2[i].getPosition().x
                    &&event.mouseButton.coords.y<piece2[i].getPosition().y+piece2[i].getLocalBounds().height&&event.mouseButton.coords.y>piece2[i].getPosition().y){
                      if(!piece2[i].Alive()){
                        piece2[i].setOnBoardPosition(piece2[i].getOnBoardPosition1D()+throwDice);
                        int newpos =piece2[i].SearchEnd(pathArray,24,piece2[i].getOnBoardPosition1D()-1);
                        if(piece2[i].getOnBoardPosition1D()-1<15){
                          piece2[i].setPosition(gf::Vector2f(tiles[newpos].getPosition().x + 19,tiles[newpos].getPosition().y + 19));
                          thrw = true;
                          p1=true;
                        }else{
                          piece2[i].setPosition(gf::Vector2f(tiles[21].getPosition().x + 19,tiles[21].getPosition().y + 19));
                          thrw = true;
                          p1=true;
                          piece2[i].Die();
                        }
                      }
                    }
                  }
                }
                break;
              }
            };
            //clear the screen before drawing anything
            renderer.clear();
            //now we can draw the objects
            for(int i = 0;i<24;i++){

              tiles[i].render(renderer);
            }
            for(int i = 0;i<24;i++){
              if(i<numTiles) {
                piece1[i].render(renderer);
                piece2[i].render(renderer);
              }
            }
            renderer.draw(DiceText);
            renderer.draw(text);
            renderer.display();
          }
          return 0;
        }
