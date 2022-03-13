#ifndef DIBUJAR_H
#define DIBUJAR_H

typedef struct {
  double r;
  double g;
  double b;
} COLOR;

extern COLOR **buffer;

extern int pixel_cambiado_x,pixel_cambiado_y;

void dibujar(int x, int y, COLOR * color);
void noDibujar(int x, int y, COLOR * color);

#endif