#include "include/graph.h"
#include "include/main.h"
#include "include/hc.h"
#include "include/colors.h"

int is_not_adj(graph_t *g, vertex_t *v, colors *s, int c){
    int i,start,end,u;
    start = s->index[c];
    end   = s->index[c+1];
    for(i = start;i<end;i++){
        u = s->vertex[i];
        if(g->mtx[v->id-1][u-1]){
            return 0;
        } 
    }
    c_insert(s, c, v->id);
    return 1;
}


colors *HC(graph_t *g){
          int v_qtt            = g->vertex_qtt;
          colors *s            = create_colors(v_qtt);
          int i;
          for(i=0; i < g->vertex_qtt; i++){
                    vertex_t *v          = &g->vertexList[i];
                    int j, add=0;
                    for(j=0;j<s->color_size;j++){
                              if (is_not_adj(g,v,s,j)){
                                        j=s->color_size;
                                        add = 1;
                              }                
                    }
                    if(add!=1){
                              increment_colors(s, v->id);
                    }
          }
          return s;
}
