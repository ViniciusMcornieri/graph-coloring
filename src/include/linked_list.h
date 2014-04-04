#ifndef Linked_List_H
#define Linked_List_H

struct node{
    void *data;
    struct node *next;
};

typedef struct node node_t;

struct linked_list{
    node_t *head;
    int quantity;
};

typedef struct linked_list linked_list_t;

void freeLinkedList(linked_list_t * ll);

linked_list_t *newLinkedList();

void push(linked_list_t *lst, void *newData);

void *peek(linked_list_t *lst);
#endif
