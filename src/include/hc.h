#ifndef hc_h
#define hc_h

#include "graph.h"
#include "colors.h"

int is_not_adj(graph *g, int  v, colors *s,  int c);

colors *HC(graph *g);
 

#endif
