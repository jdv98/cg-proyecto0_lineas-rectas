#include "include/lineas_aleatorias.h"

LINEAS* lineas;

int crearLineasAleatorias(int limite,int numlineas)
{
    // Generar Matrix
    lineas = (LINEAS *)malloc(numlineas * sizeof(LINEAS));
    limite--;
   
   srand((unsigned) time(NULL));

    for (int x= 0; x <numlineas; x++)
    {
        lineas[x].x0 = rand()%limite;
        lineas[x].x1 = rand()%limite;
        lineas[x].y0 = rand()%limite;
        lineas[x].y1 = rand()%limite;
    }

    return (0);
}