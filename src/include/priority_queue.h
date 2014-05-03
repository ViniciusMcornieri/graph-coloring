#ifndef Priority_Queue_H
#define Priority_Queue_H

struct p_node{
    int    cmp;
    void   *data;
    struct p_node *next;
};

typedef struct p_node p_node_t;

struct priority_queue{
    p_node_t *head;
    int      quantity;
};

typedef struct priority_queue priority_queue_t;

void freePriorityQueue(priority_queue_t * pq);

priority_queue_t *newPriorityQueue();

void p_insert(priority_queue_t *lst, void *newData, int cmp);

void *p_peek(priority_queue_t *lst);
#endif
