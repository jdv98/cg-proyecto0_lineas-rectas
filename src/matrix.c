#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // Genera un ramdon
    int numero = rand() % (10 + 100);

    //printf("%i", numero);

    // Generar Matrix

    int limite = 100;
    typedef struct
    {
        int x0;
        int x1;
        int y0;
        int y1;
    } LINEAS;
    int x;
    int numlineas = 5;
    LINEAS* lineas = malloc(numlineas * sizeof *lineas);

    for (x= 0; x <numlineas; x++)
    {
        lineas[x].x0 = rand() % limite;
        lineas[x].x1 = rand() % limite;
        lineas[x].y0 = rand() % limite;
        lineas[x].y1 = rand() % limite;
    }

    // Recorrer la matrix
    for (x = 0; x < numlineas; x++)
        printf("x=%i,y=%i\n",lineas[x].x0,lineas[x].y0);

    return (0);
}
