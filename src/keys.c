#include "include/keys.h"

void idles(void)
{
  for (int i = 0; i < resolucion; i++)
  {
    for (int j = 0; j < resolucion; j++)
    {
      glColor3f(buffer[i][j].r, buffer[i][j].g, buffer[i][j].b);
      glBegin(GL_POINTS);
      glVertex2i(i, j);
      glEnd();
    }
  }

  glFlush();
}

void imprimirCompletos(int repetir_veces, void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)), COLOR *color, char *algoritmo);

void imprimirLinea(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)), COLOR *color, char *algoritmo);

void noImprimir(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)), COLOR *color, char *algoritmo);

void imprimirLineaPorAlgortimo();

void reset(){
  for (int i = 0; i < resolucion; i++)
    {
      for (int j = 0; j < resolucion; j++)
      {
        buffer[i][j].r = 0.0;
        buffer[i][j].g = 0.0;
        buffer[i][j].b = 0.0;
      }
    }
}

void normal_keys(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27: // Esc
    exit(0);
    break;

  case 49:
    printf("\n\n________________________________________\n_Impresion de las lineas con repeticion_\n________________________________________\n");
    imprimirCompletos(cant_veces,fuerza_bruta,color_fuerza_bruta,"Algoritmo fuerza bruta");
    imprimirCompletos(cant_veces,algoritmo_inc,color_algoritmo_inc,"Algoritmo incremetal");
    imprimirCompletos(cant_veces,algoritmo_inc_v2,color_algoritmo_inc_v2,"Algoritmo incremental 2");
    imprimirCompletos(cant_veces,bresenham,color_bresenham, "Algoritmo de Bresenham");
    printf("\n________________________________________\n________________________________________\n________________________________________\n");
    break;
  case 50:
    printf("\n\n________________________________________\n___________Impresion por linea__________\n________________________________________\n");
    imprimirLinea(fuerza_bruta,color_fuerza_bruta,"Algoritmo fuerza bruta");
    imprimirLinea(algoritmo_inc,color_algoritmo_inc,"Algoritmo incremetal");
    imprimirLinea(algoritmo_inc_v2,color_algoritmo_inc_v2,"Algoritmo incremental 2");
    imprimirLinea(bresenham,color_bresenham, "Algoritmo de Bresenham");
    printf("\n________________________________________\n________________________________________\n________________________________________\n");
    break;

  case 51:
    printf("\n\n________________________________________\n____Tiempos de ejecucion sin impresion____\n________________________________________\n");
    noImprimir(fuerza_bruta,color_fuerza_bruta,"Algoritmo fuerza bruta");
    noImprimir(algoritmo_inc,color_algoritmo_inc,"Algoritmo incremetal");
    noImprimir(algoritmo_inc_v2,color_algoritmo_inc_v2,"Algoritmo incremental 2");
    noImprimir(bresenham,color_bresenham, "Algoritmo de Bresenham");
    printf("\n________________________________________\n________________________________________\n________________________________________\n");

    break;
  case 52:
    printf("\n\n________________________________________\n_Impresion de las lineas sin repeticion_\n________________________________________\n");
    imprimirCompletos(1,fuerza_bruta,color_fuerza_bruta,"Algoritmo fuerza bruta");
    imprimirCompletos(1,algoritmo_inc,color_algoritmo_inc,"Algoritmo incremetal");
    imprimirCompletos(1,algoritmo_inc_v2,color_algoritmo_inc_v2,"Algoritmo incremental 2");
    imprimirCompletos(1,bresenham,color_bresenham, "Algoritmo de Bresenham");
    printf("\n________________________________________\n________________________________________\n________________________________________\n");
    break;

  case 53:
    printf("\n\n________________________________________\n_Impresion de las lineas por algoritmo_\n________________________________________\n");
    imprimirLineaPorAlgortimo();
    printf("\n________________________________________\n________________________________________\n________________________________________\n");
    break;

  case 54:
    reset();
    idles();
    break;
  case 55:
    crearLineasAleatorias(resolucion,cant_lineas);
    break;

  default:
    break;
  }
}

void special_keys(int key, int x, int y)
{
}

void imprimirCompletos(int repetir_veces, void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)), COLOR *color, char *algoritmo)
{
  clock_t begin = clock();

  for (size_t t = 0; t < repetir_veces; t++)
  {
    for (size_t i = 0; i < cant_lineas; i++)
    {
      (*func)(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color, dibujar);
    }
  }
  idles();

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%s\t\tTiempo=>%lf\n", algoritmo, time_spent);
}

void imprimirLinea(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)), COLOR *color, char *algoritmo)
{
  clock_t begin = clock();
  for (size_t i = 0; i < cant_lineas; i++)
  {
    (*func)(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color, dibujar);
    idles();
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%s\t\tTiempo=>%lf\n", algoritmo, time_spent);
}

void imprimirLineaPorAlgortimo()
{
  clock_t begin = clock();
  for (size_t i = 0; i < cant_lineas; i++)
  {
    fuerza_bruta(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color_fuerza_bruta, dibujar);
    idles();
    algoritmo_inc(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color_algoritmo_inc, dibujar);
    idles();
    algoritmo_inc_v2(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color_algoritmo_inc_v2, dibujar);
    idles();
    bresenham(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color_bresenham, dibujar);
    idles();
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tiempo general=>%lf\n", time_spent);
}

void noImprimir(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)), COLOR *color, char *algoritmo)
{
  clock_t begin = clock();
  for (size_t t = 0; t < cant_veces; t++)
  {
    for (size_t i = 0; i < cant_lineas; i++)
    {
      (*func)(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color, noDibujar);
    }
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%s\t\tTiempo=>%lf\n", algoritmo, time_spent);
}
