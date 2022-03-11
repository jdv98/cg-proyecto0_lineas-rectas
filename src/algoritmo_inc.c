#include "include/algoritmo_inc.h"

void algoritmo_inc(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{
    int x0_y1 = 0,
        x = 0,
        y = 0;

    long double m = 0,
                inc = 0;

    if (x0 > x1)
    {
        x0 += x1;
        x1 = x0 - x1;
        x0 -= x1;

        y0 += y1;
        y1 = y0 - y1;
        y0 -= y1;
    }

    x = (x1 - x0);
    y = (y1 - y0);

    x0_y1 = (abs(x) > abs(y)) ? 0 : 1;

    if (x != 0 && (abs(x) > abs(y)))
        m = (long double)y / x;
    else if (abs(x) > abs(y))
        m = (long double)y;
    else if (y != 0)
        m = (long double)x / y;
    else
        m = (long double)x;


    if (x0 == x1 && y0 < y1)
    {
        for (int i = y0; i <= y1; i++)
        {
            (*func_dibujar)(x0, i, color);
        }
    }
    else if (y0 == y1 && x0 != x1)
    {
        for (int i = x0; i <= x1; i++)
        {
            (*func_dibujar)(i, y0, color);
        }
    }
    else if (!x0_y1)
    {
        inc = y0;
        for (int i = x0; i <= x1; i++)
        {
            (*func_dibujar)(i, (int)(round(inc)), color);
            inc += m;
        }
    }
    else if (x0_y1 && y0 > y1)
    {
        inc = x1;
        for (int i = y1; i <= y0; i++)
        {
            (*func_dibujar)((int)(round(inc)), i, color);
            inc += m;
        }
    }
    else if (x0_y1 && y0 < y1)
    {
        inc = x0;
        for (int i = y0; i <= y1; i++)
        {
            (*func_dibujar)((int)(round(inc)), i, color);
            inc += m;
        }
    }
}