#ifndef VND_H 
#define VND_H

#include "backtracking.h"

#include <time.h>
#include <math.h>

colors *local_search(graph* , colors* , int* , int, int);

colors *vnd(graph*, colors*, int, int);

#endif
