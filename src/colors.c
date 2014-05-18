#include "include/colors.h"
colors *create_colors(int v_qtt){
    colors *c     = malloc(sizeof(colors));
    int *vertex   = malloc(v_qtt*sizeof(int)); 
    int *index    = malloc(v_qtt*sizeof(int));
    c->v_qtt      = v_qtt;
    c->color_size = 0;
    int i;
    for(i=0;i<v_qtt;i++){
        vertex[i] = -1;
        index [i] = -1;
    }
    c->vertex     = vertex;
    c->index      = index;
    c->index[0]   = 0;
   return c;
}

colors *clone_colors(colors *s){
   colors *clone         = create_colors(s->v_qtt);
   int i;
   for(i=0;i<s->v_qtt;i++){
        clone->vertex[i] = s->vertex[i];
        clone->index[i]  = s->index [i];
   }
   clone->color_size     =  s->color_size;
   return clone;
}

void c_insert(colors *s, int c, int v){
    int start  = s->index[c+1];
    int end    = s->index[s->color_size];
    int i;
    for(i=end;i>=start;i--){
        s->vertex[i] = s->vertex[i-1]; 
    }
    s->vertex[start] = v;
    for(i=c+1;i<=s->color_size;i++){
        s->index[i]++; 
    } 
}

void increment_colors(colors *s, int v){
    s->vertex[s->index[s->color_size]] = v;
    s->color_size++;
    s->index[s->color_size] = s->index[s->color_size-1]+1;
}

void c_remove(colors *s, int v){
    int i, j, pivot, start, end, cor;
    for(i=0;i<s->color_size;i++){
        start = s->index[i];
        end   = s->index[i+1];
        for(j=start;j<end;j++){
            if(s->vertex[j] == v){
                pivot = j;
                cor   = i;
                j     = end;
                i     = s->color_size;
            }
        }
    }
    
    for(i=pivot;i < s->index[s->color_size];i++){
        s->vertex[i] = s->vertex[i+1];
    }
    
    s->vertex[s->v_qtt-1] = -1;
    
    for(i=cor+1; i <= s->color_size;i++){
        s->index[i]--; 
    }
    if(s->index[cor]==s->index[cor+1]){
        for(i=cor; i <= s->color_size;i++){
            s->index[i] = s->index[i+1];
        }
        s->color_size--;
    }
}

void free_colors(colors *s){
    free(s->vertex);
    free(s->index);
    free(s);
}

void c_print(colors *s){
   int i,j;
   for(i=0;i<s->color_size;i++){
        printf("Cor%d: >>> ", i+1);
        for(j=s->index[i];j < s->index[i+1]; j++){
            printf("V%d |", s->vertex[j]);
        }
        printf("\n");
    }
}
