#include "main.h"



int main(int argc,char **argv){
    if (argc<5)return 1;         

        if(strcmp(argv[3], "--tab")==0){        //compare wich sort we need
            sort_list(argc, argv);
        }
        else if(strcmp(argv[3], "--abr")==0){
            sort_abr(argv);
        }
        else if(strcmp(argv[3], "--avl")==0){
            sort_avl(argv);
        }
        else{
            return 1;
        }
    return 0;
}
