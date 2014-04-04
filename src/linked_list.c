#include "include/main.h"

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

linked_list_t *newLinkedList(){
    linked_list_t *lst = malloc(sizeof(struct linked_list));
    lst->head          = NULL;
    lst->quantity      = 0;
    return lst;
}

void freeNode(node_t *head){
    if(head!=NULL){
        freeNode(head->next);
        free(head);
    }
}

void freeLinkedList(linked_list_t * ll){
    freeNode(ll->head);        
    free(ll);
}

void push(linked_list_t *lst, void *newData){
    node_t *newNode = malloc(sizeof(struct node));
    newNode->data   = newData;
    newNode->next   = lst->head;
    lst->head       = newNode;
    lst->quantity   += 1;
    
}

void *peek(linked_list_t *lst){
    return (lst->head)->data;
}

