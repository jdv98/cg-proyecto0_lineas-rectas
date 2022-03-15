#ifndef DIBUJAR_H
#define DIBUJAR_H

typedef struct {
  double r;
  double g;
  double b;
} COLOR;

extern COLOR **buffer;
extern COLOR *color_fuerza_bruta,
             *color_algoritmo_inc,
             *color_algoritmo_inc_v2,
             *color_bresenham;

extern int resolucion;

void dibujar(int x, int y, COLOR * color);
void noDibujar(int x, int y, COLOR * color);

#endif