#include "include/main.h"
#include "include/linked_list.h"
#include "include/next_string.h"
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
    edge_t **mtx;
    int adjOrMtx;
};

typedef struct graph graph_t;

float calculateDensity(int vertex_qtt, int edge_qtt){
    return (edge_qtt << 1)/(vertex_qtt*vertex_qtt - vertex_qtt);
}

graph_t *newGraph(int vertex_qtt, int edge_qtt, int adjOrMtx){
    graph_t *g    = malloc(sizeof(graph_t));
    g->vertex_qtt = vertex_qtt;
    g->edge_qtt   = edge_qtt;
    g->density    = calculateDensity(vertex_qtt, edge_qtt);
    g->adjOrMtx   = adjOrMtx;         
    g->vertexList = malloc(sizeof(vertex_t)*vertex_qtt);
    g->edgeList   = malloc(sizeof(edge_t)*edge_qtt);    
    g->adj        = malloc(sizeof(linked_list_t *)*vertex_qtt);
    g->mtx        = malloc(sizeof(edge_t *)*vertex_qtt);    

    int i;    
    for(i = 0; i<vertex_qtt; g->adj[i++] = newLinkedList()); 
    for(i = 0; i<vertex_qtt; g->mtx[i++] = malloc(sizeof(edge_t)*vertex_qtt));

    return g;
}

void addVertex(graph_t *g, int id){
    int i                  = id+1;
    g->vertexList[i].id    = id;
    g->vertexList[i].color = 0;
}

void addAllVertex(graph_t *g){
    int i;
    int vqtt = g->vertex_qtt;
    for(i = 0; i<vqtt; addVertex(g,i++));
}

void addEdge(graph_t *g, int a, int b){
    edge_t *e = malloc(sizeof(edge_t));
    e->from   = a;
    e->to     = b;
   // if(g->adjOrMtx == ADJ){
        push(g->adj[a-1], e);
    /*}else{
         g->mtx[a][b] = *e;    
    }*/
}

graph_t *readGraphFile(FILE *graphFile,int adjOrMtx){
    graph_t *g = NULL;
    int vqtt, eqtt, a, b;
    char s[80];
    fscanf(graphFile, "%s", s);
    while(s[0]!='p' || strlen(s)!=1){
        fscanf(graphFile, "%s", s);
    }
    fscanf(graphFile, "%s %d %d", s, &vqtt, &eqtt);
    g = newGraph(vqtt, eqtt, adjOrMtx);
    addAllVertex(g);     
    while(fscanf(graphFile, "%s %d %d", s, &a, &b) != EOF){
        addEdge(g,a,b);
    }
    return g;
}

graph_t *buildGraph(char *fileName, int adjOrMtx){
    FILE *graphFile;
    graphFile = fopen(fileName,"r");
    graph_t *g = NULL;
    if(graphFile != NULL){
       g = readGraphFile(graphFile, adjOrMtx);
       fclose(graphFile);    
    }
    return g;
    
}


