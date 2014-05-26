#include "include/vnd.h"
#include "math.h"
colors *local_search(graph *g, colors *s, int *y, int b){
    colors *s1  = clone_colors(s);
    int i;
    for(i=0; y[i]!=-1;i++){
            c_remove(s1, y[i]);
    }
    
    for(i=0; y[i]!=-1; i++){
       s1 = backtracking(g, s1, y[i], b);
    }
    free(y);
    if(s1->color_size <= s->color_size){
        free_colors(s);
        return s1;
    }
    free_colors(s1);
    return s;
}

int *selection(colors *s){
    int pivot = 0;
    int i;
    int c = rand()%s->color_size;
    int n = s->index[c+1] - s->index[c];
    int *chosen = malloc((n+1)*sizeof(int));
    for(i=0;i<=n;i++){
        chosen[i] = -1; 
    }
       for(i=s->index[c];i<s->index[c+1];i++){
            chosen[pivot] = s->vertex[i];
            pivot++;
        } 
    return chosen;
}

colors *vnd(graph *g, colors *s, int b_max){
    int k, beta, it, *y, k_max;
    k     = 0;
    beta  = 0;
    it    = 0;
    colors *s1;
    while(it < 5*s->color_size){
        k_max = s->color_size-1;
        y   = selection(s); 
        s1  = local_search(g, s, y, beta); 
        if(s1->color_size < s->color_size){
            k     = 0;
            beta  = 0;
            it    = -1;
        }else{
            if(k < k_max){
                k++;
            }else{
                k = 0;
                if(beta < b_max){
                    beta++;
                }else{
                    beta = 0;
                }
            }
        }
        it++;
        s = clone_colors(s1);
        free_colors(s1);
    }
    return s;
}
