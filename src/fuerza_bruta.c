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
    if (x0 == x1)
    {
        m = (long double)(y1 - y0);
    }
    else
    {
        m = (long double)(y1 - y0) / (x1 - x0);
    }

    b = (long double)y0 - m * x0;

    if (x0 == x1 && y0 != y1)
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
    else if (b<0 && y0<y1)////Y
    {
        for (int i = y0; i <= y1; i++)
        {
            yx =(int)(round((i - b) / m));
            (*func_dibujar)(yx,i, color);
        }
    }
    else if ((b<0 && y1<y0) || (m<-1 && y1<y0)  )////Y
    {
        for (int i = y1; i <= y0; i++)
        {
            yx =(int)(round((i - b) / m));
            (*func_dibujar)(yx,i, color);
        }
    }
    else {////X
        for (int i = x0; i <= x1; i++)
        {
            yx =(int)(round(m * i + b));
            (*func_dibujar)(i, yx, color);
        }
    }
}

/**
 * Casos:
 *
 * fuerza_bruta(50, 50, 100, 100, 1.0, 1.0, 1.0, dibujar);
 * fuerza_bruta(50, 50, 200, 50, 1.0, 1.0, 1.0, dibujar);
 * fuerza_bruta(200, 1, 200, 100, 1.0, 1.0, 1.0, dibujar);
 *
 */