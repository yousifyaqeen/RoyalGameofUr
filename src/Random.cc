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
