#ifndef Priority_Queue_H
#define Priority_Queue_H

#define MIN_PRIORI -1
#define MAX_PRIORI  1

struct p_node{
    int    cmp;
    void   *data;
    struct p_node *next;
};

typedef struct p_node p_node_t;

struct priority_queue{
    p_node_t *head;
    int      quantity;
    int      min_or_max;
};

typedef struct priority_queue priority_queue_t;

void free_priority_queue(priority_queue_t * pq);

priority_queue_t *new_priority_queue(int priori);

void p_insert (priority_queue_t *pq, void *newData, int cmp);

void *get_data(priority_queue_t *pq, int  pos);

void *p_peek  (priority_queue_t *pq);
#endif
