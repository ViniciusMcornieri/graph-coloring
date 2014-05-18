#include "include/main.h"

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

float calculateDensity(int vertex_qtt, int edge_qtt){
    return (edge_qtt << 1)/(vertex_qtt*vertex_qtt - vertex_qtt);
}

void freeGraph(graph_t *g){
    int i;
    for(i = 0; i<g->vertex_qtt; free(g->mtx[i++]));
    free(g->mtx);    
    free(g);
    g = NULL;
}


void mallocMtx(graph_t *g){
    int i,j;
    int *e;
    g->mtx = malloc(sizeof(int *)*g->vertex_qtt);    
    for(i = 0; i < g->vertex_qtt; i++){
        g->mtx[i] = malloc(sizeof(int)*g->vertex_qtt);
        e = g->mtx[i];    
       for(j = 0; j < g->vertex_qtt; j++){
                e[j] = 0;
        }    
    }
}

graph_t *newGraph(int vertex_qtt, int edge_qtt){
    graph_t *g    = malloc(sizeof(graph_t));
    g->vertex_qtt = vertex_qtt;
    g->edge_qtt   = edge_qtt;
    g->density    = calculateDensity(vertex_qtt, edge_qtt);       
    g->vertexList = malloc(sizeof(vertex_t)*vertex_qtt);
    mallocMtx(g);
    return g;
}

void addVertex(graph_t *g, int id){
    int i                  = id-1;
    g->vertexList[i].id    = id;
    g->vertexList[i].color = 0;
	g->vertexList[i].adj_qtt= 0;
}

void addAllVertex(graph_t *g){
    int i;
    int vqtt = g->vertex_qtt;
    for(i = 0; i<vqtt;addVertex(g,++i));
}

void addEdge(graph_t *g, int a, int b){
    g->vertexList[a-1].adj_qtt++;
    g->vertexList[b-1].adj_qtt++;
    g->mtx[a-1][b-1]=1;
    g->mtx[b-1][a-1]=1; 
}

graph_t *readGraphFile(FILE *graphFile){
    graph_t *g = NULL;
    int vqtt, eqtt, a, b;
    char s[80];
    fscanf(graphFile, "%s", s);
    while(s[0]!='p' || strlen(s)!=1){
        fscanf(graphFile, "%s", s);
    }
    fscanf(graphFile, "%s %d %d", s, &vqtt, &eqtt);
    g = newGraph(vqtt, eqtt);
    addAllVertex(g);     
    while(fscanf(graphFile, "%s %d %d", s, &a, &b) != EOF){        
        addEdge(g,a,b);
    }
    return g;
}

graph_t *buildGraph(char *fileName){

    FILE *graphFile;
    graphFile = fopen(fileName,"r");
    graph_t *g = NULL;
    if(graphFile != NULL){
       g = readGraphFile(graphFile);
       fclose(graphFile);
    }
    
    return g;
    
}


