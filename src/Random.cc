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
#include "Random.h"


Random::Random(){


}

float Random::randomFloat(){
  static std::mt19937 engine(time(nullptr));
  std::uniform_real_distribution<float> dist(0.0f, 1.0f);
  return dist(engine);
}

int Random::RandomInt(){
return ((int) (randomFloat() * 100) );
}
int Random::RandomIntBetween(int lBound , int rBound){
  if(lBound >= rBound){
    int tmp = (int) (randomFloat()*lBound);
    while (tmp < rBound){
      tmp = (int) (randomFloat()*lBound);
    }
    return tmp;

  }else{
    int tmp = (int) (randomFloat()*rBound);
    while (tmp < lBound){
      tmp = (int) (randomFloat()*rBound);
    }
    return tmp;
  }
}

int Random::randomIntST(int rBound){

return Random::RandomIntBetween(0,rBound);

}
float  Random::randomFloatBetween(float lBound,float rBound){
  static std::mt19937 engine(time(nullptr));
  std::uniform_real_distribution<float> dist(lBound, rBound);
  return dist(engine);
}
float  Random::randomFloatST(int rBound){

  static std::mt19937 engine(time(nullptr));
  std::uniform_real_distribution<float> dist(0.0f, rBound);
  return dist(engine);


}
