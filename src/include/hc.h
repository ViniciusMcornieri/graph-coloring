#ifndef hc_h
#define hc_h
#include "priority_queue.h"
#include "linked_list.h"
#include "main.h"

struct color{
	int cost;
	vertex_t *vertex_list;
	int color;
};

typedef struct color color_t;

//color_t *new_color(int id);

priority_queue_t *preprocessing(graph_t *g);

int is_not_adj(graph_t *g, vertex_t *v, int *cor);

int **HC(graph_t *g);

int **new_colors_collection(int v_qtt);

int print_out(int **s, int v_qtt);
#endif
