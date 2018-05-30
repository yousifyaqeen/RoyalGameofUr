#include <gf/Event.h>
#include <gf/Font.h>
#include <gf/RenderWindow.h>
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Window.h>
#include <gf/SystemInfo.h>
#include <iostream>
#include <gf/Shapes.h>
#include <array>
#include <gf/ResourceManager.h>
const static int wWidth = 1020;
const static int wHieght = 600;
const static int numTiles = 8;
const static float Board_square_size = 100.0f;
struct Position{

    int x;
    int y;

};
class Player{
private:
     static int id;
     static std::array<bool, numTiles> tile;
     static std::array<Position, numTiles> pos;
     static int score;
public:
     Player(){
       for(int i=0;i<numTiles;i++){
        tile.at(i)=true;
        pos[i].x=0;
        pos[i].y=0;
      }
     }

     Position getPosition(int index){
       if(index<pos.size())
       return pos[index];
     }

     void setPosition(int index, int x ,int y){
       pos[index].x=x;
       pos[index].y=y;
     }

     void killTile(int index){
       tile.at(index)=false;
     }

     bool tileAlive(int index){
       return tile.at(index);
     }

     void increaseScore(){
        score+=1;
     }

     int getScore(){
       return score;
     }
};

int main() {
  int Board [][8]  = {
    {4,2,1,2,0,0,4,5},
    {6,1,3,4,1,3,2,1},
    {4,2,1,2,0,0,4,5}};

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


    gf::Text text("The Royal Game Of UR", font);
    text.setPosition({ (window.getSize().x - text.getLocalBounds().width)/2, text.getLocalBounds().height });
    text.setCharacterSize(30);
    text.setColor(gf::Color::Red);



    gf::RectangleShape tile[24];
    int currentTile        = 0;
    float totalWidth = ((wWidth/2)-(8*((Board_square_size+4)/2)));
    float totalHeight = ((wHieght/2)-(3*((Board_square_size+4)/2)));
    for(int i          = 0;i<3;i++){
      for(int j        = 0;j<8;j++){

        tile[currentTile].setSize({ Board_square_size, Board_square_size });
        tile[currentTile].setPosition({totalWidth + ((tile[currentTile].getSize().width + 4) * j),totalHeight + (tile[currentTile].getSize().height + 4)*i });
        tile[currentTile].setOutlineColor(gf::Color::Blue);
        tile[currentTile].setOutlineThickness(4);

        if(Board[i][j] ==0){
          tile[currentTile].setColor(gf::Color::White);
          tile[currentTile].setOutlineColor(gf::Color::Blue);
          tile[currentTile].setOutlineThickness(0);
        }else
        if(Board[i][j]     ==1){

          tile[currentTile].setTexture(pointat);
        }else
        if(Board[i][j]     ==2){

          tile[currentTile].setTexture(eyest);

        }else
        if(Board[i][j]     ==3){

          tile[currentTile].setTexture(pointst);
        }else
        if(Board[i][j]     ==4){

          tile[currentTile].setTexture(anothert);

        }else
        if(Board[i][j]     ==5){

          tile[currentTile].setTexture(end4pointst);
        }else
        if(Board[i][j]     ==6){

          tile[currentTile].setTexture(cantdie);
        }

        currentTile++;

      }
    }


    gf::CircleShape piece1[numTiles];
    for(int i=0;i<numTiles;i++){
      piece1[i].setRadius(30);
      piece1[i].setPosition({ 100.0f +(60*i), 30.0f });
      piece1[i].setTexture(player1);
    }


    gf::CircleShape piece2[numTiles];
    for(int i=0;i<numTiles;i++){
      piece2[i].setRadius(30);
      piece2[i].setPosition({ 100.0f +(60*i), wHieght-60.0f-30 });
      piece2[i].setTexture(player2);
    }



    renderer.clear(gf::Color::White);

    // Start the game loop
    bool chose = true;
    int current = 0;
    int MouseX = 0;
    int MouseY = 0;
    while (window.isOpen()) {
      // Process events
      for(int i          = 0 ; i<3;i++){
        for(int j        = 0;j<8;j++){

        }
      }
      gf::Event event;

      while (window.pollEvent(event)) {


        switch (event.type) {
          case gf::EventType::Closed:
          window.close();
          break;
          case gf::EventType::MouseButtonPressed:
        if(chose){
            for(int i =0;i<numTiles;i++){
              if(event.mouseButton.coords.x<piece1[i].getPosition().x+piece1[i].getLocalBounds().width &&event.mouseButton.coords.x>piece1[i].getPosition().x
              &&event.mouseButton.coords.y<piece1[i].getPosition().y+piece1[i].getLocalBounds().height&&event.mouseButton.coords.y>piece1[i].getPosition().y){
              current = i;
              std::cout << "current " << i << "\n";
              chose = false;
            }
          }
        }else{

          for(int i =0;i<24;i++){
            if(event.mouseButton.coords.x<tile[i].getPosition().x+tile[i].getLocalBounds().width &&event.mouseButton.coords.x>tile[i].getPosition().x
            &&event.mouseButton.coords.y<tile[i].getPosition().y+tile[i].getLocalBounds().height&&event.mouseButton.coords.y>tile[i].getPosition().y){
            piece1[current].setPosition(gf::Vector2f(tile[i].getPosition().x + 19,tile[i].getPosition().y + 19));

          }
        }
              chose = true;
        }

            break;
        }
      }

      renderer.clear();
      for(int i = 0;i<24;i++){
          renderer.draw(tile[i]);
      }
      for(int i = 0;i<24;i++){
        if(i<numTiles) {
          renderer.draw(piece1[i]);
          renderer.draw(piece2[i]);

        }
      }



      renderer.display();
    }

    return 0;
  }
