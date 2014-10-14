#define N 8
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc , char *argv[]){
	
	if(argc == 3){
		
		FILE *f1;
		FILE *f2;                                      
		f1=fopen(argv[1],"r");
		f2=fopen(argv[2],"w");
		
		if(f1 && f2){
		
			int r,c;
			int i=0,j=0;
			
			fscanf(f1,"%d",&r);
			fscanf(f1,"%d",&c);
			fprintf(f2,"%d ",r);
			fprintf(f2,"%d\n",c);
			
			int matrice[r][c];
			int k;
			int posizioni[N][2]={ 	{-1,-1},   //matrice delle posizioni adiacenti 
									{-1 ,0},
									{-1, 1},
									{0 ,-1},
									{0 , 1},
									{1 ,-1},
									{1 , 0},
									{1 , 1}};
			float media[r][c];
			int uno , due;
			int pass,conta;
																																																																																																																																																																																										   
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					fscanf(f1,"%d",&matrice[i][j]); //copio dal file la matrice
			
			for(i=0;i<r;i++)
				for(j=0;j<c;j++){
					pass=0;
					conta=0;
					for(k=0;k<N;k++){          
						uno = i + posizioni[k][0];		//somma degli inidici per trovare la posizione 
						due = j + posizioni[k][1];
						if((uno >= 0 && uno < r) && (due >= 0 && due < c)){	//devo esscludere alcune posizioni. 
							pass=pass + matrice[uno][due];	//se no rischio di andare a prendere celle non appartenenti alla matrice
							conta++;						
							}
					}
					media[i][j]=(float)(pass)/conta; //calcolo la media matematica 
					
				}
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					fprintf(f2,"%.1f ",media[i][j]);	//Scrivo nel file la media delle celle adiacenti
				}
				fprintf(f2,"\n");
			}	
		printf("\nScrittura Avvenuta Correttamente!\n");
		fclose(f1);
		fclose(f2);	
		}
		else 
			printf("Nome dei file non corretto o file inadatti \n");
	}else
		printf("Errore , Inserire File Input e File Output");
	
return 0;	
}
/* Note Aggiuntive:
Ho adoperato questo tipo di soluzione perchè con il vettore delle posizioni riesco , andando a lavorare solo su somme sugli indici, ad ottenere 
la posizione delle celle adiacenti. 
 */
