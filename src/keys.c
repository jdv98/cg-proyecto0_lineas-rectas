#include "include/keys.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "malloc.h"

void idles(void)
{
  for (int i = 0; i < 1000; i++)
  {
    for (int j = 0; j < 1000; j++)
    {
      glColor3f(buffer[i][j].r, buffer[i][j].g, buffer[i][j].b);
      glBegin(GL_POINTS);
      glVertex2i(i, j);
      glEnd();
    }
  }

  glFlush();
}

void imprimirCompletos(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)),char * algoritmo);

void imprimirLinea(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)),char * algoritmo);

void noImprimir(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)),char * algoritmo);

void normal_keys(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27: // Esc
    exit(0);
    break;

  case 49:
    color1->r = (double)0.0;
    color1->g = (double)0.0;
    color1->b = (double)1.0;
    imprimirCompletos(fuerza_bruta,"Algoritmo fuerza bruta");
    color1->r = (double)1.0;
    color1->g = (double)0.0;
    color1->b = (double)0.0;
    imprimirCompletos(algoritmo_inc,"Algoritmo incremetal");
    color1->r = (double)0.0;
    color1->g = (double)1.0;
    color1->b = (double)0.0;
    imprimirCompletos(algoritmo_inc_v2,"Algoritmo incremental v2");
    color1->r = (double)0.0;
    color1->g = (double)0.0;
    color1->b = (double)0.0;
    imprimirCompletos(bresenham,"Algoritmo de Bresenham");

    break;
    case 50:
    color1->r = (double)0.0;
    color1->g = (double)0.0;
    color1->b = (double)1.0;
    imprimirLinea(fuerza_bruta,"Algoritmo fuerza bruta");
    color1->r = (double)1.0;
    color1->g = (double)0.0;
    color1->b = (double)0.0;
    imprimirLinea(algoritmo_inc,"Algoritmo incremetal");
    color1->r = (double)0.0;
    color1->g = (double)1.0;
    color1->b = (double)0.0;
    imprimirLinea(algoritmo_inc_v2,"Algoritmo incremental v2");
    color1->r = (double)0.0;
    color1->g = (double)0.0;
    color1->b = (double)0.0;
    imprimirLinea(bresenham,"Algoritmo de Bresenham");
    break;

    case 51:
    color1->r = (double)0.0;
    color1->g = (double)0.0;
    color1->b = (double)1.0;
    noImprimir(fuerza_bruta,"Algoritmo fuerza bruta");
    color1->r = (double)1.0;
    color1->g = (double)0.0;
    color1->b = (double)0.0;
    noImprimir(algoritmo_inc,"Algoritmo incremetal");
    color1->r = (double)0.0;
    color1->g = (double)1.0;
    color1->b = (double)0.0;
    noImprimir(algoritmo_inc_v2,"Algoritmo incremental v2");
    color1->r = (double)0.0;
    color1->g = (double)0.0;
    color1->b = (double)0.0;
    noImprimir(bresenham,"Algoritmo de Bresenham");
    

    break;

  default:
    break;
  }
}

void special_keys(int key, int x, int y)
{
}

void imprimirCompletos(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)),char * algoritmo)
{
  clock_t begin = clock();

  for (size_t t = 0; t < cant_veces; t++)
  {
    for (size_t i = 0; i < cant_lineas; i++)
    {
      (*func)(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color1, dibujar);
    }
  }
  idles();

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%s\t\tTiempo con impresion completa=>%lf\n",algoritmo, time_spent);  
}

void imprimirLinea(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)),char * algoritmo)
{
  clock_t begin = clock();
  for (size_t i = 0; i < cant_lineas; i++)
  {
    (*func)(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color1, dibujar);
    idles();
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%s\t\tTiempo con impresion por linea=>%lf\n",algoritmo, time_spent);  
}

void noImprimir(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)),char * algoritmo)
{
  clock_t begin = clock();
  for (size_t t = 0; t < cant_veces; t++)
  {
    for (size_t i = 0; i < cant_lineas; i++)
    {
      (*func)(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1, color1, noDibujar);
    }
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%s\t\tTiempo sin imprimir=>%lf\n",algoritmo, time_spent);  
}