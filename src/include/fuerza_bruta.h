#ifndef FUERZA_BRUTRA_H
#define FUERZA_BRUTRA_H

#include <math.h>
#include "dibujar.h"

void fuerza_bruta(int x0, int y0, int x1, int y1, COLOR * color,
                void (*func_dibujar)(int,int,COLOR *));

#endif