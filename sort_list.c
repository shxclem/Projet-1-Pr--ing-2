#include "main.h"


Pchain create_Chain(int a,int b,int c){     //create the chain for the list
	Pchain d = malloc(sizeof(Pchain));
	if(c==NULL){
		exit(1);
	}
	d->elt=a;
    d->secondelt=b;
    d->temp=c
	d->next=NULL;
	return d;
}




Pchain insert(Pchain pliste, int e, int sleep,float  temp){    //insertion of element in the list
    Pchain new= create_Chain(e,sleep,temp);
    Pchain p1 = pliste;
    if (p1 == NULL) {
        return new;
    }
    while (p1->next != NULL && e >= p1->next->elt){
        p1=p1->next;
    }
    new->next=p1->next;
    p1->next=new;
    return pliste;
}




int sort_list(char **argv){                           //sort with a list
    Pchain list=NULL;
    FILE *fic=fopen(argv[1], "r");         //open file
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
        if(strcmp(argv[5], "-date")==0){          //compare argument to know wich data we will sort
            list=insert(date,id,a);
        }
        else if(strcmp(argv[5], "-id")==0){         
            list=insert(id,date,temp);
        }
        else[
            return 1;                       //case error
        ]
    }
    fclose(fic);                            //close file
    fic=fopen(argv[2], "w");                                    //open file
    Pchain temp2;
    if(fic==NULL) exit(3);
    while(list){
        fprintf(fic,"%d %d %f\n", elt, secondelt, temp);  //write the sorted value
        temp2=list;
        list=list->next;
        free(temp2);
    }
    fclose(fic);                //close file
    return 0;
}
