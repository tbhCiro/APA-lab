#include "fifo.h"

Item Init(int n){
	t=malloc(n * sizeof(dati));		//inizializzazione
	return t;
}
void Put(int n){		
	if(conta<n){	
		if(conta==0){
			tail=conta%n;			//inserimento elemento , se primo elemento cambio testa e coda
			head=conta%n;
		}
		else
		{	int c;
			c=tail;
			tail=(c+1)%n;			//se sono + elementi cambio solo la coda
		}
		char stringa[100];
		printf("Numero %d Inserisci Stringa: ",conta);
		scanf("%s",stringa);
		if(conta==0){
			//t[1]=malloc((strlen(stringa) + 2 )*sizeof(char));
			strcpy((t[conta]).nome,stringa);
		}else{
			strcpy(t[tail].nome,stringa);	
		}
		conta++;
	}else 
		Full();
}
void Get(int n ){
	if(conta!=0){
		int c;				//estrazione
		c=head;
		head =(c+1)%n;
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
void Print(int n){
		int i,c,x=0;
		i=head;
		while(x!=conta){
			c=i%n;	
			printf("%d -- %s\n",c,t[c].nome);
			i++;
			x++;
		}
}
void Save(int n ){
	char d[10];
	printf("Salvataggio su File , Inserisci il nome del file con l'estensione es: f1.txt\n");
	scanf("%s",d);
	FILE *f1;
	f1=fopen(d,"w");
	if(!f1)
		printf("Caricamento File Non Riuscito");
	else{	
		int i,c,x=0;
		i=head;
		while(x!=conta){
			c=i%n;	
			fprintf(f1,"%s\n",t[c].nome);			//salvataggio
			i++;
			x++;
		}
		printf("Salvataggio Eseguito Correttamente \n");
	fclose(f1);	
	}
}
void Getf(int n ){
	char d[10];
	char stringa[100];
	int ne=0;
	printf("Aquisizione da File , Inserisci il nome del file con l'estensione es: f1.txt\n");
	scanf("%s",d);
	FILE *f1;					//acquisizione
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
					tail=conta%n;
					head=conta%n;
				}
				else{	
					int c;
					c=tail;
					tail=(c+1)%n;
				}
				if(conta==0){
					strcpy(t[conta].nome,stringa);
				}else{
					strcpy(t[tail].nome,stringa);	
				}
				conta++;			
			}
		}
	}
}	
