#include "include/dibujar.h"

void dibujar(int x, int y, double r, double g, double b){
    buffer[x][y].r=r;
    buffer[x][y].g=g;
    buffer[x][y].b=b;
}

void noDibujar(int x, int y, double r, double g, double b){

}