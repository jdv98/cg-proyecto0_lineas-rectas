#ifndef DIBUJAR_H
#define DIBUJAR_h

typedef struct {
  double r;
  double g;
  double b;
} COLOR;

extern COLOR **buffer;

void dibujar(int x, int y, COLOR * color);
void noDibujar(int x, int y, Color * color);

#endif