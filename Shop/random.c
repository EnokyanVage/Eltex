#include <stdlib.h>

int RANDOM(int min, int max) 
{
  return min + rand() % (max - min);
}