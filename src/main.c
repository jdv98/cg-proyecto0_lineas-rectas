#include "include/main.h"

COLOR **buffer;

void draw_scene();

int main(int argc,char **argv)
{
  int i, j;

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