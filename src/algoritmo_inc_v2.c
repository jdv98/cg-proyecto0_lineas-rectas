#include "include/algoritmo_inc_v2.h"

int max(int a, int b);

void algoritmo_inc_v2(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{
    int x1_x0 = x1 - x0,
        y1_y0 = y1 - y0;
    int width = max(abs(x1_x0), abs(y1_y0));

    long double x = (long double)x0,
                y = (long double)y0,
                mx = (long double)x1_x0 /width,
                my = (long double)y1_y0 /width;

    for (int i = 0; i <= width; i++)
    {
        (*func_dibujar)((int)(round(x)), (int)(round(y)), color);
        x += mx;
        y += my;
    }
}

int max(int a, int b)
{
    if(a>b){
        return a != 0 ? a : 1;
    }
    return b != 0 ? b : 1;
}