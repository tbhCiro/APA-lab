#define N 3
#include <stdio.h>  //programma che dato un file numerato calcoli il baricentro 

//basi per file , argc argv , lettura file 

int main(int argc , char *argv[]){

	if(argc == 2){
		FILE *f1;
		f1=fopen(argv[1],"r");
				
		if(f1){
			float baricentro[N]={0};
			float var=0;
			int i=0,elemtotali=0;
			
			while(!feof(f1)){	
				fscanf(f1,"%f",&var);
				baricentro[i]=baricentro[i] + var;
					if(i!=N-1)	
						i++;
					else
						i=0;
				elemtotali++;
				}
			elemtotali=elemtotali / N;
			printf("Il baricentro è: ");
			
			for(i=0;i<N;i++){
			baricentro[i]=(float)(baricentro[i] / elemtotali) ;
			printf("%.1f ",baricentro[i]);
			}	
				
			fclose(f1);
		}else 
			printf("Nome file non corretto o file inadatto");
					
	}else
		printf("Errore , inserisci il nome del file");
	
return 0;	
}


