#include "include/priority_queue.h"
#include "include/graph.h"
#include "include/hc.h"
#include "include/backtracking.h"
#include "omp.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("hey amigo, para executar passe o caminho do bagulho como parametro. Obrigado");
        return 1;
    }else if (argc==3){
        printf("%d\n",atoi(argv[2]));
       // omp_set_num_threads(atoi(argv[2]));
    }
    char *file_path;
    file_path                = argv[1];
    printf("%s\n",file_path);
    graph_t *g               = buildGraph(file_path);
    priority_queue_t *colors = HC(g);
    priority_queue_t *cc     = clone_solution(colors);
    slash_vertex(cc, &g->vertexList[2]);
   print_out(cc);
   priority_queue_t *l1     = backtracking(g, cc, &g->vertexList[2], 1) ;
   /* p_node_t *nd             = l1->head;
   // vertex_t *v;
    while(nd!=NULL){
        v = nd->data;
        printf("id->%d\n",v->id);
        nd = nd->next;
    }*/
    print_out(colors);
    print_out(l1);
    return 0;
}
