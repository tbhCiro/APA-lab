#define MAX1 10
#define MAX2 20

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Basi per Manipolazione Stringhe

int main(int argc , char *argv[]){
	
	if(argc == 3 && strlen(argv[1]) <= MAX1 && strlen(argv[2]) <= MAX1){
		
		FILE *f1;
		FILE *f2;
		f1=fopen(argv[1],"r");
		f2=fopen(argv[2],"w");
		
		if(f1 && f2){
			
			int n;
			char p[MAX2];
			char var[MAX2];
			
			fscanf(f1,"%d",&n);
			fscanf(f1,"%s",p);
			
			if(strlen(p) <= MAX2){
			
				while(!feof(f1)){
					fscanf(f1,"%s",var);
					if(strlen(var) >= MAX2)
						printf("errore");
					else{
						if(strcmp(p,var) < 0)
							fprintf(f2,"%s\n",var);
						}
				}
			}else
				printf("Nel file sono presenti stringhe con lunghezza maggiore di %d ",MAX2);	
		}
		else 
			printf("Nome file non corretto o file inadatto \n");
	}
	else
		printf("Errore , inserisci il nome del file (MAX %d caratteri) \n",MAX1);
	
return 0;	
