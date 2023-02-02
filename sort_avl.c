#include "main.h"



PAVL create_avl(int a, int b, float c){     //create the node of an AVL
    PABR new = (PABR) malloc(sizeof(PABR));
    if(new==NULL){
		exit(4);
	}
    new->elt=a;
    new->secondelt=b;
    new->temp=c;
    new->fg=NULL;
    new->fd=NULL;
    return new;
}



int height(PAVL avl){                                   //calculate the height of a node
    if (!avl){
        return 0;
    }
    return 1+max(height(avl->fg), height(avl->fd));
}



int balance(PAVL avl){                                 //calculate the balance of a node
    if (!avl){
        return 0;
    }
    return height(avl->fg) - height(avl->fd);
}



PAVL rotate_left(PAVL avl){                 //rotation left on avl
    PAVL new = avl->fd;
    PAVL temp = new->fg;
    new->fg = avl;
    avl->fd = temp;
    return new;
}



PAVL rotate_right(PAVL avl){                //rotation right on avl
    PAVL new=avl->fg;
    PAVL temp=new->fd;
    new->fd=avl;
    avl->fg=temp;
    return new;
}



PAVL insert_AVL(PAVL pa, int e, int sleep,float temp){          //insertion in avl
    int i=balance(pa);
    if(!pa){
        return create_avl(e,sleep,temp);
    }
    if(e<pa->elt){
        pa->fg=insert_AVL(pa->fg,e);
    }
    else{                                   
        pa->fd=insert_AVL(pa->fd,e);
    }
    if((i>1) && (e<pa->fg->elt)){
        return rotate_right(pa);
    }
    if((i<-1) && (e>pa->fg->elt)){
        return rotate_right(pa);
    }
    if((i>1) && (elt>pa->fg->elt)){
        pa->fg=rotate_left(pa->fg);
        return rotate_right(pa);
    }
    if((i<1) && (elt<pa->fg->elt)){
        pa->fd=rotate_right(pa->fd);
        return rotate_left(pa);
    }
    return pa;
}



void write_inorder_avl(PAVL a){              //ascending course
    if (!a){
        write_inorder(a->fg);
        fprintf(fic,"%d %d %f\n", elt, secondelt, temp);  //write the sorted value
        temp2=a;
        write_inorder(a->fd);
        free(temp2);
    }
}



void r_write_inorder_avl(PAVL a){              //descending course
    if (!a){
        write_inorder(a->fd);
        fprintf(fic,"%d %d %f\n", elt, secondelt, temp);  //write the sorted value
        temp2=a;
        write_inorder(a->fg);
        free(temp2);
    }
}



int sort_avl(char **argv){
    PAVL avl=NULL;
    FILE *fic=fopen(argv[1], "r");         //open file and read file
    if(fic==NULL) exit(2);
    int ID;
    char predate[30];
    float temp;
    while((fscanf(fic,"%d %s %f\n", &lieu, predate, &temp)) != EOF){    //get the elmt, date and ID station
        predate[19]='\0';                                           // cut the date to have only years, months, days, and hours
        struct tm tm;
        time_t date
        if(strptime(predate, "%Y-%m-%dT%H:%M:%S", &tm) != NULL){     // change the date into int
            date=mktime(&tm);
        }
        if(strcmp(argv[4], "-date")==0){          //compare argument to know wich data we will sort
            avl=insert_AVL(date,id,a);
        }
        else if(strcmp(argv[4], "-id")==0){         
            avl=insert_AVL(id,date,temp);
        }
        else{
            return 1;                       //case error
        }   
    }
    fclose(fic); 
    fic=fopen(argv[2], "w");                                    //open file
    Pchain temp2;
    if(fic==NULL) exit(3);
    if(strcmp(argv[5], "-r")==0){               //compare with argument -r
        r_write_inorder_avl(avl);
    }
    else if(strcmp(argv[5], "-r")==0){               
        write_inorder_avl(avl);
    }
    else{
        exit (1);
    }
    fclose(fic);                //close file
    return 0;
}
