#include "include/graph.h"
#include "include/priority_queue.h"
#include "include/linked_list.h"
#include "include/hc.h"
#include "include/backtracking.h"

int **clone_solution(int **s, int v_qtt){
    int **clone = new_colors_collection(v_qtt);
    int i,j;
    for(i=0;i<v_qtt;i++){
        for(j=0;j<v_qtt;j++){
            clone[i][j] = s[i][j];
        }
    }
    return clone;
}

int *avail_color(graph_t *g, int *c, int v){
    int *adjs = malloc(g->vertex_qtt*sizeof (int));
    int i;
    int v_qtt = g->vertex_qtt;
    for(i=0;i<v_qtt;i++){
        adjs[i] = -1;
    }
    int pivot = 0;
    for (i=0;i<v_qtt;i++){
        if(c[i] == -1){
            c[i] = v;
            return adjs;
        }
        if(g->mtx[v-1][c[i]-1]){
            adjs[pivot] = c[i];
            pivot++;
            slash_pos(c, i, g->vertex_qtt);
            i--;  
        }    
    }
    return adjs;
}

void slash_pos(int *color, int pos, int v_qtt){
    int i;
    for(i=pos;i<v_qtt-1;i++){
        if (color[i] == -1){
            i = v_qtt;
        }
        color[i] = color[i+1];
    }
    color[v_qtt] = -1;
}     

int colors_counting(int **s, int v_qtt){
    int i;
    int n_colors = 0;
    for(i=0;i<v_qtt;i++){
        if(s[i][0]!=-1){
            n_colors++;
        }else{
            i = v_qtt;
        }
    }
    return n_colors;
}

int **backtracking(graph_t *g, int **s, int v, int b){
    int v_qtt = g->vertex_qtt;
    int i;
    int **s_menor = NULL;
    for(i=0;i<v_qtt;i++){
        if(s[i][0]==-1){
            i = v_qtt;
        }
        int **s_actual =  clone_solution(s, v_qtt);
        int *adjs      = avail_color(g, s[i], v);
        if(adjs[0]== -1){
            return s_actual; 
        }else{
            if(b>0){
                int j;
                for(j=0;j<v_qtt;j++){
                    if(adjs[j] != -1){
                        s_actual = backtracking(g, s_actual, adjs[i], b-1);
                    }else{
                        j = v_qtt;
                    }
                }
            if(s_menor == NULL 
                || colors_counting(s_actual, v_qtt) < colors_counting(s_menor, v_qtt)){
                   s_menor = clone_solution(s_actual, v_qtt);    
                }
            }
        }
    }
    return s_menor;
}
