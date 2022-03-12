#include "include/algoritmo_inc_v2.h"

int max(int a, int b);

void algoritmo_inc_v2(int x0, int y0, int x1, int y1, COLOR * color,void (*func_dibujar)(int,int,COLOR *))
{
    int width = max(abs(x1 - x0), abs(y1 - y0));

    long double x = x0,
                y = y0,
                mx = (long double)((x1 - x0) / width),
                my = (long double)((y1 - y0) / width);

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