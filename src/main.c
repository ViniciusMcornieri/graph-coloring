#include "include/main.h"

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
    graph *g               = buildGraph(file_path);
    colors *s = HC(g);
    c_print(s);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    s = vnd(g, s, 2);
    c_print(s);
    return 0;
}
