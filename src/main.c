#include "include/main.h"
#include <time.h>

COLOR **buffer;
COLOR *color1;

void draw_scene();
// void prueba(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)));
int pixel_cambiado_x,pixel_cambiado_y;
int main(int argc, char **argv)
{
  pixel_cambiado_x=-1;
  pixel_cambiado_y=-1;
  
  int i, j;
  color1 = malloc(sizeof(COLOR));

  buffer = (COLOR **)malloc(H_SIZE * sizeof(COLOR *));
  for (i = 0; i < H_SIZE; i++)
  {
    buffer[i] = (COLOR *)malloc(V_SIZE * sizeof(COLOR));
  }

  for (i = 0; i < H_SIZE; i++)
  {
    for (j = 0; j < V_SIZE; j++)
    {
      buffer[i][j].r = 1.0;
      buffer[i][j].g = 1.0;
      buffer[i][j].b = 1.0;
    }
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE, V_SIZE);
  glutCreateWindow("Mesa Example");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, H_SIZE + 0.5, -0.5, V_SIZE + 0.5);
  glutDisplayFunc(draw_scene);
  glutKeyboardFunc(normal_keys);
  glutSpecialFunc(special_keys);

  // prueba(fuerza_bruta);
  /*color1->r = 0.0;
  color1->g = 1.0;
  color1->b = 0.0;
  //prueba(algoritmo_inc);
  color1->r = 1.0;
  color1->g = 0.0;
  color1->b = 0.0;
  //prueba(algoritmo_inc_v2);
  color1->r = 0.5;
  color1->g = 0.5;
  color1->b = 0.5;*/
  // prueba(bresenham);

  glutMainLoop();
}

void draw_scene()
{

  
    int i, j;

    for (i = 0; i < H_SIZE; i++)
    {
      for (j = 0; j < V_SIZE; j++)
      {
        glColor3f(buffer[i][j].r, buffer[i][j].g, buffer[i][j].b);
        glBegin(GL_POINTS);
        glVertex2i(i, j);
        glEnd();
      }
    }
  

  glFlush();
}

/*void prueba(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)))
{
  /****************
  /*Prueba de caida
  clock_t begin = clock();


  double c, s;
  int cx,sy;
  for (int i = 35; i <= 45; i++)
  {
    c = cos(i) * 70;
    s = sin(i) * 70;
    cx=(int)(500+(int)(round(c)));
    sy=(int)(500+(int)(round(s)));

    /*printf("(%i,%i, 500, 500,color1,dibujar);\n",cx,sy);

    color1->r = 0.0;
    color1->g = 0.0;
    color1->b = 1.0;

    fuerza_bruta(cx,sy, 500, 500,color1,dibujar);

    color1->r = 0.0;
    color1->g = 1.0;
    color1->b = 0.0;


    //lgoritmo_inc(cx,sy, 500, 500,color1,dibujar);

    color1->r = 1.0;
    color1->g = 0.0;
    color1->b = 0.0;


    //algoritmo_inc_v2(cx,sy, 500, 500,color1,dibujar);

    color1->r = 0.5;
    color1->g = 0.5;
    color1->b = 0.5;


    bresenham(cx,sy, 500, 500,color1,dibujar);

    //(*func)(cx,sy, 500, 500,color1,dibujar);
  }


  color1->r = 0.0;
  color1->g = 1.0;
  color1->b = 0.0;
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
  fuerza_bruta(537,560, 500, 500,color1,dibujar);

  color1->r = 1.0;
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
  bresenham(537,560, 500, 500,color1,dibujar);

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("TIME===%lf\n",time_spent);
  glutPostRedisplay();
}
*/