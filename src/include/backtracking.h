#ifndef Backtracking_H
#define Backtracking_H

priority_queue_t *clone_solution(priority_queue_t *s);
linked_list_t    *avail_color(graph_t *g, color_t *color, vertex_t *vertex);
#endif
