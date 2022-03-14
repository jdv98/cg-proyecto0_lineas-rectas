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

    printf("\n\n\n");

    /*color1->r = 0.0;
    color1->g = 0.0;
    color1->b = 1.0;*/
    prueba(bresenham);

    printf("_________________\n");

    color1->r = 0.0;
    color1->g = 0.0;
    color1->b = 0.0;
    prueba(algoritmo_inc_v2);
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
  for (int i =0; i <= 10; i++)
  {
    c = cos(i) * 70;
    s = sin(i) * 70;
    cx=(int)(500+(int)(round(c)));
    sy=(int)(500+(int)(round(s)));

    (*func)(cx,sy, 500, 500,color1,dibujar);
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("TIME===%lf\n",time_spent);

    /*buffer[x][y]=(COLOR)*color;
    pixel_cambiado_x=x;
    pixel_cambiado_y=y;*/
    glutPostRedisplay();
}