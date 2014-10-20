#define N 3
#define M 100		//Es 2 Lab 2
#define L 10

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc , char *argv[]){	
	if(argc == N){
		
		FILE *f1;
		FILE *f2;
		
		f1=fopen(argv[1],"r");
		f2=fopen(argv[2],"r");
	
		if(f1 && f2){
		
			int num;
			char stringa[M][M];
			int conta,k,i,j,n;
			int posizioni[L]={0};
			int max=0,max2=0;
			
			fscanf(f2,"%d",&num); //acquisisco il numero presente come primo elemento nel secondo file
	
			char caratteri[N][num];  //definisco la matrice appena so il primo numero del file
			i=0;
			while(!feof(f2)){
				fscanf(f2,"%s",caratteri[i]);	//salvo il contenuto del file delle sequenze di inizio nella matrice caratteri
				i++;
				max++;	//conto quanti elementi ci sono dentro al file delle sequenze
			}
			i=0;
			while(!feof(f1)){		
				fscanf(f1,"%s",stringa[i]);	//salvo il contenuto del file di testo nella matrice stringa
				i++;	
				max2++;	//conto quanti elementi ci sono dentro al file 1
			}
			
			j=0;
			i=0;
			while(j<max){
				
				printf("%s - ",caratteri[j]);
				i=0; k=0; conta=0;
				
				while(i<max2){
						if(strncmp(stringa[i],caratteri[j],strlen(caratteri[j])) == 0){		//confronto i primi n caratteri della stringa "stringa" con "caratteri" , n dipende dalla lunghezza della singola riga
							if(k<=L){	//massimo 10 posizioni
								posizioni[k]=i+1;
								k++;
							}
							conta++; //conta occorrenze
						}
						i++;
				}
				printf("%d - Occorrenza/e ",conta);
				
				for(n=0;n<k;n++){							//gestione dell'output
					if(n==0)
					printf("- Posizione/i: ");
					
					printf("%d ",posizioni[n]);
					
				}
				printf("\n");
				j++;	
			}	
				
		}else
			printf("Nome file non corretto o file inadatto \n");
			
	}else 
		printf("Errore , inserisci il nome del file (MAX %d caratteri) \n",N-1);
		
	return 0;
}
