#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coda_prioritaria.h"

void Nelementi4(int conta4){
	if(conta4==0)
		printf("\nLista Vuota");
	else
		printf("\nN elementi: %d ",conta4);
}
lista4 Insert4(lista4 t4){
	printf("\nInserisci il nome della persona \n");
	scanf("%s",t4->nome4);
	printf("\nInserisci il cognome della persona \n");
	scanf("%s",t4->cognome4);
	printf("\nInserisci la matricola  \n");
	scanf("%s",t4->matricola4);
	printf("\nInserisci i crediti \n");
	scanf("%d",&(t4->voto4.crediti4));
	printf("\nInserisci la media \n");
	scanf("%f",&(t4->voto4.media4));	
	return t4;
}
void Stampa4(lista4 t4 , lista4 first4 , int conta4){
	if(conta4==0)
		printf("\nLista vuota");
	else{
		t4=first4;
		while(t4!=NULL){
			printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t4->matricola4,t4->cognome4,t4->nome4,t4->voto4.crediti4,t4->voto4.media4);
			t4=t4->succ4;
		}	
	}
}

lista4 InsPosizione4(lista4 t4 , lista4 first4 ,int conta4,lista4 a4,lista4 tmp4){
		int i=0;
		tmp4=first4;
		if(tmp4==NULL){		//ins primo elemento
			first4=t4;
			return first4;
		}
		else{
			while(tmp4!=NULL){
				if(i!=0)
					tmp4=tmp4->succ4;
				if(tmp4!=NULL){
					if(((first4->voto4.media4 < t4->voto4.media4) && tmp4==first4 )){	
							return first4;					//ins in testa 
					}	
					}else if(((t4->voto4.media4) <= (tmp4->voto4.media4)) && tmp4->succ4==NULL){
						return a4; 
						
					}else if(((tmp4->voto4.media4) < (t4->voto4.media4))){
						return tmp4; //ins ordinato
					}
						i++;
						a4=tmp4;
				}
			}	
			return NULL;
}
void Destroy4(lista4 t4){
	while(t4!=NULL){
		t4=t4->succ4;
		if(t4!=NULL)
			free(t4->prec4);
	}
}
lista4 EstrTesta3(lista4 t4 , lista4 first4 , int conta4){
	if(first4!=NULL && conta4!=1){	
		first4->succ4->prec4 = NULL;
		first4=first4->succ4;
	}else if(conta4==1)
	{	
		first4=NULL;
	}
	else
		printf("\nLista Vuota");
	return first4;
}
