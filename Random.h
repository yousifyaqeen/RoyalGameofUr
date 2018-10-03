
#include <random>


#ifndef RANDOM_H
#define RANDOM_H
class Random{
  public :
Random();
static int RandomInt();
static int RandomIntBetween(int lBound , int rBound);
static int randomIntST(int rBound);
static float randomFloat();
static float randomFloatBetween(float lBound,float rBound);
static float randomFloatST(int rBound);
};
#endif
