#include "include/graph.h"

float calculate_density(int vertex_qtt, int edge_qtt){
    return (edge_qtt << 1)/(vertex_qtt*vertex_qtt - vertex_qtt);
}

void free_graph(graph *g){
    int i;
    for(i = 0; i<g->vertex_qtt; free(g->mtx[i++]));
    free(g->mtx);    
    free(g);
    g = NULL;
}


void malloc_mtx(graph *g){
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

graph *create_graph(int vertex_qtt, int edge_qtt){
    graph*  g     = malloc(sizeof(graph));
    g->vertex_qtt = vertex_qtt;
    g->edge_qtt   = edge_qtt;
    g->density    = calculate_density(vertex_qtt, edge_qtt);       
    g->vertexList = malloc(sizeof(vertex)*vertex_qtt);
    malloc_mtx(g);
    return g;
}

void add_vertex(graph* g, int id){
    int i                    = id-1;
    g->vertexList[i].id      = id;
    g->vertexList[i].color   = 0;
	g->vertexList[i].adj_qtt = 0;
}

void add_all_vertex(graph* g){
    int i;
    int vqtt = g->vertex_qtt;
    for(i = 0; i<vqtt; add_vertex(g,++i));
}

void addEdge(graph *g, int a, int b){
    g->vertexList[a-1].adj_qtt++;
    g->vertexList[b-1].adj_qtt++;
    g->mtx[a-1][b-1]=1;
    g->mtx[b-1][a-1]=1; 
}

graph *readGraphFile(FILE *graphFile){
    graph *g = NULL;
    int vqtt, eqtt, a, b;
    char s[80];
    fscanf(graphFile, "%s", s);
    while(s[0]!='p' || strlen(s)!=1){
        fscanf(graphFile, "%s", s);
    }
    fscanf(graphFile, "%s %d %d", s, &vqtt, &eqtt);
    g = create_graph(vqtt, eqtt);
    add_all_vertex(g);     
    while(fscanf(graphFile, "%s %d %d", s, &a, &b) != EOF){        
        addEdge(g,a,b);
    }
    return g;
}

graph *buildGraph(char *fileName){

    FILE *graphFile;
    graphFile = fopen(fileName,"r");
    graph *g = NULL;
    if(graphFile != NULL){
       g = readGraphFile(graphFile);
       fclose(graphFile);
    }
    
    return g;
    
}
