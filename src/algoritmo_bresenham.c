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
    //
    int d, xp, yp;
    int Delta_E = 2 * (delta_y);
    int Delta_NE = 2 * ((delta_y) - (delta_x));
    int Delta_N = -2 * (delta_x);
    //
    xp = x0;
    yp = y0;

    d = 2*delta_y-delta_x;
    //

    if (delta_x > delta_y) // octante1 /5
    {
        while (xp < x1)
        {
            (*func_dibujar)((xp), (yp), color);
            if (d <= 0)
            {
                xp++;
                d = d + Delta_E;
            }
            else
            {
                xp++;
                yp++;
                d = d + Delta_NE;
            }
        }
    }
    else //               octante2 / 6
    {
        while (yp < y1)
        {
            if (d > 0)
            {
                yp++;
                d = d + Delta_N;
            }
            else
            {
                xp++;
                yp++;
                d = d + Delta_NE;
            }
            (*func_dibujar)((xp), (yp), color);
        }
    }
}

void cuadrante2(int x0, int y0, int x1, int y1, COLOR *color, void (*func_dibujar)(int, int, COLOR *))
{
    //
    int d, xp, yp;
    int Delta_E = 2 * delta_y;
    int Delta_S = 2 * delta_x;
    int Delta_SE = 2 * (delta_y + delta_x);
    //
    xp = x0;
    yp = y0;
    d = (2*delta_y) + delta_x;

    if (delta_x > abs(delta_y)) // octante  8/4
    {
        while (xp < x1)
        {
            if (d > 0)
            {
                xp++;
                d = d + Delta_E;
            }
            else
            {
                xp++;
                yp--;
                d = d + Delta_SE;
            }
            (*func_dibujar)((xp), (yp), color);
        }
        return;
    }
    else // Octante 7 / 3
    {
        while (yp > y1)
        {
            (*func_dibujar)((xp), (yp), color);
            if (d <= 0)
            {
                yp--;
                d = d + Delta_S;
            }
            else
            {
                xp++;
                yp--;
                d = d + Delta_SE;
            }
        }
    }
}