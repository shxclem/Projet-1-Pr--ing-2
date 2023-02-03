#include "main.h"



PAVL create_avl(int a, int b, float c){     //create the node of an AVL
    PAVL new = malloc(sizeof(Avl));
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
        pa->fg=insert_AVL(pa->fg, e, sleep, temp);
    }
    else{                                   
        pa->fd=insert_AVL(pa->fd,e, sleep, temp);
    }
    if((i>1) && (e<pa->fg->elt)){
        return rotate_right(pa);
    }
    if((i<-1) && (e>pa->fd->elt)){
        return rotate_left(pa);
    }
    if((i>1) && (e>pa->fg->elt)){
        pa->fg=rotate_left(pa->fg);
        return rotate_right(pa);
    }
    if((i<-1) && (e<pa->fd->elt)){
        pa->fd=rotate_right(pa->fd);
        return rotate_left(pa);
    }
    return pa;
}



void write_inorder_avl(FILE *fic,PAVL a){              //ascending course
    PAVL temp2;
    if (a){
        write_inorder_avl(fic,a->fg);
        fprintf(fic,"%d %d %f\n", a->elt, a->secondelt, a->temp);  //write the sorted value
        temp2=a;
        write_inorder_avl(fic,a->fd);
        free(temp2);
    }
}



void r_write_inorder_avl(FILE *fic,PAVL a){              //descending course
    PAVL temp2;
    if (a){
        r_write_inorder_avl(fic,a->fd);
        fprintf(fic,"%d %d %f\n", a->elt, a->secondelt, a->temp);  //write the sorted value
        temp2=a;
        r_write_inorder_avl(fic,a->fg);
        free(temp2);
    }
}



int sort_avl(int argc, char **argv){
    PAVL avl=NULL;
    FILE *fic=fopen(argv[1], "r");         //open file and read file
    if(fic==NULL) exit(2);
    int ID;
    char predate[30];
    float temp;
    while((fscanf(fic,"%d,%[^,],%f\n", &ID, predate, &temp)) != EOF){    //get the elmt, date and ID station
        predate[19]='\0';                                           // cut the date to have only years, months, days, and hours
        struct tm tm;
        time_t date;
        if(strptime(predate, "%Y-%m-%dT%H:%M:%S", &tm) != NULL){     // change the date into int
            date=mktime(&tm);
        }
        if(strcmp(argv[4], "-date")==0){          //compare argument to know wich data we will sort
            avl=insert_AVL(avl,date,ID,temp);
        }
        else if(strcmp(argv[4], "-id")==0){         
            avl=insert_AVL(avl,ID,date,temp);
        }
        else{
            return 1;                       //case error
        }   
    }
    fclose(fic); 
    fic=fopen(argv[2], "w+");                                    //open file
    Pchain temp2;
    if(fic==NULL) exit(3);
    if(argc == 6 && strcmp(argv[5], "-r")==0){               //compare with argument -r
        r_write_inorder_avl(fic,avl);
    }
    else {            
        write_inorder_avl(fic,avl);
    }
    fclose(fic);                //close file
    return 0;
}
