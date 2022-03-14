#include "include/main.h"
#include <time.h>

COLOR **buffer;
COLOR *color1;

int resolucion, cant_lineas, cant_veces;
void draw_scene();

int main(int argc, char **argv)
{
  if (argc < 4 || argc > 4)
  {
    (void)fprintf(stdout, "Usage: %s <resolucion> <# lineas> <# veces>\n", argv[0]);
    exit(0);
  }
  else if (argc == 4)
  {
    resolucion = atoi(argv[1]);
    cant_lineas = atoi(argv[2]);
    cant_veces = atoi(argv[3]);
  }

  crearLineasAleatorias(resolucion, cant_lineas);

  int i, j;
  color1 = malloc(sizeof(COLOR));

  buffer = (COLOR **)malloc(resolucion * sizeof(COLOR *));
  for (i = 0; i < resolucion; i++)
  {
    buffer[i] = (COLOR *)malloc(resolucion * sizeof(COLOR));
  }

  for (i = 0; i < resolucion; i++)
  {
    for (j = 0; j < resolucion; j++)
    {
      buffer[i][j].r = 1.0;
      buffer[i][j].g = 1.0;
      buffer[i][j].b = 1.0;
    }
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(resolucion, resolucion);
  glutCreateWindow("Mesa Example");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, resolucion + 0.5, -0.5, resolucion + 0.5);
  glutDisplayFunc(draw_scene);
  glutKeyboardFunc(normal_keys);
  glutSpecialFunc(special_keys);
  glutMainLoop();
}

void draw_scene()
{
  int i, j;
  for (i = 0; i < resolucion; i++)
  {
    for (j = 0; j < resolucion; j++)
    {
      glColor3f(buffer[i][j].r, buffer[i][j].g, buffer[i][j].b);
      glBegin(GL_POINTS);
      glVertex2i(i, j);
      glEnd();
    }
  }

  glFlush();
}