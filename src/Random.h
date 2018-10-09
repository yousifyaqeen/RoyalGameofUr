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
