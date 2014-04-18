#ifndef hc_h
#define hc_h
#include "linked_list.h"
#include "graph.h"
#include "main.h"
struct color{
	int cost;
	linked_list_t *vertex_list;
	int color;
};

typedef struct color color_t;


color_t *new_color(int id);
vertex_t *preprocessing(graph_t g);
int is_not_adj(graph_t *g, vertex_t *v, linked_list_t *vertex_list);
linked_list_t *HC(graph_t *g);
int print_out(linked_list_t *list);


#endif
