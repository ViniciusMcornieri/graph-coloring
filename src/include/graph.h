#ifndef graph_h
#define graph_h
#include "linked_list.h"
#define ADJ 1
#define MTX 2
#define BTH 3
#define DEN 4

struct vertex{
    int id;
    int color;
    int weight;
};

struct edge{
    int from;
    int to;
    int active;

};

typedef struct vertex vertex_t;

typedef struct edge edge_t;

struct graph{
    int vertex_qtt;
    int edge_qtt;
    float density;
    float den_limit;
    vertex_t *vertexList;
    linked_list_t **adj;
    edge_t **mtx;
    int adjOrMtx;
};

typedef struct graph graph_t;

void freeGraph(graph_t *g);
graph_t *newGraph(int vertex_qtt, int edge_qtt, int adjOrMtx, float den_param);
graph_t *buildGraph(char *fileName, int adjOrMtx, float den_param);

#endif
