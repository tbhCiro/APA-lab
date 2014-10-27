#define N 25
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void InsertionSortS(char **stringa,int *n);
int BinSearchS(char **stringa, int *n ,char *str);

int main(void){
	
	int j;
	int x,i=0;
		do{
			printf("-Menu'-\n");
			printf("1. Inserimento Nuova Stringa\n");
			printf("2. Elimina una Stringa\n");							//Menù
			printf("3. Ricerca Dicotomica Stringa\n");
			printf("4. (Debug) Visualizza tutte le Stringhe\n");
			printf("5. Uscita\n");
			printf("Scegli: ");
			scanf("%d",&x);	
			
			if(x==5)			//5 corrisponde all'uscita
			return 0;
						
			char *stringa[100];
			char str[N+1];	
			int flag,f;
				
			switch(x){
				
				case 1:
					printf("Inserisci una stringa: ");
					scanf("%s",str);
				
					if(strlen(str) > N){
						printf("Lunghezza stringa non tollerata");
						break;
					}
				
					stringa[i]=malloc((strlen(str) +1) * (sizeof(char)));
					strcpy(stringa[i],str);						//ad ogni inserimento vado ad ordinare il vettore 
					InsertionSortS(&*stringa,&i);				//così non ho problemi quando vado ad effettuare la Ricerca
					i++;										//dicotomica
				break;
			
				case 2:
					flag=0;
					printf("inserisci una stringa da eliminare: ");
					scanf("%s",str);
				
					for(j=0;j<i;j++){
						if(flag==1)
							strcpy(stringa[j-1],stringa[j]);		//Se trovo la stringa , faccio scalare di 1 posizione verso l'alto
						if(strcmp(str,stringa[j]) == 0 && flag==0)	//gli elementi del vettore di stringa , e vado a liberare l'ultimo 
							flag=1;									//puntatore a stringa
					}
					if(flag==0)
						printf("Elemento Non esistente nel vettore di Stringhe.");
					else{
						
						free(stringa[i-1]);
						i--;
						printf("Elementi Rimanenti: ");
						for(j=0;j<i;j++)
							printf("\n%s\n",stringa[j]);
					}	
				break;
				
				case 3: 
					printf("Inserisci Una Stringa da ricercare: ");
					scanf("%s",str);
					f=BinSearchS(&*stringa,&i,str);
						
					if(f!=-1)
						printf("\n Trovato! alla posizione %d \n\n",f);		//se trovato , restituisce la posizione 
					else
						printf("\n Non trovato \n");	
				break;
				case 4:
					for(j=0;j<i;j++)
						printf("%s\n",stringa[j]);		//Opzione Aggiuntiva: Per Avere un Debug in tempo reale
					printf("\n");
				break;
			}
		}while(1);
}
void InsertionSortS(char **stringa , int *n){			//inserion Sort Applicato al vettore di Stringhe
	int j,k;
	char x[N+1];
	
	for(j=1;j<=*n;j++){
		strcpy(x,stringa[j]);
		k= j -1;	
		while(k>=0 && strcmp(x,stringa[k]) < 0){
			strcpy(stringa[k+1],stringa[k]);
			k--;
		}
		strcpy(stringa[k+1],x);	
	}	
		
}
int BinSearchS(char **stringa,int *n,char *str){		//BinSearch Applicato al vettore di Stringhe
	int c,a;
	
	if(*n==0)
		return -1;
	while(a<=*n){
		c= a + (*n - a)/2;
		if(strcmp(stringa[c],str)==0)
			return(c);
		if(strcmp(stringa[c],str) < 0)
			a=c+1;
		else
			*n=c-1;
	}
	return (-1);	
}
