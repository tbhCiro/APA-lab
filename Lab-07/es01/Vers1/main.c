#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

int main(){
	int scelta,n;
	printf("Inserisci la capienza della coda(MAX 100): ");
	scanf("%d",&n);
	if(n>100) return -1;
	Init(n);
	t=NULL;
	conta=0;head=0;tail=0;  //opzionale , perchè richiesto da warning
	do{
		printf("\nMenù:\n");
		printf("1. Cardinalità\n");
		printf("2. Inserimento Elemento in coda\n");
		printf("3. Estrazione Elemento dalla coda\n");
		printf("4. Visualizzare Tutti Gli Elementi\n");
		printf("5. Salvataggio di dati su file\n");
		printf("6. Caricamento di dati da file\n");
		printf(": ");
		scanf("%d",&scelta);
		switch(scelta){
				case 1: Card();	break;
				case 2: Put(n); break;
				case 3: Get(n); break;			
				case 4: Print(n);break;
				case 5: Save(n); break;	
				case 6: Getf(n); break;
		}
	}while(scelta!=-1);
	return 0;
}
