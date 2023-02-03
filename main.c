#include "main.h"



int main(int argc,char **argv){
    if (argc<5)return 1;         

        if(strcmp(argv[3], "--tab")==0){        //compare wich sort we need
            return sort_list(argc, argv);
        }
        else if(strcmp(argv[3], "--abr")==0){
            return sort_abr(argc, argv);
        }
        else if(strcmp(argv[3], "--avl")==0){
            return sort_avl(argc, argv);
        }
        else{
            return 1;
        }
    return 0;
}
