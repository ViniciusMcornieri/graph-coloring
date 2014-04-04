#include "include/main.h"
#include "include/linked_list.h"
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

float calculateDensity(int vertex_qtt, int edge_qtt){
    return (edge_qtt << 1)/(vertex_qtt*vertex_qtt - vertex_qtt);
}

void freeGraph(graph_t *g){
    int i;
    if(g->adjOrMtx == ADJ){
        for(i = 0; i<g->vertex_qtt; freeLinkedList(g->adj[i++])); 
    }else if(g->adjOrMtx == MTX){
        for(i = 0; i<g->vertex_qtt; free(g->mtx[i++]));
        free(g->mtx);    
    }else if(g->adjOrMtx == BTH){
        for(i = 0; i<g->vertex_qtt; freeLinkedList(g->adj[i++])); 
        for(i = 0; i<g->vertex_qtt; free(g->mtx[i++]));
        free(g->adj);        
        free(g->mtx);
    }
    free(g);
    g = NULL;
    //*/
}


void mallocAdj(graph_t *g){
    int i;
    g->adj = malloc(sizeof(linked_list_t *)*g->vertex_qtt);
    for(i = 0; i < g->vertex_qtt; g->adj[i++] = newLinkedList());
}

void mallocMtx(graph_t *g){
    int i,j;
    edge_t *e;
    g->mtx = malloc(sizeof(edge_t *)*g->vertex_qtt);    
    for(i = 0; i < g->vertex_qtt; i++){
        g->mtx[i] = malloc(sizeof(edge_t)*g->vertex_qtt);
        e = g->mtx[i];    
        for(j = 0; j < g->vertex_qtt; j++){
                e[j].active = 0;
        }    
    }
}

void mallocEdges(graph_t *g){
    if(g->adjOrMtx == ADJ){
        mallocAdj(g);     
    }else if(g->adjOrMtx == MTX){
        mallocMtx(g); 
    }else if(g->adjOrMtx == BTH){
        mallocAdj(g);
        mallocMtx(g);
    }else if(g->adjOrMtx == DEN){
        if( g->density <= g->den_limit){
            mallocAdj(g);
            g->adjOrMtx = ADJ;       
        }else{
            mallocMtx(g);
            g->adjOrMtx = MTX;    
        }
    }
}


graph_t *newGraph(int vertex_qtt, int edge_qtt, int adjOrMtx, float den_param){
    graph_t *g    = malloc(sizeof(graph_t));
    g->vertex_qtt = vertex_qtt;
    g->edge_qtt   = edge_qtt;
    g->density    = calculateDensity(vertex_qtt, edge_qtt);
    g->den_limit  = den_param;
    g->adjOrMtx   = adjOrMtx;         
    g->vertexList = malloc(sizeof(vertex_t)*vertex_qtt);
    mallocEdges(g);
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
    edge_t *e;
    if(g->adjOrMtx == ADJ){
        e = malloc(sizeof(edge_t));
        e->from   = a;
        e->to     = b;
        e->active = 1;
        push(g->adj[a-1], e);
    }else if(g->adjOrMtx == MTX){
    }else if(g->adjOrMtx == BTH){
    } 
    
}

graph_t *readGraphFile(FILE *graphFile, int adjOrMtx, float den_param){
    graph_t *g = NULL;
    int vqtt, eqtt, a, b;
    char s[80];
    fscanf(graphFile, "%s", s);
    while(s[0]!='p' || strlen(s)!=1){
        fscanf(graphFile, "%s", s);
    }
    fscanf(graphFile, "%s %d %d", s, &vqtt, &eqtt);
    g = newGraph(vqtt, eqtt, adjOrMtx, den_param);
    addAllVertex(g);     
    while(fscanf(graphFile, "%s %d %d", s, &a, &b) != EOF){        
        addEdge(g,a,b);
    }
    return g;
}

graph_t *buildGraph(char *fileName, int adjOrMtx, float den_param){

    FILE *graphFile;
    graphFile = fopen(fileName,"r");
    graph_t *g = NULL;
    if(graphFile != NULL){
       g = readGraphFile(graphFile, adjOrMtx, den_param);
       fclose(graphFile);
    }
    
    return g;
    
}


