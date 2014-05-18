#ifndef hc_h
#define hc_h
#include "main.h"
#include "colors.h"
int is_not_adj(graph_t *g, vertex_t *v, colors *s,  int c);

colors *HC(graph_t *g);
 

#endif
