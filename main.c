#include "main.h"


int main(int argc,char **argv){
    if (argc < 6)return 1;         
    if(strcmp(argv[3], "r")==0){               //compare if we need ascending or descending sort
        if(strcmp(argv[4], "--tab")==0){        //compare wich sort we need
            
        }
        else if(strcmp(argv[4], "--abr")==0){
         
        }
        else if(strcmp(argv[4], "--avl")==0{
        
        }
        else{
            return 1;
        }
    }



    else{                                          //ascending sort
        if(strcmp(argv[4], "--tab")==0){           //compare wich sort we need
            sort_list(argv);
        }
        else if(strcmp(argv[4], "--abr")==0){
       
        }
        else if(strcmp(argv[4], "--avl")==0{
        
        }
        else{
            return 1;
        }
    }
    return 0;
}
