#include "include/linked_list.h"
#include "include/graph.h"
#include "include/main.h"

struct color{
	int cost;
	linked_list_t *vertex_list;
	int color;
};

typedef struct color color_t;

color_t *new_color(int id){
	linked_list_t *list = newLinkedList();
	color_t *c = malloc(sizeof(struct color));
	c->cost = 0;
	c->vertex_list = list;
	c->color = id;
	return c;
}

vertex_t *preprocessing(graph_t g){
	vertex_t *pi    = malloc(sizeof(vertex_t)*g.vertex_qtt);
	int       index = 0;
	int i;	
	for(i=0;i<g.vertex_qtt;i++){
		if(g.vertexList[i].adj_qtt!=0){
			pi[index] = g.vertexList[i];
			index++;
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


linked_list_t *HC(graph_t *g){
	linked_list_t *s = newLinkedList();
	int not_add = 1;
	int cost_s = 0;
	int i;
	int id_c = 0;
	node_t *node = NULL;
	color_t *c = NULL;
	vertex_t *v;
	for(i=0;i<g->vertex_qtt;i++){
		v = &g->vertexList[i];
		not_add = 1;
		node = s->head;
		while(not_add){
			if (node==NULL){
				c = new_color(++id_c);
				push(s,c);
				node = s->head;
			}else{
				c = node->data;
			}
			if(is_not_adj(g,v,c->vertex_list)){
				push(c->vertex_list,v);
				v->color = c->color;
				not_add = 0;
			}else{
				node = node->next;
			}
		}
	}
	return s;
}

int print_out(linked_list_t *list){
	node_t *node = list->head;
	linked_list_t *vlist;
	color_t *cor = NULL;
	node_t *vnode = NULL;
	vertex_t *v1 = NULL;
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
