#define N 100
#define M 1000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc , char *argv[]){
	if(argc == 2){
		
		FILE *f1;
		
		f1=fopen(argv[1],"r");
		if(f1){

			char stringa[N];
			int lunghstringa[M];
			int posizione[N];
			int max=0,conta=0,contamax=0;
			int i,j,k,var;
		
			i=0;
			while(!feof(f1)){
				fscanf(f1,"%s",stringa);
				var=strlen(stringa);
				for(j=0;j<strlen(stringa);j++)
					if(!isalpha(stringa[j]))
						var--;
						
				lunghstringa[i]=var;
				posizione[lunghstringa[i]]++;
				contamax++;
				if(lunghstringa[i]>max)
					max=lunghstringa[i];
				i++;
			}
		
			i=0;	
			j=1;
			while(j <= max) 	//entro nel while quando la condizione è vera
			{
				conta=0;
				var=posizione[lunghstringa[i]];
				k=0;
				
				while(conta <  var && k < contamax ){					
					if(lunghstringa[k]==j){
						if(conta==0)
							printf("lunghezza %d , conteggio %d Posizione: ",j,var);
							
							printf(" %d ",k+1);
							conta++;
					}
					k++;
				}
				if(conta!=0)
				printf("\n");
				
				i++;
				j++;
			}	
			
		}else 
			printf("Nome file non corretto o file inadatto \n");			
	}else
		printf("Errore , Inserire 2 File Input e 1 File Output");
	
return 0;	
}
/* Note Aggiuntive:

*/

