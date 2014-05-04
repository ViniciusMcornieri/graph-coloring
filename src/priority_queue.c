#include "include/main.h"
#include "include/priority_queue.h"

priority_queue_t *new_priority_queue(){
    priority_queue_t *lst = malloc(sizeof(struct priority_queue));
    lst->head             = NULL;
    lst->quantity         = 0;
    return lst;
}

void free_p_node(p_node_t *head){
    if(head!=NULL){
        free_p_node(head->next);
        free(head);
    }
}

void free_priority_queue(priority_queue_t *pq){
    free_p_node(pq->head);
    free(pq);
}

void p_insert(priority_queue_t *pq, void *newData, int cmp){
    p_node_t *newNode  = malloc(sizeof(struct p_node));
    newNode->data      = newData;
    newNode->cmp       = cmp;
    newNode->next      = NULL;
    int stop           = 0;
    p_node_t *pivot    = pq->head;
    p_node_t *father   = NULL;

    while(!stop){
        if(pivot == NULL){
            stop = 1;
            pq->quantity++;
        }else if(pivot->cmp <= cmp){
            newNode->next = pivot;
            stop          = 1;
            pq->quantity++;
        }else{
            father = pivot;
            pivot = pivot->next;
        }
    }

    if(father == NULL){
        pq->head = newNode;
    }else{
        father->next = newNode;
    }
}

void *get_data(priority_queue_t *pq, int pos){
    int pivot     = 0;
    p_node_t *node = pq->head; 
    if(node==NULL){
        return NULL;
    }
    while(pivot != pos){
        node = node->next;
        if(node==NULL){
            return NULL;
        }
        pivot++;
    }
    return node->data;
}

void *p_peek(priority_queue_t *pq){
    return (pq->head)->data;
}
