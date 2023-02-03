#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define __USE_XOPEN
#define _GNU_SOURCE

#include <time.h>

#define max(a,b) \
   ({ typeof (a) _a = (a); \
       typeof (b) _b = (b); \
     _a > _b ? _a : _b; })

#define __USE_XOPEN
#define _GNU_SOURCE
#include <time.h>



#define max(a,b) \
   ({ typeof (a) _a = (a); \
       typeof (b) _b = (b); \
     _a > _b ? _a : _b; })



typedef struct chain{
    int elt;
    int secondelt;
    float temp;
    struct chain *next;
}Chain;
typedef Chain* Pchain;  //Pchain = list (--tab)



typedef struct abr{
    int elt;
    int secondelt;
    float temp;
    struct abr *fg;
    struct abr *fd;
}Abr;
typedef Abr* PABR;   //PABR = abr (--abr)



typedef struct avl{
    int elt;
    int secondelt;
    float temp;        
    struct avl *fg;
    struct avl *fd;
}Avl;
typedef Avl* PAVL;  //PAVL = avl (--avl)



//all fonction for the list
Pchain create_Chain(int a,int b,int c);                         
Pchain insert(int argc, char **argv,Pchain pliste, int e, int sleep,float temp);
int sort_list(int argc, char **argv);



//all fonction for the abr
PABR create_abr(int a, int b, float c);
PABR new_elt(PABR pa, int e, int sleep,float temp);
void write_inorder(FILE *fic,PABR a);
void r_write_inorder(FILE *fic,PABR a);
int sort_abr(int argc, char **argv);



//all fonction for the avl
PAVL create_avl(int a, int b, float c);
int height(PAVL avl);
int balance(PAVL avl);
PAVL rotate_left(PAVL avl);
PAVL rotate_right(PAVL avl);
PAVL insert_AVL(PAVL pa, int e, int sleep,float temp);
void write_inorder_avl(FILE *fic,PAVL a);
void r_write_inorder_avl(FILE *fic,PAVL a);
int sort_avl(int argc, char **argv);
