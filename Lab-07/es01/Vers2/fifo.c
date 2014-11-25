#include "fifo.h"

Item Init(int n , Item t){
	t=malloc(sizeof (*t));
	t->p= malloc(n * sizeof(dati));
	return t;
}
void Put(int n , Item *t){		//passo t by reference
	if(conta<n){	
		if(conta==0){
			(*t)->tail=conta%n;
			(*t)->head=conta%n;
		}
		else
		{	int c;
			c=(*t)->tail;
			(*t)->tail=(c+1)%n;	
		}
		char stringa[100];
		printf("Numero %d Inserisci Stringa: ",conta);
		scanf("%s",stringa);
		if(conta==0){
			(*t)->p[conta].nome = malloc((strlen(stringa) + 2) * sizeof (char));
			strcpy((*t)->p[conta].nome,stringa);
		}else{
			(*t)->p[(*t)->tail].nome = malloc((strlen(stringa) + 2) * sizeof (char));
			strcpy((*t)->p[(*t)->tail].nome,stringa);	
		}
		conta++;
	}else 
		Full();
}
void Get(int n , Item *t){
	if(conta!=0){
		int c;
		c=(*t)->head;
		free((*t)->p[c].nome);
		(*t)->head =(c+1)%n;
		conta--;
		
	}else
		Empty();
}
void Full(){
	printf("Coda piena \n");	
}
void Empty(){
	printf("Coda Vuota \n");	
}
void Card(){
	printf("N elementi: %d \n",conta);	
}
void Print(int n,Item t){
		int i,c,x=0;
		i=t->head;
		while(x!=conta){
			c=i%n;	
			printf("%d -- %s\n",c,t->p[c].nome);
			i++;
			x++;
		}
}
void Save(int n , Item t){
	char d[10];
	printf("Salvataggio su File , Inserisci il nome del file con l'estensione es: f1.txt\n");
	scanf("%s",d);
	FILE *f1;
	f1=fopen(d,"w");
	if(!f1)
		printf("Caricamento File Non Riuscito");
	else{	
		int i,c,x=0;
		i=t->head;
		while(x!=conta){
			c=i%n;	
			fprintf(f1,"%s\n",t->p[c].nome);
			i++;
			x++;
		}
		printf("Salvataggio Eseguito Correttamente \n");
	fclose(f1);	
	}
}
void Getf(int n , Item *t){
	char d[10];
	char stringa[100];
	int ne=0;
	printf("Aquisizione da File , Inserisci il nome del file con l'estensione es: f1.txt\n");
	scanf("%s",d);
	FILE *f1;
	f1=fopen(d,"r");
	if(!f1)
		printf("Caricamento File Non Riuscito");
	else{
		while(!feof(f1)){
			fscanf(f1,"%s\n",stringa);
			ne++;
		}
		rewind(f1);
		if(ne > n - conta)
			printf("\nNon posso Acquisire , Dimensione Buffer Non sufficente per questo file\n\n");
		else{	
			while(!feof(f1)){
				fscanf(f1,"%s\n",stringa);
				printf("%s\n",stringa);
				if(conta==0){
					(*t)->tail=conta%n;
					(*t)->head=conta%n;
				}
				else{	
					int c;
					c=(*t)->tail;
					(*t)->tail=(c+1)%n;
				}
				if(conta==0){
					(*t)->p[conta].nome = malloc((strlen(stringa) + 2) * sizeof (char));
					strcpy((*t)->p[conta].nome,stringa);
				}else{
					(*t)->p[(*t)->tail].nome = malloc((strlen(stringa) + 2) * sizeof (char));
					strcpy((*t)->p[(*t)->tail].nome,stringa);	
				}
				conta++;			
			}
			
		}
	}
}	
