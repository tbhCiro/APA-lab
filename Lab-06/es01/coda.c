#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coda.h"

void Nelementi3(int conta3){
	if(conta3==0)
		printf("\nLista Vuota");
	else
		printf("\nN elementi: %d ",conta3);
}
lista3 Insert3(lista3 t3){
	printf("\nInserisci il nome della persona \n");
	scanf("%s",t3->nome3);
	printf("\nInserisci il cognome della persona \n");
	scanf("%s",t3->cognome3);
	printf("\nInserisci la matricola  \n");
	scanf("%s",t3->matricola3);
	printf("\nInserisci i crediti \n");
	scanf("%d",&(t3->voto3.crediti3));
	printf("\nInserisci la media \n");
	scanf("%f",&(t3->voto3.media3));	
	return t3;
}
void Stampa3(lista3 t3 , lista3 first3 , int conta3){
	if(conta3==0)
		printf("\nLista vuota");
	else{
		t3=first3;
		while(t3!=NULL){
			printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t3->matricola3,t3->cognome3,t3->nome3,t3->voto3.crediti3,t3->voto3.media3);
			t3=t3->succ3;
		}	
	}
}

lista3 InsCoda3(lista3 t3 , lista3 first3 ,int conta3 , lista3 a3){
	if(conta3==0){
		a3=malloc(sizeof *a3);
		first3=t3;
		a3=first3;
		return a3;
	}else{	
		a3->succ3 = t3;
		t3->prec3 = a3;
	}
		a3=t3;
		return a3;
}
void Destroy3(lista3 t3){
	while(t3!=NULL){
		t3=t3->succ3;
		if(t3!=NULL)
			free(t3->prec3);
	}
}
lista3 EstrTesta2(lista3 t3 , lista3 first3 , int conta3){
	if(first3!=NULL && conta3!=1){	
		first3->succ3->prec3 = NULL;
		first3=first3->succ3;
	}else if(conta3==1)
	{	//free(first2);
		first3=NULL;
	}
	else
		printf("\nLista Vuota");
	return first3;
}
