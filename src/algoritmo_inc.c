#include "include/algoritmo_inc.h"

void algoritmo_inc(int x0, int y0, int x1, int y1, double rc, double gc, double bc,
                   void (*func_dibujar)(int, int, double, double, double))
{
    long double m,y;

    m=(y1-y0)/(x1-x0);
    y=y0;

    for (int i = x0; i < x1; i++)
    {
        (*func_dibujar)(i, (int)(round(y)), rc, gc, bc);
        y+=m;
    }
    
}