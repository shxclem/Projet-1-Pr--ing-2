#include "main.h"



Pchain create_Chain(int a,int b,int c){     //create the chain for the list
	Pchain d = malloc(sizeof(Pchain));
	if(d==NULL){
		exit(4);
	}
	d->elt=a;
    d->secondelt=b;
    d->temp=c;
	d->next=NULL;
	return d;
}



Pchain insert(int argc, char **argv, Pchain pliste, int e, int sleep,float temp){    //insertion of element in the list
    Pchain new= create_Chain(e,sleep,temp);
    Pchain p1 = pliste;
    if (p1 == NULL) {
        return new;
    }
    if(argc == 6 && strcmp(argv[5], "-r")==0){                                //compare with argument -r     
        while (p1->next != NULL && e <= p1->next->elt){
            p1=p1->next;
        }
        if (new->elt > p1->elt) {
            new->next = p1;
            return new;
        }
        else {
            new->next=p1->next;
            p1->next=new;
        }
    }
    else {
        while (p1->next != NULL && e >= p1->next->elt){
            p1=p1->next;
        }
        if (new->elt < p1->elt) {
            new->next = p1;
            return new;
        }
        else {
            new->next=p1->next;
            p1->next=new;
        }
    }

    return pliste;
}



int sort_list(int argc, char **argv){                           //sort with a list
    Pchain list=NULL;
    FILE *fic=fopen(argv[1], "r");         //open file
    if(fic==NULL) exit(2);
    int ID;
    char predate[25];
    float temp;
    while((fscanf(fic,"%d,%[^,],%f\n", &ID, predate, &temp)) != EOF){    //get the elmt, date and ID station
       printf("a\n");

        predate[19]='\0';                                           // cut the date to have only years, months, days, and hours
        struct tm tm;
        time_t date;
        if(strptime(predate, "%Y-%m-%dT%H:%M:%S", &tm) != NULL){     // change the date into int
            date=mktime(&tm);
        }
        if(strcmp(argv[4], "-date")==0){          //compare argument to know wich data we will sort
            list=insert(argc, argv,list,date,ID,temp);
        }
        else if(strcmp(argv[4], "-id")==0){         
            list=insert(argc, argv,list,ID,date,temp);
        }
        else{
            return 1;                       //case error
        }

    }
    fclose(fic);                            //close file
    fic=fopen(argv[2], "w+");                                    //open file
    Pchain temp2;
    if(fic==NULL) exit(3);
    while(list){
        fprintf(fic,"%d %d %f\n", list->elt, list->secondelt, list->temp);  //write the sorted value
        temp2=list;
        list=list->next;
        free(temp2);
    }
    fclose(fic);                //close file
    return 0;
}
