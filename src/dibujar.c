#include "include/dibujar.h"

void dibujar(int x, int y, COLOR * color){
    buffer[x][y].r=color->r;
    buffer[x][y].g=color->g;
    buffer[x][y].b=color->b;
}

void noDibujar(int x, int y, COLOR * color){

}