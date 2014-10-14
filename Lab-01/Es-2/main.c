#define N 80
#define M 99
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc , char *argv[]){
	
	if(argc == 4){
		
		FILE *f1;
		FILE *f2;
		FILE *f3;
		
		f1=fopen(argv[1],"r");
		f2=fopen(argv[2],"r");
		f3=fopen(argv[3],"w");
		
		if(f1 && f2 && f3){
			 
			char stringavet[M][N];
			char carattere;
			int numero;
			
			while(!feof(f2)){
				fscanf(f2,"%d",&numero);			
				fscanf(f2,"%s",stringavet[numero]);  //salvo la stringa in un vettore usando come indice il numero che la precede nel file 
					
			}	
			while(!feof(f1)){
					
				fscanf(f1,"%c",&carattere); 
					
				if(carattere=='$'){	//prendo carattere per carattere e confronto con il carattere speciale
	
					if(numero < 0 || numero > 99)
						printf("errore decodifica"); 	
					else{
								 
						fscanf(f1,"%d",&numero);			//acquisisco il numero dopo il '$' e lo uso come indice del vettore
						fprintf(f3,"%s ",stringavet[numero]); 	//stampo nel file decodifica stringa[numero]
					}			
				}else
					fprintf(f3,"%c",carattere);  //se carattere != '$' stampo su file normalmente , anche il carattere '\0' terminatore
			}
			
		}else 
			printf("Nome file non corretto o file inadatto \n");			
	}else
		printf("Errore , Inserire 2 File Input e 1 File Output");
	
return 0;	
}
/* Note Aggiuntive:
Ho adoperato questo tipo di soluzione perchè vado a salvare la stringa nella posizione "numero" , quindi gestisco gli indici e
questo tipo di soluzione risulta essere veloce e avere una complessità bassa.
*/
