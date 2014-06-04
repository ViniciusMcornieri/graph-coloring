#include "include/backtracking.h"

int *avail_color(graph *g, colors *s, int c, int v){
    int start  = s->index[c];
    int end    = s->index[c+1];
    int c_size = (end - start);
    int *adjs  = malloc(c_size*sizeof (int));
    int i;
    for(i=0;i<c_size;i++){
        adjs[i] = -1;
    }
    int pivot = 0;
    for (i=start;i<end;i++){
        if(g->mtx[v-1][s->vertex[i]-1]){
            adjs[pivot] = s->vertex[i];
            pivot++;
        }    
    }
    c_insert(s, c, v);
    for(i=0;i<pivot;i++){
        c_remove(s, adjs[i]);
    }
    return adjs;
}


colors *backtracking(graph *g, colors *s, int v, int b){
    int i,j;
    int *adjs;
    int n_adj;
    colors *s_menor = NULL;
    for(i=0;i<s->color_size;i++){
        colors *s_actual =  clone_colors(s);
        adjs             =  avail_color(g, s_actual, i, v);
        n_adj            =  s->index[i+1] - s->index[i];
        if(adjs[0]== -1){
            if(s_menor!=NULL){
                free_colors(s_menor);
            }
            free_colors(s);
            return(s_actual);
        }else{
            if(b>0){
                
                for(j=0;j<n_adj && adjs[j]!=-1;j++){
                    s_actual = backtracking(g, s_actual, adjs[j], b-1);
                }
                
                if(s_menor == NULL){
                    s_menor = clone_colors(s_actual);    
                }else if(s_actual->color_size <= s_menor->color_size){
                    free_colors(s_menor);   
                    s_menor = clone_colors(s_actual);    
                }
            }
        }
        free(adjs);
        free_colors(s_actual);
    }
    if(s_menor==NULL){
        increment_colors(s, v);
        return s;        
    }
    free_colors(s);
    return s_menor;
}

colors *backtracking_parallel(graph *g, colors *s, int v, int b){
    int i;
    colors *s_menor = NULL;
    #pragma omp parallel for shared(s_menor)
    for(i=0;i<s->color_size;i++){
        colors *s_actual =  clone_colors(s);
        int *adjs             =  avail_color(g, s_actual, i, v);
        int n_adj            =  s->index[i+1] - s->index[i];
        if(adjs[0]== -1){
            #pragma omp critical
            {
                if(s_menor == NULL){
                    s_menor = clone_colors(s_actual);    
                }else if(s_actual->color_size < s_menor->color_size){
                    free_colors(s_menor);   
                    s_menor = clone_colors(s_actual);    
                }
            }
        }else{
            if(b>0){
                int j;
                for(j=0;j<n_adj && adjs[j]!=-1;j++){
                    s_actual = backtracking(g, s_actual, adjs[j], b-1);
                }
                #pragma omp critical 
                {
                    if(s_menor == NULL){
                        s_menor = clone_colors(s_actual);    
                    }else if(s_actual->color_size <= s_menor->color_size){
                        free_colors(s_menor);   
                        s_menor = clone_colors(s_actual);    
                    }
                }
            }
        }
        free(adjs);
        free_colors(s_actual);
    }
    if(s_menor==NULL){
        increment_colors(s, v);
        return s;
    }
    free_colors(s);
    return s_menor;
}
