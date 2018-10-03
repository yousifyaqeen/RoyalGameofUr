#include "Random.h"
#include <iostream>
int main(){


std::cout << "raw : " << Random::randomFloat() << '\n';
std::cout << "int between 0,100 : " << Random::RandomInt() << '\n';
std::cout << "int between 3,10: " << Random::RandomIntBetween(3,10) << '\n';
std::cout << "int smallerthen 5: " << Random::randomIntST(5) << '\n';
std::cout << "randomFloatBetween 3.5 , 10.2 : " << Random::randomFloatBetween(3.5f,10.2f) << '\n';
std::cout << " randomFloatST 10.0 : " << Random::randomFloatST(10.0f) << '\n';
}
