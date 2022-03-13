#include "include/algoritmo_inc_v2.h"

int max(int a, int b);

void algoritmo_inc_v2(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{
    int x1_x0 = x1 - x0,
        y1_y0 = y1 - y0;
    int width = max(abs(x1_x0), abs(y1_y0));

    long double x = (long double)x0,
                y = (long double)y0,
                mx = x1_x0 / (long double)width,
                my = y1_y0 / (long double)width;

    for (int i = 0; i <= width; i++)
    {
        (*func_dibujar)((int)(round(x)), (int)(round(y)), color);
        x += mx;
        y += my;
    }
}

int max(int a, int b)
{
    int r = a > b ? a : b;
    return r != 0 ? r : 1;
}