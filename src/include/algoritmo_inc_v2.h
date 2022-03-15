#ifndef ALGORITMO_INC_V2_H
#define ALGORITMO_INC_V2_H

#include <math.h>
#include <stdlib.h>
#include "dibujar.h"

void algoritmo_inc_v2(int x0, int y0, int x1, int y1, COLOR * color,
                void (*func_dibujar)(int,int,COLOR *));

#endif