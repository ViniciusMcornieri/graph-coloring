#ifndef Backtracking_H
#define Backtracking_H

int **clone_solution(int **s, int v_qtt);

int *avail_color(graph_t *g, colors  *color, int c,  int v);

colors *backtracking(graph_t *g, colors *s, int v, int b);

void slash_pos(int *cor, int pos, int v_qtt);

int colors_counting(int **s, int v_qtt);
#endif
