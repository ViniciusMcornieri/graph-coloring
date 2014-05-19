#ifndef VND_H 
#define VND_H

#include "graph.h"
#include "hc.h"
#include "backtracking.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

colors *local_search(graph *g, colors *s, int *y, int b);
colors *vnd(graph *g, colors *s, int alpha, int beta);

#endif
