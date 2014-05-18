#ifndef COLORS_H
#define COLORS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *vertex;
    int *index;
    int color_size;
    int v_qtt;
} colors;

colors *create_colors(int v_qtt);

colors *clone_colors(colors *s);

void c_insert(colors *s, int c, int v);

void increment_colors(colors *s, int v);

void c_remove(colors *s, int v);

void free_colors(colors *s);

void c_print(colors *s);

#endif
