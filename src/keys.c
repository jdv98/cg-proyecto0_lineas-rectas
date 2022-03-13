#include "include/keys.h"

void prueba(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)));


void normal_keys(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27: // Esc
    exit(0);
    break;

  case 49:

    color1->r = 0.0;
    color1->g = 1.0;
    color1->b = 0.0;
    //prueba(fuerza_bruta);


    color1->r = 1.0;
    color1->g = 0.0;
    color1->b = 0.0;
    //prueba(algoritmo_inc);


    color1->r = 0.0;
    color1->g = 0.0;
    color1->b = 1.0;
    prueba(algoritmo_inc_v2);


    color1->r = 0.0;
    color1->g = 0.0;
    color1->b = 0.0;
    //prueba(bresenham);
    break;

  default:
    break;
  }
}

void special_keys(int key, int x, int y){

}

void prueba(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)))
{
  
  /*****************/
  /*Prueba de caida*/
  clock_t begin = clock();

  double c, s;
  int cx,sy;
  for (int i = 35; i <= 45; i++)
  {
    c = cos(i) * 70;
    s = sin(i) * 70;
    cx=(int)(500+(int)(round(c)));
    sy=(int)(500+(int)(round(s)));

    (*func)(cx,sy, 500, 500,color1,dibujar);
  }


  /*fuerza_bruta(437,470, 500, 500,color1,dibujar);
  fuerza_bruta(491,431, 500, 500,color1,dibujar);
  fuerza_bruta(554,455, 500, 500,color1,dibujar);
  fuerza_bruta(567,521, 500, 500,color1,dibujar);
  fuerza_bruta(519,567, 500, 500,color1,dibujar);
  fuerza_bruta(453,552, 500, 500,color1,dibujar);
  fuerza_bruta(431,489, 500, 500,color1,dibujar);
  fuerza_bruta(472,436, 500, 500,color1,dibujar);
  fuerza_bruta(539,442, 500, 500,color1,dibujar);
  fuerza_bruta(570,501, 500, 500,color1,dibujar);
  fuerza_bruta(537,560, 500, 500,color1,dibujar);*/

  /*color1->r = 1.0;
  color1->g = 0.0;
  color1->b = 0.0;

  bresenham(437,470, 500, 500,color1,dibujar);
  bresenham(491,431, 500, 500,color1,dibujar);
  bresenham(554,455, 500, 500,color1,dibujar);
  bresenham(567,521, 500, 500,color1,dibujar);
  bresenham(519,567, 500, 500,color1,dibujar);
  bresenham(453,552, 500, 500,color1,dibujar);
  bresenham(431,489, 500, 500,color1,dibujar);
  bresenham(472,436, 500, 500,color1,dibujar);
  bresenham(539,442, 500, 500,color1,dibujar);
  bresenham(570,501, 500, 500,color1,dibujar);
  bresenham(537,560, 500, 500,color1,dibujar);*/

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("TIME===%lf\n",time_spent);
  glutPostRedisplay();
}