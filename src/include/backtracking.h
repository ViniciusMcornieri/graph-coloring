#ifndef Backtracking_H
#define Backtracking_H

#include "graph.h"
#include "hc.h"

int *avail_color(graph *g, colors  *color, int c,  int v);

colors *backtracking(graph *g, colors *s, int v, int b);

#endif
