#define N 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bag.h"

/*lab 9 eseguito in modo greedy (dinamico) , ordino il vettore di item , inizialmente per importanza. 
Prendo gli elementi con importanza maggiore , quando la somma delpeso  supera n inserito  passo all'elemento successivo 
e cerco di "tappare i buchi" , fino alla fine del vettore. Faccio ritornare il puntatore ad item con il campo flag modificato.
A questo punto riempio i bagagli della stiva  tenendo conto del peso massimo , lo faccio fino a che non ho il campo flag , in tutti gli elementi , uguale a 1.
*/

int main(int argc , char *argv[]){
	if(argc!=3) return -1;
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"w");
	if(!f1) return -1;
	int n=0,i;
	float peso;
	printf("Peso massimo: ");
	scanf("%f",&peso);
	
	n= n_element();
	
	t=malloc(n * sizeof(Item));
	for(i=0;i<n;i++){	
		t[i]=malloc(sizeof(struct oggetti));		//inizializzazione struttura dati
		Init_bag(&t[i]);	
	}	
	*t=InsertionSort(0,t,0,n); //ordina per importanza
		
	float p=0;
	fprintf(f2,"-------Bagaglio a mano--------\n");
	Greedy_mano(n,0,t,p,0,peso);					//Funzione Greedy per il bagaglio a mano
		
	*t=InsertionSort(1,t,0,n); //ordina per peso	
	int interrupt=1,n_bag;
	
	for(i=0;i<n;i++)
			if(t[i]->flag==0)		//il while si deve fermare quando  il campo flag di tutta la struttura è a 1
				interrupt=0;
	
	if(interrupt==0){
		while(interrupt!=1){ 
			n_bag++;
			fprintf(f2,"-------Bagaglio stiva n %d ----\n",n_bag);  //Funzione Greedy per il bagaglio a stiva
			Greedy_stiva(n,0,t,p,peso);
			printf("\n");
			interrupt=1;
			for(i=0;i<n;i++)
				if(t[i]->flag==0)		//il while si deve fermare quando  il campo flag di tutta la struttura è a 1
					interrupt=0;
		}
		fprintf(f2,"-----------------------------\n");
	}
	printf("File %s Scritto con Successo , numero bagagli stiva %d ! \n ",argv[2],n_bag);
return 0;	
}
