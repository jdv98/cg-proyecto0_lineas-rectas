#include "include/main.h"

/**
 * Estudiantes:
 * Luis Gerardo Sanchez Alvarez
 * Jose Daniel Villegas Paniagua
 * 
 */

COLOR **buffer;
COLOR *color_fuerza_bruta,
             *color_algoritmo_inc,
             *color_algoritmo_inc_v2,
             *color_bresenham;

int resolucion, cant_lineas, cant_veces;
void draw_scene();
void init_colors();

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

  init_colors();
  //return;
  crearLineasAleatorias(resolucion, cant_lineas);

  int i, j;

  buffer = (COLOR **)malloc(resolucion * sizeof(COLOR *));
  for (i = 0; i < resolucion; i++)
  {
    buffer[i] = (COLOR *)malloc(resolucion * sizeof(COLOR));
  }

  for (i = 0; i < resolucion; i++)
  {
    for (j = 0; j < resolucion; j++)
    {
      buffer[i][j].r = 0.0;
      buffer[i][j].g = 0.0;
      buffer[i][j].b = 0.0;
    }
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(resolucion, resolucion);
  glutCreateWindow("Proyecto 0 Lineas Rectas Aleatorias");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0, resolucion, 0, resolucion);
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

void init_colors(){
  color_fuerza_bruta = malloc(sizeof(COLOR));
  color_algoritmo_inc = malloc(sizeof(COLOR));
  color_algoritmo_inc_v2 = malloc(sizeof(COLOR));
  color_bresenham = malloc(sizeof(COLOR));

  color_fuerza_bruta->r = (double)0.0;
  color_fuerza_bruta->g = (double)0.0;
  color_fuerza_bruta->b = (double)0.0;

  color_algoritmo_inc->r = (double)1.0;
  color_algoritmo_inc->g = (double)0.0;
  color_algoritmo_inc->b = (double)0.0;

  color_algoritmo_inc_v2->r = (double)0.0;
  color_algoritmo_inc_v2->g = (double)1.0;
  color_algoritmo_inc_v2->b = (double)0.0;

  color_bresenham->r = (double)0.5;
  color_bresenham->g = (double)1.0;
  color_bresenham->b = (double)0.5;
}