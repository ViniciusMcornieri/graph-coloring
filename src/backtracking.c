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

priority_queue_t *avail_color(graph_t *g, color_t *c, vertex_t *v){
    priority_queue_t *adjs = new_priority_queue(MIN_PRIORI);
    node_t        *node = (c->vertex_list)->head;
    vertex_t      *u;
    while(node != NULL){
        u    = node->data; 
        if(g->mtx[v->id-1][u->id-1]==1){
            p_insert(adjs, node->data, 1);
        }
        node = node->next;
    }
    push(c->vertex_list, v);
    return adjs;
}

int slash_vertex(priority_queue_t *s, vertex_t *v){
    p_node_t *pnd  = s->head;
    while(pnd != NULL){
        color_t  *c    = pnd->data;
        node_t   *nd   = (c->vertex_list)->head;
        node_t   *last = NULL;
        vertex_t *u;
        while(nd!=NULL){
            u = nd->data;
            if(v->id==u->id){
                if(last==NULL){
                    (c->vertex_list)->head = nd->next;
                }else{
                    last->next = nd->next;
                }
                return 0;
            }else{
                last = nd;
                nd   = nd->next;
            }
        }
        pnd = pnd->next;
    }
    return 1;
}     

priority_queue_t *backtracking(graph_t *g, priority_queue_t *s, vertex_t *v, int b){
    priority_queue_t *s3;
    priority_queue_t *s2 = NULL;
    priority_queue_t *s1 = clone_solution(s);
    int i;
    for(i=0;i<s1->quantity;i++){
        color_t *c           = get_data(s1, i);
        priority_queue_t *Jv = avail_color(g, c, v);
        if(s1->quantity <= s->quantity && Jv->quantity==0){
            if(s1->quantity < s->quantity){
                return s1;
            }
            s2 = s1;
        }else{
            if(s2==NULL || s1->quantity <= s2->quantity){
                s2 = s1;
            }
            if(Jv->quantity != 0 && b > 0){
                int j;
                for(j=0;j<Jv->quantity;j++){
                    vertex_t *u = get_data(Jv, j);
                    priority_queue_t *temp = clone_solution(s1);
                    slash_vertex(temp, u);
                    s3 = backtracking(g, temp, u, b-1);
                    if(s3->quantity <= s2->quantity){
                        if(s3->quantity < s2->quantity){
                            return s3;
                        }
                        s2 = s3;
                    }
                }  
            }
        }
        s1 = clone_solution(s2);
        slash_vertex(s1, v);
    }
    return s2; 
}
