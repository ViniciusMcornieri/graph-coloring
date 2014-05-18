#include "include/vnd.h"

colors *local_search(graph *g, colors *s, int *y, int b){
    colors *s1  = clone_colors(s);
    int i;
    for(i=0; y[i]!=-1;i++){
            c_remove(s1, y[i]);
    }
    
    for(i=0; y[i]!=-1; i++){
       s1 = backtracking(g, s1, y[i], b);
    }
    
    if(s1->color_size <= s->color_size){
        free_colors(s);
        return s1;
    }
    free_colors(s1);
    return s;
}
