#include "include/algoritmo_inc_v2.h"

int max(int a, int b);

void algoritmo_inc_v2(int x0, int y0, int x1, int y1, double rc, double gc, double bc,
                      void (*func_dibujar)(int, int, double, double, double))
{
    int width = max(abs(x1 - x0), abs(y1 - y0));

    long double x = x0,
                y = y0,
                mx = (x1 - x0) / width,
                my = (y1 - y0) / width;

    for (int i = 0; i < width; i++)
    {
        (*func_dibujar)((int)(round(x)), (int)(round(y)), rc, gc, bc);
        x += mx;
        y += my;
    }
}

int max(int a, int b)
{
    int *r = a > b ? &a : &b;
    return r > 0 ? *r : 1;
}