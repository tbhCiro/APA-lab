#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct punti{
	float x,y;
	float distanza;
	
};  

void minmax(struct punti *punto , int *n);
void InsertionSort(struct punti *punto , int *n, FILE *f2);

int main(int argc , char *argv[]){	
	
	FILE *f1;
	FILE *f2;
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"w");
	if(argc != 3 || !(f1 && f2)){
		printf("Errore nell'inserimento del nome del file");
		return -1;
	}
	
	int var,i;
	float num;
	struct punti *punto;
	
	while(!feof(f1)){	
		fscanf(f1,"%f",&num);
		var++;
	}
	fseek(f1,0,0);	//riporto il file all'inizio 

	punto=(struct punti*)malloc(3 * var * sizeof(float));
	//numero elementi * conta degli elementi * dimensione del tipo degli elementi

	i=0;
	while(!feof(f1)){
		fscanf(f1,"%f",&punto[i].x);		//metto il puntatore
		fscanf(f1,"%f",&punto[i].y);		
		punto[i].distanza=sqrtf(powf(punto[i].x , 2) + powf(punto[i].y , 2));
		i++;
	}

	minmax(punto,&var);			//richiamo la funzione minmax e Inserion Sort
	InsertionSort(punto,&var,f2);
	fclose(f1);
	fclose(f2);
	return 0;
}

void minmax(struct punti *punto,int *n){

	int i,j;
	float dist;
	float min,max;
	float distanza;
	int indici[4];
	int conta=0;
	
	printf("Inserisci una Distanza: ");
	scanf("%f",&distanza);
	
	for(i=0;i<*n/2;i++)	
	{
		for(j=i+1;j<*n/2;j++)
		{
			if(i!=j){
				dist=sqrtf(powf((punto[i].x - punto[j].x),2) + powf((punto[i].y - punto[j].y),2));	//calcolo della distanza
				if(i==0){
					min=dist;
					indici[0]=i;
					indici[1]=j;	
				}	
				
				if(dist < min){
					min=dist;
					indici[0]=i;		//mi salvo gli indici per capire qual'è il min o max
					indici[1]=j;	
				}
				if(dist > max){
					max=dist;
					indici[2]=i;
					indici[3]=j;		
				}
				if(dist < distanza)
					conta++;				//conto numero di segmenti con distanza minore di "distanza"
			}
		}
	}
	printf("\nLa coppia di Punti più vicina è X1: %.1f Y1:%.1f X2: %.1f Y2: %.1f\n ",punto[indici[0]].x , punto[indici[0]].y , punto[indici[1]].x , punto[indici[1]].y);
	printf("La coppia di Punti più lontana è X1: %.1f Y1:%.1f X2: %.1f Y2: %.1f\n ",punto[indici[2]].x , punto[indici[2]].y , punto[indici[3]].x , punto[indici[3]].y);
	printf("Numero di Segmenti con distanza Minore di %.1f sono: %d \n",distanza,conta);
}
void InsertionSort(struct punti *punto , int *n , FILE *f2){
	
	int i,j;
	float x,y,z;
	
	for(i=1;i<=*n/2-1;i++){
		
		x=punto[i].distanza;
		y=punto[i].y;
		z=punto[i].x;
		
		j=i-1;
		while(j>=0 && x<punto[j].distanza){		//ordino gli elementi in ordine crescente mediante Insertion Sort (conosciuto)
			punto[j+1].distanza=punto[j].distanza;
			punto[j+1].x=punto[j].x;
			punto[j+1].y=punto[j].y;
			j--;
		}
		punto[j+1].distanza = x;
		punto[j+1].y = y;
		punto[j+1].x = z;
	}
	for(i=0;i<*n/2;i++)
		fprintf(f2,"%.1f %.1f\n",punto[i].x,punto[i].y);		//stampo nel secondo file , i punti ordinati per distanza
}

 
