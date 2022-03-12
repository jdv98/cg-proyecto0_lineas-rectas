#include "include/algoritmo_bresenham.h"

int delta_x, delta_y;

void cuadrante1(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *));
void cuadrante2(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *));

void bresenham(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{
    delta_x = (x1 - x0);
    delta_y = (y1 - y0);

    if (delta_x < 0)
        if (delta_y < 0) // x- y-
        {
            delta_x *= -1;
            delta_y *= -1;
            cuadrante1(x1, y1, x0, y0, color, (*func_dibujar));
        }
        else // x- y+
        {
            delta_x *= -1;
            delta_y *= -1;
            cuadrante2(x1, y1, x0, y0, color, (*func_dibujar));
        }
    else
    {
        if (delta_y < 0) // x+ y-
        {
            cuadrante2(x0, y0, x1, y1, color, (*func_dibujar));
        }
        else // x+ y+
        {
            cuadrante1(x0, y0, x1, y1, color, (*func_dibujar));
        }
    }
}

void cuadrante1(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{
    delta_ne=2*(delta_y-delta_x);
    if (delta_x > delta_y) // octante1
    {
    }
    else
    {
    }
}

void cuadrante2(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{
    delta_se=2*(delta_x + delta_y);
    if ( > 0)
    {
    }
    else
    {
    }
}