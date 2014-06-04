#include "include/main.h"

int main(int argc, char* argv[]){
   int p = 0;
   if(argc < 2){
        printf("Falta de parâmetros: favor informe o caminho do grafo e se necessário o número de threads");
        return 1;
    }else if (argc==3){
        printf("threads: %d\n",atoi(argv[2]));
        omp_set_num_threads(atoi(argv[2]));
        p = 1;
    }
    char *file_path;
    file_path                = argv[1];
    printf("%s\n",file_path);
    graph *g               = buildGraph(file_path);
    colors *s = HC(g);
    //c_print(s);
    printf(">>>\n");
    double start_time = omp_get_wtime();
    s = vnd(g, s, 2, p);
    double end_time = omp_get_wtime() - start_time;
    int min = end_time/60;
    int seg = end_time - min*60;
    printf("time %dm %ds\n", min, seg);
    //c_print(s);
    return 0;
}
