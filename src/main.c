#include "include/priority_queue.h"
#include "include/graph.h"
#include "include/hc.h"
#include "omp.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("hey amigo, para executar passe o caminho d bagulho como parametro. Obrigado");
        return 1;
    }else if (argc==3){
        printf("%d",atoi(argv[2]));
        omp_set_num_threads(atoi(argv[2]));
    }
    char *file_path;
    file_path                = argv[1];
    printf("%s\n",file_path);
    graph_t *g               = buildGraph(file_path);
    priority_queue_t *colors = HC(g);
    print_out(colors);
    return 0;
}
