#ifndef graph_h
#define graph_h
#include "linked_list.h"
#include "next_string.h"
#define ADJ 1
#define MTX 2

struct vertex{
    int id;
    int color;
};

struct edge{
    int from;
    int to;
};

typedef struct vertex vertex_t;

typedef struct edge edge_t;

struct graph{
    int vertex_qtt;
    int edge_qtt;
    float density;
    vertex_t *vertexList;
    edge_t *edgeList;
    linked_list_t **adj;
    int **mtx;
};

typedef struct graph graph_t;

float calculateDensity(int vertex_qtt, int edge_qtt);

graph_t *newGraph(int vertex_qtt, int edge_qtt, int adjOrMtx);

void addVertex(graph_t *g, int id);

void addAllVertex(graph_t *g);

void addEdge(graph_t *g, int a, int b);

graph_t *buildGraph(char *fileName, int adjOrMtx);


#endif
