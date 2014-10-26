#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct punti{
	float x,y;
	float distanza;
	
};  

void minmax(struct punti *punto , int *n);
void InsertionSort(struct punti *punto , int *n);

int main(int argc , char *argv[]){	
	
	FILE *f1;
	f1=fopen(argv[1],"r");
	if(argc != 2 || !f1){
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
			
		//pass=fabs(((float)punto[i].x - punto[i].y));
		i++;
	}

	minmax(punto,&var);
	InsertionSort(punto,&var);
	return 0;
}

void minmax(struct punti *punto,int *n){

	int i,j;
	float dist;
	float min,max;
	float distanza;
	int indici[4];
	
	
	printf("Inserisci una Distanza");
	scanf("%f",&distanza);
	
	for(i=0;i<*n/2;i++)	
	{
		for(j=i+1;j<*n/2;j++)
		{
			if(i!=j){
				dist=sqrtf(powf((punto[i].x - punto[j].x),2) + powf((punto[i].y - punto[j].y),2));		
				if(i==0){
					min=dist;
					indici[0]=i;
					indici[1]=j;	
				}	
				
				if(dist < min){
					min=dist;
					indici[0]=i;
					indici[1]=j;	
				}
				if(dist > max){
					max=dist;
					indici[2]=i;
					indici[3]=j;		
				}
				if(dist < distanza)
					printf("---> X1: %.1f Y1 %.1f X2 %.1f Y2 %.1f distanza --> %.1f \n", punto[i].x , punto[i].y , punto[j].x , punto[j].y , dist);					
			}
		}
	}
	printf("\nLa coppia di Punti più vicina è X1: %.1f Y1:%.1f X2: %.1f Y2: %.1f\n ",punto[indici[0]].x , punto[indici[0]].y , punto[indici[1]].x , punto[indici[1]].y);
	printf("La coppia di Punti più lontana è X1: %.1f Y1:%.1f X2: %.1f Y2: %.1f\n ",punto[indici[2]].x , punto[indici[2]].y , punto[indici[3]].x , punto[indici[3]].y);
	
}
void InsertionSort(struct punti *punto , int *n){
	
	int i,j;
	float x,y,z;
	
	for(i=1;i<=*n/2-1;i++){
		
		x=punto[i].distanza;
		y=punto[i].y;
		z=punto[i].x;
		
		j=i-1;
		while(j>=0 && x<punto[j].distanza){
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
		printf("\n Elemento n %d , Cordinata: %.1f , %.1f distanza %.1f \n",i+1,punto[i].x,punto[i].y, punto[i].distanza);
} 
