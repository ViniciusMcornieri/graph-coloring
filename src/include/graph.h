#ifndef graph_h
#define graph_h

struct vertex{
    int id;
    int color;
    int weight;
    int adj_qtt;
};

typedef struct vertex vertex_t;


struct graph{
    int vertex_qtt;
    int edge_qtt;
    float density;
    vertex_t *vertexList;
    int **mtx;
};

typedef struct graph graph_t;

//

void freeGraph(graph_t *g);

graph_t *newGraph(int vertex_qtt, int edge_qtt);

graph_t *buildGraph(char *fileName);

#endif
