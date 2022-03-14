#ifndef KEYS_H
#define KEYS_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

#include "dibujar.h"
#include "fuerza_bruta.h"
#include "algoritmo_inc.h"
#include "algoritmo_inc_v2.h"
#include "algoritmo_bresenham.h"
#include <stdio.h>
#include <time.h>
#include "lineas_aleatorias.h"

extern COLOR *color1;
void normal_keys(unsigned char key, int x, int y);
void special_keys(int key, int x, int y);

#endif