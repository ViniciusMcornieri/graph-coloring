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
    int **s = HC(g);
    int v   = s[1][1];
    printf(">%d<\n",v);
    slash_pos(s[1], 1, g->vertex_qtt);
    print_out(s, g->vertex_qtt);
    printf("kkk\n");
    print_out(backtracking(g, s, v, 0), g->vertex_qtt);
    return 0;
}
