#include "include/fuerza_bruta.h"

void fuerza_bruta(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{

    long double m=0, b=0;
    int yx=0;

    if (x1 < x0 || (x1 <= x0 && y1<y0))
    {
        int tmpx = x0,
            tmpy = y0;
        x0 = x1;
        y0 = y1;
        x1 = tmpx;
        y1 = tmpy;
    }

    int x = (x1 - x0),
        y = (y1 - y0);

    int x0_y1 = (abs(x) > abs(y)) ? 0 : 1;

    if (x==0)
    {
        m = (long double)y;
    }
    else
    {
        m = (long double)y / x;
    }

    b = (long double)y0 - m * x0;

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
    else if (x0_y1 && y0 > y1)////Y
    {
        for (int i = y1; i <= y0; i++)
        {
            yx =(int)(round((i - b) / m));
            (*func_dibujar)(yx,i, color);
        }
    }
    else if (x0_y1 && y0 < y1)////Y
    {
        for (int i = y0; i <= y1; i++)
        {
            yx =(int)(round((i - b) / m));
            (*func_dibujar)(yx,i, color);
        }
    }
    else if(!x0_y1) {////X
        for (int i = x0; i <= x1; i++)
        {
            yx =(int)(floor(m * i + b));
            (*func_dibujar)(i, yx, color);
        }
    }
}