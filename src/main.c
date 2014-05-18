#include "include/graph.h"
#include "include/hc.h"
#include "include/backtracking.h"
#include "include/colors.h"
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
    colors *s = HC(g);
    c_print(s);
    c_remove(s, 5);
    c_print(s);
    s = backtracking(g, s, 5, 2);
    c_print(s);
    return 0;
}
