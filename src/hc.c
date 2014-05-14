#include "include/priority_queue.h"
#include "include/linked_list.h"
#include "include/graph.h"
#include "include/main.h"
#include "include/hc.h"
/*
color_t *new_color(int color_id, int vertex_qtt){
    color_t *color     = malloc(sizeof color_t);
    color->vertex_list = malloc(sizeof int * vertex_qtt);
    color->color       = color_id;
    return color;
}
*/
priority_queue_t *preprocessing(graph_t *g){
    priority_queue_t *pi = new_priority_queue(MAX_PRIORI);
    int i;
    for(i=0; i<g->vertex_qtt; i++){
        if(g->vertexList[i].adj_qtt != 0){
            p_insert(pi, &g->vertexList[i], g->vertexList[i].adj_qtt);
        }
    }
    return pi;
}

int is_not_adj(graph_t *g, vertex_t *v, int *cor){
    if(cor[0]==-1){
        cor[0] = v->id;
        return 1;
    }

    int i;
    for(i=0;i<g->vertex_qtt;i++){
        if (cor[i]==-1){
            cor[i]=v->id;
            return 1;
        }else if(g->mtx[v->id-1][cor[i]-1]){
            return 0;        
        }
    }
    return 0;
}

int **new_colors_collection(int v_qtt){
    int **colors = malloc(v_qtt * sizeof(int *));
    int i,j;
    for(i=0;i<v_qtt;i++){
     colors[i]   = malloc(v_qtt * sizeof(int));
    }
    for(i=0;i<v_qtt;i++){
        for(j=0;j<v_qtt;j++){
            colors[i][j]= -1;    
        }
    }
    return colors;
}

int **HC(graph_t *g){
    int v_qtt            = g->vertex_qtt;
    int **s              = new_colors_collection(v_qtt);
    priority_queue_t *pi = preprocessing(g);
    int i;
    for(i=0; i < pi->quantity; i++){
        vertex_t *v          = get_data(pi, i);
        int j;
        for(j=0;j<v_qtt;j++){
           if (is_not_adj(g,v,s[j])){
                j=v_qtt;
           }                
        }/*
        while(not_add){
            if (color_node == NULL){
                c = new_color(++id_c);
                p_insert(s, c, id_c);
                color_node = s->head;
            }else{
                c = color_node->data;
            }
            if(is_not_adj(g,v,c->vertex_list)){
                push(c->vertex_list,v);
                v->color = c->color;
                not_add = 0;
            }else{
                color_node = color_node->next;
            }
        }**/
    }
    return s;
}

int print_out(int **s, int v_qtt){
   int i,j;
   for(i=0;i<v_qtt;i++){
        if (s[i][0]!= -1){
            printf("cor: %d >>>", i);
        }else{
            return 0;
        }
        for(j=0;j<v_qtt;j++){
                if(s[i][j] != -1 ){
                    printf("V%d ", s[i][j]);
                }else{
                    j = v_qtt;
                }
        }
        printf("\n");
   }
    return 0; 
   
   /* 
    p_node_t *node  = list->head;
    color_t *cor  = NULL;
    node_t *vnode = NULL;
    vertex_t *v1  = NULL;
    linked_list_t *vlist;
    
    int i,j;
    for(i=0;i<;i++){
        if(node!=NULL){
            cor = node->data;
            printf("cor: %d >>>",cor->color);
            vlist = cor->vertex_list;
            vnode = vlist->head;
            for(j=0;j<vlist->quantity;j++){
                if(vnode!=NULL){
                    v1 = vnode->data;
                    printf("V%d ",v1->id);
                    vnode = vnode->next;
                }
            }
            printf("\n");
        }
        node = node->next;

    }

    return 0;*/
}
