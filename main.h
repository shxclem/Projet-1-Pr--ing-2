#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




typedef struct chain{
    int elt;
    int secondelt;
    float temp;
    struct chain *next;
}Chain;
typedef Chain* Pchain;  //Pchain = list (--tab)



typedef struct abr{
    Element elt;
    char date;
    int height;
    struct chainon *fg;
    struct chainon *fd;
}Abr;
typedef Abr* PABR;   //PABR = abr (--abr)



typedef struct avl{ 
    Element elt;
    int height; 
    int nelt;           //nelt = number of the same element
    struct avl *fg;
    struct avl *fd;
}Avl;
typedef Avl* PAVL;  //PAVL = avl (--avl)



Pchain create_Chain(int a,int b,int c);
Pchain insert(Pchain pliste, int e, int sleep,float  temp);

