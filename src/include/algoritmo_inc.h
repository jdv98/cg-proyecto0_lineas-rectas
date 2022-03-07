#ifndef ALGORITMO_INC_H
#define ALGORITMO_INC_H

#include <math.h>

void algoritmo_inc(int x0, int y0, int x1, int y1, double rc, double gc, double bc,
                   void (*func_dibujar)(int, int, double, double, double));

#endif