#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc , char *argv[]){	

	if(argc!=4){
		printf("Numero Argomenti non valido");
		return -1;		
	}
		
	FILE *f1;
	FILE *f2;
	FILE *f3;
			
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"r");
	f3=fopen(argv[3],"w");
	
	if(!(f1 && f2 && f3)){
		printf("Errore Apertura File");
		return -1;
	}
		
	int m1[2],m2[2];
	int **matrice1;
	int **matrice2;
	int **matrice3;
	int i,j,k;
	
	fscanf(f1,"%d%d",&m1[0],&m2[0]);		//prendo i primi 2 numeri del file
	fscanf(f2,"%d%d",&m1[1],&m2[1]);
		
	if(m2[0]!=m1[1]){	//il numeri di colonne di A deve essere uguale al num di righe di B 
		printf("Il prodotto tra matrici non può essere eseguito");
		return -1;
	}
		
	matrice1=malloc(m1[0] * sizeof(int));
	for(i=0;i<m1[0];i++){
		matrice1[i]=malloc(m2[0] * sizeof(int));	//allocazione dinamica prima matrice
		for(j=0;j<m2[0];j++)
			fscanf(f1,"%d",&matrice1[i][j]);
	}
		
	matrice2=malloc(m1[1] * sizeof(int));
	for(i=0;i<m1[1];i++){
		matrice2[i]=malloc(m2[1] * sizeof(int));	//allocazione dinamica seconda matrice
		for(j=0;j<m2[1];j++)
			fscanf(f2,"%d",&matrice2[i][j]);
	}
		
	matrice3=malloc(m1[0] * sizeof(int));			
	for(i=0;i<m1[0];i++){							//allocazione dinamica terza matrice	
		matrice3[i]=malloc(m2[1] * sizeof(int));
	}
	for(i=0;i<m1[0];i++)
		for(j=0;j<m2[1];j++)						//calcolo il prodotto tra matrici
			for(k=0;k<m1[1];k++)					
				matrice3[i][j]= matrice3[i][j] + ( matrice1[i][k] * matrice2[k][j]);		
	fprintf(f3,"%d %d\n",m1[0],m2[1]);
		
	for(i=0;i<m1[0];i++){
		for(j=0;j<m2[1];j++)
			fprintf(f3,"%d ",matrice3[i][j]);		//stampo sul terzo file la matrice soluzione del prodotto
		fprintf(f3,"\n");
	}
return 0;	
}
