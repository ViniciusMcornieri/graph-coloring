#include "include/graph.h"
#include "include/priority_queue.h"
#include "include/linked_list.h"
#include "include/hc.h"
#include "include/backtracking.h"

priority_queue_t *clone_solution(priority_queue_t *s){
    p_node_t *pnode          = s->head;
    priority_queue_t *clone  = new_priority_queue(s->min_or_max);
    color_t  *c;
    color_t  *clone_color;
    node_t   *vnode;
    while(pnode != NULL){
        c           = pnode->data;
        clone_color = new_color(c->color);
        vnode       = (c->vertex_list)->head; 
        while(vnode != NULL){
            push(clone_color->vertex_list, vnode->data);
            vnode = vnode->next;
        }
        p_insert(clone, clone_color, clone_color->color);
        pnode = pnode->next;
    }
    return clone;
}

linked_list_t *avail_color(graph_t *g, color_t *c, vertex_t *v){
    linked_list_t *adjs = newLinkedList();
    node_t        *node = (c->vertex_list)->head;
    node_t        *last = NULL;
    vertex_t      *u;
    while(node != NULL){
        u    = node->data; 
        if(g->mtx[v->id-1][u->id-1]==1){
            if(last==NULL){
                (c->vertex_list)->head = node->next;
            }else{
                last->next = node->next;
            }
            push(adjs, node->data);
            node = node->next;
        }else{
            last = node;
            node = node->next;
        } 
    }
    push(c->vertex_list, v);
    return adjs;
}

priority_queue_t *backtracking(graph_t *g, priority_queue_t *s, vertex_t *v, int b){
   // priority_queue_t *s2 = NULL;
    priority_queue_t *s1 = clone_solution(s);
    return s1; 
}
