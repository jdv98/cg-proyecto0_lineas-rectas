#include "include/main.h"
#include <time.h>

COLOR **buffer;

void draw_scene();
void prueba(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)));
COLOR *color1;

int main(int argc, char **argv)
{
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
      buffer[i][j].r = 0.5;
      buffer[i][j].g = 0.5;
      buffer[i][j].b = 0.5;
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

  color1->r = 0.0;
  color1->g = 0.0;
  color1->b = 1.0;
  prueba(fuerza_bruta);
  color1->r = 0.0;
  color1->g = 1.0;
  color1->b = 0.0;
  prueba(algoritmo_inc);
  color1->r = 1.0;
  color1->g = 0.0;
  color1->b = 0.0;
  prueba(algoritmo_inc_v2);
  
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

void prueba(void (*func)(int, int, int, int, COLOR *, void (*func_dibujar)(int, int, COLOR *)))
{
  /*****************/
  /*Prueba de caida*/
  clock_t begin = clock();


  double c, s;
  int cx,sy;
  for (size_t i = 0; i <= 360; i++)
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
  glutPostRedisplay();
}