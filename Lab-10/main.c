#define N 30 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "job.h"

int main(int argc , char *argv[]){
	if(argc!=4) return -1;
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"r");
	f3=fopen(argv[3],"w");
	if(!f1 || !f2 || !f3) return -1;
	
	int njob,nris,i;
	float tot=0;
	
	njob=numjob(&tot);
	nris=numris();
	
	t=malloc(njob * sizeof(Item));
	for(i=0;i<njob;i++){	
		t[i]=malloc(sizeof(struct oggetti));		//inizializzazione struttura dati
		Init_job(&t[i],njob);	
	} 
	tot=(float) tot/nris;	//totale delle difficoltà / numero risorse
	*t=InsertionSort(0,t,0,njob);		 //ordina per diff
	
	for(i=0;i<nris;i++)
	{
		fprintf(f3,"------Nome Risorsa: risorsa_%d------\n",i+1);
		if(i!=nris-1)
			Greedy_job(i+1,njob,0,t,0,tot);
		else
			Greedy_job(i+1,njob,0,t,0,tot*2); //nell'ultima operazione , se è rimasto qualche residuo , lo prende lo stesso
		fprintf(f3,"\n");
	}		
	
	printf("file %s scritto correttamente!",argv[3]);
	return 0;	
}
