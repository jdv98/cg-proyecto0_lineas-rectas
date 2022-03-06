#include "include/keys.h"

void normal_keys(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27: // Esc
    exit(0);
    break;

  default:
    break;
  }
}

void special_keys(int key, int x, int y){

}