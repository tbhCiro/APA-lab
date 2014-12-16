#define N 30 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "job.h"

int numjob( float *tot){
	int conta=0;
	char buff[N];
	int tmp;
	while(!feof(f1)){
		fscanf(f1,"%s",buff);
		fscanf(f1,"%d",&tmp);
		*tot=*tot + tmp; 	
		conta++;
	}
	rewind(f1);
	return conta-1;
	
}
int numris(){
	int conta=0;
	char buff[N];
	while(!feof(f2)){
		fscanf(f2,"%s",buff);	
		conta++;
	}

	rewind(f2);
	return conta-1;
}
void Init_job(Item *t , int njob){
	fscanf(f1,"%s",(*t)->job); 
	fscanf(f1,"%d",&(*t)->diff); 
	(*t)->ris_assegnata=0;	
	
}
Item InsertionSort(int a , Item *t , int l , int r){
	Item x;
	x=malloc(sizeof(Item));
	int i,j;
	r=r-1;
	
	for(i=l+1;i<=r;i++)
	{
		x=t[i];
		j=i-1;
		while(j>=l && x->diff > (*t)->diff){		//funzione Compare che confronta , a turno , il peso e l'importanza
			t[j+1] = t[j];
			j--;
		}
		t[j+1]= x;
	}
	return *t;
}
void Greedy_job(int pos , int n , int i, Item *t , float somma , float peso)
{
	if(i<n){
		somma =  somma + (float) t[i]->diff; 		
		if(somma<=peso && t[i]->ris_assegnata==0){	
			t[i]->ris_assegnata=pos;
			fprintf(f3,"Nome job: %s - Importanza: %d \n",t[i]->job,t[i]->diff);	
		}
		else{
			somma = somma - (float)t[i]->diff; 		
			
		}	
		Greedy_job(pos,n,i+1,t,somma,peso);
	}
}
void Stampa_job(Item t){
	printf("%s ",t->job);
	printf("%d ",t->diff);
	printf("%d \n",t->ris_assegnata);
}
