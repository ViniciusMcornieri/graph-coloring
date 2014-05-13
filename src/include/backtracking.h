#ifndef Backtracking_H
#define Backtracking_H

priority_queue_t *clone_solution(priority_queue_t *s);

priority_queue_t    *avail_color(graph_t *g, color_t *color, vertex_t *vertex);

priority_queue_t *backtracking(graph_t *g, priority_queue_t *s, vertex_t *v, int b);

int slash_vertex(priority_queue_t *s, vertex_t *v);
#endif
