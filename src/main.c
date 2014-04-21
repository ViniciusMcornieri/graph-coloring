#include "include/linked_list.h"
#include "include/graph.h"
#include "include/hc.h"
#include "omp.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("hey amigo, para executar passe o caminho do grafo como parametro. Obrigado");
        return 1;
    }
    char *file_path;
    file_path = argv[1];
    printf("%s\n",file_path);
    graph_t *g = buildGraph(file_path);
    linked_list_t *colors = HC(g);
    print_out(colors);
}
