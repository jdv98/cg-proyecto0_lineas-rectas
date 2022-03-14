#ifndef LINEAS_ALEATORIAS_H
#define LINEAS_ALEATORIAS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int x0;
    int x1;
    int y0;
    int y1;
} LINEAS;

extern LINEAS* lineas;

int crearLineasAleatorias(int limite,int numlineas);

#endif