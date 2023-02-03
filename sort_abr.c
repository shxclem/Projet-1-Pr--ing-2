#include "main.h"



PABR create_abr(int a, int b, float c){     //create the node of an ABR
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



PABR new_elt(PABR pa, int e, int sleep,float temp){   //insertion in abr
    if (pa==NULL){
        return create_abr(e,sleep,temp);;
    }
    else if(e<pa->elt){
        new_elt(pa->fg, e);
    }
    else if(e>=pa->elt){
        new_elt(pa->fd,e);
    }
    return pa;
}



void write_inorder(PABR a){              //ascending course
    if (!a){
        write_inorder(a->fg);
        fprintf(fic,"%d %d %f\n", elt, secondelt, temp);  //write the sorted value
        temp2=a;
        write_inorder(a->fd);
        free(temp2);
    }
}



void r_write_inorder(PABR a){              //descending course
    if (!a){
        write_inorder(a->fd);
        fprintf(fic,"%d %d %f\n", elt, secondelt, temp);  //write the sorted value
        temp2=a;
        write_inorder(a->fg);
        free(temp2);
    }
}



int sort_abr(char **argv){
    PABR abr=NULL;
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
            abr=insert(date,id,a);
        }
        else if(strcmp(argv[4], "-id")==0){         
            abr=insert(id,date,temp);
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
        r_write_inorder(abr);
    }
    else if(strcmp(argv[5], "-r")==0){               
        write_inorder(abr);
    }
    else{
        exit (1);
    }
    fclose(fic);                //close file
    return 0;
}