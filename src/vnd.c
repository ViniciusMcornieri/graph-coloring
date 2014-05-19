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

int *selection(colors *s, int alpha, int gamma){
    int pivot = 0;
    int i, j, v;
    int *chosen = malloc((alpha+1)*sizeof(int));
    for(i=0;i<=alpha;i++){
        chosen[i] = -1; 
    }
    if(gamma==0){
        for(i=0;i<alpha;){
            v = s->vertex[rand()%s->v_qtt]; 
            for(j=0;j<=pivot;j++){
                if(chosen[j]==-1){
                    chosen[j] = v;
                    pivot++;
                    i++;
                    j = pivot;
                }else if(chosen[j]==v){
                    j=pivot;
                }  
            }  
        }    
    }else{
        v = rand()%s->color_size;
        for(i=s->index[v];i<s->index[v+1];i++){
            chosen[pivot] = s->vertex[i];
        } 
    }
    return chosen;
}

colors *vnd(graph *g, colors *s, int a_max, int b_max){
    int k, alpha, beta, gamma, it, *y, t_a, g_max, k_max;
    k     = 0;
    alpha = 0;
    beta  = 0;
    gamma = 0;
    it    = 0;
    g_max = 2;
    k_max = (s->v_qtt)/(log(((double) (b_max*s->v_qtt)+1))+1);
    colors *s1;
    while(it!=20*s->v_qtt){
        t_a = (alpha*0.03333*s->v_qtt)+1;
        y   = selection(s, t_a, gamma); 
        s1  = local_search(g, s, y, beta); 
        if(s1->color_size < s->color_size){
            k     = 0;
            alpha = 0;
            beta  = 0;
            gamma = 0;
        }else{
            if(k < k_max){
                k++;
            }else{
                k = 0;
                if(alpha < a_max){
                    alpha++;
                }else{
                    alpha = 0;
                    if(gamma < g_max){
                        gamma++; 
                    }else{
                        gamma = 0;
                        if(beta < b_max){
                            beta++;
                        }else{
                            beta = 0;
                        }
                    }
                }
            }
        }
        it++;
        s = clone_colors(s1);
        free_colors(s1);
    }
    return s;
}
