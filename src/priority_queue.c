#include "include/main.h"
#include "include/priority_queue.h"

priority_queue_t *newPriorityQueue(){
    priority_queue_t *lst = malloc(sizeof(struct priority_queue));
    lst->head             = NULL;
    lst->quantity         = 0;
    return lst;
}

void freePNode(p_node_t *head){
    if(head!=NULL){
        freePNode(head->next);
        free(head);
    }
}

void freePriorityQueue(priority_queue_t *pq){
    freePNode(pq->head);
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

void *p_peek(priority_queue_t *pq){
    return (pq->head)->data;
}
