#include <stdio.h>
#include <stdlib.h>

void catalan(int num , int *vet);
void stampacatalan(int num , int *vet);

int main (void){
	
	int num;
	int *vet;
	
	printf("Inserisci un numero: ");
	scanf("%d",&num);
	
	vet=malloc(num  * sizeof(int));
	catalan(num,&*vet);
	stampacatalan(num , &*vet);
	
	return 0;	
}
void catalan(int num , int *vet){
	int i;
	vet[0]=1;
	if(num >= 1)
		catalan(num-1,&*vet);	
	for(i=0;i<=num-1;i++)
		vet[num] = vet[num] + (vet[i] * vet[num - 1 - i]);	
}

void stampacatalan(int num , int *vet){
	int x;
	printf("La serie di catalam fino a quel valore è: \n");
		for(x=0;x<num;x++)
			printf("%d ",vet[x]);
	printf("\nPrecisamente C(%d) è uguale a %d \n",num,vet[num-1]);
}
