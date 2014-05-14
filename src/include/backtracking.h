#ifndef Backtracking_H
#define Backtracking_H

int **clone_solution(int **s, int v_qtt);

int *avail_color(graph_t *g, int *color, int v);

int **backtracking(graph_t *g, int **s, int v, int b);

void slash_pos(int *cor, int pos, int v_qtt);

#endif
