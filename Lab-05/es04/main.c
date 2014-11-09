#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	char *stringa;	
	struct nodo *succ;	
};
int main(void)
{
	struct nodo *t = NULL , *a = NULL , *prima = NULL;
	int i=0,scelta,b,j;
	char str[10];
			
	do{
		printf("\nMenù:");
		printf("\n1. Aggiunta in fondo alla coda");
		printf("\n2. Estrazione in cima alla lista");
		printf("\n3. Stampa lista");
		printf("\n4. Esci");
		printf("\nScegli: ");
		scanf("%d",&scelta);
		
		switch(scelta){
			case 1: 
				printf("Inserisci il codice della persona \n");
				scanf("%s",str);
				b=strlen(str);
				
				if(b < 10){
					for(j=0;j<b;j++){
						if(str[j]==' '){
							printf("stringa con spazi");
							return -1;
						}
					}
				}
				else{
					printf("Lunghezza > 10");
					return -1;
				}	
				
				t=malloc(sizeof *t);
				t->stringa = malloc((strlen(str) + 2 )* sizeof(char));
				strcpy(t->stringa,str);
				if(i==0){
					a=malloc(sizeof *a);
					prima=t;
					strcpy(prima->stringa,str);
				}else{	
					a->succ = t;
					}	
				a = t;
				i++;	
			break;
			case 2: 
				if(i==0)
					printf("Lista vuota");
				else{
					free(prima->stringa);
					prima = prima->succ;	
				}
			break;
			case 3: 
				if(i==0)
					printf("Lista vuota");
				else{
					t=prima;
					while(t != NULL){
					printf("| %s |",t->stringa);
					t = t->succ;
					}	
				}
			break;
		}
	}
	while(scelta!=4);
return 0;	
}
