#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

void Nelementi2( int conta2){
	if(conta2==0)
		printf("\nLista Vuota");
	else
		printf("\nN elementi: %d ",conta2);
}
lista2 Insert2(lista2 t2){
	printf("\nInserisci il nome della persona \n");
	scanf("%s",t2->nome2);
	printf("\nInserisci il cognome della persona \n");
	scanf("%s",t2->cognome2);
	printf("\nInserisci la matricola  \n");
	scanf("%s",t2->matricola2);
	printf("\nInserisci i crediti \n");
	scanf("%d",&(t2->voto2.crediti2));
	printf("\nInserisci la media \n");
	scanf("%f",&(t2->voto2.media2));	
	return t2;
}
void Stampa2(lista2 t2 , lista2 first2 , int conta2){
	if(conta2==0)
		printf("\nLista vuota");
	else{
		t2=first2;
		while(t2!=NULL){
			printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t2->matricola2,t2->cognome2,t2->nome2,t2->voto2.crediti2,t2->voto2.media2);
			t2=t2->succ2;
		}	
	}
}
lista2 InsTesta2(lista2 t2 , lista2 first2 , int conta2){
	if(conta2==0){
		first2=t2;
		                                                                                     
	}
	else{
		t2->succ2=first2;
		t2->succ2->prec2 = t2;
		first2=t2;
	}
	return first2;
}
void Destroy2(lista2 t2){
	while(t2!=NULL){
		t2=t2->succ2;
		if(t2!=NULL)
			free(t2->prec2);
	}
		
}
lista2 EstrTesta(lista2 t2 , lista2 first2 , int conta2){
	if(first2!=NULL && conta2!=1){	
		first2->succ2->prec2 = NULL;
		first2=first2->succ2;
	
	}else if(conta2==1)
	{	//free(first2);
		first2=NULL;
		
	}
	else
		printf("\nLista Vuota");
	return first2;
}
