#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc , char *argv[]){	
		if(argc!=2){
			printf("Numero Argomenti non valido");
			return -1;		
		}
		FILE *f1;
		f1=fopen(argv[1],"r");
		if(!f1){
			printf("Errore Apertura File");
			return -1;
		}
		
		struct dati{
			int indice;
			int valore;
		};
		struct dati **val;
		int **matrice;
		int app;
		int r,c,i,j,k; 
		int *conta,conta2=0;
		int flag=0,flag2=0;
		
		fscanf(f1,"%d%d",&r,&c);
		
		if(r==c)
			flag=1;
		
		matrice=malloc((r + 1)* sizeof(int));		//allocazione matrice da file
		conta=malloc(r * sizeof(int));
		
		for(i=0;i<r;i++){
			matrice[i]=malloc(c * sizeof(int));
			printf("|");
			for(j=0;j<c;j++){
				fscanf(f1,"%d",&matrice[i][j]);			//stampa della matrice completa
				printf(" %d ",matrice[i][j]);	
				if(matrice[i][j]!=0)
					conta[i]++;
			}
			printf("|\n");
		}
		printf("\n\n\n");
		
		val=malloc(r * sizeof(int));
		for(i=0;i<r;i++){
			val[i]=malloc(conta[i] * 2 * sizeof(int));	
			j=0;
			for(k=0;k<c;k++){
				
				if(matrice[i][k]!=0){	
					val[i][j].indice= k;
					val[i][j].valore= matrice[i][k];			//creazione matrice compatta
					j++;
				}
				if(i!=k)
					if(matrice[i][k]!=matrice[k][i])
						flag2=1;
			}		
		}
		for(i=0;i<r;i++){
			for(j=0;j<conta[i];j++){
				printf("| %d " , val[i][j].indice);			//stampa matrice compatta + verifica della simmetria
				printf("%d | ", val[i][j].valore);
				app=val[i][j].indice;
				if(flag==1){
					for(k=0;k<conta[app];k++){
						if((val[app][k].valore == val[i][j].valore) && (i == val[app][k].indice))
							conta2++;
					}	
				}
			}
		printf("\n");	
		}
		if(flag==0 || flag2==1)
			printf("La matrice completa non è simmetrica\n");
		else
			printf("La matrice completa è simmetrica \n");
		
		if(conta2 != ((r * c)-r) || flag==0)
			printf("La matrice Ridotta non è simmetrica\n");
		else
			printf("La matrice Ridotta è simmetrica\n");
			
			
		printf("inserisci <i,j>: ");
		scanf("%d %d",&i,&j);
		
		if((i>=0 && i<r) && (j>=0 && j<c)){
			if(matrice[i][j]!=0)
				for(k=0;k<conta[i];k++)
					if(val[i][k].indice==j)
						printf("Nella matrice Completa corrisponde all'elemento %d , Nella matrice compatta si trova in val[%d][%d].valore \n",matrice[i][j],i,k);	
			else
				printf("Nella matrice Completa corrisponde all'elemento %d , Nella matrice compatta l'elemento non esiste perchè è uno zero\n",matrice[i][j]);		
		}
		else
			printf("indice/i fuori dalla matrice");
return 0;	
}
