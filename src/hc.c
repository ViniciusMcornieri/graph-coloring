#include "include/priority_queue.h"
#include "include/linked_list.h"
#include "include/graph.h"
#include "include/main.h"
#include "include/hc.h"

color_t *new_color(int color_id){
    linked_list_t *lst = newLinkedList();
    color_t *color     = malloc(sizeof (struct color));
    color->cost        = 0;
    color->color       = color_id;
    color->vertex_list = lst;
    return color;
}

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

int is_not_adj(graph_t *g, vertex_t *v, linked_list_t *vertex_list){
    int not_adj = 1;
    if(vertex_list->quantity==0){
        return 1;
    }
    node_t *node = vertex_list->head;
    vertex_t *u = NULL;
    while(not_adj){
        u = node->data;
        if (u == NULL){
            return 1;
        }else if(g->mtx[v->id-1][u->id-1]){
            return 0;
        }else{
            node = node->next;
            if (node == NULL){
                return 1;
            }
        }	
    }
    return 0;
}


priority_queue_t *HC(graph_t *g){
    priority_queue_t *s  = new_priority_queue(MIN_PRIORI);
    int id_c             = 0;
    // p_node_t  *color_node  = NULL;
    //color_t *c           = NULL;
    priority_queue_t *pi = preprocessing(g);
    int i;
    for(i=0; i < pi->quantity; i++){
        vertex_t *v          = get_data(pi, i);
        int not_add          = 1;
        p_node_t *color_node = s->head;
        color_t *c           = NULL;
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
        }
    }
    return s;
}

int print_out(priority_queue_t *list){
    p_node_t *node  = list->head;
    color_t *cor  = NULL;
    node_t *vnode = NULL;
    vertex_t *v1  = NULL;
    linked_list_t *vlist;
    int i,j;
    for(i=0;i<list->quantity;i++){
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

    return 0;
}
