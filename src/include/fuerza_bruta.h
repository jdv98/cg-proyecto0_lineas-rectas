#ifndef FUERZA_BRUTRA_H
#define FUERZA_BRUTRA_H

#include <math.h>
#include <stdio.h>

void fuerza_bruta(int x0, int y0, int x1, int y1, double rc, double gc, double bc,
                void (*func_dibujar)(int,int,double,double,double));

#endif