#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_non_ordinata.h"

void Nelementi(int conta){
	if(conta==0)
		printf("\nLista Vuota");
	else
		printf("\nN elementi: %d ",conta);
	
}
lista InsCoda(lista t , lista first ,int conta , lista a){
	if(conta==0){
		a=malloc(sizeof *a);
		first=t;
		a=first;
		return a;
	}else{	
		a->succ = t;
		t->prec = a;
	}
		a=t;
		return a;
}
lista Insert(lista t){
	printf("\nInserisci il nome della persona \n");
	scanf("%s",t->nome);
	printf("\nInserisci il cognome della persona \n");
	scanf("%s",t->cognome);
	printf("\nInserisci la matricola  \n");
	scanf("%s",t->matricola);
	printf("\nInserisci i crediti \n");
	scanf("%d",&(t->voto.crediti));
	printf("\nInserisci la media \n");
	scanf("%f",&(t->voto.media));	
	return t;
}
void Stampa(lista t , lista first , int conta , lista last){
	if(conta==0)
		printf("Lista vuota");
	else{
		t=first;
		while(t!=NULL){
			printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t->matricola,t->cognome,t->nome,t->voto.crediti,t->voto.media);
			last=t;
			t=t->succ;
		}	
	}
}
lista InsTesta(lista t , lista first , int conta){
	if(conta==0){
		first=t;
		a=malloc(sizeof *a);                                                                                     
	}
	else{
		t->succ=first;
		t->succ->prec = t;
		first=t;
	}
	return first;
}
lista SearchDestroy(int scelta3 , lista t , lista first , int flag2 , lista a , lista tmp){
	char chiave1[36];
	int chiave2;
	float chiave3;
	int flag=0;
	printf("Inserisci Chiave: ");
	switch(scelta3){
		case 1: 
			scanf("%s",chiave1);
			t=first;
			while(t!=NULL){
				tmp = t->succ;
				if(strcmp(t->nome,chiave1)==0){
					printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t->matricola,t->cognome,t->nome,t->voto.crediti,t->voto.media);
					if(flag2==1 && t->succ!=NULL)
						first=Canc(t,first,a);
					flag=1;
				}
				t=tmp;
			}
			if(flag==0 || first==NULL)
				printf("\nChiave Non trovata (La Lista Potrebbe essere Vuota)");
		break; 
		case 2:	
			scanf("%s",chiave1);
			t=first;
			while(t!=NULL){
				tmp = t->succ;
				if(strcmp(t->cognome,chiave1)==0){
					printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t->matricola,t->cognome,t->nome,t->voto.crediti,t->voto.media);
					if(flag2==1 && t->succ!=NULL)
						first=Canc(t,first,a);
					flag=1;
				}
				t=tmp;	
			}
			if(flag==0 || first==NULL)
				printf("\nChiave Non trovata (La Lista Potrebbe essere Vuota)");
		break;
		case 3:
			scanf("%s",chiave1);
			t=first;
			while(t!=NULL){
				tmp = t->succ;
				if(strcmp(t->matricola,chiave1)==0){
					printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t->matricola,t->cognome,t->nome,t->voto.crediti,t->voto.media);
					if(flag2==1 && t->succ!=NULL)
						first=Canc(t,first,a);
					flag=1;
				}
				t=tmp;
			}
			if(flag==0 || first==NULL)
				printf("\nChiave Non trovata (La Lista Potrebbe essere Vuota)");
		break;
		case 4:
			scanf("%d",&chiave2);
			t=first;
			while(t!=NULL){
				tmp = t->succ;
				if(t->voto.crediti==chiave2){
					printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t->matricola,t->cognome,t->nome,t->voto.crediti,t->voto.media);
					if(flag2==1 && t->succ!=NULL)
						first=Canc(t,first,a);
					flag=1;
				}
				t=tmp;
			}
			if(flag==0 || first==NULL)
				printf("\nChiave Non trovata (La Lista Potrebbe essere Vuota)");
		break;
		case 5:
			scanf("%f",&chiave3);
			t=first;
			while(t!=NULL){
				tmp = t->succ;
				if(t->voto.media==chiave3){
					printf("\n|Matricola %s - Cognome %s - Nome %s - Crediti: %d - Media %.2f|",t->matricola,t->cognome,t->nome,t->voto.crediti,t->voto.media);
					if(flag2==1 && t->succ!=NULL)
						first=Canc(t,first,a);
					flag=1;
				}
				t=tmp;
			}
			if(flag==0 || first==NULL)
				printf("\nChiave Non trovata (La Lista Potrebbe essere Vuota");	
				
		default: printf("Non valido. Riprovare"); break;
	}
	return first;
}
void Destroy(lista t){
	while(t!=NULL){
		t=t->succ;
		if(t!=NULL)
			free(t->prec);
	}	
}
lista Canc(lista t , lista first , lista a){
	if(t->succ==NULL){
		t->prec->succ=NULL;
	}else if(t->prec == NULL){
		t->succ->prec=NULL;
		first=t->succ;
	}else if(t->prec == NULL && t->succ == NULL)
	{}
	else{
		t->succ->prec = t->prec;
		t->prec->succ = t->succ;
	}
	free(t);	
	return first;
}		
