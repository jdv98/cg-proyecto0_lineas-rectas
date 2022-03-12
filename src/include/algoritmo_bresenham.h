#ifndef ALGORITMO_BRESENHAM_H
#define ALGORITMO_BRESENHAM_H

void bresenham(int x0, int y0, int x1, int y1, COLOR * color,
                void (*func_dibujar)(int,int,COLOR *));

#endif