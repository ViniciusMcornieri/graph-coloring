#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    int color;
    int weight;
    int adj_qtt;
} vertex;


typedef struct {
    int vertex_qtt;
    int edge_qtt;
    float density;
    vertex *vertexList;
    int **mtx;
} graph;


void freeGraph(graph *g);

graph *newGraph(int vertex_qtt, int edge_qtt);

graph *buildGraph(char *fileName);

#endif
