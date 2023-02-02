#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



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
    struct chainon *fg;
    struct chainon *fd;
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
Pchain insert(Pchain pliste, int e, int sleep,float temp);
int sort_list(char **argv);



//all fonction for the abr
PABR create_abr(int a, int b, float c);
PABR new_elt(PABR pa, int e, int sleep,float temp);
void write_inorder(PABR a);
void r_write_inorder(PABR a);
int sort_abr(char **argv);



//all fonction for the avl
PAVL create_avl(int a, int b, float c);
int height(PAVL avl);
int balance(PAVL avl);
PAVL rotate_left(PAVL avl);
PAVL rotate_right(PAVL avl);
PAVL insert_AVL(PAVL pa, int e, int sleep,float temp);
void write_inorder_avl(PAVL a);
void r_write_inorder_avl(PAVL a);
int sort_avl(char **argv);
