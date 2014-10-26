#define N 25


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void InsertionSortS(char **stringa,int *n);
int BinSearchS(char **stringa, int *n ,char *str);


int main(void){
	
	
	int j;
	int x,i=0;
		do
		{
			printf("-Menu'-\n");
			printf("1. Inserimento Nuova Stringa\n");
			printf("2. Elimina una Stringa\n");
			printf("3. Ricerca Dicotomica Stringa\n");
			printf("4. (Debug) Visualizza tutte le Stringhe\n");
			printf("5. Uscita\n");
			printf("Scegli: ");
			scanf("%d",&x);	
			
			if(x==5)
			return 0;
						
			
			char *stringa[100];
			char str[N+1];	
			int flag,f;
				
			switch(x){
				
				case 1:
					printf("Inserisci una stringa: ");
					scanf("%s",str);
				
					if(strlen(str) > N)
					{
						printf("Lunghezza stringa non tollerata");
						break;
					}
				
					stringa[i]=malloc((strlen(str) +1) * (sizeof(char)));
					strcpy(stringa[i],str);
					InsertionSortS(&*stringa,&i);
					i++;
				break;
			
				case 2:
            
				flag=0;
				printf("inserisci una stringa da eliminare: ");
				scanf("%s",str);
            
				for(j=0;j<i;j++){
					if(flag==1)
						strcpy(stringa[j-1],stringa[j]);
					if(strcmp(str,stringa[j]) == 0 && flag==0)
						flag=1;	
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
					printf("\n Trovato! alla posizione %d \n\n",f+1);
				else
					printf("\n Non trovato \n");
					
				break;
				case 4:
						
				for(j=0;j<i;j++)
					printf("%s\n",stringa[j]);
				printf("\n");
			
				break;
			}
		}while(1);
}
void InsertionSortS(char **stringa , int *n){
	int j,k;
	char x[N+1];
	
	printf("%s  ",stringa[0]);
	
	for(j=1;j<=*n;j++){
		strcpy(x,stringa[j]);
		printf("%s ",x);
		k= j -1;	
		while(k>=0 && strcmp(x,stringa[k]) < 0){
			strcpy(stringa[k+1],stringa[k]);
			k--;
		}
		strcpy(stringa[k+1],x);	
	}	
		
}
int BinSearchS(char **stringa,int *n,char *str){
	
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
	
	
	
	
	






